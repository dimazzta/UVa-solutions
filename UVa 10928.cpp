#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> mi;
typedef vector<vector<pair<int, int>>> w_graph;
typedef vector<vector<int>> uw_graph;

int main() {
	int n;
	cin >> n;
	while (n--) {
		int p;
		cin >> p;
		vector<int> ans;
		int mn = INT_MAX;
		cin.ignore();
		for (int i = 0; i < p; i++) {
			string s;
			getline(cin, s);
			int cnt = count(s.begin(), s.end(), ' ') + 1;
			if (cnt <= mn) {
				if (cnt < mn)
					ans.clear();
				mn = cnt;
				ans.push_back(i + 1);
			}
			
		}
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i];
			if (i != ans.size() - 1) cout << " ";
		}
		cout << endl;
	}
	
}
