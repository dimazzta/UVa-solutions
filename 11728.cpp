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

int main(){
	#ifdef DEBUG
	freopen("out.txt", "w", stdout);
	#endif
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    vi ans(1001, -1);
    for (int i = 1; i <= 1000; i++){
        int sd = 0;
        for (int j = 1; j * j <= i; j++){
            if (i % j == 0){
                sd += j;
                if (i / j != j) sd += i / j;
            }
        }
        if (sd <= 1000)
            ans[sd] = i;
    }
    int n;
    int tc = 1;
    while(cin >> n, n) {
        cout << "Case " << tc++ << ": " << ans[n] << endl;
    }
	return 0;
}

