@echo off

set LIB=..\StlPort;%LIB%
set INCLUDE=..\StlPort;%INCLUDE%
set PATH=C:\Program Files (x86)\Microsoft Visual Studio 10.0\Common7\IDE;%PATH%
set PATH=C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\BIN;%PATH%
set LIB=C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\LIB;%LIB%
set LIB=C:\Program Files (x86)\Microsoft SDKs\Windows\v7.0A\Lib;%LIB%
set INCLUDE=C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\include;%INCLUDE%

cl.exe /nologo /MT /W3 /O2 /Gd /D "__SERVER" /Fo"./dllmain.obj" /FD /c "./dllmain.cpp"
cl.exe /nologo /MT /W3 /O2 /Gd /D "__SERVER" /Fo"./factory.obj" /FD /c "./factory.cpp"
cl.exe /nologo /MT /W3 /O2 /Gd /D "__SERVER" /Fo"./refcount.obj" /FD /c "./refcount.cpp"
cl.exe /nologo /MT /W3 /O2 /Gd /D "__SERVER" /Fo"./register.obj" /FD /c "./register.cpp"
cl.exe /nologo /MT /W3 /O2 /Gd /D "__SERVER" /Fo"./tinystr.obj" /FD /c "./tinystr.cpp"
cl.exe /nologo /MT /W3 /O2 /Gd /D "__SERVER" /Fo"./tinyxml.obj" /FD /c "./tinyxml.cpp"
cl.exe /nologo /MT /W3 /O2 /Gd /D "__SERVER" /Fo"./tinyxmlerror.obj" /FD /c "./tinyxmlerror.cpp"
cl.exe /nologo /MT /W3 /O2 /Gd /D "__SERVER" /Fo"./tinyxmlparser.obj" /FD /c "./tinyxmlparser.cpp"

link.exe /nologo /dll /incremental:no /machine:I386 "./dllmain.obj" "./factory.obj" "./refcount.obj" "./register.obj" "./tinystr.obj" "./tinyxml.obj" "./tinyxmlerror.obj" "./tinyxmlparser.obj" /out:"./Xml.dll"
pause