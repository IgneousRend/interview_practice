'''
For N nodes, numbered 1 to N,
find the number of unique BSTs
that can be formed.
'''

def uniqueBST(n):
	if n == 1 or n == 0:
		return 1
	s = 0
	for i in range(0,n):
		s += uniqueBST(i)*uniqueBST(n-i-1)
	return s

N = int(input("Enter N: "))
print (uniqueBST(N))
