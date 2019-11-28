#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

ll cat[12];

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cat[1] = 1;
	for (int n = 1; n < 11; n++){
		cat[n + 1] = cat[n] * (4 * n + 2) / (n + 2);
	}
	int n; 
	int f = false;
	while(cin >> n){
		if (f) cout << endl;
		f = true;
		cout << cat[n] << endl;
	}
	return 0;
}


