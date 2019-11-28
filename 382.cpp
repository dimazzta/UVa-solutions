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
	
	cout << "PERFECTION OUTPUT" << endl;
	int a;
	while(cin >> a, a){
		int sum = 0;
		for (int i = 1; i <= a / 2; i++){
			if (a % i == 0) sum += i;
		}
		string s = to_string(a);
		int tmp = 5 - s.size();
		if (sum == a){
			cout << string(tmp, ' ') << a << "  " << "PERFECT" << endl;
		}
		if (sum < a){
			cout << string(tmp, ' ') << a << "  " << "DEFICIENT" << endl;
		}
		if (sum > a){
			cout << string(tmp, ' ') << a << "  " << "ABUNDANT" << endl;
		}
		
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}

