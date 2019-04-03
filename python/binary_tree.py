import random
class node:
    def __init__(self,val=None):
        self.val = val
        self.left = None
        self.right = None
    def insert(self,val):
        if self.val is None:
            self.val = val
            return
        if val > self.val:
            if self.right is None:
                self.right = node(val)
            else:
                self.right.insert(val)
        else:
            if self.left is None:
                self.left = node(val)
            else:
                self.left.insert(val)
    def inorder(self):
        if self.left is not None:
            self.left.inorder()
        print(self.val, end=" ")
        if self.right is not None:
            self.right.inorder()
    def lbound(self):
        current = self
        current = current.left
        while current.left is not None or current.right is not None:
            if current.right is None:
                current = current.left
            else:
                current = current.right
        return current.val
    def ubound(self):
        current = self
        current = current.right
        while current.left is not None or current.right is not None:
            if current.left is None:
                current = current.right
            else:
                current = current.left
        return current.val
    def delete(self,val):
        current = self
        pred = None
        while current is not None and current.val != val:
            pred = current
            if current.val < val:
                current = current.right
            else:
                current = current.left
        if current is None:
            return
        if pred is None:
            if current.right is None and current.left is None:
               del current
            elif current.right is None and current.left is not None:
                temp = current
                current = current.left
                del temp
            elif current.right is not None and current.left is None:
                temp = current
                current = current.right
                del temp
            else:
                current.val = current.lbound()
                current.left.delete(current.val)
 
        elif pred.right is current:
            if current.right is None and current.left is None:
               del pred.right
               pred.right = None
            elif current.right is None and current.left is not None:
                pred.right = current.left
                del current
            elif current.right is not None and current.left is None:
                pred.right = current.right
                del current
            else:
                current.val = current.lbound()
                current.left.delete(current.val)
        
        elif pred.left is current:
            if current.right is None and current.left is None:
               del pred.left
               pred.left = None
            elif current.right is None and current.left is not None:
                pred.left = current.left
                del current
            elif current.right is not None and current.left is None:
                pred.left = current.right
                del current
            else:
                current.val = current.lbound()
                current.left.delete(current.val)
    def search(self,val):
        current = self
        pred = None
        while current is not None:
            pred = current
            if current.val == val:
                break
            elif current.val < val:
                current = current.right
            else:
                current = current.left
        return pred,current
            
    def height(self):
        if self.right is None and self. left is None:
            return 1
        elif self.right is None and self.left is not None:
            return 1 + self.left.height()
        elif self.right is not None and self.left is None:
            return 1 + self.right.height()
        else:
            return 1 + max(self.right.height(), self.left.height())

def build_balance_tree(a, root):
    if len(a) == 0:
        return
    root.insert(a[len(a)//2])
    build_balance_tree(a[:len(a)//2],root)
    build_balance_tree(a[len(a)//2 + 1:],root)

if __name__ == '__main__':
    n = int(input())
    a = [random.randint(0,10000) for x in range(n)]
    root = node()
    for i in a:
        root.insert(i)
    print(root.height())
    root.inorder()
    print()
