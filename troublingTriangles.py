# https://dmoj.ca/problem/geometry1
# Troubling Triangles

n = int(input())

for i in range(n):
    x1, y1, x2, y2, x3, y3 = map(int, input().split())
    area = 0.5 * (x1*y2+x2*y3+x3*y1 - (x1*y3+x3*y2+x2*y1))
    area = abs(round(area, 2))
    peri = ((y2-y1)**2 + (x2-x1) ** 2) ** 0.5 + ((y3-y2)**2 + (x3-x2) ** 2) ** 0.5 + ((y3-y1)**2 + (x3-x1) ** 2) ** 0.5
    peri = round(peri, 2)
    print(str(area), str(peri))
