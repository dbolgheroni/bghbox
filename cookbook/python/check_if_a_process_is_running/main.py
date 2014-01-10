#!/usr/local/bin/python2.7

import re
import subprocess

# Python 2.x
ps_output = subprocess.Popen(["ps", "ax"], stdout=subprocess.PIPE).communicate()[0]
ps = ps_output.split("\n")

regex = "foo"
#regex = "om_(model|project|test)"
pattern = re.compile(regex)

psfound = False
for p in ps:
    #print(p)
    match = pattern.search(p)

    if match:
        psfound = True
        pid = p.split()[0]
        command = p.split()[4]
        print pid.ljust(6), command
        #print("process found")
        #print "job running", match.group('ticket')

if not psfound:
    print "no instances found"
