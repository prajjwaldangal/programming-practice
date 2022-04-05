#include <iostream>
#include "bst.h"
#include <string.h>

using namespace std;

BST::BST() {
	root = NULL;
}

void destroy(TreeNode *& tree) {
	if (tree != NULL) {
		destroy(tree->left);
		destroy(tree->right);
		delete tree;
	}
}

BST::~BST() {
	destroy(root);
}

void copyTree(TreeNode*& copy, const TreeNode* originalTree) {
	if (originalTree == NULL) {
		copy = NULL;
	} else {
		copy = new TreeNode;
		copy->info = originalTree->info;
		copyTree(copy->left, originalTree->left);
		copyTree(copy->right, originalTree->right);
	}
}

BST::BST(const BST & originalTree) {
	copyTree(root, originalTree.root);
}

/* this prototype is equivalent to:
void _insertNodeHelp(itemType item, TreeNode * & tree)
*/
void _insertNodeHelper(itemType item, TreeNode ** tree) {
	if (*tree == NULL) {
		*tree = new TreeNode;
		(*tree)->info = item;
		(*tree)->left = NULL;
		(*tree)->right = NULL;
	} else if (item >= (*tree)->info)
		_insertNodeHelper(item, &(*tree)->right);
	else
		_insertNodeHelper(item, &(*tree)->left);
}

void _insertNodeHelper(itemType item, TreeNode * tree) {
	if (tree == NULL) {
		tree = new TreeNode;
		(tree)->info = item;
		(tree)->left = NULL;
		(tree)->right = NULL;
	} else if (item >= (tree)->info)
		_insertNodeHelper(item, (tree)->right);
	else
		_insertNodeHelper(item, (tree)->left);
}

void BST::insertNode(itemType item) {
	_insertNodeHelper(item, &root);
}

void _printTree(TreeNode * node, int level) {
	if (node == NULL)
		return;
	_printTree(node->right, level+1);
	for (int i=0; i < level; ++i) {
		printf("\t");
	}
	printf("%d\n\n", node->info);
	_printTree(node->left, level+1);
}

void BST::printTree(int level) {
	return _printTree(root, level);
}

// bool _isFull(TreeNode *)