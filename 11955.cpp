#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

const int nax = 55;
vector<vll> coef(nax);

void gen(){
	coef[0].push_back(1);
	coef[1].push_back(1);
	coef[1].push_back(1);
	for (int i = 2; i < nax; i++){
		coef[i].push_back(1);
		for (int j = 0; j + 1 < i; j++){
			coef[i].push_back(coef[i - 1][j] + coef[i - 1][j + 1]);
		}
		coef[i].push_back(1);
	}
}

int main(){
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	gen();
	
	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++){
		string s; cin >> s;
		string first, second;
		int idx = 1;
		while(s[idx] != '+'){
			first += s[idx];
			idx++;
		}
		idx++;
		while(s[idx] != ')'){
			second += s[idx];
			idx++;
		}
		while(s[idx] != '^'){
			idx++;
		}
		idx++;
		string p = s.substr(idx);
		int power = stoi(p);
		
		cout << "Case " << tc << ": ";
		int f_power = power;
		int s_power = 0;
		vll c = coef[power];
		int n = c.size();
		for (int i = 0; i < n; i++){
			if (i) cout << "+";
			if (f_power){
				if (c[i] > 1) cout << c[i] << "*";
				cout << first;
				if (f_power > 1) cout << "^" << f_power;
			}
			if (s_power){
				if (f_power){
					cout << "*";
				}
				cout << second;
				if (s_power > 1) cout << "^" << s_power;
			}
			f_power--;
			s_power++;
			
		}
		cout << endl;
	}
	return 0;
}


