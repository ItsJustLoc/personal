CC=gcc

final:	main.o functions_iterative.o functions_recursive.o
	$(CC) main.o functions_iterative.o functions_recursive.o -o final

main.o:	main.o
	$(CC) -c main.c

functions_iterative.o:	functions_iterative.o
	$(CC) -c functions_iterative.c

functions_recursive.o:	functions_recursive.o
	$(CC) -c functions_recursive.c

clean:
	rm *.o final