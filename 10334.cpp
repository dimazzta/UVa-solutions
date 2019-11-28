#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

const int nax = 1e3 + 5;
int fib[nax][nax];

int main(){
	freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	fib[0][0] = 1;
	fib[1][0] = 2;
	for (int i = 2; i < nax; i++){
		for (int j = 0; j < nax; j++){
			fib[i][j] = fib[i - 1][j] + fib[i - 2][j];
		}
		for (int j = 0; j < nax; j++){
			fib[i][j + 1] += fib[i][j] / 10;
			fib[i][j] %= 10;
		}
	}
	int n; 
	while(cin >> n){
		int start = nax - 1;
		while(!fib[n][start]) start--;
		for (int i = start; i >= 0; i--){
			cout << fib[n][i];
		}
		cout << endl;
	}
	return 0;
}


