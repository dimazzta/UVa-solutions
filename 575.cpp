#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

int to_dec(string a){
	int base = 2;
	int n = a.size();
	int result = 0;
	for (int i = n - 1; i >= 0; i--){
		char c = a[i];
		int k = c - '0';
		result += k * (base - 1);
		base <<= 1;
	}
	return result;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	while(cin >> s, s != "0"){
		cout << to_dec(s) << endl;
	}
	return 0;
}


