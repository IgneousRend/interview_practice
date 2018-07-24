def roman_to_integer(s: str):
	D = {'I':1, 'V': 5, 'X':10, 'L':50, 'C': 100, 'D':500, 'M':1000}
	sub = int(0)
	total = int(0)
	for i in range(len(s)-1):
		if D[s[i]] < D[s[i+1]]:
			sub += D[s[i]]
		else:
			total += D[s[i]] - sub
			sub = 0
	total += D[s[-1]] - sub
	return total

tc = int(input())
for _ in range(tc):
	s = input().strip()
	print(roman_to_integer(s))