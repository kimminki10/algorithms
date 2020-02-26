
def solve_line(line):
    stack = []

    for s in line:
        if s == '(' or s== '[':
            stack.append(s)
        elif s == ')' or s == ']':
            empty = len(stack) != 0
            if empty and s == ')' and stack[-1] == '(':
                stack.pop()
            elif empty and s == ']' and stack[-1] == '[':
                stack.pop()
            else:
                print("no")
                return
    if len(stack) != 0:
        print("no")
    else:
        print("yes")
        


if __name__ == "__main__":
    while True:
        line = input()
        if line == ".":
            break
        else:
            solve_line(line)