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

bool can(vi & a, int k){
	int pr = 0;
	for (int i = 0; i < a.size(); i++){
		if (a[i] - pr > k) return false;
		else if (a[i] - pr == k) k--;
		pr = a[i];
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	#ifdef DEBUG
		freopen("out.txt", "w", stdout);
	#endif


	int t; cin >> t;
	for (int test = 1; test <= t; test++){
		int n; cin >> n; vi a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		int lo = 1, hi = 1e8;
		int ans = INT_MAX;
		while(lo <= hi){
			int mid = lo + (hi - lo) /  2;
			if (can(a, mid)){
				ans = min(mid, ans);
				hi = mid - 1;
			}
			else{
				lo = mid + 1;
			}
		}
		cout << "Case " << test << ": " << ans << endl; 
	}

	return 0;
}

