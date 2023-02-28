# https://dmoj.ca/problem/ccc21s1
# CCC '21 S1 - Crazy Fencing

import sys
input = sys.stdin.readline

n = int(input())
side = [int(i) for i in input().split()]
width = [int(i) for i in input().split()]
ttl = 0
for i in range(n):
    ttl+=(side[i]+side[i+1])*width[i]/2
print(ttl)