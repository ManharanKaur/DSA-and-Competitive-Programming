class Node:
    def __init__(self, data):
        self.data = data  # Initialize data to put in the node
        self.next = None  # Pointer to the next node, initially None

class LinkedList:
    def __init__(self, arr = None):
        self.head = None  # Initialize head to None
        if arr:  # If an array is provided, create the linked list
            self.head = Node(arr[0])  # Set the first element of the array to head
            temp = self.head  # For now, temporary variable temp is pointing to arr[0]
            for i in range(1, len(arr)):
                temp.next = Node(arr[i])  # arr[0]'s next points to arr[1]
                temp = temp.next  # Move temp to arr[1]

    #Traversal
    def display(self):
        temp = self.head
        while temp is not None:
            print(temp.data, end=" ")  # Print the data of each node
            temp = temp.next  # Move to the next node
        print()  # Newline after the linked list is displayed

arr = [2, 3, 1, 1, 7, 0, 1, 9]
ll = LinkedList(arr)
ll.display()  # Output: 2 3 1 1 7 0 1 9
