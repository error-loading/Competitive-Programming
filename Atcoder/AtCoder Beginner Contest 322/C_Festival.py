import sys, bisect
input = sys.stdin.readline

N, M = map(int, input().split())
lst_m = list(map(int, input().split()))

for i in range(1, N + 1):
    ind = bisect.bisect_left(lst_m, i)

    if lst_m[ind] == i: print(0)
    else: print(lst_m[ind] - i)
