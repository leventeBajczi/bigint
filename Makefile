bigint: src/*.*
		gcc -c src/operations.s -o src/op.o
		gcc src/*.c src/*.h src/*.o -o bigint
		./bigint
gdb:	src/*.c 
		gcc -c src/operations.s -o src/op.o -g
		gcc src/*.c src/*.h src/*.o -o bigint -g
		gdb bigint