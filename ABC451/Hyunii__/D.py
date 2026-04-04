import sys
input = sys.stdin.readline
import heapq

n = int(input())

twos = []   # 2**Ns
p = 1
while p <= 10**9:
    twos.append(p)
    p *= 2
# print(twos)

heap = []
seen = set()
for t in twos:
    heapq.heappush(heap, t)
    seen.add(t)

ans = 0
for _ in range(n):
    x = heapq.heappop(heap)
    # print(x)
    ans = x

    for t in twos:
        GIs = x * (10 ** len(str(t))) + t
        if GIs > 10**9:
            break
        
        # print(GIs)
        if GIs not in seen:
            heapq.heappush(heap, GIs)
            seen.add(GIs)   
    #print("//")

print(ans)


"""
1, 2, 4, 8, 16, 32, 64 ...

1 + @ .. => Sort(Min-Heap)
set => Eliminate Duplicates
...

for n : Nth Smallest

"""