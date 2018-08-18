# versioning probably not needed, but let it be

../libs/fdelt_chk.so: fdelt_chk.c fdelt_chk.versions
	gcc -m32 -c -fPIC fdelt_chk.c -o fdelt_chk.o
	gcc -m32 -shared -nostartfiles -Wl,-s -Wl,--version-script fdelt_chk.versions -o $@ fdelt_chk.o
