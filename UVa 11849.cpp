#include <bits/stdc++.h>
using namespace std;
#define DEBUG

typedef long long ll;
int main(){
    #ifdef DEBUG
        freopen("out.txt", "w", stdout);
    #endif

    int n, m;
    while (scanf("%d %d", &n, &m) && n != 0){
        set<ll> jack, jill;
        for(int i = 0; i < n; i++) {
            int cd;
            scanf("%d",  &cd);
            jack.insert(cd);
        }
        for(int i = 0; i < m; i++) {
            int cd;
            scanf("%d",  &cd);
            jill.insert(cd);
        }
        ll cnt = 0;
        for (auto it = jack.begin(); it != jack.end(); it++){
            if (jill.find(*it) != jill.end()) cnt++;
        }
        cout << cnt << endl;
    }
    
}
