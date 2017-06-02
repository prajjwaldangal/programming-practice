/*
	1 km = 1 l
	capacity = 200 l

*/

// Problem: adventures_in_moving_IV 
// Website: kattis

#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>

int main() {
	std::string s("Some'where down the road");
    std::istringstream iss(s);
    std::string out_str;
    char delim = ' ';
    std::getline(iss, out_str, delim);
    std::cout << out_str << std::endl; // outputs Some'where
    
    std::istringstream iss2(out_str);
    delim = '\'';
    std::getline(iss2, out_str, delim);
    std::cout << out_str << std::endl; // outputs Some

	return 0;
}