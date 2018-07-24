def endElements(a):
	return [i[-1] for i in a]

def longestActives(a):
	return max(a, key=len)

def LIS(a):
	active = [[a[0]]]
	for i in a[1:]:
		if i < min(endElements(active)):
			active.append([i])
		elif i > max(endElements(active)):
			l = longestActives(active)[:]
			l.append(i)
			active.append(l)			
		else:
			l = max([x for x in active if x[-1] < i],\
			 key=lambda y: y[-1])
			l.append(i)
			active = [i for i in active if len(i) != len(l)]
			active.append(l)
	return max(active, key=len)

A = [ 2, 5, 3, 7, 11, 8, 10, 13, 6 ]
x = LIS(A)
print(x, len(x))