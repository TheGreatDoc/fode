Running FOnlineServer on debian with libc < 2.15
================================================
 
NOTE: step 1 *MUST* be repeated after every SDK update
 
 
1. Hexedit FOnlineServer and copy to Server/, (see http://stackoverflow.com/a/15182339)
 
2. Compile fdelt_chk.so and copy to Server/libs/ (see Makefile)
 
3. Start server: LD_PRELOAD=./libs/fdelt_chk.so ./FOnlineServer
 
4. ???
 
5. Profit
