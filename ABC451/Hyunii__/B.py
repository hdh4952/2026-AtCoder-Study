import sys
input = sys.stdin.readline

n, m = map(int, input().split())
d = [0] * (m+1)
for _ in range(n):
    a, b = map(int, input().split())
    d[a-1] -= 1
    d[b-1] += 1

for i in range(m):
    print(d[i])


"""

"""