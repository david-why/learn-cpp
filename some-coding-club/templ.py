#!/usr/bin/env python3
import argparse
import io
import os
import re

TEMPLATE = '''#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{


    return 0;
}
'''

use_urls = False
try:
    from urllib.parse import urlparse

    import requests
    from bs4 import BeautifulSoup

    use_urls = True
except ImportError as e:
    import warnings

    warnings.warn(
        ImportWarning(
            'One or more of urllib.parse.urlparse, bs4, or requests'
            'are not found. URL support will be disabled.'
        ),
        source=e,
    )

ap = argparse.ArgumentParser(description='generate coding template')
ap.add_argument(
    'file',
    help='code file to write to',
)
ap.add_argument(
    'url',
    nargs='?',
    default='',
    help='optional url of the problem',
)
ap.add_argument(
    '-t',
    '--template',
    default=io.StringIO(TEMPLATE),
    type=argparse.FileType('r'),
    required=False,
    help='template to use, leave blank to use default template',
    dest='templ',
)
args = ap.parse_args()
url = args.url
name = args.file
templ = args.templ.read()

get_soup = lambda r: BeautifulSoup(r.content, 'html.parser')

USER_AGENT = (
    'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 '
    '(KHTML, like Gecko) Chrome/97.0.4692.99 Safari/537.36'
)

with open(name, 'w') as f:
    cases = []
    title = None
    if use_urls:
        up = urlparse(url)
        netloc = up.netloc
        path = up.path
        if netloc.endswith('codeforces.com'):
            m = re.match(r'/contest/([0-9]+)/problem/([A-Za-z0-9]+)/?', path)
            n = re.match(r'/problemset/problem/([A-Za-z0-9]+)/(.)/?', path)
            if m or n:
                contid, task = m and m.groups() or n.groups()
                r = requests.get(url)
                if 'Redirecting...' in r.text:
                    try:
                        from Crypto.Cipher import AES
                    except ModuleNotFoundError as e:
                        raise ImportError('Did you install PyCrypto?') from e

                    def toNumbers(s):
                        b = []
                        for i in range(0, len(s), 2):
                            b.append(int(s[i : i + 2], 16))
                        return bytes(b)

                    a = r.text.index('a=toNumbers')
                    a = r.text[r.text.index('"', a) + 1 :]
                    a = toNumbers(a[: a.index('"')])
                    b = r.text.index('b=toNumbers')
                    b = r.text[r.text.index('"', b) + 1 :]
                    b = toNumbers(b[: b.index('"')])
                    c = r.text.index('c=toNumbers')
                    c = r.text[r.text.index('"', c) + 1 :]
                    c = toNumbers(c[: c.index('"')])
                    cr = AES.new(a, mode=AES.MODE_CBC, IV=b)
                    r = requests.get(url, cookies={'RCPC': cr.decrypt(c).hex()})
                s = get_soup(r)
                ps = s.select_one('.problem-statement')
                title = 'Codeforces Contest #%s %s' % (
                    contid,
                    ps.select_one('.title').text,
                )
                ex = ps.select_one('.sample-test')
                it = iter(ex.children)
                for i in range(0, len(ex), 2):
                    cases.append(
                        (
                            next(it).select_one('pre').get_text('\n').strip(),
                            next(it).select_one('pre').get_text('\n').strip(),
                        )
                    )
        elif netloc.endswith('luogu.com.cn'):
            m = re.match(r'/problem/([0-9A-Z]+)', path)
            if m:
                r = requests.get(
                    url,
                    params={'_contentOnly': '1'},
                    headers={'User-Agent': USER_AGENT},
                )
                j = r.json()
                title = 'Luogu %s %s' % (
                    m.groups()[0],
                    j['currentData']['problem']['title'],
                )
                cases = j['currentData']['problem']['samples']
        elif netloc.endswith('atcoder.jp'):
            m = re.match(
                r'/contests/([a-zA-Z]*[0-9]*)/tasks/[a-zA-Z]*[0-9]*_([a-z])/?',
                path,
            )
            if m:
                r = requests.get(url)
                s = get_soup(r)
                title = 'AtCoder %s %s %s' % (
                    m.groups()[0].upper(),
                    m.groups()[1].upper(),
                    s.select_one('title').text.rpartition(' - ')[-1],
                )
                parts = s.select('.lang-en .part section')
                for i, p in enumerate(parts):
                    if 'Sample Input' in p.text:
                        break
                for i in range(i, len(parts), 2):
                    if 'Sample Input' not in parts[i].text:
                        break
                    cases.append(
                        (
                            parts[i]
                            .select_one('pre')
                            .text.replace('\r\n', '\n')
                            .strip(),
                            parts[i + 1]
                            .select_one('pre')
                            .text.replace('\r\n', '\n')
                            .strip(),
                        )
                    )
    f.write('// ')
    f.write(url)
    f.write('\n')
    if title:
        f.write('// ')
        f.write(title)
        f.write('\n')
    f.write(templ)
if cases:
    with open(name + '.sh', 'w') as f:
        f.write(
            '''#!/bin/bash
g++ -Wall -Wextra "%s" -o "%s.out" || exit $?
ac=1
'''
            % (name, name)
        )
        for i, (ipt, opt) in enumerate(cases):
            f.write(
                '''echo 'Running testcase %(i)i'
v="$(time -p ./%(n)s.out << CASE%(i)i
%(ipt)s
CASE%(i)i
)"
if [ "$v" = "%(opt)s" ]; then echo "Passed"; else echo "Failed"; ac=0; fi
'''
                % {'i': i + 1, 'ipt': ipt, 'opt': opt, 'n': name}
            )
        f.write('if [ "$ac" = "1" ]; then echo "AC"; else echo "WA"; fi\n')
    os.chmod(name + '.sh', 0o755)
