#include <bits/stdc++.h>

using namespace std;

#define dbg(x) { cerr << #x << " = " << x << "\n"; } 
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;

vi ts;
bool visited[123];
vi adj[123];

void dfs(int s) {
	visited[s] = true;

	for(auto it: adj[s]) {
		if(!visited[it])
			dfs(it);
	}

	ts.pb(s);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for(auto it = ts.end() - 1; it > ts.begin(); it--){
		cout << it << " ";
	}

	cout << "\n";
	return 0;
}
