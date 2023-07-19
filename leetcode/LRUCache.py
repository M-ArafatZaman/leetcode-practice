# https://leetcode.com/problems/lru-cache/description/
# @ Arafat

# Node of a linked list
class Node:
    def __init__(self, key: int, val: int, next=None, prev=None):
        self.key = key
        self.val = val
        self.next = next
        self.prev = prev
    
    def __repr__(self):
        return f"{self.key}:{self.val}"

class LRUCache:

    def __init__(self, capacity: int):
        self.key = None
        self.size = 0
        self.CAP = capacity
        self.map = {} # key, Node
        self.end = None

    def get(self, key: int) -> int:
        if key in self.map:
            
            # Prioritize key
            self.prioritize(key)

            return self.map[key].val
        else: 
            return -1

    def put(self, key: int, value: int) -> None:
        # First put
        if self.key == None:
            self.key = Node(key, value)
            self.map[key] = self.key
            self.end = self.key
            self.size += 1
        # Add new node
        elif self.size < self.CAP and key not in self.map:
            self.end.next = Node(key, value)
            self.end.next.prev = self.end
            self.end = self.end.next
            self.map[key] = self.end
            self.size += 1
        # Key already exists
        elif key in self.map:
            # Prioritize key
            _node = self.map[key]
            _node.val = value
            self.prioritize(key)    
        # Cache size maxed out (difficult part)
        else:
            print(key, "needs to be pushed...")
            print(self.key)
            self.end.next = Node(key, value)
            self.end.next.prev = self.end
            self.end = self.end.next
            self.map[key] = self.end
            key = self.key.key
            del self.map[key]
            self.key = self.key.next

    def prioritize(self, key: int):
        _node = self.map[key]
        if not _node.next: return
        _next = _node.next
        _prev = _node.prev
        if _prev:
            _prev.next = _next
        _node.prev = _next
        _node.next = _next.next
        _next.prev = _prev
        _next.next = _node
        # Reorder head
        if self.key.prev:
            self.key = self.key.prev


# Your LRUCache object will be instantiated and called as such:
if __name__ == "__main__":
    x = LRUCache(2)
    x.put(1,1)
    x.put(2,2)
    print(x.get(1))
    x.put(3,3)
    print(x.map)
    print(x.get(2))
    print(x.map)
    x.put(4,4)
    print(x.map)
    
    print(x.get(1))
    print(x.get(3))
    print(x.get(4))

