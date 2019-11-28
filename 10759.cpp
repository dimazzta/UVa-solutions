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

ll dp[25][151];

int main(){
	#ifdef DEBUG
	freopen("out.txt", "w", stdout);
	#endif
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    dp[0][0] = 1;
    for (int i = 1; i <= 24; i++){
        for (int j = 1; j <= 150; j++){
            for (int k = 1; k <= 6; k++){
                if (j - k >= 0){
                    dp[i][j] += dp[i - 1][j - k];
                }
            }
        }
    }
    int n, x;
    while(cin >> n >> x, n || x){
        ll den = 1;
        for (int i = 0; i < n; i++) den *= 6LL;
        ll num = 0;
        for (int i = x; i <= 150; i++){
            num += dp[n][i];
        }
        ll g = __gcd(den, num);
        if (num == 0) {
            cout << 0 << endl;
        }
        else if (num == den){
            cout << 1 << endl;
        }
        else{
            cout << num / g;
            cout << "/";
            cout << den / g;
            cout << endl;
        }

    }
	return 0;
}

