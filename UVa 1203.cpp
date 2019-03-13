#include <bits/stdc++.h>
using namespace std;
#define DEBUG

typedef long long ll;
int main(){
    #ifdef DEBUG
        freopen("out.txt", "w", stdout);
    #endif
    string s;
    int qn, d, k;
    auto cmp = [](pair<int, int> a, pair<int, int> b) {
            if (a.first != b.first)
                return a.first > b.first;
            else
                return a.second > b.second;
        };
    priority_queue<pair<int, int>, std::vector<pair<int, int>>, decltype(cmp)> q(cmp);
    while (getline(cin, s) && s[0] != '#'){
        sscanf(s.c_str(), "Register %d %d", &qn, &d);
        int cd = d;
        for (int i = 0; i < 10000; i++){
            q.push(make_pair(cd, qn));
            cd += d;
        }
    }
    scanf("%d", &k);
    int a, b;
    while(k--){
        tie(a, b) = q.top();
        cout << b << endl;
        q.pop();
    }
}
