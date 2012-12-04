#!/usr/bin/env python

import os

path = os.path.join('mkdir_REMOVEME', 'foo', 'bar')

try:
    os.makedirs(path)
except OSError:
    print("can't make dir")
