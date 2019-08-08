
def reverse_str(s):
    ls = list(s)
    ls.reverse()
    rs = "".join(ls)
    return rs

def isSymetric(num):
    oa = str(num)
    ra = reverse_str(oa)

    if oa == ra:
        return True
    else:
        return False

def solve(num):
    onum = int(num)
    rnum = int(reverse_str(num))

    snum = onum+rnum
    result = isSymetric(snum)

    if result == True:
        print("YES")
    else:
        print("NO")


t = int(input())

for _ in range(t):
    solve(input())