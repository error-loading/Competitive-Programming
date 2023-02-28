# https://dmoj.ca/problem/ccc22s2
# CCC '22 S2 - Good Groups

x = int(input())
together = {}
separate = {}
groups = {}
for i in range(x):
    name1, name2 = input().split()
    if name1 in together:
        together[name1].append(name2)
    else:
        together[name1]=[name2]

y = int(input())
for i in range(y):
    name1, name2 = input().split()
    if name1 in separate:
        separate[name1].append(name2)
    else:
        separate[name1]=[name2]
g = int(input())
for i in range(g):
    name1, name2, name3 = input().split()
    groups[name1] = [name2, name3]
    groups[name2] = [name1, name3]
    groups[name3] = [name1,name2]
constraints = 0
for i in together.keys():
    for j in together[i]:
        if j not in groups[i]:
            constraints+=1
for i in separate.keys():
    for j in separate[i]:
        if j in groups[i]:
            constraints+=1
print(constraints)