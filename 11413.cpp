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
	while(cin >> n >> m){
		vi a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		int lo = 1, hi = 1e9;
		int ans = INT_MAX;
		while(lo <= hi){
			int mid = lo + (hi - lo) / 2;
			int cn = 1, cc = 0;
			bool f = true;
			for (int i = 0; i < n; i++){
				if (a[i] > mid){
					f = false; break;
				}
				int left = mid - cc;
				if (a[i] <= left){
					cc += a[i];
				}
				else{
					cn++;
					cc = a[i];
				}
			}
			
			if (f){
				if (cn <= m){
					ans = min(ans, mid);
					hi = mid - 1;
				}
				else{
					lo = mid + 1;
				}
			}
			else{
				lo = mid + 1;
			}
		}
		cout << ans << endl;
	}

	return 0;
}

