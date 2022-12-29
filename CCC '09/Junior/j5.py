# https://dmoj.ca/problem/ccc09s3
# CCC '09 S3 - Degrees Of Separation

from collections import deque
adj = {0:[], 1:[6], 2:[6], 3:[4,5,6,15], 4:[3,5,6], 5:[3,4,6], 6:[1,2,3,4,5,7], 7:[6,8], 8:[7,9], 9:[8,10,12], 10:[9,11], 11:[10,12], 12:[9,11,13], 13:[12,14,15], 14:[13], 15:[3,13], 16:[17,18], 17:[16,18], 18:[16,17]}

def bfs(startNode, endNode):
    visited = [False for i in range(len(adj)+5)]
    dq = deque()
    dq.append((startNode, 0))
    visited[startNode] = True
    while len(dq) > 0:
        some = dq.popleft()
        curNode, curDis = some[0], some[-1]
        if curNode == endNode:
            return curDis
        for i in adj[curNode]:
            if not visited[i]:
                visited[i] = True
                dq.append((i, curDis+1))
    return "Not connected"

def numFriends(n):
    return len(adj[n])

def friendsOfFriends(n):
    lst = adj[n]
    newArr = set()
    for i in lst:
        for j in adj[i]:
            if j != n and j not in lst:
                newArr.add(j)
    return len(newArr)


def delete(x, y):
    if y in adj[x]:
        adj[x].remove(y)
    if x in adj[y]:
        adj[y].remove(x)

def post(x, y):
    if x not in adj:
        adj[x] = [y]
        
    elif y not in adj[x]:
        adj[x].append(y)

    if y not in adj:
        adj[y] = [x]

    elif x not in adj[y]:
        adj[y].append(x)

while True:
    string = input().strip()
    if string == "q":
        break
    elif string == "i":
        x = int(input())
        y = int(input())
        post(x, y)
    elif string == "d":
        x = int(input())
        y = int(input())
        delete(x, y)
    elif string == "n":
        x = int(input())
        print(numFriends(x))
    elif string == "f":
        x = int(input())
        print(friendsOfFriends(x))
    elif string == "s":
        x = int(input())
        y = int(input())
        print(bfs(x, y))