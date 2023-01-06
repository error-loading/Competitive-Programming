# https://dmoj.ca/problem/dwite09c6p5
# DWITE '09 R6 #5 - Air Travel Planning

import queue

for i in range(5):
    q = queue.PriorityQueue()
    dist = {}
    adj = {}

    n = int(input())

    for i in range(n):
        u, v, w = input().split()
        if u in adj:
            adj[u].append((v, int(w)))
            dist[u] = 100000000
            dist[v] = 100000000
        else:
            adj[u] = [(v, int(w))]
            dist[u] = 100000000
            dist[v] = 100000000
        if v not in adj:
            adj[v] = []
    q.put((0, "YYZ"))
    dist["YYZ"] = 0

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
    print(dist["SEA"])