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
		vi number(1000);
		number[0] = 1;
		for (int i = 2; i <= n; i++){
			for (int j = 0; j < 1000; j++){
				number[j] *= i;
			}
			for (int j = 0; j < 999; j++){
				number[j + 1] += number[j] / 10;
				number[j] = number[j] % 10; 
			}
		}
		int st = 999;
		while(!number[st]) st--;
		vi f(10);
		for (; st >= 0; st--){
			f[number[st]]++;
		}
		cout << n << "!" << " --" << endl;
		for (int i = 0; i <= 9; i++){
			cout << "   (" << i << ")" << "  " << f[i] << " ";
			if (i == 4) cout << endl;
		}
		cout << endl;
	}
	return 0;
}


