#creating a node
class Node:
    def __init__(self, data):
        self.data = data #data
        self.prev = None #previous node
        self.next = None #next node

# creating a Double Linked List
class LinkedListDouble:
    def __init__(self, arr):
        self.head = None
        self.tail = None
        if arr:  # If an array is provided, create the double linked list
            self.head = Node(arr[0])  # Set the first element of the array to head
            temp = self.head  # For now, temporary variable temp is pointing to arr[0]
            for i in range(1, len(arr)):
                newnode = Node(arr[i])
                temp.next = newnode
                newnode.prev = temp
                temp = temp.next  # Move temp to arr[1]
            self.tail = temp


    # Traversal
    def display(self):
        # forward
        print("Forward: ", end=" ")
        print("NULL: ", end=" ")









arr = [2, 3, 1, 1, 7, 0, 1, 9]
ll = LinkedListDouble(arr)