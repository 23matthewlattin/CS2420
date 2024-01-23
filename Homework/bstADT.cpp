
/* This file implements the methods defined in the header file for the 
 * Binary Search Tree template.
 */
 
// -------------  =   Operator ---------------//
template 
const bstADT& bstADT::operator=(const bstADT& sourceTree){
// overload of the assignment operator for a binary search tree
// If the source is the same as destination, do nothing, otherwise
// delete the destination tree and build a dumpilcate of source
	if (this != &sourceTree) { // check to see if assigning to self
		if (!isempty()) // destination is not empty, must delete first
			deleteTree(root);
		if (sourceTree.root == nullptr) // source is empty, make this null
			root = nullptr;
		else
			copyTree(root, nullptr, sourceTree.root);
	} // end of if statement
	
	return *this; // return the tree 
}

// -------------    isempty   ---------------//
template 
bool bstADT::isempty(void){
// returns true for an empty tree
	return root == nullptr;
}


// -------------  search (need < and !=) ---------------//
template 
bool bstADT::search(aType value) {
// method to search for a value, returns true if the value is in the 
// tree
	curNode = root;
	while (curNode != nullptr && value != curNode->value) {
		if (value < curNode->value) {
			curNode = curNode->left;
		} else {
			curNode = curNode->right;  // duplicates in right subtree
		}
	} // end of while loop curNode == nullptr, not found 
	return (curNode != nullptr);
	// curNode points to the node if found and can be used elsewhere
}


// -------------  inOrder print tree ---------------//
template 
void bstADT::inOrder(void) {
// prints the elements of the tree "in-Order", need output stream to
// be defined for aType     i.e.,  cout << aTypeVar   must work
	inOprint(root);
}


// -------------  insert a new node ---------------//
template 
void bstADT::insert(aType value){
// method to insert a value in the list 
	nodeType *x, *y, *z;  // pointers used to manipulate the tree and store value
	
	z = new nodeType; // z contains data for the new node
	z->value = value;
	z->right = z->left = z->parent = nullptr; // initialize pointers for new node
	
	y = nullptr;
	x = root;
	while (x != nullptr) { // look for node with empty child for the new node
		y = x;
		if (z->value < x->value) {
			x = x->left;
		} else {
			x = x->right;
		}
	} // y points to a node which will become the new node's parent
	
	z->parent = y;
	if (y == nullptr) { // The tree is empty
		root = z;  // z is the new root for the empty BST
	} else if (z->value < y->value) { // this will be a left child
		y->left = z;
	} else { // otherwise the right child
		y->right = z;
	}
}


// ---------------  deleteNode from the tree -------------------//
template 
bool bstADT::deleteNode(aType value){
// deletes a value if it exists, returning true if deleted and false 
// if it is not found
	bool result = true; // assume delete is successful
	nodeType *y;  // used as a temporary pointer in the tree
	
	if (result = search(value)) { // node exists and curNode points to it
		if (curNode->left == nullptr) { // no left child
			transplant(curNode, curNode->right);  // curNode was the parent
		} else if (curNode->right == nullptr) { // no right child
			transplant(curNode, curNode->left);
		} else { // need to find the minimum of right subtree to transplant
			y = treeMin(curNode->right); //  y is the next inorder node
			if (y->parent != curNode) { // down the subtree, y can't have left child
				transplant(y, y->right);
				y->right = curNode->right;
				y->right->parent = y;
			}
			transplant(curNode, y);
			y->left = curNode->left;
			y->left->parent = y;
		}
		delete(curNode); // all the pointers are fixed, remove the node
	} 
	return result; // false if not found
}


// ------------  determine the height of the whole tree  --------------//
template 
int bstADT::treeHeight(void) {
// returns the height of the tree
	return nHeight(root);
}


// ------------  Default constructor creates empty tree  -------------//
template 
bstADT::bstADT(void){
// Default constructor sets root of tree to nullptr
	root = nullptr;
}


// ----------  Copy constructor creates duplicate tree  --------------//
template 
bstADT::bstADT(const bstADT& sourceTree){
// Copy constructor is used if the tree is passed as a parameter
// or initialized when declared
	if(sourceTree.root == nullptr) {
		root = nullptr;
	} else {
		copyTree(root, nullptr, sourceTree.root);
	}
}


// ----------  Default destructor deallocates all nodes  --------------//
template 
bstADT::~bstADT(void){
// Default destructor, deletes all nodes in the tree
	deleteTree(root);
	root = nullptr;
}


////////////////////////////////////////////////////////////////////////
//      The following are private utility methods                     //
////////////////////////////////////////////////////////////////////////


// -------  inOprint prints a tree inorder given the root  --------//
template 
void bstADT::inOprint(nodeType *root) {
// this method prints a subtree in inOrder given a pointer to the root
	if (root != nullptr) {
		inOprint(root->left);
		std::cout << root->value << std::endl;
		inOprint(root->right);
	}
}


// -------------  nextInOrder determine the next node  ---------------//
template 
nodeType * bstADT::nextInOrder(nodeType *aNode) {
// function to return a pointer to the next inOrder node, returns nullptr if
// aNode points to the maximum value in the tree
	nodeType *y, *x = aNode; // temporary pointers
	
	if(x->right != nullptr) {
		return treeMin(x->right); // minimum value is in right subtree
	}
	// otherwise, the next in order is an ancestor node
	y = aNode->parent;
	while(y != nullptr && x == y->right) {
		x = y;
		y = y->parent;
	}
	return y;
}

// -------------  Minimum value node in subtree  ---------------//
template 
nodeType * bstADT::treeMin(nodeType *sroot) {
// return a pointer to the minimum valued node in the subtree at sroot
	nodeType *x = sroot;
	 
	while (x->left != nullptr) {
		x = x->left;
	}
	return x;
}

// -------------  Maximum value node in subtree  ---------------//
template 
nodeType * bstADT::treeMax(nodeType *sroot) {
// return a pointer to the maximum valued node in the subtree at sroot
	nodeType *x = sroot;
	
	while (x->right != nullptr) {
		x = x->right;
	}
	return x;
}

// Swaps two nodes, but only fixes pointers for 'v', which replaces 'u'
template 
void bstADT::transplant(nodeType *u, nodeType *v) {
// a utility function to "transplant" nodes in the tree, takes two node
// pointers as an argument and swaps their positions in the tree
// v is replacing u... the pointers for u must be handled by the caller
// this function is used by deleteNode
	if(u->parent == nullptr) { // u is the root, so make v the root
		root = v;
	} else if (u == u->parent->left) { // u is the left child
		u->parent->left = v;
	} else {
		u->parent->right = v;
	}
	if (v != nullptr) { // if v is null, we can't do this
		v->parent = u->parent;
	}
}


// ---------- delete an entire tree given the root pointer  ----------//
template 
nodeType * bstADT::deleteTree(nodeType *tree) {
// Delete the ccontents of an entire tree, should not be used with subtrees
// as it doesn't clean up the pointer from the parent node
	if (tree != nullptr) {
		deleteTree(tree->left);  // delete left subtree
		deleteTree(tree->right); // delete right subtree
		delete tree; // delete this node
	}
	return 	tree;
}


// ---------------- Create a copy of the source tree ---------------- //
template 
void bstADT::copyTree(nodeType* &destTree,  
				nodeType* dTreep, const nodeType* srcTree) {
// makes a copy of the tree, deleting destTree if necessary
	if(srcTree == nullptr) { // nothing to copy
		destTree = nullptr;
	} else {
		destTree = new nodeType;
		destTree->value = srcTree->value;
		destTree->parent = dTreep;
		copyTree(destTree->left, destTree, srcTree->left);
		copyTree(destTree->right, destTree, srcTree->right);
	}
}


// returns a pointer to the matching node, or a null poiner if not there //
template 
nodeType * bstADT::searchTree(nodeType *root, aType theVal) {
// searches using node pointers, returns a pointer to the value if found
	
	if (root != nullptr) {
		if (theVal == root->value) {
			return root;
		} else if (theVal < root->value) {
			return searchTree(root->left, theVal);
		} else if (theVal > root->value) {
			return searchTree(root->right, theVal);
		}
	}
	return nullptr;
}

// ----------- Recursively return the height of any node ------------ //
template 
int bstADT::nHeight(nodeType *aNode)  {
// Determines the height of the subtree with root at aNode
	if(aNode == nullptr) { // Null subtree has height zero
		return 0;
	} else {
		return 1 + max(nHeight(aNode->left), nHeight(aNode->right));
	}
}

// ---------------- Return the maximum of two integers ------------- //
template 
int bstADT::max(int x, int y) {
// return the maximum of two integer values
	if (x > y) 
		return x;
	else
		return y;
}
