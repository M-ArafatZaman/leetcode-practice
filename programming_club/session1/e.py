class Node:
    def __init__(self, k=0, parent=None, left=None, right=None):
        self.k = k
        self.parent = parent
        self.right = right
        self.left = left

class BST:
    def __init__(self) -> None:
        self._root = None

    def _search(self, n, k):
        if n.k == k:
            return n
        
        elif k < n.k and n.left:
            return self._search(n.left, k)
        
        elif k > n.k and n.right:
            return self._search(n.right, k)
        
        return n
    
    def search(self, k):
        return self._search(self._root, k)
    
    def insert(self, k):
        if self._root == None:
            self._root = Node(k=k)
            return
        else:
            n = self.search(k)

            while n.k == k and n.right:
                # Already exists
                n = self._search(n.right, k)

            if k < n.k: 
                new = Node(k=k, parent=n)
                n.left = new

            if k >= n.k:
                new = Node(k=k, parent=n)
                n.right = new

            return

max_fact = 1
fact = {0: 1, 1: 1}
def factorial(n):
    global max_fact
    if n in fact:
        return fact[n]

    curr = fact[max_fact]
    for i in range(max_fact + 1, n+1):
        curr *= i
        fact[i] = curr
    
    max_fact = n
    return fact[n]

def getPermAndCount(node) -> tuple[int, int]:
    # returns [perm, count]
    if not node.left and not node.right:
        return 1, 1
    
    elif node.left and not node.right:
        perm, count = getPermAndCount(node.left)
        return perm, count + 1
    
    elif not node.left and node.right:
        perm, count = getPermAndCount(node.right)
        return perm, count + 1
    
    else:
        l_perm, l_count = getPermAndCount(node.left)
        r_perm, r_count = getPermAndCount(node.right)

        this_perm = int(factorial(l_count + r_count)/(factorial(min(l_count, r_count) * factorial((l_count+r_count) - min(l_count, r_count)))))
        this_perm *= l_perm * r_perm
        return this_perm, l_count + r_count + 1

out = []
while True:
    n = int(input())
    if n == 0:
        break

    l = [int(i) for i in input().split()] 
    tree = BST()
    for i in l:
        tree.insert(i)

    out.append(getPermAndCount(tree._root)[0])



for i in out:
    print(i)


"""
5
3 4 3 5 4
7
3 4 3 5 4 1 2
31
16 8 24 4 12 20 28 2 6 10 14 18 22 26 30 1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31
0
"""




