CC?=gcc
CCFLAGS=-Os -s -g

all:
	$(CC) $(CCFLAGS) -c src/codegen.c -Isrc/ -o libtxcodegen.o
	$(CC) $(CCFLAGS) -fPIC -c src/parser.c -Ideps/ -Isrc/ -o libtxparser.o
	$(CC) $(CCFLAGS) -fPIC -c deps/mpc/mpc.c -Ideps/mpc/ -Isrc/ -o libtxmpc.o
	$(CC) $(CCFLAGS) -c src/taxi.c -L. -ltxparser -ltxcodegen -Ideps/ -Isrc/ -o taxi.o
	$(CC) $(CCFLAGS) taxi.o libtxparser.o libtxcodegen.o libtxmpc.o -Ideps/ -Isrc/ -o taxi
	@rm -f *.o
	

debug: clean all
	gdb ./bin/taxi

install:
	cp bin/taxi /usr/bin/

clean:
	rm -f libcodegen.a
	rm -f bin/taxi