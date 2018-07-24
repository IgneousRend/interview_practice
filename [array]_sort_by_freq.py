def sort_by_frequency(A):
	freq = dict()
	for i in A:
		if i not in freq:
			freq[i] = 1
		else:
			freq[i] += 1
	A.sort(key=lambda y:(freq[y], -y), reverse=True)
	return A

tc = int(input())
for _ in range(tc):
	n = int(input())
	A = list(map(int, input().split()))
	print(*sort_by_frequency(A))