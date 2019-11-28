#include <bits/stdc++.h>
using namespace std;

 #define DEBUG

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

    int car, cow, show;
    while(cin >> cow >> car >> show){
        int tot = car + cow;
        double ans = (double)(car * (car - 1) + cow * car) / (tot * (tot - show - 1));
        cout << setprecision(5) << fixed << ans << endl;
    }


	return 0;
}

