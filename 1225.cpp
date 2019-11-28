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
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s;
		for (int i = 1; i <= n; i++){
			s += to_string(i);
		}
		
		map<int, int> mp; 
		for (int i = 0; i < s.size(); i++){
			mp[s[i] - '0']++;
		}
		for (int i = 0; i <= 9; i++){
			if (i > 0) cout << " ";
			cout << mp[i];
		}
		cout << endl;
		
	}
	return 0;
}

