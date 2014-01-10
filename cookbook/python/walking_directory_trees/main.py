#!/usr/local/bin/python2.7

import os
import re

for f in os.walk('.'):
    files = f[2]

regex = "model_req\.(?P<ticket>[a-zA-Z0-9]{6})"
for f in files:
    pattern = re.compile(regex)
    match = pattern.search(f)

    if match:
        #print "found"
        print "job running", match.group('ticket')
