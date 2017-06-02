#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

// make read_2d function

// make print_list function

int FILT [3][3] = {
	{1, 1, 1},
	{0, 1, 0},
	{1, 1, 1}
};

int main () {
	std::vector < std::vector <int> > arr;
	// char arr [6][6];
	std::string line;
	for (int i=0; i<6; i++) {
		std::getline(std::cin, line);
		std::istringstream is(line);
		arr.push_back(
			std::vector<int> (
				std::istream_iterator <int> (is),
				std::istream_iterator <int>() )
		);
	}
	int m = -63, temp = 0;
	for (int i=1; i<5; i++) {
		for (int j=1; j<5; j++) {
			temp = FILT[0][0] * arr[i-1][j-1] + FILT[0][1] * arr[i-1][j] + FILT[0][2] * arr[i-1][j+1] +
				   FILT[1][0] * arr[i][j-1]   + FILT[1][1] * arr[i][j]   + FILT[1][2] * arr[i][j+1] +
				   FILT[2][0] * arr[i+1][j-1] + FILT[2][1] * arr[i+1][j] + FILT[2][2] * arr[i+1][j+1];
			if (temp > m)
				m = temp;
		}
	}
	std::cout << "The max hourglass value is: " << m << std::endl;
	return 0;
}