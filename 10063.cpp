#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

vector<string> perm(string s) {
	if (s.size() == 1) {
		vector<string> res;
		res.push_back(s);
		return res;
	}

	vector<string> res;
	string norm = s.substr(0, s.size() - 1);
	char last = s[s.size() - 1];
	vector<string> perms = perm(norm);
	for (int i = 0; i < perms.size(); i++) {
		string cur_perm = perms[i];
		for (int j = 0; j < cur_perm.size(); j++) {
			string cur = cur_perm.substr(0, j) + last + cur_perm.substr(j);
			res.push_back(cur);
		}
		res.push_back(cur_perm + last);
	}
	return res;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	bool f = false;
	while (cin >> s) {
		if (f) cout << endl;
		f = true;
		vector<string> ans = perm(s);
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << endl;
		}
	}
	return 0;
}


