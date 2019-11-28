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



int popcount(int a){
	int cnt = 0;
	for (int i = 0; i < 32; i++){
		if ((1 << i) & a) cnt++;
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	#ifdef DEBUG
		freopen("out.txt", "w", stdout);
	#endif

	int tc = 1;
	int n, k;
	while(cin >> n >> k, n && k){
		vi a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		int m; cin >> m;
		vector<pair<set<int>, int>> b(m);
		for (int i = 0; i < m; i++){
			int sz; cin >> sz;
			for (int j = 0; j < sz; j++){
				int x; cin >> x;
				b[i].first.insert(x - 1);
			}
			int cnt; cin >> cnt;
			b[i].second = cnt;
		}
		vi ans;
		int mx = -1;
		for (int i = 1; i < (1 << n); ++i){
			if (popcount(i) == k){
			   vi pos_ans;
			   int sum = 0;
			   for(int j = 0; j < n; j++){
 		           if ((1 << j) & i){
           	          pos_ans.push_back(j);
           	          sum += a[j];
 		           }
			   }
			   for (int j = 0; j < m; j++){
		   	      int cnt = 0;
		   	      for (int v = 0; v < k; v++){
		   	      	if (b[j].first.find(pos_ans[v]) != b[j].first.end()){
		   	      		cnt++;
		   	      	} 
		   	      }
		   	      if (cnt >= 2) 
					 {
					 	sum -= (cnt - 1) * b[j].second;
					 }
			   }
			   
			   if (sum > mx){
					ans = pos_ans;
					mx = sum;
			   }
			   else if (sum == mx){
			   	   for (int j = 0; j < k; j++){
			   	   	   if (pos_ans[j] < ans[j]){
			   	   	   	  ans = pos_ans;
			   	   	   	  break;
			   	   	   }
			   	   }
			   }
			}
		}
		cout << "Case Number  " << tc++ << endl;
		cout << "Number of Customers: " << mx << endl;
		cout << "Locations recommended:";
		for (int i = 0; i < k; i++){
			cout << " " << ans[i] + 1;
		}
		cout << endl << endl;
	}
	

	return 0;
}

