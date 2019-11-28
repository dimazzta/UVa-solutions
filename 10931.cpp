#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

pair<string, int> solve(int a){
	int cnt = 0;
	string res;
	while (a){
		if (a % 2 == 1){
			res = '1' + res;
			cnt++;
		}
		else{
			res = '0' + res;
		}
		a >>= 1;
	}
	return {res, cnt};
}


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	while(cin >> n, n){
		pair<string, int> a = solve(n);
		cout << "The parity of " << a.first << " is " << a.second << " (mod 2)." << endl;
	}
	return 0;
}


