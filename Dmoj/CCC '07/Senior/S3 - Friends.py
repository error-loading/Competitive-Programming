# https://dmoj.ca/problem/ccc07s3
# CCC '07 S3 - Friends

from collections import deque

n = int(input())

def theory(start, end, adj):
    dq = deque()
    dq.append((start, 0))

    visited = {}

    for i in adj.values():
        for j in i:
            if j not in visited:
                visited[j] = False

    while len(dq) > 0:
        curNode, dis = dq.pop()
        if curNode == end:
            return f"Yes {dis - 1}"
        
        if visited[curNode]:
            continue

        visited[curNode] = True

        for i in adj[curNode]:
            if not visited[i]:
                dq.append((i, dis+1))

    return f"No"


adj = {}

for i in range(n):
    a, b = map(int, input().split())
    if a in adj:
        adj[a].append(b)
    else:
        adj[a] = [b]

while True:
    start, end = map(int, input().split())

    if start == 0 and end == 0:
        break

    print(theory(start, end, adj))