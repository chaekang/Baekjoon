import sys

stick = list(sys.stdin.readline().strip())
stack =[]
result = 0

for i in range(len(stick)):
    if stick[i] == "(":
        stack.append("(")
    else:
        if stick[i - 1] == "(":
            stack.pop()
            result += len(stack)
        else:
            stack.pop()    
            result += 1      

print(result)