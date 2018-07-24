tc = int(input())
for _ in range(tc):
	a = input()
	b = input()
	if sorted(a) == sorted(b):
		print("YES")
	else:
		print("NO")