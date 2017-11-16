bigint: src/
		gcc -Wall src/*.* src/*/*.* src/*/*/*.* -c
		gcc *.o -o build/bigint
		find . -type f -name '*.gch' -exec rm {} +
		rm *.o
		./bigint
gdb:	src/*.c 
		gcc -c src/base_arithmetic/asm/amd64.s -o build/amd64.o -g
		gcc -Wall src/*.* src/*/*.* src/*/*/*.h build/amd64.o -o build/bigint -g
		gdb build/bigint