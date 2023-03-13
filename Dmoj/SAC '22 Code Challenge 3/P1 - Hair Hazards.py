# https://dmoj.ca/problem/sac22cc3p1
# SAC '22 Code Challenge 3 P1 - Hair Hazards

h, s, q = [int(input()) for i in range(3)]
for i in range(q): 
    h-=s; print(h)