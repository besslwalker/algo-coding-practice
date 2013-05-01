# AVL Tree
# Bess L. Walker
# 2-22-12

class AVL_node:
	
	def __init__(self, key = None, value = None):
		self.key = key
		self.value = value
		self.heigh = 0
		self.balance = 0
		self.left = None
		self.right = None
	
	# your basic binary search; returns None if key cannot be found
	# returns value
	def search(self, key):
		if key == self.key:
			return self.value
		if key < self.key and left != None:
			return left.search(key)
		if key > self.key and right != None:
			return right.search(key)
		
		return None
		
	# insert and maintain balance
	def insert(self, key, value):
		if key == self.key:
			print "ERROR: duplicate keys are not currently allowed."
			return
			
		if key < self.key:
			if self.left == None:
				self.left = AVL_node(key, value)
			else:
				self.left.insert(key, value)
		
		if key > self.key:
			if se
	
class AVL_tree:
	root = None
	
	# your everyday binary search
	# returns None if key is not found
	def search(self, key):
		if self.root == None: return None
		return self.root.search(key)
		
	# insert and maintain balance
	def insert(self, key, value):
		if self.root == None:
			self.root = AVL_node(key, value)
			return
		
		self.root.insert(key, value)
		
		
A = AVL_tree()
print A.search(37)
A.insert(37, "initial root value")
print A.search(37)