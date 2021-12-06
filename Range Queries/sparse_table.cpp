using namespace std;

typedef vector<int> vi;

//implementation for min sparse table
class SparseTable {
private:
	vi A, logs;
	vector<vi> spt;
	int N, K;

public:
	SparseTable() {}

	SparseTable(vi &initialA) {
		A = initialA;
		N = (int)A.size();
		K = (int)log2(N);
		
		logs.resize(N+1);

		logs[1] = 0;
		for(int i = 2; i <= N; i++) 
			logs[i] = logs[i/2] + 1;

		spt = vector<vi> (N+1, vector<int>(K+1));

		for(int i = 0; i < N; i++) {
			spt[i][0] = A[i];
		}

		for(int j = 1; j <= K; j++)
			for(int i = 0; i + (1 << j) <= N; i++) {
				spt[i][j] = min(spt[i][j-1], spt[i + (1 << (j-1))][j-1]);
			}
	}




	int RMQ(int l, int r) {
		int j = logs[r - l + 1];

		return min(spt[l][j], spt[r - (1 << j) + 1][j]);
	}
};