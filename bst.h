//bst.h

#ifndef BST_H_EXISTS
#define BST_H_EXISTS

#include <iostream>
#include <string>

class BstNode {
	
	public:
		int value;
		BstNode* left;
		BstNode* right; 
		BstNode* up;
		
	
};

class Bst {
	
		
	public:
		BstNode* root;
	
		Bst(int num);
		BstNode* add(BstNode* node, int number);
		void showBst(BstNode* node);
		int kSmallest(BstNode* node, int k );
		
	
};


#endif
