# https://dmoj.ca/problem/bts18p2
# Back To School '18: Letter Frequency

import  sys
input = sys.stdin.readline
s = input()

arr = [[0 for i in range(len(s))] for j in range(27)]

for i in range(len(s)-1):
    some = ord(s[i])
    if some==32:
        arr[-1][i] +=1
    else:
        arr[some-97][i] +=1

q = int(input())

for i in range(26):
    for j in range(1,len(s)):
        arr[i][j] +=arr[i][j-1]

for i in range(q):
    i,j,c = input().split()
    i = int(i)-1; j = int(j)-1
    if arr[ord(c)-97][i-1] == 0 or i==0:
        print(arr[ord(c)-97][j])
    else:
        print(arr[ord(c)-97][j]-arr[ord(c)-97][i-1])