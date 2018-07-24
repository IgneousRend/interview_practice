def spiral(A):
	l = []
	while A:
		l.append(A[0])
		del A[0]
		A = list(zip(*A))
		A = A[::-1]
	l = [list(i) for i in l]
	l = sum(l,[])
	return l


# A = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
tc = int(input())
for _ in range(tc):
	A = list()
	for i in range(4):
		x = list(map(int,input().split()))
		A.append(x)
	print(*spiral(A))
	# for i in range(4):
	# 	print(*A[4*i:4*(i+1)])