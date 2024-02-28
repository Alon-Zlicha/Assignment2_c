all:libmy_mat.a my_graph

main.o: main.c my_mat.h
	gcc -c -Wall main.c

my_mat.o: my_mat.c my_mat.h
	gcc -c -Wall my_mat.c

libmy_mat.a: my_mat.o 
	$ ar -rc libmy_mat.a my_mat.o

my_graph: main.o libmy_mat.a
	gcc -Wall main.o -lmy_mat -L. -o my_graph

clean: 
	rm -f main.o my_mat.o libmy_mat.a my_graph

.PHONY: clean all