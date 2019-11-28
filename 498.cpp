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

	string s;
	while(getline(cin, s)){
		string s1;
		getline(cin, s1);
		stringstream ss(s);
		stringstream ss1(s1);
		
		vi c;
		vi x;
		int f;
		while(ss >> f) c.push_back(f);
		while(ss1 >> f) x.push_back(f);
		
		reverse(c.begin(), c.end());

		
		
		for (int i = 0; i < x.size(); i++){
			int cur_x = x[i];
			ll cur = 1;
			ll result = 0;
			for (int j = 0; j < c.size(); j++){
				result += c[j] * cur;
				cur *= cur_x;
			}
			if (i) cout << " ";
			cout << result;
		}
		cout << endl;
	}
	return 0;
}


