# https://dmoj.ca/problem/ccc07j5
# CCC '07 J5 - Keep on Truckin'

motel = [0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000]

a = int(input())
b = int(input())
m = int(input())

for i in range(m):
  mi = int(input())
  motel.append(mi)
motel.sort()

combs = [0 for i in range(len(motel))]
combs[0] = 1

for i in range(1,len(motel)):
  for j in range(i-1, -1, -1):
    if motel[i] - motel[j] >= a and motel[i] - motel[j] <= b:
      combs[i]+=combs[j]
print(combs[-1])