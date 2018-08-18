@echo off

@: Environment
@set PATH=C:\Program Files (x86)\Microsoft Visual Studio 10.0\Common7\IDE;%PATH%
@set PATH=C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\BIN;%PATH%
@set LIB=C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\LIB;%LIB%
@set LIB=C:\Program Files (x86)\Microsoft SDKs\Windows\v7.0A\Lib;%LIB%
@set LIB=.\StlPort;%LIB%
@set LIB=.\mariadb_client\win32\lib;%LIB%
@set INCLUDE=C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\include;%INCLUDE%
@set INCLUDE=.\StlPort;%INCLUDE%
@set INCLUDE=.\mariadb_client\win32\mariadbclient\include;%INCLUDE%
@set INCLUDE=C:\Program Files (x86)\Microsoft SDKs\Windows\v7.0A\Include;%INCLUDE%



@: Server
@del "./MySqlConnect.dll"
cl.exe /nologo /MT /W3 /O2 /Gd /D "__SERVER" /Fo"./MySqlConnect.obj" /FD /c "./MySqlConnect.cpp"
link.exe /nologo /dll /incremental:no /machine:I386 "./MySqlConnect.obj" /out:"./MySqlConnect.dll"


@: Delete unnecessary stuff
@del "./MySqlConnect.obj"
@del "./MySqlConnect.exp"
@del "./MySqlConnect.lib"
@del "./vc100.idb"

@pause