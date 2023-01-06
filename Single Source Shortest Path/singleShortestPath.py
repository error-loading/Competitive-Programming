# https://dmoj.ca/problem/sssp
# Single Source Shortest Path

import queue
q = queue.PriorityQueue()
dist = [100000000 for i in range(1005)]
adj = [[] for i in range(1005)]

n, m = map(int, input().split())

for i in range(m):
    u, v, w = map(int, input().split())
    adj[u].append((v, w))
    adj[v].append((u, w))

q.put((0, 1))
dist[1] = 0

while not q.empty():
    cur = q.get()
    dis = cur[0]
    node = cur[1]
    for i in adj[node]:
        ttlDis = dis + i[1]
        nextNode = i[0]
        if dist[nextNode] > ttlDis:
            dist[nextNode] = ttlDis
            q.put((ttlDis, nextNode))

for i in range(1,n+1):
    if dist[i] == 100000000:
        print(-1)
    else:
        print(dist[i])