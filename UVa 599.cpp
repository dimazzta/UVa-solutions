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
	int t;
	cin >> t;
	while (t--) {
		string s;
		bitset<26> edg;
		int e = 0;
		while (true) {
			cin >> s;
			if (s[0] == '*') {
				string gr;
				cin >> gr;
				int v = gr.size() / 2 + 1;
				int cc = v - e;
				int ac = v - edg.count();
				cout << "There are " << cc - ac << " tree(s) and " << ac << " acorn(s)." << endl;
				break;
			}
			else {
				edg[s[1] - 'A'] = true;
				edg[s[3] - 'A'] = true;
				e++;
			}
		}
	}
}
