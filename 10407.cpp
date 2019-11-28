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
	freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vi a;
	int x;
	while(cin >> x, x){
		int y;
		a.clear();
		a.push_back(x);
		while(cin >> y, y){
			a.push_back(y);
		}
		int ans = a[1] - a[0];
		for (int i = 2; i < a.size(); i++){
			ans = __gcd(ans, a[i] - a[i - 1]);
		}
		cout << abs(ans) << endl;
	}
	return 0;
}


