# https://dmoj.ca/problem/ccc15j2
# CCC '15 J2 - Happy or Sad

string = input()
happy = ':-)'
sad = ':-('
nhap = 0
nsad = 0
for i in range(len(string)-2):
  newS =string[i:i+3] 
  if newS == happy:
    nhap+=1
  elif newS == sad:
    nsad+=1
if not nhap and not nsad:
  print('none')
elif nhap == nsad:
  print('unsure')
elif nhap>nsad:
  print('happy')
else:
  print('sad')