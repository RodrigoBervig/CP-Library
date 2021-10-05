#include <bits/stdc++.h>

using namespace std;

int binarySearch(const vector<int> v, int target){
	int low = 0;
	int high = v.size() - 1;
	int mid;
	
	while(low <= high){
		mid = low + (high - low)/2;
		if((mid == 0 || target > v[mid - 1]) && v[mid] == target){
			return mid;
		} else if (v[mid] > target ){
			high = mid - 1;
		} else low = mid + 1;
	}

	return high;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	vector<int> v1 = {123, 168, 714, 868, 987};
	cout << v1.size() << endl;
	
	int result = binarySearch(v1, 424);
	int nextBigger = binarySearch(v1, 425);
	cout << nextBigger << endl;
	cout << result << endl;

	return 0;
}
