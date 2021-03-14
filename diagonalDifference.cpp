#include <iostream>
#include <algorithm>    // std::sort
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;
int diagonalDifference(std::vector<std::vector<int> > arr) {
    if (arr.size() < 1 || arr[0].size() < 1)
        return 0;
        
    size_t i = 0;
    size_t j = 0; 
    int mainDiagSum = 0;
    int secondaryDiagSum = 0;
    size_t count = 0;
    while (count < arr.size()) {
        mainDiagSum += arr[i][j];
        secondaryDiagSum += arr[i][arr[0].size()-1-j];
        i += 1;
        j += 1;
        count += 1;
        std::cout << mainDiagSum << " " << secondaryDiagSum << " " << std::endl;
    }
    int diff = abs(mainDiagSum - secondaryDiagSum);
    std::cout << diff << " " << mainDiagSum << " " << secondaryDiagSum << " " << std::endl;
    return diff;
}

void plusMinus(std::vector<int> arr) {
    int nPos = 0, nNeg = 0, nZeros = 0;
    for (int i=0; i < arr.size(); i++) {
        if (arr[i] == 0)
            nZeros += 1;
        else if (arr[i] > 0)
            nPos += 1;
        else
            nNeg += 1;
    }
    float ratioPos = ((float) nPos) / float(arr.size());
    float ratioNeg = ((float) nNeg) / float(arr.size());
    float ratioZeros = ((float) nZeros) / float(arr.size());
    std::cout << std::setprecision(6) << std::fixed;
    std::cout << ratioPos << std::endl;
    std::cout << ratioNeg << std::endl;
    std::cout << ratioZeros << std::endl;
}

void staircase(int n) {
    int height = 0;
    int width = 0;
    while (height < n) {
        while (width < n) {
            if (width < n-1-height) {
		
            	cout << " ";
	    } else {
		cout << "#";
	    } 
            width += 1;
        }
	cout << "\n";
	width = 0;
	height += 1;
    }
}

// Function to slice a given vector 
// from range X to Y 
vector<int> slicing(vector<int>& arr, 
                    int X, int Y) 
{ 
  
    // Starting and Ending iterators 
    auto start = arr.begin() + X; 
    auto end = arr.begin() + Y + 1; 
  
    // To store the sliced vector 
    vector<int> result(Y - X + 1); 
  
    // Copy vector using copy function() 
    copy(start, end, result.begin()); 
  
    // Return the final sliced vector 
    return result; 
} 

// Complete the miniMaxSum function below.
void miniMaxSum(vector<int> arr) {
	// apply heapsort to sort the array
	make_heap(arr.begin(), arr.end());
	sort_heap(arr.begin(), arr.end());
	// take first four
	vector <int>  mimum = slicing(arr, 0, 3);
	vector <int>  mamum = slicing(arr, 1, 4);
	cout << mimum << " " << mamum << endl;	
}

int main() {
	std::vector <std::vector <int> > arr {
		{11, 2, 4},
		{4,  5, 6},
		{10, 8, -12}
	};
	// diagonalDifference(arr);
	std::vector <int> arr2 {-4, 3, -9, 0, 4, 1};
	// plusMinus(arr2)
	// staircase(6);
	vector <int> arr3 {7, 69, 2, 221, 8974};	
	miniMaxSum(arr3);
}
