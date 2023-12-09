import sys

class Deque():
    def __init__(self):
        self.deque = []
    def push_front(self, data):
        self.deque.insert(0, data)
    def push_back(self, data):
        self.deque.append(data)
    def pop_front(self):
        pop_obj = None
        if self.empty() == 1:
            pop_obj = -1
        else:
            pop_obj = self.deque.pop(0)
        return pop_obj
    def pop_back(self):
        pop_obj = None
        if self.empty() == 1:
            pop_obj = -1
        else:
            pop_obj = self.deque.pop()
        return pop_obj
    def size(self):
        return len(self.deque)
    def empty(self):
        is_Empty = 0
        if len(self.deque) == 0:
            is_Empty = 1
        return is_Empty
    def front(self):
        front_obj = None
        if self.empty() == 1:
            front_obj = -1
        else:
            front_obj = self.deque[0]
        return front_obj
    def back(self):
        back_obj = None 
        if self.empty() == 1:
            back_obj = -1
        else:
            back_obj = self.deque[-1]
        return back_obj

N = int(sys.stdin.readline())
d = Deque()

for i in range(N):
    order = sys.stdin.readline().strip()
    ls = order.split()
    
    if ls[0] == "push_front":
        d.push_front(ls[1])
    elif ls[0] == "push_back":
        d.push_back(ls[1])
    elif ls[0] == "pop_front":
        print(d.pop_front())
    elif ls[0] == "pop_back":
        print(d.pop_back())
    elif ls[0] == "size":
        print(d.size())
    elif ls[0] == "empty":
        print(d.empty())
    elif ls[0] == "front":
        print(d.front())
    elif ls[0] == "back":
        print(d.back())