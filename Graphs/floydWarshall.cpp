//find the distance of every node to every other node
//complexity: O(n^3)

// be careful with not using T_MAX for default values in dist matrix, since it can overflow 
int n;
const int MAXN = 450; //less than this and you can use something like N dijkstras
int dist[MAXN][MAXN];

void floydWarshall(){
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

//to check if a negative cycle exists, check the diagonal and see if there is a negative value
