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
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++){
		int n; cin >> n;
		bool can = true;
		map<int, int> mp;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				int x; cin >> x;
				mp[x]++;
				if (mp[x] > n) can = false;
			}
		}
		cout << "Case " << tc << ": ";
		if (can){
			cout << "yes" << endl;
		}
		else{
			cout << "no" << endl;
		}
	}
	return 0;
}


