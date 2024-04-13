import sys

class Stack():
    def __init__(self):
        self.stack = []
        
    def push(self, data):
        self.stack.append(data)
        
    def pop(self):
        pop_obj = None
        if not self.empty():
            pop_obj = self.stack.pop()
        return pop_obj
    
    def empty(self):
        is_Empty = False
        if len(self.stack) == 0:
            is_Empty = True
        return is_Empty
    
    def top(self):
        top_obj = None
        if not self.empty():
            top_obj = self.stack[-1]
        return top_obj
    
N = int(sys.stdin.readline())
cur = 1
s = Stack()
ls = list()
able = True

for i in range(N):
    num = int(sys.stdin.readline())
    
    while cur <= num:
        s.push(cur)
        ls.append("+")
        cur += 1
    
    if num == s.top():
        s.pop()
        ls.append('-')
    else:
        able = False
        
if able:
    for i in ls:
        print(i)
else:
    print("NO")