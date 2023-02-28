from collections import deque

x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
visited = [[False for i in range(9)] for j in range(9)]

dq = deque()
dq.append((x1, y1, 0))
visited[8-y1][x1] = True

print(visited)

mini = []

while len(dq) > 0:
    x, y, dis = dq.popleft()
    if x == x2 and y == y2:
        mini.append(dis)

    if x+1 <= 8 and y+2<=8:
        if not visited[y+2][x+1]:
            visited[y+2][x+1] = True
            dq.append((x+1, y+2, dis+1))

    if x+2 <= 8 and y-1>0:
        if not visited[y-1][x+2]:
            visited[y-1][x+2] = True
            dq.append((x+2, y-1, dis+1))

    if x+1 <= 8 and y-2>0:
        if not visited[y-2][x+1]:
            visited[y-2][x+1] = True
            dq.append((x+1, y-2, dis+1))

    if x-2 >0 and y-1>0:
        if not visited[y-1][x-2]:
            visited[y-1][x-2] = True
            dq.append((x-2, y-1, dis+1))


    if x-1 >0 and y-2>0:
        if not visited[y-2][x-1]:
            visited[y-2][x-1] = True
            dq.append((x-1, y-2, dis+1))

    if x-2 >0 and y+1<=8:
        if not visited[y+1][x-2]:
            visited[y+1][x-2] = True
            dq.append((x-2, y+1, dis+1))

    if x-1 >0 and y+2<=8:
        if not visited[y+2][x-1]:
            visited[y+2][x-1] = True
            dq.append((x-1, y+2, dis+1))
    
print(mini)