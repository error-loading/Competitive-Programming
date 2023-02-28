# https://dmoj.ca/problem/ccc21s2
# CCC '21 S2 - Modern Art

import sys
input = sys.stdin.readline
m = int(input())
n = int(input())
k = int(input())
row = [0 for i in range(m)]
columns = [0 for j in range(n)]
gph = [[0 for i in range(n)] for b in range(m)]
for i in range(k):
    x, y = [i for i in input().split()]
    y = int(y)
    if x=='R':
        row[y-1]+=1
    else:
        columns[y-1]+=1
for i in range(m):
    for j in range(n):
        gph[i][j]+=row[i]
ans = 0
for i in range(m):
    for j in range(n):
        gph[i][j]+=columns[j]
        if gph[i][j]%2==1:
            ans+=1
print(ans)