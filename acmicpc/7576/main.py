m, n = [int(i) for i in input().split()]
box = [[int(i) for i in input().split()] for _ in range(n)]

q = []
check = []
check_num = m * n
count = 0
for i, v in enumerate(box):
    l = []
    for j, w in enumerate(v):
        if w != 0:
            l.append(1)
            if w == 1:
                q.append([j, i])
            check_num -= 1
        else:
            l.append(0)
    check.append(l)

def xys(x, y):
    result = []
    result.append([x+1, y])
    result.append([x-1, y])
    result.append([x, y+1])
    result.append([x, y-1])
    return result

tempq = []
while q:
    if check_num == 0:
        break
    while q:
        tempq.append(q.pop())
    while tempq:
        cur = tempq.pop()
        for x, y in xys(cur[0], cur[1]):
            if 0 <= x < m and 0 <= y < n and check[y][x] == 0:
                q.append([x,y])
                check[y][x] = 1
                check_num -= 1
    count += 1

for i,v in enumerate(check):
    for j,w in enumerate(v):
        if w == 0:
            print(-1)
            exit(0)

print(count)