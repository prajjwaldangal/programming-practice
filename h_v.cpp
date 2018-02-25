#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int n, m;
	cin >> n;
	cin >> m;
	int arr[n][n];
	map <string, bool> seen;
	for (int i = 0; i<m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		int sx = x;
		int sy = y;
		int ex = x;
		int ey = y;
		seen.clear();
		while (w > 0) {
			if (sx < 0)
				sx = 0;
			if (ex > n-1)
				ex = n-1;
			if (sy < 0)
				sy = 0;
			if (ey > n-1)
				ey = n-1;
			int j = sx;
			while ( j <= ex ) {
				int k = sy;
				while (k<=ey) {
					map<string,bool>::iterator it;
					string key = to_string(j);
					key = key + to_string(k);
					it = seen.find(key);
					if (it == seen.end()) {
						arr[j][k] += w;
						seen[key] = true;
					}
					k ++;
				}
				j ++;
				w -= 1;
				sx -= 1;
				sy -= 1;
				ex += 1;
				ey += 1;
			}
		}
	}
    int max = 0;
    for (int i=0; i<n; i++) {
    	for (int j = 0; j <n; j++) {
    		if (arr[i][j] > max) {
    			max = arr[i][j];
    		}
    	}
    }
    cout << max << endl;
    return 0;
}
