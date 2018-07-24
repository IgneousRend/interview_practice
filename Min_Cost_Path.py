def MinCostPath(cost, R, C):
	aux = [[0 for i in range(C)] for i in range(R)]
	print(aux)
	aux[0][0] = cost[0][0]
	for i in range(1,C):
		aux[0][i] = aux[0][i-1] + cost[0][i]
	for i in range(1,R):
		aux[i][0] = aux[i-1][0] + cost[i][0]

	for i in range(1, R):
		for j in range(1, C):
			aux[i][j] = min(aux[i-1][j], aux[i][j-1]) + cost[i][j]
	print(aux)
	return aux[R-1][C-1]

tc = int(input())
for _ in range(tc):
	n = int(input())
	x = list(map(int, input().split()))
	x = [x[i*n:(i+1)*n] for i in range(n)]
	print(MinCostPath(x,n,n))
