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
	//freopen("out.txt", "w", stdout);
	double price;
	int m;
	int tc =1;
	while(cin >> price >> m){
		cout << "Case " << tc++ << ":" << endl;
		vector<int> w(m + 1);
		vector<double> v(m + 1);
		w[0] = 1;
		v[0] = price;
		for (int i = 1; i <= m; i++){
			cin >> w[i] >> v[i];
		}
		vector<double> dp(300);
		dp[0] = 0;
		for (int i = 1; i < 300; i++) dp[i] = 1e15;
		
		for (int i = 0; i <= m; i++){
			for (int j = 0; j < 300; j++){
				if (j >= w[i])
					dp[j] = min(dp[j], dp[j - w[i]] + v[i]);
			}
		}
		cin.ignore();
		string s;
		getline(cin, s);
		stringstream ss(s);
		int k;
		while (ss >> k){
			double mn = 1e15;
			for (int i = k; i < 300; i++){
				mn = min(mn, dp[i]);
			}
			cout << "Buy " << k << " for $" << setprecision(2) << fixed << mn << endl;
		}
	}
	
	
	return 0;
}

