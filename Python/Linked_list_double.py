#creating a node
class Node:
    def __init__(self, data):
        self.data = data #data
        self.prev = None #previous node
        self.next = None #next node

# creating a Double Linked List
class LinkedListDouble:
    def __init__(self):
        self.head = None
        self.tail = None
