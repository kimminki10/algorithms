import time

start_time = time.time()


# input
n = int(input())
xy = {}

for _ in range(n):
    position, color = input().split()
    position = int(position)
    color = int(color)

    if not color in xy.keys():
        xy[color] = [position]
    else:
        xy[color].append(position)

## endinput

# find diff
diff = {}
for color in xy:
    arr = xy[color]
    arr.sort()
    diff[color] = []
    lastidx = len(arr) - 1

    for i, v in enumerate(arr):
        if i < lastidx:
            diff[color].append(arr[i+1] - v)
        else:
            diff[color].append(v - arr[i - 1])

## end find diff

result = 0
for color in diff:
    arr = diff[color]

    for i, v in enumerate(arr):
        if i == 0:
            result += v
        else:
            result += min(arr[i-1], v)

print(result)
        


print("--- %s seconds ---" % (time.time() - start_time))