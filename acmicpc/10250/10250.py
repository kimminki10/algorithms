
def testcase():
    h, w, n = [ int(i) for i in input().split()]
    if n%h:
        print("{}{:02}".format(n%h, n//h + 1))
    else:
        print("{}{:02}".format(h, n//h))

if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        testcase()