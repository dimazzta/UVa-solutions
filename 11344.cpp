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


bool check(string s, int n){
    int cur = 0;
    int mod = 0;
    for (int i = 0; i < s.size(); i++){
        cur = cur * 10 + s[i] - '0';
        cur %= n;
    }
    return cur == 0;
}

int main(){
	#ifdef DEBUG
	freopen("out.txt", "w", stdout);
	#endif
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n; cin >> n;
        bool ans = true;
        for (int i = 0; i < n; i++) {
             int x; cin >> x;
             ans &= check(s, x);
        }
        cout << s << " - ";
        if (ans){
            cout << "Wonderful." << endl;
        }
        else{
            cout << "Simple." << endl;
        }

    }
	return 0;
}

