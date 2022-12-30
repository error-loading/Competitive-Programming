# https://dmoj.ca/problem/pwindsor18p2
# VMSS Pre-Windsor P2 - Get Off My Lawn

def dis(x,y):
  return (x**2+y**2)**0.5
n = int(input())

greatest = [0, 0, 0]

for i in range(n):
  a, b = map(int, input().split())
  x = dis(abs(a), abs(b))
  if x > greatest[-1]:
    greatest = [a, b, x]
print(greatest[0], greatest[1])
