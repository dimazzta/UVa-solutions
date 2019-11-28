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

const int nax = 1e6 + 5;
vector<vi> ndif(nax);

void sieve(){
    for (int i = 2; i < nax; i++){
        if (!ndif[i].size()){
            for (int j = i; j < nax; j += i){
                ndif[j].push_back(i);
            }
        }
    }
}

int mu(int x){
    if (x == 1) return 1;
    int sm = 1;
    for (int i = 0; i < ndif[x].size(); i++){
        sm *= ndif[x][i];
    }
    if (sm != x) return 0;
    if (ndif[x].size() % 2 == 0) return 1;
    return -1;
}

int main(){
	#ifdef DEBUG
	freopen("out.txt", "w", stdout);
	#endif
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    sieve();
    vi mers(nax);
    vi m(nax);
    for (int i = 1; i < nax; i++){
        mers[i] = mu(i);
        m[i] = mers[i] + m[i - 1];
    }
    int n;

    while(cin >> n, n){
        cout << right << setw(8) << n  << right << setw(8) << mers[n] << right << setw(8) << m[n] << endl;
    }
	return 0;
}

