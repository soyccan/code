// PKZIP version 2.0
#include <bits/stdc++.h>
#define FOR(i,end) for (int i=0; i<end; ++i)
#define FOR1(i,end) for (int i=1; i<=end; ++i)
#define DEBUGMSG(format, ...) printf(format, ##__VA_ARGS__); fflush(stdout)
using namespace std;

#define FILE_CONTENT_ERROR 20
#define FILE_FORMAT_ERROR 66
#define FILE_UNEXPECTED_CLOSE 70
#define SUCCESS 0

class BitsReader {
public:
    BitsReader(istream* input, char* buf, size_t buf_size) {
        this->input = input;
        this->buf = buf;
        this->buf_size = buf_size;
        this->cBit = this->cByte = 0;

        this->input->read(this->buf, buf_size);
    }
    unsigned readbits(size_t count) {
        // beware of overflow
        unsigned bits = 0;
        for (unsigned i=0; i<count; i++)
            bits |= nextbit() << i;
        return bits;
    }

private:
    istream* input;
    char* buf;
    size_t buf_size, cByte, cBit;

    unsigned nextbit() {
        unsigned res = (buf[cByte] >> cBit) & 1;
        ++cBit;
        if (cBit > 7) {
            ++cByte;
            cBit = 0;
        }
        if (cByte > buf_size) {
            input->read(buf, buf_size);
            cByte = 0;
        }
        return res;
    }
};

class MyZipEncoder {
public:
    static constexpr size_t MAX_BUFFER_SIZE = 1048576; // 1M
    static constexpr size_t MAX_FIELD_LEN = 65535;
    static constexpr size_t MAX_FILE_COUNT = 1048576;
    // 32KiB for search block and for string block, 64KiB in total

    // void encode(byte* begin, size_t size, size_t block_size) {
    //     size_t dataend = 0;
    //     data[dataend++] = Block(0, 0, *begin);
    //     DEBUGMSG("%lld %lld %c\n", data[dataend-1].offset, data[dataend-1].length, data[dataend-1].next);
    //     byte* cur = begin + 1;
    //     byte* search = begin;
    //     while (cur < begin+size) {
    //         byte *pStart, *pEnd;
    //         pStart = search;
    //         while (*pStart != *cur && pStart+1 < cur)
    //             pStart++;
    //         data[dataend].offset = cur - pStart - 1;
    //         pEnd = pStart;
    //         while (*pEnd == *cur && pEnd < cur)
    //             pEnd++, cur++;
    //         data[dataend].length = pEnd - pStart;
    //         data[dataend].next = *cur;
    //         DEBUGMSG("%d %d %d %d\n", search-begin, pStart-begin, pEnd-begin, cur-begin);
    //         DEBUGMSG("data: %lld %lld %c\n", data[dataend].offset, data[dataend].length, data[dataend].next);
    //         dataend++;
    //         cur++;
    //         if (search < cur - block_size)
    //             search = cur - block_size;
    //     }
    // }
    int decode_deflate(size_t size) {
        DEBUGMSG("[decode_deflate] begin: %llu size: %llu\n", (size_t)input->tellg(), size);

        size_t buf_size = MAX_BUFFER_SIZE;
        if (buf_size > size)
            buf_size = size;
        BitsReader reader(input, buf, buf_size);
        char bFinal, bType;
        do {
            bFinal = reader.readbits(1);
            bType = reader.readbits(2);
            DEBUGMSG("header: %hx %hx\n", bFinal, bType);
            if (bType == 0) {
                // stored
                reader.readbits(5); // ignore
                uint16_t block_size = reader.readbits(16);
                DEBUGMSG("stored block_size: %hx\n", block_size);
                dump_stored(block_size);

            } else if (bType == 1) {
                // fixed huffman code
                DEBUGMSG("fixed huffman\n");
                // char c;
                // while (input->get(c) && !(c & 1)) {
                //     while (c) {
                //         DEBUGMSG("%d", c&1);
                //         c >>= 1;
                //     }
                //     DEBUGMSG(" ");
                // }
                // DEBUGMSG("\n");

                unsigned bits = 0;
                unsigned symbol = 0xfffffff;
                for (int bits_count=1; bits_count<=9; bits_count++) {
                    bits = (bits << 1) | reader.readbits(1);
                    if (bits_count == 8 && 48 <= bits && bits <= 191) {
                        symbol = bits - 48;
                        break;
                    } else if (bits_count == 9 && 400 <= bits && bits <= 511) {
                        symbol = bits - 256;
                        break;
                    } else if (bits_count == 7 && bits <= 23) {
                        symbol = bits + 256;
                        break;
                    } else if (bits_count == 8 && 192 <= bits && bits <= 199) {
                        symbol = bits + 88;
                        break;
                    }
                }
                DEBUGMSG("symbol: %u\n", symbol);

            } else if (bType == 2) {
                // dynamic huffman code
                DEBUGMSG("dynamic huffman\n");

            } else {
                DEBUGMSG("file content error!\n");
                return FILE_CONTENT_ERROR;
            }
        } while (!bFinal);
        return SUCCESS;
    }
    int dump_stored(size_t size) {
        copy_n(istream_iterator<char>(*input),
               size,
               ostream_iterator<char>(output));

        DEBUGMSG("tellg: %d\n", (int)input->tellg());
        DEBUGMSG("stored data: \n");
        cout<<output.rdbuf();

        return SUCCESS;
    }
    int init(istream* input) {
        this->input = input;
        while (input->good()) {
            input->read(buf, 4);
            uint32_t signature = read32(buf);
            if (signature == 0x04034b50) {
                // local file header
                // these information is not read into memory
                // but central directory header instead
                DEBUGMSG("local file header\n");

                FileInfo info;
                input->read(buf, 26);

                info.required_version = read16(buf);
                info.purpose = read16(buf+2);
                info.method = read16(buf+4);
                info.modtime = read16(buf+6);
                info.moddate = read16(buf+8);
                info.crc32 = read32(buf+10);
                info.compressed_size = read32(buf+14);
                info.uncompressed_size = read32(buf+18);
                uint16_t filename_len = read16(buf+22);
                uint16_t extrafield_len = read16(buf+24);

                input->read(info.filename, filename_len);
                info.filename[filename_len] = '\0';
                input->read(info.extrafield, extrafield_len);
                info.extrafield[extrafield_len] = '\0';

                if ((info.purpose >> 3) & 1) {
                    // data descriptor
                    DEBUGMSG("data descriptor\n");
                    input->read(buf, 12);
                    info.crc32 = read32(buf);
                    info.compressed_size = read32(buf+4);
                    info.uncompressed_size = read32(buf+8);
                }

                // file data
                if (info.method == 0) {
                    dump_stored(info.compressed_size);
                } else if (info.method == 8) {
                    decode_deflate(info.compressed_size);
                } else {
                    DEBUGMSG("unsupported compression method\n");
                    return FILE_FORMAT_ERROR;
                }

            } else if (signature == 0x02014b50) {
                // central directory header
                DEBUGMSG("central directory header\n");

                FileInfo info;
                input->read(buf, 42);

                info.made_version = read16(buf);
                info.required_version = read16(buf+2);
                info.purpose = read16(buf+4);
                info.method = read16(buf+6);
                info.modtime = read16(buf+8);
                info.moddate = read16(buf+10);
                info.crc32 = read32(buf+12);
                info.compressed_size = read32(buf+16);
                info.uncompressed_size = read32(buf+20);
                uint16_t filename_len = read16(buf+24);
                uint16_t extrafield_len = read16(buf+26);
                uint16_t comment_len = read16(buf+28);
                info.start_disk = read16(buf+30);
                info.inter_attr = read16(buf+32);
                info.exter_attr = read32(buf+34);
                info.offset = read32(buf+38);

                input->read(info.filename, filename_len);
                info.filename[filename_len] = '\0';
                input->read(info.extrafield, extrafield_len);
                info.extrafield[extrafield_len] = '\0';
                input->read(info.comment, comment_len);
                info.comment[comment_len] = '\0';

                files_info.push_back(info);

            } else if (signature == 0x06054b50) {
                // end of central directory record
                DEBUGMSG("end of central directory record\n\n");

                input->read(buf, 18);
                zip_info.this_disk = read16(buf);
                zip_info.start_disk = read16(buf+2);
                zip_info.count_entry_total = read16(buf+4);
                zip_info.count_entry_here = read16(buf+6);
                zip_info.dir_size = read32(buf+8);
                zip_info.dir_offset = read32(buf+12);
                uint16_t comment_len = read16(buf+16);

                input->read(zip_info.comment, comment_len);
                zip_info.comment[comment_len] = '\0';

                break;
            } else {
                DEBUGMSG("unsupported signature: %x\n", signature);
                return FILE_CONTENT_ERROR;
            }
        }
        return (input->eof() ? SUCCESS : FILE_UNEXPECTED_CLOSE);
    }
    void list_files() {
        DEBUGMSG("files in zip:\n");
        for (FileInfo info : files_info) {
            tm moddt = dosdatetime(info.moddate, info.modtime);
            DEBUGMSG("file: %s\n", info.filename);
            DEBUGMSG("made_version: %hu\n", info.made_version);
            DEBUGMSG("required_version: %hu\n", info.required_version);
            DEBUGMSG("purpose: %hx\n", info.purpose);
            DEBUGMSG("method: %hx\n", info.method);
            DEBUGMSG("modtime: %u:%u:%u\n", moddt.tm_hour, moddt.tm_min, moddt.tm_sec);
            DEBUGMSG("moddate: %u.%u.%u\n", 1900+moddt.tm_year, 1+moddt.tm_mon, moddt.tm_mday);
            DEBUGMSG("crc32: %x\n", info.crc32);
            DEBUGMSG("compressed size: %u\n", info.compressed_size);
            DEBUGMSG("uncompressed size: %u\n", info.uncompressed_size);
            DEBUGMSG("start_disk: %hx\n", info.start_disk);
            DEBUGMSG("inter_attr: %hx\n", info.inter_attr);
            DEBUGMSG("exter_attr: %x\n", info.exter_attr);
            DEBUGMSG("offset: %u\n", info.offset);
            DEBUGMSG("\n");
        }
    }


private:
    struct FileInfo {
        char filename[MAX_FIELD_LEN],
             extrafield[MAX_FIELD_LEN],
             comment[MAX_FIELD_LEN];
        uint16_t made_version, required_version,
                 purpose, method,
                 modtime, moddate,
                 inter_attr, start_disk;
        uint32_t crc32, compressed_size, uncompressed_size, exter_attr, offset;
    };
    struct ZipInfo {
        char comment[MAX_FIELD_LEN];
        uint16_t this_disk, start_disk,
                 count_entry_total, count_entry_here;
        uint32_t dir_size, dir_offset;
    };

    vector<FileInfo> files_info;
    ZipInfo zip_info;

    istream* input;
    stringstream output;
    char buf[MAX_BUFFER_SIZE];
    // TODO: prevent buffer overflow

    inline struct tm dosdatetime(uint16_t date, uint16_t time) {
        struct tm datetime;
        datetime.tm_mday = date & 0x1f;
        datetime.tm_mon = ((date >> 5) & 0xf) - 1;
        datetime.tm_year = ((date >> 9) & 0x7f) + 80;
        datetime.tm_sec = time & 0x1f;
        datetime.tm_min = (time >> 5) & 0x3f;
        datetime.tm_hour = (time >> 11) & 0x1f;
        return datetime;
    }
    inline uint16_t read16(void* ptr) {
        return *(uint16_t*)ptr;
    }
    inline uint32_t read32(void* ptr) {
        return *(uint32_t*)ptr;
    }
};

char str[10000];
int main() {
    fstream infile("z.zip", ios::in | ios::binary);
    // file size: 470241
    if (infile.is_open()) {
        MyZipEncoder z;
        cout<<"init: "<<z.init(&infile)<<endl;
        z.list_files();
        infile.close();
    }
#ifdef soytw
    system("pause");
#endif
    return 0;
}
