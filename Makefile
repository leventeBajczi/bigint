bigint: src/*
		gcc -c src/base_arithmetic/asm/amd64.s -o build/amd64.o
		gcc -Wall src/*.* src/*/*.* src/*/*/*.h build/amd64.o -o build/bigint -lgmp
		build/bigint
gdb:	src/
		gcc -c src/base_arithmetic/asm/amd64.s -o build/amd64.o -g
		gcc -Wall src/*.* src/*/*.* src/*/*/*.h build/amd64.o -o build/bigint -g -lgmp
		gdb build/bigint
