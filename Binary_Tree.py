class Node:

	def __init__(self, value):
		self.data = value
		self.lc = None
		self.rc = None

def createBinaryTree():
	x = int(input("Data > ").strip())
	if(x == 0):
		return None
	root = Node(x)
	print("L(",x,") ", end='')
	root.lc = createBinaryTree()
	print("R(",x,") ", end=' ')
	root.rc = createBinaryTree()
	return root

def BTFromArray(array):
	x = array[0]
	if(x == 0):
		return None
	root = Node(x)
	del array[0]
	root.lc = BTFromArray(array)
	del array[0]
	root.rc = BTFromArray(array)
	return root

def inorder(root):
	if(root == None):
		return 
	inorder(root.lc)
	print(root.data)
	inorder(root.rc)

def levelOrder(root):
	if root is None:
		return
	queue = []
	queue.append(root)
	while(queue):
		print(queue[0].data)
		node = queue.pop(0)
		if(node.lc is not None):
			queue.append(node.lc)
		if(node.rc is not None):
			queue.append(node.rc)	

a = [1,2,4,0,0,5,0,0,3,0,0]
bt = BTFromArray(a)
inorder(bt)
levelOrder(bt)