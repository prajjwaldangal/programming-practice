class Solution:
    def minAbsoluteSumDiff(self, nums1, nums2) -> int:
        sumDiff = 0
        n = len(nums1)
        ls = []
        def findDiff(nums1, nums2):
            s  = 0
            for i in range(n):
                s += abs(nums1[i]-nums2[i])
            return s
    
        newNums1 = []

        for i in range(n):
            # replace 0, with 0, 1, 2 .. element
            # replace 1, with 0,    2, .. element
            # replace 
            newNums1 = nums1.copy()
            for j in range(n):
                newNums1[i] = newNums1[j]
                ls.append(findDiff(newNums1, nums2))
        
        sumDiff = min(ls) 
        return sumDiff % 1000000007


