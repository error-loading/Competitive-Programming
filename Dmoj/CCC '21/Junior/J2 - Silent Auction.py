# https://dmoj.ca/problem/ccc21j2
# CCC '21 J2 - Silent Auction

import sys
input = sys.stdin.readline

n = int(input())

maxN = 0
maxName = ""
for i in range(n):
    name = input()
    val = int(input())
    if val > maxN:
        maxN = val; maxName = name
print(maxName)