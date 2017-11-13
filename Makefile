bigint: src/*.*
		gcc -c src/operations.s -o op.o
		gcc src/test.c src/init.c src/compl.c op.o src/*.h -o bigint
		./bigint
gdb:	src/*.c 
		gcc -c src/operations.s -o op.o
		gcc src/test.c src/init.c src/compl.c op.o src/*.h -g -o bigint
		gdb bigint