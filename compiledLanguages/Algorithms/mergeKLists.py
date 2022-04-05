class Solution:
    
    def mergeKLists(self, lists):
        c = 0
        for ls in lists:
            for _ in ls:
                c += 1
        ret_list = [10**5] * c
        
        for ls in lists:
            
            tmp_list = [10**5] * c
            i = j = 0
            k = 0
            while i < len(ls):
                if ls[i] <= ret_list[j]:
                    tmp_list[k] = ls[i]
                    i += 1
                else:
                    tmp_list[k] = ret_list[j]
                    j += 1
                k += 1
            ret_list = tmp_list[:k+1] + ret_list[k::]
        return ret_list

s = Solution()
ls_of_ls = [[1,4,6,10], [0, 3, 9], [1], [11], [-1]]
print(s.mergeKLists(ls_of_ls))