#include <bits/stdc++.h>
using namespace std;
#define DEBUG

typedef long long ll;
int main(){
    #ifdef DEBUG
        freopen("out.txt", "w", stdout);
    #endif
    int n;
    while (scanf("%d", &n) && n != 0){
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i = 0; i < n; i++){
            int t;
            scanf("%d", &t);
            q.push(t);
        }
        ll ac = 0;
        while (q.size() > 1){
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            q.push(a + b);
            ac += a + b;
        }
        cout << ac << endl;
    }
}
