#!/usr/bin/python 
# -*- coding: utf-8 -*-
# simplelangtool.py
# by Galachad
version='v0.1.2'
print version
from os import *
import io
import re
listaplikow = listdir('./engl')
listaplikowF2 = listdir('../../Text/english/game')
for filename in listaplikow:
    print filename
    totranslate = ['']
    try:
        file = io.open('./engl/'+filename)
        text = file.readlines()
    finally:
        file.close()
    for s in text:
        temptext=s.split('{}')
        if len(temptext)>=1: 
            newtext=temptext[len(temptext)-1]
            if newtext[0]=='{' and newtext[0:1]!='{}':
                totranslate.append(newtext)
    for s in totranslate:
        for F2filename in listaplikowF2:
            try:
                file = io.open('../../Text/english/game/'+F2filename)
                text = file.readlines()
            finally:
                file.close()
            for line in text:
                if line[0]=='{': 
                    if line.find(s)!=-1: 
                        linetochenge=line.split('{}')
                        linetochenge.append(F2filename)
                        break
        if len(linetochenge)>0 :
            try:
                file = io.open('../../Text/german/game/'+linetochenge[2]) #scieїka do plikуw tekstowych
                text = file.readlines()
            finally:
                file.close()
            for line in text:
                if line[0]=='{':
                    if line.find(linetochenge[0])!=-1:
                        linetochenge.append(line.split('{}')[1])
                        break
        if len(linetochenge)<4: break
        file = io.open('./engl/'+filename)
        text = file.read()
        file.close()
        cel = io.open('./engl/'+filename, 'w+')
        cel.write(text.replace(linetochenge[1], linetochenge[3]))
        cel.close
    print 'done'