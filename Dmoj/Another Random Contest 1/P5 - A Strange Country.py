import sys

input = sys.stdin.readline
sys.setrecursionlimit(20000)

MM = 10**3 + 5

N, M, K = map(int, input().split())

edge = []
dsu = [0 for i in range(MM)]
date = [0 for i in range(MM)]
vis = [True for i in range(MM)]

def make_set(v):
    dsu[v] = v


def union_sets(a, b):
    dsu[b] = a


def find_set(a):
    if (dsu[a] != a): find_set(dsu[a])
    return dsu[a]


for i in range(M):
    a, b, w = map(int, input().split())
    edge.append((w, a, b))


for _ in range(1, K+1):
    newEdge = sorted(edge)
    dsu = [0 for i in range(MM)]

    for i in range(1, N+1): make_set(i)


    for w, a, b in newEdge:
        ind = edge.index((w, a, b)) + 1
        fa = find_set(a); fb = find_set(b)

        if fa != fb and vis[ind]:
            union_sets(fa, fb)
            vis[ind] = False
            date[ind] = _
    
for i in range(1, M+1):
    if date[i] == 0: print(-1)
    else: print(date[i])
