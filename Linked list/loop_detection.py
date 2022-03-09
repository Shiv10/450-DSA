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

    def detectLoop(self, head):
            slow = head
            fast = head
            while(slow and fast and fast.next):
                slow = slow.next
                fast = fast.next.next
                if slow == fast:
                    return True
                   
            return False
        


        

linkedList = LinkedList()
linkedList.push(8)
linkedList.push(7)
linkedList.push(6)
linkedList.push(5)
linkedList.push(4)
linkedList.push(3)
linkedList.push(2)
linkedList.push(1)