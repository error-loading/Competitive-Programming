# https://dmoj.ca/problem/aac1p1
# An Animal Contest 1 P1 - Alpaca Shapes

import sys
input = sys.stdin.readline
x, y = map(int, input().split())

if x*x > 3.14 * y ** 2:
  print('SQUARE')
else:
  print('CIRCLE')
