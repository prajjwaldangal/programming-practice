class QuickSort:
    def __init__(self, arr=None):
        self.arr = arr
        self.l = len(self.arr)
    
    def partition(self, low, high, arr):
        pivot = arr[low]
        i = low
        for j in range(low + 1, high):
            if arr[j] <= pivot:
                i += 1
                tmp = arr[j]
                arr[j] = arr[i]
                arr[i] = tmp
        # print("before last swap: ", arr)
        tmp = arr[i]
        arr[i] = arr[low]
        arr[low] = tmp
        # print("after last swap: ", arr)
        return i

    def _sort(self, low, high, arr):
        if low < high:
            q = self.partition(low, high, self.arr)
            self._sort(low, q, self.arr)
            self._sort(q+1, high, self.arr)

    def sort(self):
        self._sort(0, len(self.arr), self.arr)

class MergeSort:
    def __init__(self, arr=None):
        self.arr = arr
        self.l = len(arr)
        self.ret_array = None

    def merge(self, low, middle, high):
        i = low
        j = middle
        r = low
        while (i < middle and j < high):
            if self.arr[i] <= self.arr[j]:
                self.ret_arr[r] = self.arr[i]
                i += 1
            else:
                self.ret_arr[r] = self.arr[j]
                j += 1
            r += 1
        while (i < middle):
            self.ret_arr[r] = self.arr[i]
            r += 1
        while (j < high):
            self.ret_arr[r] = self.arr[j]
            j += 1

    def _sort(self, low, high):
        # print("low: {}, high:{}".format(low, high))
        if low < high: 
            middle = low + (high - low) // 2
            print("middle: ", middle)
            self._sort(low, middle)
            self._sort(middle, high)
            self.merge(low, middle, high)

    def sort(self):
        self.ret_array = self.arr.copy()
        self._sort(0, self.l)

    def print_it(self):
        print(self.arr)

class HeapSort:
    def __init__(self):
        pass




