# https://dmoj.ca/problem/seed3
# The Cosmic Era P3 - Battle Positions

import sys
input = sys.stdin.readline
i = int(input())
n = int(input())
j = int(input())

arr = [0 for b in range(i+1)]

for itr in range(j):
    xi, xf, k = map(int, input().split())
    arr[xi-1] +=k
    arr[xf] -=k


for itr in range(1,i+1):
    arr[itr] += arr[itr-1]


ttl = 0

for a in range(i):
    if arr[a] < n:
        ttl+=1
print(ttl)