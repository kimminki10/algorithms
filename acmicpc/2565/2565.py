from bisect import bisect_left

def solve(n, arr):
    arr.sort(key=lambda x: x[0])

    d = []
    idx = 0
    length = 0
    d.append(arr[0])
    for i in range(1,n):
        if d[idx][1] < arr[i][1]:
            idx+=1
            d.insert(idx, arr[i])
        else:
            tmp = bisect_left([i[1] for i in d], arr[i][1], 0, idx)
            d[tmp] = arr[i]
            length += 1
    print(length)


if __name__ == "__main__":
    n = int(input())
    arr = [[int(j) for j in input().split()] for i in range(n)]

    solve(n, arr)