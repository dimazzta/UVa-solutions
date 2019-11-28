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

int main(){
	#ifdef DEBUG
	freopen("out.txt", "w", stdout);
	#endif
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    while(cin >> s){
        string h = s, l = s;
        sort(h.begin(), h.end(), greater<char>());
        sort(l.begin(), l.end());
        int i = 0;
        while(l[i] == '0') i++;
        swap(l[i], l[0]);

        ll a = stoll(h);
        ll b = stoll(l);
        ll d = a - b;
        ll g = d / 9;
        cout << h << " - " << l << " = " << a - b << " = " << "9 * " << g << endl;
    }
	return 0;
}

