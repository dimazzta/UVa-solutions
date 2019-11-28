#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;
const double pi = 3.14159265358979323846;
int main(){
	double a, b, v, alpha, t;
	while(cin >> a >> b >> v >> alpha >> t, a || b || v || alpha || t){
		double angle = alpha * pi / 180;
		double dx = v * t * cos(angle) / 2.0;
		double dy = v * t * sin(angle) / 2.0;
		
		int vb = floor((a / 2 + dx) / a);
		int hb = floor((b / 2 + dy) / b);
		cout << vb << " " << hb << endl;
	}
	
	return 0;
}

