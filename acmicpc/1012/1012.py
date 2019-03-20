
def check_direction_validity(i, j, m, n):
    if 0 <= i < m and 0 <= j < n:
        return True
    return False


def explore_continent(mapmap, checkmap, i, j, m, n):
    stack = [[i, j]]
    while stack:
        p = stack.pop()
        checkmap[p[1]][p[0]] = 1

        direction = [[p[0] + 1, p[1]],
                     [p[0], p[1] + 1],
                     [p[0] - 1, p[1]],
                     [p[0], p[1] - 1]]

        for d in direction:
            if check_direction_validity(d[0], d[1], m, n) \
                    and mapmap[d[1]][d[0]] is 1 \
                    and checkmap[d[1]][d[0]] is 0:
                stack.append(d)


def solve1012():
    m, n, k = [int(i) for i in input().split()]
    mapmap = [[0 for _ in range(m)] for _ in range(n)]
    checkmap = [[0 for _ in range(m)] for _ in range(n)]
    for _ in range(k):
        x, y = [int(i) for i in input().split()]
        mapmap[y][x] = 1

    result = 0
    for j in range(n):
        for i in range(m):
            if checkmap[j][i] is 0 and mapmap[j][i] is 1:
                result += 1
                explore_continent(mapmap, checkmap, i, j, m, n)

    print(result)


t = int(input())
for _ in range(t):
    solve1012()
