#include <bits/stdc++.h>
#define FOR(i,end) for (int i=0; i<end; ++i)
#define FOR1(i,end) for (int i=1; i<=end; ++i)
#define DEBUGMSG(format, ...) printf(format, ##__VA_ARGS__); fflush(stdout)
using namespace std;

#define FILE_FORMAT_ERROR 66


typedef unsigned char byte;
struct Block {
    size_t offset, length;
    byte next;
    Block() {}
    Block(size_t offset, size_t length, byte next):
        offset(offset),
        length(length),
        next(next) {}
};

class MyZipEncoder {
public:
    static constexpr size_t MAX_BUFFER_SIZE = 65535;
    static constexpr size_t MAX_FIELD_LEN = 65535;
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
    int decode(char* src) {}
    int read_header(istream& input) {
        while (input.good()) {
            input.read((char*)buffer, 4);
            signature = *(uint32_t*)(buffer);
            if (signature == 0x04034b50) {
                // -- LOCAL FILE HEADER --
                input.read((char*)buffer+4, 26);
                extract_version = *(uint16_t*)(buffer+4);
                purpose = *(uint16_t*)(buffer+6);
                method = *(uint16_t*)(buffer+8);
                modtime = *(uint16_t*)(buffer+10);
                moddate = *(uint16_t*)(buffer+12);
                crc32 = *(uint32_t*)(buffer+14);
                compressed_size = *(uint32_t*)(buffer+18);
                uncompressed_size = *(uint32_t*)(buffer+22);
                filename_len = *(uint16_t*)(buffer+26);
                extrafield_len = *(uint16_t*)(buffer+28);

                input.read(filename, filename_len);
                filename[filename_len] = '\0';
                input.read(extrafield, extrafield_len);
                extrafield[extrafield_len] = '\0';

                DEBUGMSG("file: %s\n", filename);
                DEBUGMSG("size: %d\n", uncompressed_size);
                DEBUGMSG("compressed size: %d\n", compressed_size);
                DEBUGMSG("\n");
                // -- END LOCAL FILE HEADER --

                // [TODO] ENCRYPTION FILE HEADER

                // -- FILE DATA --
                input.read((char*)buffer, compressed_size);
                decode(buffer);
                // -- END FILE DATA --

                // [TODO] DATA DESCRIPTOR
            } else if (signature == 0x08064b50) {
                // ARCHIVE EXTRA DATA RECORD
                input.read((char*)(buffer+4), 4);
                extrafield_len = *(uint32_t*)(buffer+4);
                input.read(extrafield, extrafield_len);
                extrafield[extrafield_len] = '\0';
                DEBUGMSG("archive extrafield: %s\n", extrafield);
                // END ARCHIVE EXTRA DATA RECORD
            } else if (signature == 0x02014b50) {
                // CENTRAL DIRECTORY STRUCTURE
                input.read(buffer+4, 46);
                made_version = *(uint16_t*)(buffer+4);
                extract_version = *(uint16_t*)(buffer+6);
                purpose = *(uint16_t*)(buffer+8);
                method = *(uint16_t*)(buffer+10);
                modtime = *(uint16_t*)(buffer+12);
                moddate = *(uint16_t*)(buffer+14);
                crc32 = *(uint32_t*)(buffer+16);
                compressed_size = *(uint32_t*)(buffer+20);
                uncompressed_size = *(uint32_t*)(buffer+24);
                filename_len = *(uint16_t*)(buffer+28);
                extrafield_len = *(uint16_t*)(buffer+30);
                comment_len = *(uint16_t*)(buffer+32);
                disknum = *(uint16_t*)(buffer+34);
                inter_attr = *(uint16_t*)(buffer+36);
                exter_attr = *(uint32_t*)(buffer+38);
                offset = *(uint32_t*)(buffer+42);

                input.read(filename, filename_len);
                filename[filename_len] = '\0';
                input.read(extrafield, extrafield_len);
                extrafield[extrafield_len] = '\0';
                input.read(comment, comment_len);
                comment[comment_len] = '\0';

                DEBUGMSG("[DIR] filename: %s\n", filename);
                DEBUGMSG("extrafield: %s\n", extrafield);
                DEBUGMSG("comment: %s\n", comment);
                DEBUGMSG("\n");
                // END CENTRAL DIRECTORY STRUCTURE
            } else if (signature == 0x05054b50) {
                // DIGITAL SIGNATURE
                input.read(buffer+4, 2);
                uint16_t datasize = *(uint16_t*)(buffer+4);
                input.read(buffer, datasize);
                DEBUGMSG("digital sign: %.*s\n", datasize, buffer);
                // END DIGITAL SIGNATURE
            }
        }
        return 0;
    }
private:
    char buffer[MAX_BUFFER_SIZE],
         filename[MAX_FIELD_LEN],
         extrafield[MAX_FIELD_LEN],
         comment[MAX_FIELD_LEN];
    // TODO: prevent buffer overflow
    uint32_t signature, crc32, compressed_size, uncompressed_size, exter_attr, offset;
    uint16_t extract_version, made_version,
             purpose, method, modtime, moddate,
             filename_len, extrafield_len, comment_len,
             disknum, inter_attr;
};

char str[10000];
int main() {
    fstream infile("abccc.zip", ios::in | ios::binary);
    if (infile.is_open()) {
        MyZipEncoder z;
        int result = z.read_header(infile);
        cout<<result<<endl;
        infile.close();
    }
    // encode((byte*)str, 14, 9);
#ifdef soytw
    system("pause");
#endif
    return 0;
}
