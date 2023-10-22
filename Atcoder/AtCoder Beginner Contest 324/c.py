import sys
input = sys.stdin.readline

N, T = input().split(); N = int(N)
a = [input().strip() for i in range(N)]
ans = []

def solve(s, t):
    if len(s) > len(t): return solve(t, s)
    if s == t: return True
    if len(s) < len(t) - 1: return False

    fi = 0
    se = 0
    add = 0

    while fi < len(s):
        if add > 1: return False
        if s[fi] == t[se]: fi+=1; se+=1
        else:
            add += 1
            if len(s) == len(t): fi += 1
            se += 1

    return True



for s in range(len(a)):
    b = solve(a[s], T)
    if b: ans.append(s + 1)

print(len(ans))
print(*ans)