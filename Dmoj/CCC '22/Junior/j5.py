# https://dmoj.ca/problem/ccc22j5
# CCC '22 J5 - Square Pool

n = int(input())
t = int(input())
trees = [tuple(map(int,input().split())) for i in range(t)] + [(0,0),(n+1,n+1)]
t += 2
ans = 0 
for i in range(t): 
    for j in range(t): 
        if trees[i][0] < trees[j][0]: 
            y1 = trees[i][0] + 1 
            y2 = trees[j][0] - 1 
            length = y2 - y1 + 1 
            for k in range(t): 
                x1 = trees[k][1] + 1 
                x2 = x1 + length - 1 
                if 1 <= y1 <= n and 1 <= y2 <= n and 1 <= x1 <= n and 1 <= x2 <= n:
                    ok = True
                    for l in range(t):
                        if y1 <= trees[l][0] <= y2 and x1 <= trees[l][1] <= x2:
                            ok = False
                            break
                    if ok:
                        ans = max(ans,length)
        if trees[i][1] < trees[j][1]: #
            x1 = trees[i][1] + 1 
            x2 = trees[j][1] - 1 
            length = x2 - x1 + 1
            for k in range(t): 
                y1 = trees[k][0] + 1 #
                y2 = y1 + length - 1 #
                if 1 <= y1 <= n and 1 <= y2 <= n and 1 <= x1 <= n and 1 <= x2 <= n:
                    ok = True
                    for l in range(t):
                        if y1 <= trees[l][0] <= y2 and x1 <= trees[l][1] <= x2:
                            ok = False
                            break
                    if ok:
                        ans = max(ans,length)
print(ans)