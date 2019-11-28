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
        g = a;
        x = 1;
        y = 0;
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

    int t; cin >> t;
    while(t--){
        ll x, k;
        cin >> x >> k;
        ll a = x / k;
        ll b = (x - 1) / k + 1;
        ll x_0, y_0, g;
        gcde(a, b, x_0, y_0, g);
        ll x0 = x_0 * x / g;
        ll y0 = y_0 * x / g;
        cout << x0 << " " << y0 << endl;
    }
	return 0;
}

