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

	int x; 
	vi a;
	while(cin >> x){
        a.push_back(x);
	}
	int n = a.size();
	vi dp;
	map<int, int> idx, p;
	for (int i = 0; i < n; i++){
		int pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
		if (pos == dp.size()){
			dp.push_back(a[i]);
		}
		else{
			dp[pos] = a[i];
		}
		idx[pos] = i;
		p[i] = pos ? idx[pos - 1] : -1;
	}

	int lst = idx[dp.size() - 1];
	vi ans;
	while(lst != -1){
		ans.push_back(a[lst]);
		lst = p[lst];
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	cout << "-" << endl;
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
	
}

