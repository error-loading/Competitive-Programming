s = input()

big = 0

for sz in range(1, len(s) + 1):
  for l in range(0, len(s) - sz + 1):
    if s[l : l + sz] == s[l : l + sz][::-1]: big = max(big, sz)

print(big)

'''

 (n - 1) * d + 300 =   (3n - 1) * d

 nd - d + 300 = 3nd - d
 2nd = 300
 nd = 150
 





'''