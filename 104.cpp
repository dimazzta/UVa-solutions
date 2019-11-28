#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;


const int inf = 1e8;
const int nax = 25;

double mat[nax][nax][nax];
int path[nax][nax][nax];

int main() {
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	while (cin >> n) {
		for (int i = 0; i < nax; i++) {
			for (int j = 0; j < nax; j++) {
				for (int k = 0; k < nax; k++) {
					mat[i][j][k] = 0.0;
					path[i][j][k] = -1;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				path[i][j][0] = j;
				if (i == j) {
					mat[i][j][0] = 1.0;
				}
				else {
					cin >> mat[i][j][0];
				}
			}
		}
		for (int s = 1; s < n; s++) {
			for (int k = 0; k < n; k++) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						double cand = mat[i][k][s - 1] * mat[k][j][0];
						if (cand > mat[i][j][s]) {
							mat[i][j][s] = cand;
							path[i][j][s] = k;
						}
					}
				}
			}
		}
		bool f = false;
		for (int s = 1; s < n; s++) {
			if (f) break;
			for (int i = 0; i < n; i++) {
				if (mat[i][i][s] > 1.01) {
					stack<int> st;
					st.push(i);
					int cur = i;
					for (int j = s - 1; j >= 0; j--) {
						st.push(path[i][cur][j + 1]);
						cur = st.top();
					}
					st.push(i);
					while (!st.empty()) {
						cout << st.top() + 1;
						st.pop();
						if (st.size()) cout << " ";
					}
					cout << endl;
					f = true;
					break;
				}
			}
		}
		if (!f){
			cout << "no arbitrage sequence exists" << endl;
		}
	}
}


