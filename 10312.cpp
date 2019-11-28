#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

ll super[27];
ll cat[27];

int main(){
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cat[0] = 1;
	cat[1] = 1;
	for (int i = 1; i <= 26; i++){
		cat[i + 1] = cat[i] * (4 * i + 2) / (i + 2);
	}
	
	super[1] = 1;
	super[2] = 1;
	for (int i = 3; i <= 26; i++){
		super[i] = ((6 * i - 9) * super[i - 1] - (i - 3) * super[i - 2]) / i;
	}
	int n; 
	while(cin >> n){
		cout << super[n] - cat[n - 1] << endl;
	}
	return 0;
}


