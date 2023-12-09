import sys

class Queue():
    def __init__(self):
        self.queue = []
    
    def push(self, data):
        self.queue.append(data)

    def pop(self):
        pop_obj = None
        if self.empty() == 1:
            pop_obj == -1
        else:
            pop_obj = self.queue.pop()
        return pop_obj
    
    def size(self):
        return len(self.queue)
    
    def empty(self):
        is_empty = None
        if len(self.queue) == 0:
            is_empty = 1
        else:
            is_empty = 0
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
    
q = Queue()

N = int(sys.stdin.readline())

for i in range(N):
    order = sys.stdin.readline().strip()
    ch = order.split()
    