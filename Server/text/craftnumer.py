#!/usr/bin/python 
# -*- coding: utf-8 -*-
# craftnumer.py
# by Galachad
version='v0.0.1'
print version
from os import *
import io
import re
filename = 'FOCRAFT.MSG'
numer =1
zapis = ['']
print filename
try:
    file = io.open('./engl/'+filename)
    text = file.readlines()
finally:
    file.close()
for s in text:
    temptext=s.split('{}')
    if len(temptext)>=1: 
        newtext=temptext[0]
        if newtext[0]=='{' and newtext[len(newtext)-1]=='}':
            if newtext[1:len(newtext)-1].isnumeric():
                newtext=newtext.replace(newtext[1:(len(newtext)-1)], str(numer))               
                numer+=1
                temptext[0]=newtext
                temptext="{}".join(temptext)
                print temptext
                zapis.append(temptext)

zapis=''.join(zapis[1:len(zapis)])        
cel = io.open('./engl/'+filename, 'w+')
cel.write(zapis)
cel.close
print 'done'