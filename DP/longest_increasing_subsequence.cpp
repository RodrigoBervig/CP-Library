void solve_dp_lis() {
	vector<int> a(1);

	int e;
	while(cin >> e) {
		a.pb(e);
	}

	vector<int> dp(a.size(), 1);
	vector<int> pred(a.size(), -1);

	for(int i = 2; i < (int)a.size(); i++) {
		for(int j = 1; j < i; j++) {
			if(a[j] < a[i]) {
				if(dp[j]+1 > dp[i]) {
					pred[i] = j;
					dp[i] = dp[j]+1;
				}
			}
		}
	}

	int maximum_lis = *max_element(dp.begin()+1, dp.end());

	int idx = a.size()-1;
	while(dp[idx]!=maximum_lis) idx--;

	vector<int> lis_elements;
	while(true) {
		lis_elements.pb(a[idx]);
		idx = pred[idx];
		if(idx == -1) break;
	}

	cout << maximum_lis << "\n-\n";

	reverse(lis_elements.begin(), lis_elements.end());
	for(auto it: lis_elements) {
		cout << it << "\n";
	}
}

void solve_nlogk_lis() {
	vector<int> a(1);

	int e;
	while(cin >> e)
		a.push_back(e);

	vector<int> lis;
	vector<int> lis_id;
	vector<int> pred(a.size(),-1);

	for(int i = 1; i <= (int)a.size(); i++) {
		//find lower_bound of a
		int pos = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();

		if(pos == (int)lis.size()){
			lis.push_back(a[i]);
			lis_id.push_back(i);
		} else {
			lis[pos] = a[i];
			lis_id[pos] = i;
		}
		
		if(pos)
			pred[i] = lis_id[pos-1];
	}

	cout << lis.size() << "\n-\n";

	vector<int> actual_lis;

	int idx = [lis_id[lis.size()-1]];
	actual_lis.push_back(a[idx]);
	idx = pred[idx];
	
	while(idx != -1) {
		actual_lis.push_back(a[idx]);
		idx = pred[idx];
	}

	for(auto it = actual_lis.rbegin(); it != actual_lis.rend(); it++){
		cout << *it << "\n";
	}
}
 
