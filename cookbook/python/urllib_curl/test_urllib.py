#!/usr/bin/env python

import urllib.request

f = urllib.request.urlopen("http://www.guiainvest.com.br/raiox/abcb4.aspx")
stockfile = f.read().decode('iso-8859-1')

print(stockfile)
