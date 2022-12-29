# https://dmoj.ca/problem/ccc03j2
# CCC '03 J2 - Picture Perfect

while True:
    n = int(input())
    if n == 0:
        break

    for i in range(int(n**0.5), 0, -1):
        if n%i == 0:
            print(f"Minimum perimeter is {2*(i + n//i)} with dimensions {i} x {n//i}")
            break
