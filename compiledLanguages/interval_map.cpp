#include <map>
#include <ostream>
#include <iostream>
template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val) {}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
if (!(keyBegin < keyEnd))
	return;

// use binary search to find keyBegin O(logN)
auto iter = m_map.lower_bound(keyBegin);

m_map.insert(std::pair<K, V> (iter->first, val));
// next need to remove the succeeding elements upto and not including
// keyEnd. 
while (iter != m_map.end()) 
{
	if (iter->first < keyEnd) 
	{
		iter = m_map.erase(iter);
	} else 
	{
		++iter;
	}
}
		}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}

	void printMap() {
		for (auto it = m_map.begin(); it != m_map.end(); ++it) {
			std::cout << "key: " << it->first << " " << "val: " << it->second << std::endl;
		}
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.
int main() {
	class myKeyClass {
	 	int num;
		public:
			// default constructor
			myKeyClass(int num) {
				num = num;
			}

			// copy constructor
			myKeyClass(const myKeyClass & copy) {
				num = copy.num;
			}

			// assignment overloading
			myKeyClass operator = (const myKeyClass& key2) {
				num = key2.num;
				return * this;
			}

			// operator < overloading
			bool operator <(const myKeyClass& key2) {
				if (num < key2.num) {
					return true;
				}
				return false;
			}
			
	};

	class myValueClass {
		char letter;
		public:
			// default constructor
			myValueClass(char letter) {
				letter = letter;
			}

			// copy constructor
			myValueClass(const myValueClass & copy) {
				letter = copy.letter;
			}

			// assignment overloading
			myValueClass operator = (const myValueClass & val2) {
				letter = val2.letter;
				return *this;
			}

			// operator == overloading
			bool operator== (const myValueClass& val2) {
				if (letter == val2.letter)
						return true;
				return false; 
			}

	};

	interval_map<int, char> my_interval_map((char)'A');
	my_interval_map.assign(1, 3, 'B');
	my_interval_map.printMap();
	return 0;
}