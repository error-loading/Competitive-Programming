# https://dmoj.ca/problem/stack1
# The DMOJ Driveway

from collections import deque
 
t, m = map(int, input().split())
driveway = deque()
 
for i in range(t):
    name, direction = input().split()
 
    if direction == "in":
        driveway.append(name)
    else:
        carLeaving = driveway.pop()
       
        if carLeaving != name:
            driveway.append(carLeaving)
 
            if m > 0:
                carLeaving = driveway.popleft()
                if carLeaving != name:
                    driveway.appendleft(carLeaving)
                else:
                    m-=1
 
for name in driveway:
    print(name)
