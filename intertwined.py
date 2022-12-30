# https://dmoj.ca/problem/ul2
# Intertwined Strings

s, t = input().split()

newComb = set()
def rec(s, t, cur):
  if len(s)==0 and len(t) == 0:
    if cur not in newComb:
      newComb.add(cur)
      print(cur)
    return 0
  elif len(s)==0:
    rec("", t[1:], cur + t[:1])
  elif len(t)==0:
    rec(s[1:], "", cur + s[:1])
  else:
    for i in range(2):
      if i == 0:
        rec(s[1:], t, cur + s[:1])
      else:
        rec(s, t[1:], cur + t[:1])
        
rec(s, t, "")