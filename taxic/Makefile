CC=tcc
CCFLAGS=-Os -s -g

all:
	$(CC) $(CCFLAGS) -c src/codegen.c -Isrc/ -o libcodegen.o
	ar rcs libcodegen.a libcodegen.o
	@rm -rf bin
	@mkdir bin
	$(CC) $(CCFLAGS) src/taxi.c deps/mpc/mpc.c libcodegen.a -Ideps/ -Isrc/ -o bin/taxi
	

debug: clean all
	gdb ./bin/taxi

install:
	cp bin/taxi /usr/bin/
	cp libcodegen.so /usr/lib/
	cp src/codegen.h /usr/include/

clean:
	rm -f libcodegen.so
	rm -f bin/taxi