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

const int mod = 131071;

int main(){
	#ifdef DEBUG
	freopen("out.txt", "w", stdout);
	#endif
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    char c;
    while(cin >> c){
        string s;
        s += c;
        while(cin >> c, c != '#') {
            s += c;
        }
        int n = s.size();
        int base = 1;
        int ans = 0;
        for (int i = n - 1; i >= 0; i--){
            if (s[i] == '1'){
                ans += base;
                ans %= mod;
            }
            base *= 2;
            base %= mod;

        }
        if (ans == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
	return 0;
}

