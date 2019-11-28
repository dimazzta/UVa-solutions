#include <bits/stdc++.h>
using namespace std;
//#define DEBUG

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> mi;
typedef vector<vector<pair<int, int>>> w_graph;
typedef vector<vector<int>> uw_graph;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	#ifdef DEBUG
		freopen("out.txt", "w", stdout);
	#endif

	int n, m;
	while (cin >> n >> m){
		if (n == 0) break;
		  mi a(n, vi(m));
		  for (int i = 0; i < n; i++){
			  	for (int j = 0; j < m; j++){
			  		cin >> a[i][j];
			  	}
		  }	
		  int q; cin >> q;
		  while(q--){
		  	 int mn, mx;
		  	 cin >> mn >> mx;
		  	 int mside = 0;
		  	 bool k = false;
		  	 for (int i = 0; i < n; i++){
		  	 	
		  	 	auto el = lower_bound(a[i].begin(), a[i].end(), mn);
		  	 	if (el != a[i].end()){
		  	 		int col = el - a[i].begin();
		  	 		int lo = 0;
		  	 		int hi = min(m - col - 1, n - i - 1);
		  	 		int ans = -1;
		  	 		while(lo <= hi){
		  	 			int mid = lo + (hi - lo) / 2;
		  	 			if (a[i + mid][col + mid] <= mx){
		  	 				ans = max(mid, ans);
		  	 				lo = mid + 1;
		  	 			}
		  	 			else{
		  	 				hi = mid - 1;
		  	 			}
		  	 		}
		  	 		if (ans != -1){
		  	 			k = true;
		  	 		}
		  	 		mside = max(mside, ans);
		  	 	}
		  	 }
		  	 if (k)  cout << mside + 1 << endl;
		  	 else cout << 0 << endl;
		  }
		  cout << "-" << endl;
	}
	return 0;
}
	
