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

/*The idea is that given two nodes, A and B, in a tree, we want to find
the common ancestor of A and B such that the height of it is the biggest
as possible */

#define MAXN 100 //the number of nodes in the tree (can be defined dynamically)

int logN; //the log base 2 of the number of nodes in the tree
int ancestor[MAXN][logN]; //matrix used in the dp
int height[MAXN]; //to store the height of each node in the tree


void dfs(int s) {
	for(int i = 1; i <= logN; i++)
		ancestor[s][i] = ancestor[ancestor[s][i-1]][i-1];

	//because it is a tree, we don't need to check if a node has been visited before,
	//just be careful with biderectional edges!
	for(auto it: adj[s]){
		height[it] = height[s] + 1;
		ancestor[it][0] = s; //mark the parent;
		// if you want to know the lenght of the path here it may be useful to have an array like acc[it] = acc[s] + it.weight ;)
		dfs(it);		 
	}
}

int lca(int a, int b){
	if(height[a] < height[b]) swap(a,b); //always make sure a is deeper than b
	
	//greedly put them in the same level
	for(int i = logN; i >= 0; i--)
		if(height[a] - (1 << i) >= height[b])
			a = ancestor[a][i];

	if(a == b) return a; //if they are the same node than one was the ancestor of the other

	//take both up in the tree until they are one before their lca
	for(int i = logN; i >= 0; i--)
		if(ancestor[a][i] != ancestor[b][i]){
			a = ancestor[a][i];
			b = ancestor[b][i];
		}

	return ancestor[a][0];
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//read input and put it in a adj list or something like that

	ancestor[0][0] = 0;
	dfs(0); //perform dfs to get height of each node and parent, also the dp

	return 0;
}
