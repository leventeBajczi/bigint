bigint: src/*.*
		gcc -c src/operations.s -o src/op.o
		gcc src/*.c src/*.h src/op.o -o bigint
		rm -f src/op.o
		./bigint
gdb:	src/*.c 
		gcc -c src/operations.s -o src/op.o -g
		gcc src/*.c src/*.h src/op.o -o bigint -g
		rm -f src/op.o
		gdb bigint