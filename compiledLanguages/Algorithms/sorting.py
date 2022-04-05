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
        self.ret_arr = []

    def merge(self, low, middle, high):
        i = low
        j = middle + 1
        r = low
        while (i <= middle and j <= high):
            if self.arr[i] <= self.arr[j]:
                self.ret_arr[r] = self.arr[i]
                i += 1
            else:
                self.ret_arr[r] = self.arr[j]
                j += 1
            r += 1
        while (i <= middle):
            self.ret_arr[r] = self.arr[i]
            r += 1
            i += 1
        while (j <= high):
            self.ret_arr[r] = self.arr[j]
            r += 1
            j += 1

    def _sort(self, low, high):
        
        if low < high: 
            middle = low + (high - low) // 2
            
            self._sort(low, middle) # (0, 3), (0, 1), (0, 0)
            self._sort(middle + 1, high) # (4, 6), ()
            self.merge(low, middle, high)
        print(self.ret_arr)
        

    def sort(self):
        self.ret_arr = self.arr.copy()
        self._sort(0, self.l-1)

    def print_it(self):
        print("sorted list: ", self.ret_arr)

class HeapSort:
    def __init__(self):
        pass


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
            self._sort(q + 1, high, self.arr)

    def sort(self):
        self._sort(0, len(self.arr), self.arr)


class MergeSort:
    def __init__(self, arr=None):
        self.arr = arr
        self.l = len(arr)
        self.ret_arr = []

    def merge(self, low, middle, high):
        i = low
        j = middle + 1
        r = low
        while i <= middle and j <= high:
            if self.ret_arr[i] >= self.ret_arr[j]:
                self.arr[r] = self.ret_arr[i]
                i += 1
            else:
                self.arr[r] = self.ret_arr[j]
                j += 1
            r += 1
        while i <= middle:
            self.arr[r] = self.ret_arr[i]
            r += 1
            i += 1
        while j <= high:
            self.arr[r] = self.ret_arr[j]
            r += 1
            j += 1
        self.ret_arr = self.arr.copy()

    def _sort(self, low, high):

        if low < high:
            middle = low + (high - low) // 2

            self._sort(low, middle)  # (0, 3), (0, 1), (0, 0)
            self._sort(middle + 1, high)  # (4, 6), ()
            self.merge(low, middle, high)
        print(self.ret_arr)

    def sort(self):
        self.ret_arr = self.arr.copy()
        self._sort(0, self.l - 1)

    def print_it(self):
        print("sorted list: ", self.ret_arr)


class HeapSort:
    def __init__(self):
        self.heap = []
        pass

    
