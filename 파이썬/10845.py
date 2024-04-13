import sys

class Queue():
    def __init__(self):
        self.queue = []
        
    def push(self, data):
        self.queue.append(data)
            
    def pop(self):
        pop_obj = None
        if self.empty() == 1:
            pop_obj = -1
        else:
            pop_obj = self.queue[0]
            self.queue = self.queue[1:]
        return pop_obj
    
    def size(self):
        size = len(self.queue)
        return size
    
    def empty(self):
        is_empty = 0
        if len(self.queue) == 0:
            is_empty = 1
        return is_empty
    
    def front(self):
        front_obj = None
        if self.empty() == 1:
            front_obj = -1
        else:
            front_obj = self.queue[0]
        return front_obj
    
    def back(self):
        back_obj = None
        if self.empty() == 1:
            back_obj = -1
        else:
            back_obj = self.queue[-1]
        return back_obj
    
queue = Queue()

N = int(sys.stdin.readline())

for i in range(N):
    order = sys.stdin.readline().strip()
    ch = order.split()
    if ch[0] == 'push':
        queue.push(ch[1])
    elif ch[0] == 'pop':
        print(queue.pop())
    elif ch[0] == 'size':
        print(queue.size())
    elif ch[0] == 'empty':
        print(queue.empty())
    elif ch[0] == 'front':
        print(queue.front())
    else:
        print(queue.back())