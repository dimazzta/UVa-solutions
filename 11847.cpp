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
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	while(cin >> n, n){
		cout << (int)floor(log2(n)) << endl;
	}
	return 0;
}


