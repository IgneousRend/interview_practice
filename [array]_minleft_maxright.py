def MinLeftMaxRight(A,N):
	leftMax = []
	m = -1
	for i in A:
		if i > m:
			m = i
		leftMax.append(m)
	print(leftMax)

A = [4,2,5,7]
N = 4
MinLeftMaxRight(A,N)