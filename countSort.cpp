#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countSort(vector<int> &v, int max){
	vector<int> indexes(max + 1, 0);
	
	for(auto it = v.begin(); it != v.end(); it++){
		indexes[*it] += 1;
	}
	cout << endl;
	
	int i = 0;
	int pos = 0;
	for(auto it = indexes.begin(); it != indexes.end(); it++){
		while(*it > 0){
			v[pos] = i;
			pos += 1;
			*it -= 1;
		}
		i++;
	}
	cout << endl;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	vector<int> v1;
	for(int i = 0; i < 10000000; i++){
		v1.push_back(rand() % 10);
	}

	/*for(auto it = v1.begin(); it != v1.end(); it++){
		cout << *it << " ";
	}*/
	
	countSort(v1, 9);
	//sort(v1.begin(), v1.end());
	
	/*for(auto it = v1.begin(); it != v1.end(); it++){
		cout << *it << " ";
	}*/
	
	cout << endl;

	return 0;
}
