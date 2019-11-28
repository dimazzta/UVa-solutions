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
		
		int x;
		ss >> x;
		vi c;
		int f;
		while(ss1 >> f) c.push_back(f);
		
		reverse(c.begin(), c.end());
		int n = c.size();
		ll result = 0;
		ll cur = 1;
		for (int i = 1; i < n; i++){
			result += c[i] * cur * i;
			cur *= x;
		}
		cout << result << endl;
	
	}
	return 0;
}


