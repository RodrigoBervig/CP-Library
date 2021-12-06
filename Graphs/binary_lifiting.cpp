//given a tree of size N, answer Q queries: given v and k, find the k-th ancestor of v.
//if done trivialy O(Q*N), the goal is to have O(Q * log(N))	

// How to improve from O(N) to O(log(N)) -> either divide by two(bs, d&c) or use powers
// o  f two (segment_trees, binary_lifting, sparse_tables)
#include <bits/stdc++.h>

using namespace std;

class TreeAncestor {
	vector<vector<int>> up;
	int LOG;

public:
	TreeAncestor(int n, vector<int> &parent) {
		LOG = 0;
		while((1 << (LOG + 1)) <= n){
			LOG++;
		}

		up = vector<vector<int>>(n, vector<int>(LOG));
		//up[v][j] is 2^j -th ancestor of node v
		parent[0] = 0;

		for(int v = 0; v < n; v++) {
			up[v][0] = parent[v];
			for(int j = 1; j < LOG; j++) {
				up[v][j] = up[ up[v][j-1] ][j-1];
			}
		}
	}

	int getKthAncestor(int node, int k) {

		return 0;
	}
};