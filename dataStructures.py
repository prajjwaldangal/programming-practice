import math
from collections import deque

# A queue data structure is useful for First In First Out (FIFO) behavior. It is 
# essentially a list with a FIFO order. It consists of 
# methods:
#       enqueue which puts items into the rear of the queue,
#       dequeue which removes items from the front of the queue
#       makeEmpty which clears the queue, resulting in an empty queue
#       isFull which returns True if there are as many items in the queue
#               as its capacity, otherwise it returns False
#       isEmpty which retuns True if there is no item in the queue
#               otherwise it returns False

# A variation of queue is the priority queue data structure. In a priority queue
# items that have higher priorities are released from the queue before items with
# lower priorities.
class Queue(object):
    def __init__(self, capacity):
        self.capacity = capacity
        self.currInd = -1
        self.queue = deque()

    def makeEmpty(self):
        self.deque.clear()

    def isFull(self):
        return self.currInd == self.capacity -1

    def isEmpty(self):
        return self.currInd == -1

    def enqueue(self, val):
        if self.isFull():
            print("Queue is full, returning")
            return
        self.queue.append(val)
        self.currInd += 1

    def dequeue(self):
        if self.isEmpty():
            print("Queue is empty, returning")
            return
        j = self.queue.popleft()
        self.currInd -= 1
        return j

    def printQueue(self):
        print(self.queue)

def runQueue():
    q = Queue(4)
    q.enqueue(0)
    q.enqueue(1)
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)
    q.enqueue(5)

    q.printQueue()
    print(q.dequeue())
    print(q.dequeue())
    print(q.dequeue())
    q.printQueue()

"""
A stack data structure mimics Last In First Out (LIFO) behavior.
"""
class Stack(object):

    def __init__(self, capacity):
        self.capacity = capacity
        self._stack = [''] * self.capacity
        self.currInd = -1

    def isEmpty(self):
        return self.currInd == -1

    def isFull(self):
        return self.currInd == self.capacity-1

    def makeEmpty(self):
        for i in range(self.capacity):
            self._stack[i] = ''

    def push(self, val):
        if self.isFull():
            print("stack full, returning")
            return

        self._stack[self.currInd+1] = val
        self.currInd += 1

    def top(self):
        if self.isEmpty():
            print("stack empty, nothing to return")
            return
        return self._stack[self.currInd]

    def pop(self):
        if self.isEmpty():
            print("stack empty")
            return

        j = self._stack[self.currInd]
        self._stack[self.currInd] = ''
        self.currInd -= 1
        return j

    def printStack(self):
        print(self._stack)

def runStack():
    s = Stack(4)
    s.push(12)
    s.push(3)
    s.printStack()
    print("stack's top is: ", s.top())
    s.pop()
    print("after popping: ")
    s.printStack()
    print("s.pop() returns ", s.pop())
    print("######################")

class minHeap(object):

    def __init__(self, capacity):
        self.capacity = capacity
        self.Heap = [''] * capacity
        self.currInd = -1

    def swap(self, ls, i1, i2):
        tmp = ls[i1]
        ls[i1] = ls[i2]
        ls[i2] = tmp

    def getParentIndex(self, indx):
        return math.ceil(indx / 2) - 1

    def getLeftChildIndex(self, indx):
        return 2 * indx + 1

    def getRightChildIndex(self, indx):
        return 2 * indx + 2

    def hasLeftChild(self, indx):
        return not self.Heap[self.getLeftChildIndex(indx)] == ''

    def hasRightChild(self, indx):
        return not self.Heap[self.getRightChildIndex(indx)] == ''

    def leftChild(self, indx):
        return self.Heap[self.getLeftChildIndex(indx)]

    def rightChild(self, indx):
        return self.Heap[self.getRightChildIndex(indx)]

    def heapifyDown(self, currI):
        if currI == self.currInd: return
        # make sure parent is smaller than the smaller of its children
        if self.hasLeftChild(currI):
            if self.hasRightChild(currI) and self.leftChild(currI) > self.rightChild(currI):
                smallChildI = self.getRightChildIndex(currI)
            else:
                smallChildI = self.getLeftChildIndex(currI)
            # repeat until the deepest level
            if self.Heap[smallChildI] < self.Heap[currI]:
                self.swap(self.Heap, smallChildI, currI)
                self.heapifyDown(smallChildI)


    def heapifyUp(self, currI):
        parentI = self.getParentIndex(currI)
        if currI and self.Heap[parentI] > self.Heap[currI]:
            self.swap(self.Heap, currI, parentI)
            self.heapifyUp(parentI)
        return

    def insert(self, val):
        self.ensureCapacity()
        self.Heap[(self.currInd+1)] = val
        self.currInd += 1
        # self.heapifyUp(self.currInd)

    def remove(self, val):
        if self.Heap == []: return
        def _remove(indx):

            self.Heap[indx] = self.Heap[self.currInd]
            self.Heap[self.currInd] = ''
            self.currInd -= 1
            self.heapifyDown(indx)
        # search
        for i, el in enumerate(self.Heap):
            if el == val:
                break
        # remove
        _remove(i)

    def heapSort(self):
        # 1 create another heap
        newHeap  = [''] * self.currInd
        # 2 take an item from unsorted heap and insert into new heap
        

        # 3 repeat (2) for all the elements in the unsorted heap
        # the resulting heap is sorted


    def ensureCapacity(self):
        if (self.currInd + 1) == self.capacity:
            tmp = self.Heap
            self.capacity *= 2
            self.Heap = [''] * self.capacity
            for i, ele in enumerate(tmp):
                self.Heap[i] = ele


def runMinHeap():
    H = minHeap(6)

    H.insert(9)
    print(H.Heap)
    H.insert(6)
    print(H.Heap)
    H.insert(4)
    print(H.Heap)
    H.insert(12)
    H.insert(11)
    H.insert(13)
    print(H.Heap)
    # H.remove(4)
    print(H.Heap)

def main():
    # runQueue()
    #runStack()
    runMinHeap()
main()
