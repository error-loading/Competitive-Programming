# https://dmoj.ca/problem/gfssoc2j4
# GFSSOC '15 Fall J4 - Marathon

import sys
input = sys.stdin.readline
n, q = map(int,input().split())
rating = [int(i) for i in input().split()]

rating.insert(0,0)

for i in range(1,len(rating)):
    rating[i]+=rating[i-1]

for i in range(q):
    a,b = map(int,input().split())
    print(rating[-1]-rating[b] + rating[a-1])