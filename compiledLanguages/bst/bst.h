// itemType can be defined through either typedef or Template
typedef char itemType;
struct TreeNode
{
	itemType info;
	TreeNode* left;
	TreeNode* right;
};

class BST {
	private:
		TreeNode * root;

	public:
		BST();
		~BST();
		BST(const BST & originalTree);
		void insertNode(itemType item);
		bool isFull() const;
		int lengthIs() const;
		void retrieveItem(itemType& item, bool& found) const;
		void insertItem(itemType item);
		void deleteItem(itemType item);
		void printTree(int level);
		void MakeEmpty();
		bool IsEmpty() const;
};
