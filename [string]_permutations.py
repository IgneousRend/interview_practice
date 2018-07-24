from itertools import permutations as pt

def permute(a):
	a = sorted([''.join(i) for i in pt(a)])
	print(*a)	


tc = int(input())
for _ in range(tc):
	s = input().strip()
	permute(s)