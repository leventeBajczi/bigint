bigint: src/*.c 
		gcc src/test.c src/init.c src/*.h -o bigint
		./bigint
gdb:	src/*.c 
		gcc src/test.c src/init.c src/*.h -g -o bigint
		gdb bigint