# https://dmoj.ca/problem/dmopc18c2p3
# https://dmoj.ca/problem/dmopc18c2p3

import queue
n, m, k, a, b = [int(i) for i in input().split()]
gifts = [int(i) for i in input().split()]
adjacencyList = [[] for i in range(n+1)]

visitedA=[False for i in range(n+1)]
visitedB=[False for i in range(n+1)]

distA = [1000000 for i in range(n+1)]
distB = [1000000 for i in range(n+1)]

q = queue.Queue()
q.put(a)

distA[a] = 0
distB[b] = 0

visitedA[a] = True
visitedB[b] = True

for i in range(m):
    x, y = [int(i) for i in input().split()]
    adjacencyList[x].append(y)
    adjacencyList[y].append(x)

while not q.empty():
    c = q.get()

    for adjacentNodes in adjacencyList[c]:
        if not visitedA[adjacentNodes]:
            visitedA[adjacentNodes] = True
            distA[adjacentNodes] = distA[c] + 1
            q.put(adjacentNodes)
q = queue.Queue()
q.put(b)

while not q.empty():
    c = q.get()
    for adjacentNodes in adjacencyList[c]:
        if not visitedB[adjacentNodes]:
            visitedB[adjacentNodes] = True
            distB[adjacentNodes] = distB[c] + 1
            q.put(adjacentNodes)
a = 10000000
for i in gifts:
    a = min(a, distA[i] + distB[i] )

print(a)