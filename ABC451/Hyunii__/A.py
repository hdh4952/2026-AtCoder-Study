import sys
input = sys.stdin.readline

s = input().strip()
if len(s) % 5:
    print("No")
else:
    print("Yes")