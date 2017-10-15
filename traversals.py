def inorder(root):
	if root == None:
		return
	print(root.val)
	inorder(root.left)
	inorder(root.right)

