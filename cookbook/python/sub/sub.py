#!/usr/bin/env python

import re

def extract_pe():
    f = open("abcb4.aspx", encoding='iso-8859-1')

    pattern = re.compile(r'lbPrecoLucroAtual">(?P<pe>(\d)+,(\d)+)')

    s = f.read()
    match = pattern.search(s)
    if match:
        r = match.group('pe')
        pe = float(re.sub(r',', r'.', r))
        return pe

print (extract_pe())
