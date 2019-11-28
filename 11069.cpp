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

	vll dp(80);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 2;
	for (int i = 4; i < 80; i++){
		dp[i] = dp[i - 3] + dp[i - 2];
	}
	int n; 
	while(cin >> n){
		cout << dp[n] << endl;
	}
	return 0;
}


