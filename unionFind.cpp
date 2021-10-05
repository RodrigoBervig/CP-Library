#include <bits/stdc++.h>

using namespace std;

#define MAX 10

#define MAX 100003

int n, k;
int link[MAX];
int sizes[MAX];

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

int main() {

	for(int i = 0; i < MAX; i++)
		link[i] = i;

	//remember to set size of each i to 0 (doing that in the directives)

	return 0;
}