# https://dmoj.ca/problem/ccc21j1
# CCC '21 J1 - Boiling Water

import sys
input = sys.stdin.readline

n = int(input())
n = 5*n - 400

print(n)

if n == 100:
    print(0)
elif n>100:
    print(-1)
else:
    print(1)