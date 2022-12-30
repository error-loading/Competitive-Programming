# https://dmoj.ca/problem/occ19s2
# OCC '19 S2 - Rimuru's Number Game

import sys
input = sys.stdin.readline

n = int(input())

ttl = []


def rec(cur):
    if cur != "" and int(cur) > n:
        return 0
    ttl.append(1)
    rec(int(str(cur) + "3"))
    rec(int(str(cur) + "2"))

rec("")
print(len(ttl)-1)