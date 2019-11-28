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
	int n; 
	while(cin >> n, n >= 0){
		int mx = -1;
		for (int i = 2; i * i <= n + 5; i++){
			int tmp = n;
			bool can = true;
			for (int j = 1; j <= i; j++){
				tmp--;
				if (tmp % i != 0){
					can = false;
					break;
				}
				tmp -= tmp / i;
			}
			if (tmp % i != 0){
				can = false;
			} 
			if (!can) continue;
			mx = max(mx, i);
		}
		if (mx == -1){
			cout << n << " coconuts, no solution" << endl;
		}
		else{
			cout << n << " coconuts, " << mx << " people and 1 monkey" << endl;
		}
	}
	
	
	return 0;
}

