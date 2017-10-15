struct node {
	char c;
	node * next;
};

class BinaryTree {
	private:
		node * root;

	public:
		BinaryTree();
		~BinaryTree();
		void Insert();
		BinaryTree(const BinaryTree& originalTree);
		void operator=(BinaryTree& originalTree);
		void MakeEmpty();
		bool IsFull() const;
		int LengthIs() const;
		void RetrieveItem(); // uses parameter as carrier instead of returning compound type 
		// InsertItem, DeleteItem, ResetTree, GetNextItem,
		// PrintTree
};