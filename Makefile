bigint: src/*.s 
		gcc src/*.s -c
		ld *.o -o bigint
		rm *.o
		./bigint
gdb: src/*.s 
		gcc src/*.s -c -g
		ld *.o -o bigint -g
		rm *.o
		gdb bigint
