# https://dmoj.ca/problem/coci20c6p2
# COCI '20 Contest 6 #2 Alias

import queue
import sys

input = sys.stdin.readline

n, m = map(int, input().split())
adj = [[] for i in range(1005)]
assign = {}

temp = 1

for i in range(m):
    x, y, t = input().split()
    t = int(t)
    if x not in assign:
        assign[x] = temp
        temp +=1
    if y not in assign:
        assign[y] = temp
        temp+=1

    adj[assign[x]].append((t, assign[y]))

q = int(input())

for i in range(q):
    a, b =input().split()
    a = assign[a]; b = assign[b]
    q = queue.PriorityQueue()
    dist = [10000000000 for i in range(1005)]
    q.put((0, a))
    dist[a] = 0
    while not q.empty():
        some = q.get()
        dis = some[0]; node1 = some[-1]
        for cost, node2 in adj[node1]:
            if dist[node2] > cost + dis:
                dist[node2] = cost + dis
                q.put((cost + dis, node2))
    
    if dist[b] == 10000000000:
        print('Roger')
    else:
        print(dist[b])
    




