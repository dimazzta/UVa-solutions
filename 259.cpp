#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

map<char, set<int>> a;
vector<char> apps;
int k;
bool found;
string anns;

void solve(string mask, int cnt) {
	if (cnt == apps.size()) {
		anns = mask;
		found = true;
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (mask[i] == '_' && a[apps[cnt]].count(i)){
			mask[i] = apps[cnt];
			solve(mask, cnt + 1);
			if (found) return;
			mask[i] = '_';
		}
	}
}


int main() {
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string s;
	while (getline(cin, s)) {
		a.clear();
		apps.clear();
		do{
			char app = s[0];
			int cnt = s[1] - '0';
			for (int i = 0; i < cnt; i++) {
				apps.push_back(app);
			}
			for (int i = 3; i < s.size() - 1; i++) {
				char t; t = s[i];
				int num = t - '0';
				a[app].insert(num);
			}
			getline(cin, s);
		}
		while(!s.empty());
		
		found = false;
		string in = "__________";
		solve(in, 0);
		if (found) {
			cout << anns << endl;
		}
		else {
			cout << "!" << endl;
		}
	}
	return 0;
}


