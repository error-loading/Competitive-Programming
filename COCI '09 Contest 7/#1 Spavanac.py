# https://dmoj.ca/problem/coci09c7p1
# COCI '09 Contest 7 #1 Spavanac

import sys
input = sys.stdin.readline
h, m = map(int, input().split())
if m < 45:
    if h == 1:
        h = 0
        m = 60-(45-m)
    elif h == 0:
        h = 23
        m = 60-(45-m)
    else:
        h -= 1
        m = 60-(45-m)
else:
    m -= 45

print(str(h) + " " + str(m))