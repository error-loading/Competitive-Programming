# https://dmoj.ca/problem/ccc22j2
# CCC '22 J2 - Fergusonball Ratings

n = int(input())
lst = []
first = 0
for i in range(2*n):
    new =  int(input())
    if i%2==0:
        first = new
    else:
        lst.append(first*5-new*3)
ttl = 0
for i in lst:
    if i>40:
        ttl+=1
if ttl==n:
    print('{}+'.format(n))
else:
    print(ttl)