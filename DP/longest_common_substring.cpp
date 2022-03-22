int longest_common_substring(){
	string a, b;
	cin >> a >> b;

	if(b.size() > a.size()) swap(a,b);


	vector<vector<int>> dp(2, vector<int>(a.size()+1));

	dp[1][0] = 0;
	for(int j = 0; j <= (int)a.size(); j++) {
		dp[0][j] = 0;
	}

	int atual = 0;

	for(int i = 1; i <= (int)b.size(); i++) {

		atual = 1 - atual;

		for(int j = 1; j <= (int)a.size(); j++) {
			int maior = 0;

			if(b[i-1] == a[j-1])
				maior = 1 + dp[1-atual][j-1];
			else
				maior = max(dp[1-atual][j], dp[atual][j-1]);

			dp[atual][j] = maior;
		}
	}

	int msc = dp[atual][a.size()];
}