#include <bits/stdc++.h>
using namespace std;

//#define DEBUG

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

void gcde(ll n1, ll n2, ll &x, ll &y, ll &g){
    if (n2 == 0){
        x = 1; y = 0;
        g = n1;
        return;
    }
    gcde(n2, n1 % n2, x, y, g);
    ll x1 = y;
    ll y1 = x - (n1 / n2) * y;
    x = x1;
    y = y1;
}


int main(){
	#ifdef DEBUG
	freopen("out.txt", "w", stdout);
	#endif
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


    ll n;
    while(cin >> n, n){
        ll n1, c1, n2, c2;
        cin >> c1 >> n1 >> c2 >> n2;
        ll x, y, g;
        gcde(n1, n2, x, y, g);
        if (n % g != 0){
            cout << "failed" << endl;
        }
        else{
            ll m1 = x * n / g;
            ll m2 = y * n / g;

            //cout << m1 << " " << m2 << endl;
            ll t1 = ceil((double)-m1 * g / n2);
            ll t2 = floor((double)m2 * g / n1);
            //cout << t1 << " " << t2 << endl;
            if (t2 < t1) {
                cout << "failed" << endl;
                continue;
            }
            ll cost1 = (m1 + n2 / g * t1) * c1 + (m2 - n1 / g * t1) * c2;
            ll cost2 = (m1 + n2 / g * t2) * c1 + (m2 - n1 / g * t2) * c2;

            //cout << cost1 << " " << cost2 << endl;
            ll t = t1;
            if (cost2 < cost1){
                t = t2;
            }
            ll r1 = m1 + n2 / g * t;
            ll r2 = m2 - n1 / g * t;
            cout << r1 << " " << r2 << endl;
        }


    }

	return 0;
}

