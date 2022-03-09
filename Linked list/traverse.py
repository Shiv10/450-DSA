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

    def displayRecursion(self, p=None):
        if p==None:
            return

        print(p.data)
        self.displayRecursion(p.next)

    def displayRecursionReverse(self, p = None):
        if p.next==None:
            print(p.data)
            return

        self.displayRecursionReverse(p.next)
        print(p.data)

        

linkedList = LinkedList()
linkedList.push(4)
linkedList.push(3)
linkedList.push(2)
linkedList.push(1)
# linkedList.display(linkedList.head)
# linkedList.displayRecursion(linkedList.head)
linkedList.displayRecursionReverse(linkedList.head)