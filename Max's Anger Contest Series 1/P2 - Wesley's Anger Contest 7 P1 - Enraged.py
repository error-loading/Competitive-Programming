# https://dmoj.ca/problem/macs1p2
# Max's Anger Contest Series 1 P2 - Wesley's Anger Contest 7 P1 - Enraged

n = int(input())
arr1 = [i for i in input()]
arr2 = [i for i in input()]

x = 0

for i in range(n):
  if arr1[i] == "S" and arr2[i] == "S":
    x+=1

if x>2:
  print("NO")
else:
  print("YES")