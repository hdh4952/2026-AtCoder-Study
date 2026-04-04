import sys
input = sys.stdin.readline
import heapq

q = int(input())
heap = []

for _ in range(q):
    i, h = map(int, input().split())

    if i == 1:
        heapq.heappush(heap, h)
    else:
        while heap:
            if heap[0] <= h:
                heapq.heappop(heap)
            else:
                break
    
    print(len(heap))


"""
[5]
[5, 7]
[5, 7, 8]
[8]
[8, 3]

"""