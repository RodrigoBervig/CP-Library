int n; // the length of our array
int logs[MAXN]; // logs[i] means such maximum p that 2^p <= i

void computeLogs() {
	logs[1] = 0;
	for(int i = 2; i <= n; i++)
		logs[i] = logs[i/2] + 1;
}

// table[i][j] means the minimum in the range of 2^i starting from position j

// table[i][j] = min(table[i-1][j], table[i-1][j+2^(i-1)])
// i.e table[2][3] = min(table[1][3], table[1][5])

const int MAXN = 105000;
const int MAXLOG = 20;

int n;
int a[MAXN];
int table[MAXN][MAXLOG];

void buildSparseTable() {
	for(int i = 0; i <= logs[n]; i++){
		int currLen = 1 << i; // 2^i
		for(int j = 0; j + currLen <= n; j++){
			if(currLen == 1)
				table[i][j] = a[i];
			else {
				table[i][j] = min(table[i-1][j], table[i-1][j + currLen/2]);
			}
		}
	}
}

//complexity for building the sparse table -> we have N elements and for each
//element we have at max log2(N) levels, therefore O(N.log2(N))

int getMin(int l, int r){
	int p = logs(r - l + 1);
	int len = 1 << p;
	return min(table[p][l], table[p][r - len + 1]);
}