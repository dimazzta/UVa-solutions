#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

int main() {
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; 
	while(cin >> n, n){
		int k = floor(sqrt(n));
		if (k % 2 == 0) {
			int row = 1;
			int col = k;
			int sq = k * k;
			if (sq != n) {
				if (n <= sq + k + 1) {
					col++;
					row = n - sq;
				}
				else {
					row = k + 1;
					col = k + 1 - (n - (sq + k + 1));
				}
			}
			cout << col << " " << row << endl;
		}
		else{
			int col = 1;
			int row = k;
			int sq = k * k;
			if (sq != n){
				if (n <= sq + k + 1){
					row++;
					col = n - sq;
				}
				else{
					col = k + 1;
					row = k + 1 - (n - (sq + k + 1));
				}
			}
			cout << col << " " << row << endl;
		}
	}
	
	return 0;
}


