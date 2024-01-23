/*this program implements the functions for a binary search tree
 * the set of inegreres
 *  batree.h
 * */
 
class bsTree {
 
 public:
	bool isEmpty();
	
	bool search(int);
	//returns true if integer found in tree
	
	void insertInt(int);
	
	void deleteInt(int);
	
	int treeHeight();
	//returns the height of tree (max patch from root to leaf)
	
	int numNodes();
	//returns number of nodes in the tree
	
	bsTree();
	//default construcotr of type
	
	~baTree();
	//destructor we dont want to have allcated memory that is unaccessible
	
	
private:
	typedef struct node_T {
		int value;
		struct node_T *parent, *left, *right;
	} node;
	
	node *root; //root of tree
	int height; //the tree's height
	int count; //number of nodes in tree
	
	
 
 
 };

