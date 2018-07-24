def relative_sorting(A,B):
	C = [i for i in A if i in B]
	D = [i for i in A if i not in B]
	C.sort(key=lambda y:B.index(y))
	D.sort()
	return C+D

tc = int(input())
for _ in range(tc):
	n = list(map(int, input().split()))
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	print(*relative_sorting(a,b))