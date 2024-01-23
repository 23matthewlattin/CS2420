/*this program implements the functions for a binary search tree
 * the set of inegreres
 *  batree.h
 * */
 
 #include <iostream> 
 #incude "bsTree.h"
bool isEmpty(){
	return count == 0;
}

bool search(int value){
//returns true if integer found in tree
	node *tmp = root;
	//make sure we dont check null nodes
	while(tmp != NULL && tmp->value != value){
		if (tmp->value <= value) {
			tmp = tmp->right;
		}
		else {
			tmp = tmp->left;
		}
	}//tmp points to value or is null
	return (tmp != NULL);
}

void insertInt(int value){
//inserts the interger value in the tree
	node * tmp = root;
	node * newNode;
	int heightCount =0; //used to compute new node height and compare to
						//existing tree

	//search until left or right pointer is null, put value there
	newNode = new node; 
	newNode->parent = newNode->left = newNode->right = NULL; //make all pointers null
	newNode->value = value;
	
	//search for where to put the new value
	if (root == NULL) {
		root = newNode;
	}else{
		while(tmp != NULL){
			heightCount++;
			if (tmp-value <= value) { //search right subtree
				if (tmp->right != NULL){ //there is a right subtree
					tmp = tmp->right; //continue down the tree
				}else { //newNode becomes the right subtree
					tmp->right = newNode; //set parent to point to noce
					newNode->parent = tmp; //set node to point to parent
					tmp = NULL; //exit while loop after insertion
					}
			}else {//search the left subtree
				if (tmp->left != NULL) { //there is a left subtree
					tmp = tmp->left; //continue down the left subtree
					} else { //newNode becomes the left subtree
						tmp->left = newNode;
						newNode->parent = tmp;
						tmp = NULL; //exit the loop
						}
				}
		}
	}
	count++;
	height = (height >= heightCount) ? height : heightCount; //conditional 
	//to put larger value in height
}

void deleteInt(int) {
//delete a node from tree if it exists
	node * tmp;
	}

int treeHeight()
//returns the height of tree (max patch from root to leaf)
{
	return height;
}


int numNodes(){ 
//returns number of nodes in the tree
	return count;
}

bsTree();
//default construcotr of type

~baTree();
//destructor we dont want to have allcated memory that is unaccessible
	
	
