#creating a node
class Node:
    def __init__(self, data):
        self.data = data  # Initialize data to put in the node
        self.next = None  # Pointer to the next node, initially None

#creating linked list 
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
            print(temp.data, end=" -> ")  # Print the data of each node
            temp = temp.next  # Move to the next node
        print("NULL")  # Newline after the linked list is displayed

    #Searching
    def searching(self,key):
        temp = self.head
        while temp is not None:
            if temp.data == key:
                return True
            temp = temp.next
        return False
    
    #Finding length
    def length(self):
        temp = self.head
        l = 0
        while temp is not None:
            l = l + 1
            temp = temp.next
        return l
    
    #Insertion
    def insertion_at_beginning(self,ele):
        newNode = Node(ele)
        newNode.next = self.head # New node pointing toward first element 
        self.head = newNode # head pointing to new node
    def Insertion_At_End(self,ele):
        newNode = Node(ele)
        if self.head == None: #Empty list
            self.head = newNode
            return
        temp = self.head
        while temp.next != None:
            temp = temp.next #it was null before
        temp.next = newNode
    def Insertion_At_Specific_position(self, ele, pos):
        newNode = Node(ele)
        if self.head == None: #Empty list
            self.head = newNode
            return
        if pos == 1: # insertion at head
            newNode.next =self.head
            self.head = newNode
            return
        temp = self.head
        for i in range(1,pos - 1):
            if temp == None:
                del newNode # position out of bound
                return
            temp = temp.next
        newNode.next = temp.next
        temp.next = newNode


    # Deletion
    def deletion_at_beginning(self):
        if self.head is None: # List is empty
            return # Nothing to delete
        temp = self.head 
        self.head = self.head.next # move head to next node
        del temp
    def deletion_at_end(self):
        if self.head is None:
            return 
        if self.head.next is None: # only one element
            del head
            return
        temp = self.head
        temp1 = temp.next
        while temp1.next is not None:
            temp = temp.next # 2nd last element
            temp1 = temp.next #last element
        temp.next = None # Disconnect last node
        del temp1
    def deletion_at_specific_position(self,pos):
        if self.head is None:
            return 
        if pos == 1: 
            del head
            return
        temp = self.head
        temp1 = None # keep track of previous node
        count = 1
        while (temp is not None and count < pos):
            temp1 = temp
            temp = temp.next
            count += 1
        if temp is None: # out of bound
            return
        temp1.next = temp.next
        del temp

    # Reversal
    def reversal(self):
        previous = None
        temp = self.head
        next = None
        while temp is not None:
            next = temp.next # Store next node
            temp.next = previous # Reverse current node's pointer
            previous = temp # move previous and temp one step forward
            temp = next
        self.head = previous


arr = [2, 3, 1, 1, 7, 0, 1, 9]
ll = LinkedList(arr)
ll.display()  # Output: 2 3 1 1 7 0 1 9
print("Present" if ll.searching(7) == True else "Not present")
print("Length:",ll.length())
ll.insertion_at_beginning(5)
ll.display()
ll.Insertion_At_End(7)
ll.display()
ll.Insertion_At_Specific_position(9, 5)
ll.display()
ll.deletion_at_beginning()
ll.display()
ll.deletion_at_end()
ll.display()
ll.deletion_at_specific_position(4)
ll.display()
ll.reversal()
ll.display()