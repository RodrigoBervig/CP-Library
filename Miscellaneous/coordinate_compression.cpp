// vector<int> d = a;
// sort(d.begin(), d.end());
// d.resize(unique(d.begin(), d.end()) - d.begin());
// for (int i = 0; i < n; ++i) {
//   a[i] = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
// }
// //original value of a[i] can be obtained through d[a[i]]

#include <bits/stdc++.h>
 
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
 
using namespace std;
 
#define dbg(x) { cerr << #x << " = " << x << "\n"; } 
#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull; 

void solve() {
  vector<int> a = {1, 2, 2, 4, 4, 4, 9};

  for(auto it: a) {
    cout << it << " ";
  } cout <<"\n";


  auto it1 = unique(a.begin(), a.end());

  for(auto it: a) {
    cout << it << " ";
  } cout <<"\n";
}
 
int main() {
 
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  solve();

  return 0;
}
