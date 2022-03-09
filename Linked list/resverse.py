class Node:

    def __init__(self, data) -> None:
        self.data = data
        self.next = None

class LinkedList:

    def __init__(self):
        self.head = None

    def push(self, data):
        newNode = Node(data)
        newNode.next = self.head
        self.head = newNode

    def display(self, p=None):
        if p==None:
            return
        
        while(p!=None):
            print(p.data)
            p = p.next

    def reverseList(self, current):
        next = prev = None
        while(current!=None):
            next = current.next
            current.next = prev
            prev = current
            current = next

        self.head = prev

    def reverseRecursive(self, current):
        if(current.next == None):
            self.head = current
            return
        self.reverseList(current.next)
        tempNode = current.next
        tempNode.next = current
        current.next = None

    def reverseListInChunks(self, head, k):
        next = prev = None
        current = head
        c = 0
        while(current!=None and c<k):
            next = current.next
            current.next = prev
            prev = current
            current = next
            c += 1 

        if(next!=None):
            head.next = self.reverseListInChunks(next, k)
        
        return prev

        


        

linkedList = LinkedList()
linkedList.push(8)
linkedList.push(7)
linkedList.push(6)
linkedList.push(5)
linkedList.push(4)
linkedList.push(3)
linkedList.push(2)
linkedList.push(1)
# linkedList.display(linkedList.head)
# linkedList.reverseList(linkedList.head)
# linkedList.display(linkedList.head)

linkedList.head = linkedList.reverseListInChunks(linkedList.head, 2)
linkedList.display(linkedList.head)
