
solution = []
value = [3, 2, 5, 6, 7, 8]
weight =  [2, 3, 4, 1, 5, 3]
Z = zip(weight,value)
Z = sorted(Z)
weight,value = zip(*Z)
capacity = 6
x = [0] * (capacity+1)

n = len(value)

def knapSack(capacity, weight, value, n):
    solution = [[0 for x in range(capacity+1)] for x in range(n+1)]
 
    # Build table solution[][] in bottom up manner
    for i in range(n+1):
        for w in range(capacity+1):
            if i==0 or w==0:
                solution[i][w] = 0
            elif weight[i-1] <= w:
                solution[i][w] = max(value[i-1] + solution[i-1][w-weight[i-1]],  solution[i-1][w])
            else:
                solution[i][w] = solution[i-1][w]
    return solution

def Traceback():
	A = capacity
	for i in range(n,0,-1):
		if solution[i][A] == solution[i-1][A]:
			x[i] = 0
		else:
			x[i] = 1
			A = A - weight[i-1]
	if solution[n][A] == 1:
		x[n] = 1
	else:
		x[n] = 0
 

solution = (knapSack(capacity, weight, value, n))
print "Max Profit: ", solution[n][capacity]
Traceback()
print "Selected: ",x[1:]
print "Weights : ", weight
print "Values  : ", value