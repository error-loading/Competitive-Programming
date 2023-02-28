#  https://dmoj.ca/problem/dmopc15c3p3
#  DMOPC '15 Contest 3 P3 - Dimethylbenzene

from collections import deque
def solve():
    n, m = map(int, input().split())

    visited = [False for i in range(n+1)]

    adj = [[] for i in range(n+1)]

    for i in range(m):
        x, y = map(int, input().split())
        adj[x].append(y)

    dq = deque()

    dq.append((1, 0))

    while len(dq) > 0:
        node, dis = dq.pop()
        if node == 1 and dis >= 6:
            print("YES")
            return 0
        
        for i in adj[node]:
            if not visited[i]:
                dq.append((i, dis+1))
                visited[i] = True
        
    print("NO")

solve()
