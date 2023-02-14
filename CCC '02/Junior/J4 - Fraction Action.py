# https://dmoj.ca/problem/ccc02s2
# CCC '02 S2 - Fraction Action

import sys
from fractions import Fraction
input = sys.stdin.readline
first = int(input())
last = int(input())

cur = ""
cur += str(first // last) + " " if first // last != 0 else ""


if first % last == 0:
    print(first // last)
    sys.exit()


top = first % last
bot = last
cur += f"{Fraction(top, bot)}"
print(cur)