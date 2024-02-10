using ll = long long;
constexpr ll M = 998244353;

// get det(A) mod M, M can be composite number
// remove mod M -> get pure det(A) in integer
ll Det(vector<vector<ll>> a){//destroy matrix
  int n = a.size(); ll ans = 1;
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      while(a[j][i] != 0){ // gcd step
        ll t = a[i][i] / a[j][i];
        if(t)for(int k=i;k<n;k++) a[i][k]=(a[i][k]-a[j][k]*t)%M;
        swap(a[i], a[j]); ans *= -1;
      }
    }
    ans = ans * a[i][i] % M; if(!ans) return 0;
  } return (ans + M) % M;
}
