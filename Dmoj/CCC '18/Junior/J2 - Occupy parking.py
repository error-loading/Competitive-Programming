# https://dmoj.ca/problem/ccc18j2
# CCC '18 J2 - Occupy parking

import sys
input = sys.stdin.readline
n = int(input())
str1 = [i for i in input()]
str2 = [i for i in input()]
x = 0
for i in range(n):
  if str1[i] == "C" and str2[i] == "C":
    x+=1
print(x)