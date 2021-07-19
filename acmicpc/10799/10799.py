import sys
input = sys.stdin.readline

def solve() -> int:
    l = input()

    pipe_num = 0
    result = 0

    len_l = len(l)
    for i in range(len_l):
        if l[i:i+2] == '()':
            result += pipe_num
        elif l[i:i+2] == '((':
            pipe_num += 1
        elif l[i:i+2] == '))':
            pipe_num -= 1
            result += 1

    return result

print(solve())

