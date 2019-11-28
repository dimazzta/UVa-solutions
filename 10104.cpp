#include <bits/stdc++.h>
using namespace std;

// #define DEBUG

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;


void gcde(ll a, ll b, ll &x, ll &y, ll &g){
    if (b == 0){
        x = 1;
        y = 0;
        g = a;
        return;
    }
    gcde(b, a % b, x, y, g);
    ll x1 = y;
    ll y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

int main(){
	#ifdef DEBUG
	freopen("out.txt", "w", stdout);
	#endif
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    ll a, b;
    while(cin >> a >> b){
        ll x, y, d;
        gcde(a, b, x, y, d);
        cout << x << " " <<  y << " " << d << endl;
    }

 	return 0;
}

