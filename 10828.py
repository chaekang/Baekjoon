class Stack():
    def __init__(self):
        self.stack = []
        
    def push(self, data):
        self.stack.append(data)
        
    def pop(self):
        pop_obj = None
        if self.empty() == 1:
            pop_obj = -1
        else:
            pop_obj = self.stack.pop()
        return pop_obj
    
    def size(self):
        size = len(self.stack)
        return size
    
    def top(self):
        top_obj = None
        if self.empty() == 1:
            top_obj = -1
        else:
            top_obj = self.stack[-1]
        return top_obj
    
    def empty(self):
        is_empty = 0
        if len(self.stack) == 0:
            is_empty = 1
        return is_empty
    
import sys
    
N = int(input())
s = Stack()
for i in range(N):
    order = sys.stdin.readline().strip() # strip으로 개행문자 제거
    ls = order.split()
    if ls[0] == "push":
        s.push(ls[1])
    elif ls[0] == "pop":
        ch = s.pop()
        print(ch)
    elif ls[0] == "size":
        ch = s.size()
        print(ch)
    elif ls[0] == "empty":
        ch = s.empty()
        print(ch)
    elif ls[0] == "top":
        ch = s.top()
        print(ch)