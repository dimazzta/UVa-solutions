#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	while(cin >> n >> k){
		vector<pair<double, ii>> ans;
		for (int i = 1; i < n; i++){
			for (int j = i; j <= n; j++){
				if (__gcd(i, j) == 1){
					ans.push_back({(double)i / j, {i, j}});
				}
			}
		}
		sort(ans.begin(), ans.end());
		cout << ans[k - 1].second.first << "/" << ans[k - 1].second.second << endl;
	}
	return 0;
}


