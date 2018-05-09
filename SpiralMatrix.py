# Print a matrix spirally, clockwise.

matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
out = []

# Uncomment for counter-clockwise.
# matrix = list(zip(*matrix))

while len(matrix) > 0:
    out.append(list(matrix[0]))
    del matrix[0]
    matrix = list(zip(*matrix))
    matrix = matrix[::-1]

print(sum(out, []))
