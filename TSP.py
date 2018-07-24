def TSP(Matrix, source):
	return TSP_Aux(Matrix, source, source, \
		[i for i in range(len(Matrix)) if i != source])

def TSP_Aux(M, source, home, remaining):
	total = int(0)
	if not remaining:
		return M[source][home]
	else:
		return min([(M[source][i] + TSP_Aux(M, i, home, \
			[v for v in remaining if v != i])) for i in remaining] )

tc = int(input())
for _ in range(tc):
	n = int(input())
	M = list()
	for i in range(n):
		x = list(map(int,input().split()))
		M.append(x)
	print(TSP(M,0))
