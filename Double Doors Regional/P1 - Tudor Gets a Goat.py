# https://dmoj.ca/problem/ddrp1
# Double Doors Regional P1 - Tudor Gets a Goat

import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
p = int(input())

if n == m:
    print("Switch")
else:
    print("Stay")