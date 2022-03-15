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
    def __init__(self, arr):
        self.arr = arr
        self.l = len(arr)

    def merge(self):
        pass

    def sort(self):
        pass




