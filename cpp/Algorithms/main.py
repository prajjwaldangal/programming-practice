import sorting

tests = [[], [1], [1,1], [10, 1000, 100000000000], \
    [10**20, 10**20+1, 10**20-1], [4,5,7,1,23,57,213,-12], \
        [3, 0, 1, 5, 4, 7, -1], [-4.0, -5, 8, 0]]

for test in tests:
    print("unsorted list: ", test)
    q = sorting.QuickSort(test)
    q.sort()
    print("sorted list: ", q.arr)
    print()