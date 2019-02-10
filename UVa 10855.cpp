#include <bits/stdc++.h>
using namespace std;


void rotate(vector <vector<char> > &mat) {
	int n = mat.size();
	for (int i = 0; i < n / 2; i++) {
		for (int j = i; j < n - i - 1; j++) {
			char temp = mat[i][j];
			mat[i][j] = mat[n - j - 1][i];
			mat[n - j - 1][i] = mat[n - i - 1][n - j - 1];
			mat[n - i - 1][n - j - 1] = mat[j][n - i - 1];
			mat[j][n - i - 1] = temp;
		}
	}
}


int main() {
	int N, n;
	while (scanf("%d %d", &N, &n), n) {
		string s;
		vector< vector<char> > V(N, vector<char>(N));
		vector< vector<char> > v(n, vector<char>(n));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> V[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> v[i][j];
			}
		}
		for(int i = 0; i < 4; i++){
			long cnt = 0;
			for (int i = 0; i < N - n + 1; i++) {
				for (int j = 0; j < N - n + 1; j++) {
					bool match = true;
					for (int U = i, u = 0; U < i + n; U++, u++) {
						for (int K = j, k = 0; K < j + n; K++, k++) {
							if (V[U][K] != v[u][k]) {
								match = false;
								break;
							}
						}
					}
					if (match) cnt++;
				}
			}
			i != 0 ? cout << " " << cnt : cout << cnt;
			rotate(v);
		}
		cout << endl;
	}


}
