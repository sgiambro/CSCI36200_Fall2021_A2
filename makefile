BST: bst.o
	g++ -g bst.o -o BST

bst.o: bst.cpp bst.h
	g++ -c bst.cpp

run: BST
	./BST
