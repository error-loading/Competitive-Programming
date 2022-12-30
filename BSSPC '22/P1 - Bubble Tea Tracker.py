# https://dmoj.ca/problem/bsspc22c1p1
# BSSPC '22 P1 - Bubble Tea Tracker

n = int(input())
pref = [int(input()) for i in range(n)]
print(pref[0])
for i in range(1, n):
    pref[i]+=pref[i-1]
    print(pref[i])