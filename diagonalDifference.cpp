#include <iostream>
#include <vector>
#include <cmath>
int diagonalDifference(std::vector<std::vector<int> > arr) {
    if (arr.size() < 1 || arr[0].size() < 1)
        return 0;
        
    int i, j, mainDiagSum, secondaryDiagSum = 0;
    int count = 0;
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
/*
11 2 4

4 5 6

10 8 -12
*/

int main() {
	std::vector <std::vector <int> > arr {
		{11, 2, 4},
		{4,  5, 6},
		{10, 8, -12}
	};
	diagonalDifference(arr);
}
