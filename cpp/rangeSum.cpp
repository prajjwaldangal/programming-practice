#include <math.h>
#include <vector>
using namespace std;
class NumArray {
private:
    int sqr;
    int * arr;
    vector <int> myNums;
public:
    NumArray(vector<int>& nums) {
        sqr = (int) sqrt((double) nums.size());
        
        arr = (int *) malloc(sizeof(int) * (sqr+1));
        int lim = sqr+1;
        for (int i = 0; i < lim; ++i) {
            arr[i] = 0;
        }
        size_t l = nums.size(); 
        for (int i = 0; i < l; ++i) {
            arr[i / sqr] += nums[i];
        }
        for (int i =0; i < l; i++) {
            myNums.push_back(nums[i]);
        }
    }
    
    void update(int index, int val) {
        int diff = myNums[index] - val;
        myNums[index] = val;
        arr[index / sqr] += diff;
    }
    
    int sumRange(int left, int right) {
        int s = 0;
        for (int i = left; i <= right; ++i) {
            s += myNums[i];
        }
        return s;
    }
};
int main() { 
	vector <int> nums = {1,3,5};
	NumArray * obj = new NumArray(nums);
	obj->update(0, 2);
	int param_2 = obj->sumRange(0, 2);
	return 0; 
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */





