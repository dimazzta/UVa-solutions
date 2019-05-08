#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> mi;
typedef vector<vector<pair<int, int>>> w_graph;
typedef vector<vector<int>> uw_graph;
typedef tuple<int, int, int> iii;
typedef vector<long long> vll;




int main() {
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		pair<ll, ll> nodes[3] = { { 0, 1 },{ 1, 1 },{ 1, 0 } };
		for (int j = 0; j < s.size(); j++) {

			if (s[j] == 'L') {
				nodes[2] = nodes[1];
				nodes[1].first = nodes[2].first + nodes[0].first;
				nodes[1].second = nodes[2].second + nodes[0].second;
			}
			else {
				nodes[0] = nodes[1];
				nodes[1].first = nodes[2].first + nodes[0].first;
				nodes[1].second = nodes[2].second + nodes[0].second;
			}
		}
		cout << nodes[1].first << "/" << nodes[1].second << endl;
	}

}
