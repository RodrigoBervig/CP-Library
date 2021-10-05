	#include <bits/stdc++.h>

using namespace std;
#define MAX 10
typedef pair<int, int> pii;

pii edges[MAX];
int sizes[MAX]; //change
int link[MAX]; //change

int find(int x) {
	while(x != link[x])
		x = link[x];
	return x;
}

bool same(int a, int b) {
	return find(a) == find(b);
}

void join(int a, int b) {
	a = find(a);
	b = find(b);

	if(sizes[b] < sizes[a])
		swap(a,b);

	sizes[b] += sizes[a];
	link[a] = b;
}

/*Algorithm to find the minimum spanning tree, the idea is to greedily choose 
always the edge with the minimum weight if and only if the nodes are not in 
the same component already*/
void kruskal() {
	//you can break if N (number of nodes) edges have been joined also.
	for(int i = 0; i < MAX; i++){
		int a = edges[i].first;
		int b = edges[i].second;
		
		if(!same(a,b)) 
			join(a, b);
	}
}

int main() {

}