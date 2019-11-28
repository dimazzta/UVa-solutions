#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

int main(){
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	while(cin >> n){
		int diag = 1;
		while(true){
			int res = (diag * diag + diag) / 2;
			if (res >= n) break;
			diag++;
		}
		int start_diag = ((diag - 1) * (diag - 1) + diag - 1) / 2 + 1;
		int cnt = n - start_diag;
		string ans = "";
		if (diag % 2 == 0){
			ans = to_string(1 + cnt) + "/" + to_string(diag - cnt);
		}
		else{
			ans = to_string(diag - cnt) + "/" + to_string(1 + cnt);
		}
		cout << "TERM " << n << " IS " << ans << endl;
	}
	return 0;
}


