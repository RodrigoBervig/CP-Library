/**
*	author:     Bervig
**/

#include <bits/stdc++.h>

using namespace std;

#define dbg(x) { cerr << #x << " = " << x << "\n"; } 
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;

//algo to find the distance of every node to every other node
//complexity: O(n^3)

int dist[MAXN][MAXN];

void floydWarschal(){
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= j++)
				dist[i][j] = min(dist[i][j], dist[k][i] + dist[k][j]);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	return 0;
}
