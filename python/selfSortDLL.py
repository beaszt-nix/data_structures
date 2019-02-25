#!/usr/bin/python3

import time
class node:
    def __init__(self, val=None):
        self.val = val
        self.prev = None
        self.next = None
class dll:
    def __init__(self):
        self.root = None
        self.tail = self.root
    def insert(self,val):
        if self.root is None:
            self.root = node(val)
            self.tail = self.root
            return
        fwd = self.root
        while fwd is not None:
            if fwd.val < val:
                fwd = fwd.next
                continue
            else:
                break
        if fwd is self.head:
            self.head.prev = node(val)
            self.head.prev.next = self.head
            self.head = self.head.next
            return
        if fwd is None:
            tail.next = node(val)
            tail.next.prev = tail
            tail = tail.next
            return
        new = node(val)
        new.next = fwd
        new.prev = fwd.prev
        fwd.prev = new
        new.prev.next = new
    
    def find(self, val):
        fwd = self.root
        bwd = self.tail
        if fwd.val == val:
            return fwd
        elif bwd.val == val:
            return bwd
        while fwd.prev is not bwd:
            if fwd.val == val:
                break
            if bwd.val == val:
                break
            fwd = fwd.next
            bwd = bwd.prev
        if fwd.val == val:
            return fwd
        else:
            return bwd
    
    def delete(self, val):
        delval = self.find(val)
        if delval == root:
            self.root = self.root.next
            self.root.prev=None
            del delval
            return
        if delval == tail:
            self.tail = self.tail.prev
            self.tail.next = None
            del delval
            return
        delval.prev.next = delval.next
        delval.next.prev = delval.prev
        del delval
    
    def __str__(self):
        current = self.root
        while current is not None:
            print(current.val, end=" ")
            current = current.next
        print()


