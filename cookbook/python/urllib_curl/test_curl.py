#!/usr/bin/env python

import os

cmd = "curl -s 'http://www.guiainvest.com.br/raiox/abcb4.aspx' > abcb4.aspx" 
os.system(cmd)

f = open('abcb4.aspx', encoding='iso-8859-1')
stockfile = f.read()
print(stockfile)
