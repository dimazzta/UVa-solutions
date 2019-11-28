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

	int y;
	while(cin >> y, y){
		int p = 1 << (((y / 10) * 10 - 1960) / 10 + 2);
		double current = 0;
		int n = 1;
		for (;;n++){
			current += log2((double)n);
			if (current > p){
				break;
			}
		}
		cout << n - 1 << endl;
		
	}
	return 0;
}


