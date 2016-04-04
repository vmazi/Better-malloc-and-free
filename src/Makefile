all: test0 test1 test2 test3 test4

test0: test0.c libmem.a
	gcc -o test0 test0.c libmem.a -Wall -Werror

test1: test1.c libmem.a
	gcc -o test1 test1.c libmem.a -Wall -Werror

test2: test2.c libmem.a
	gcc -o test2 test2.c libmem.a -Wall -Werror

test3: test3.c libmem.a
	gcc -o test3 test3.c libmem.a -Wall -Werror

test4: test4.c libmem.a
	gcc -o test4 test4.c libmem.a -Wall -Werror

libmem.a: mymalloc.o
	ar r libmem.a mymalloc.o

mymalloc.o: mymalloc.c mymalloc.h
	gcc -c mymalloc.c mymalloc.h -Wall -Werror

clean:
	rm -f test0 test1 test2 test3 test4 Makefile~ mymalloc.c~ mymalloc.h~ mymalloc.h.gch