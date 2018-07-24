def min_diff(A,K,M):
	A.sort()
	res = int(999)
	if K == M:
		return max(A) - min(A)
	elif M == 1:
		return 0
	else:
		for i in range(M-K+1):
			x = max(A[i:i+K]) - min(A[i:i+K])
			res =  x if x < res else res
	return res

tc = int(input())
for i in range(tc):
	n = int(input())
	a = list(map(int, input().split() ) )
	k = int(input())
	print(min_diff(a,k,n))