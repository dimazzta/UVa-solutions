#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;


const int nax = 1e6 + 5;
vll ans(nax);
vll pref(nax);

int main(){
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	ll st = 1;
	int cnt = 0;
	for (int i = 4; i < nax; i++){
		ans[i] = ans[i - 1] + st;
		cnt++;
		if (cnt == 2){
			cnt = 0;
			st++;
		}
	}
	
	pref[4] = ans[4];
	for (int i = 5; i < nax; i++){
		 pref[i] = pref[i - 1] + ans[i];
	}
	
	int n; 
	while(cin >> n, n >= 3){
		cout << pref[n] << endl;
	}
	
	return 0;
}


