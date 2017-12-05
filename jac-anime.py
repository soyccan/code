from urllib.request import urlopen, Request
from urllib.error import URLError
from http.cookiejar import CookieJar
import re, os.path, time, sys, math, shutil

def human_size(size, decimals = 2):
    if size <= 0:
        return '0'
    unit = ('Bytes', 'KiB', 'MiB', 'GiB', 'TiB', 'PiB', 'EiB', 'ZiB', 'YiB')
    factor = int(math.log2(size) // 10)
    if factor > 8:
        factor = 8
    return "{0:.{2}f}{1}".format(size / (1 << (10 * factor)), unit[factor], decimals)

def try_other_filename(filename):
    base, ext = os.path.splitext(filename)
    for i in range(1, sys.maxsize):
        newname = base + ' ' + str(i) + ext
        if not os.path.exists(newname):
            return newname

def get_jac_video(index_page):
    # return list of (video id, filename) pairs
    res = []
    try:
        print('Connecting', index_page)
        html = urlopen(index_page, timeout=30).read()
    except URLError:
        sys.stderr.write('Error when connecting!')
        return res

    for i, match in enumerate(re.finditer(br'https://(drive|docs)\.google\.com/file/d/([^/]+)', html)):
        res.append((
            match.group(2).decode(),
            '{:02}.mp4'.format(i+1) ))
    return res

def dl_jac_video(url_filename_list):
    total_start_tm = time.clock()
    total_sz = 0

    for videoid, filename in url_filename_list:
        if os.path.exists(filename):
            print('Ignoring exisiting file "{}"'.format(filename))
            # filename = try_other_filename(filename)
            # print('changing filename to "{}"'.format(filename))
            continue

        ck = CookieJar()
        rq = Request("https://drive.google.com/uc?export=download&id=" + videoid)
        try:
            rp = urlopen(rq, timeout=10)
        except URLError:
            sys.stderr.write('[ERROR] when connecting: ID "{}" / file "{}"\n'.format(videoid, filename))
            continue

        ck.extract_cookies(rp, rq)

        try:
            dllink = re.search(
                rb'uc-download-link[^>]*href="([^>"]*)"',
                rp.read()).group(1).decode().replace('&amp;', '&')
        except:
            sys.stderr.write('[ERROR] while downloading: ID "{}" / file "{}"\n'.format(videoid, filename))
            continue

        rq1 = Request('https://drive.google.com' + dllink)
        ck.add_cookie_header(rq1)
        with urlopen(rq1) as rp1, \
              open(filename, 'wb') as f1:
            print('Downloading video ID "{}" to file "{}"'.format(videoid, filename))
            if rp1.getheader('Content-Type') not in ('video/mp4', 'video/x-matroska'):
                sys.stderr.write('Error on file "{}"\n'.format(filename))
                continue

            blksz = 1024 * 1024 * 16
            dlsz = 0
            # totalsz = rp1.getheader('Content-Length')
            tm = time.clock()
            while not rp1.closed:
                chunk = rp1.read(blksz)
                if len(chunk) == 0: break
                dlsz += len(chunk)
                sys.stdout.write('\r' + ' ' * (shutil.get_terminal_size()[0]-2))
                sys.stdout.write('\rDownloaded {}% at {}/s'.format('?',
                    human_size(dlsz / (time.clock() - tm))))
                f1.write(chunk)
                time.sleep(0.05)

            total_sz += dlsz
            sys.stdout.write(
                '\nSpent: {:.2f}s\nSize: {}\n\n'.format(
                    time.clock() - tm,
                    human_size(dlsz)))

    total_spend = time.clock() - total_start_tm
    sys.stdout.write(
        '\n\nTotal Spent: {:.2f}\n'
        'Total Size: {}\n'
        'Average Download Speed: {}/s\n'.format(
        total_spend, human_size(total_sz), human_size(total_sz / total_spend)))

print('Jac Animation Downloader')
if len(sys.argv) >= 3 and sys.argv[1] == '-u':
    l = get_jac_video(sys.argv[2])
    dl_jac_video(l)
elif len(sys.argv) >= 3 and sys.argv[1] == '-f':
    l = []
    for line in open(sys.argv[2]):
        (videoid, filename) = line.split()
        l.append((videoid, filename))
    dl_jac_video(l)
else:
    print('Usage: {} [-f file containing urls and filenames] [-u index page]'.format(sys.argv[0]))


# dl_jac_video([('0B1H-WTo5XmcrdDlPYm1YSXZMMTQ', 'xx.mp4')])
# https://www.googleapis.com/drive/v3/files/0B62NacqK6vZnRVMtSDFLbkVEUGs
