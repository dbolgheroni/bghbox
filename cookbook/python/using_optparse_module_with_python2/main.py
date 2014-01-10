#!/usr/local/bin/python2.7
# 
# option, flag, switch
# argument
# parameter

from optparse import OptionParser

opts = OptionParser()

# option/flag/switch
opts.add_option("-x", "--xxx",
                default=False,
                action="store_true",
                help="x option/flag/switch")
# option with argument
opts.add_option("-y", "--yyy", # argument is stored in options.yyy
                #action="store", # doesn't need, defaults to "store"
                help="y option with argument")
(options, args) = opts.parse_args()

print options
print args

print options.xxx
print options.yyy

# check for arguments
if not args:
    print "no args"
