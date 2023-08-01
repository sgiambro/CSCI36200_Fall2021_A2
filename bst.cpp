//bts.cpp

#include <iostream>
#include <sstream>
#include "bst.h"

using namespace std;

	
	//constructor
	Bst::Bst(int num){
		
		BstNode* node = new BstNode;
		node->value = num;
		node->left = NULL;
		node->right = NULL;
		
		root = node;
	}
	
	//inserts a new node
	BstNode* Bst::add(BstNode* node, int number){
		
		//creates a new node if none exist
		if(node == NULL){
			node = new BstNode;
			node->value = number;
			node->left = NULL;
			node->right = NULL;
			node->up = NULL;
		}
		
		//checks the right child node
		else if(node->value < number){
			node->right = add(node->right , number);
			node->right->up = node;
		}
		
		//checks the left child node
		else if(node->value > number){
			node->left = add(node->left , number);
			node->left->up = node;
		}
		
		//returns the current node for recursion
		return node;
		
	}
	
	//prints the BST
	void Bst::showBst(BstNode* node){
		
		if(node == NULL){
			return;
		}
		
		showBst(node->left);
		cout << node->value << " | ";
		showBst(node->right);
		
	}
	
	
	//finds the k smallest node's value
	int Bst::kSmallest(BstNode* node, int k){
		
		
		if(node->value == k){
			return node->value;
		}
		
		else if(node->value < k){
			return kSmallest(node->right , k );
		}
		
		else if(node->value > k){
			return kSmallest(node->left , k );
		}
		
		else if(node == NULL){
			return 999;
		}
		
		
	}
		


int main(){
	
	string strk = " ";
	int k = 0;
	
	//create array
	int number1[] = {6 , 17 , 20 , 41 , 45 , 52 , 57 , 65 , 71 , 76 , 79 , 87 , 92 , 95 , 99};
	int number2[] = {65 , 41 , 87 , 17 , 52 , 6 , 20 , 45 , 57 , 76 , 95 , 71 , 79 , 92 , 99};
	
	//create the tree and set the root 
	Bst* bst = new Bst(number2[0]);
	
	//add all numbers from array to the bst
	for(int i=1; i<15; i++){
		bst->add(bst->root , number2[i]);
	}
	
	//print the bst
	bst->showBst(bst->root);
	
	
	cout << endl;
		
		
	//gets the user input for K
	while(k < 1 || k > 15){
	
		cout << "Enter k for the k smallest node:  ";
		getline(cin , strk);
		
		stringstream ss;
		ss << strk;
		ss >> k;
		
		if (k < 1  ||  k > 15 ){
			cout << "ERROR! Number has to be 1 through 15. " << endl;
		}
	
	}
	
	//find k smallest value
	cout << bst->kSmallest(bst->root, number1[k-1]) << endl;
	
}