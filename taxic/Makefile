CC=cc
CCFLAGS=-ansi -march=native

all:
	$(CC) $(CCFLAGS) -c src/codegen.c -Isrc/ -o libcodegen.o
	$(CC) $(CCFLAGS) -shared libcodegen.o -Isrc/ -o libcodegen.so
	@rm -f libcodegen.o
	@rm -rf bin
	@mkdir bin
	$(CC) $(CCFLAGS) src/taxi.c deps/mpc/mpc.c -L. -lcodegen -Ideps/ -Isrc/ -o bin/taxi
	

debug: clean all
	valgrind ./bin/taxi

install:
	cp bin/taxi /usr/bin/
	cp libcodegen.so /usr/lib/
	cp src/codegen.h /usr/include/

clean:
	rm -f libcodegen.so
	rm -f bin/taxi