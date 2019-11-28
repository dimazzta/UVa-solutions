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
	
	vll dp(50);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 5;
	for (int i = 3; i <= 40; i++){
		dp[i] = dp[i - 2] * 5 + dp[i - 1] - dp[i - 2] + dp[i - 3] * 2;
	}
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}


