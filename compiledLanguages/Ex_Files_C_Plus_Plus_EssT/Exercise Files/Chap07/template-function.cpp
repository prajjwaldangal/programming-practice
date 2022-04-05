// template-function.cpp by Bill Weinman <http://bw.org/>
// updated 2020-07-21
#include <iostream>
#include <string>

template <typename T>
T maxof ( T a, T b ) {
    return ( a > b ? a : b );
}

int main() {
    std::cout << maxof<int>( 7, 9 ) << std::endl;
    printf("maxof<const char *> (\"apple\", \"acid\"): %s\n", \
                maxof<const char *> ("apple", "acid"));

    printf("(maxof<std::string> (\"apple\", \"acid\")).c_str(): %s\n", \
        (maxof<std::string> ("apple", "acid")).c_str());

    std::cout << "maxof<std::string> (\"apple\", \"acid\"): " \
         << maxof<std::string> ("apple", "acid") << std::endl;

    return 0;
}
