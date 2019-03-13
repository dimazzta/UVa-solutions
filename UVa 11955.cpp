#include <bits/stdc++.h>
using namespace std;
#define DEBUG

typedef long long ll;
int main(){
    #ifdef DEBUG
        freopen("out.txt", "w", stdout);
    #endif
    int n;

    while (scanf("%d", &n) != EOF){
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        bitset<3> bits;
        bits.set();
        for (int i = 0; i < n; i++){
            int o, op;
            scanf("%d %d", &o, &op);
            
            
            if (o == 1){
                s.push(op);
                q.push(op);
                pq.push(op);
            }
            else {
                if (!s.empty()){
                    if (s.top() == op){
                        s.pop();
                    }
                    else {
                        bits.reset(0);
                    }
                }
                else {
                    bits.reset(0);
                }

                if (!q.empty()){
                    if (q.front() == op){
                        q.pop();
                    }
                    else {
                        bits.reset(1);
                    }
                }
                else {
                    bits.reset(1);
                }
                
                if (!pq.empty()){
                    if (pq.top() == op){
                        pq.pop();
                    }
                    else {
                        bits.reset(2);
                    }
                }
                else {
                    bits.reset(2);
                }
            }
        }
        if (bits.count() > 1){
            cout << "not sure" << endl;
        }
        else if (bits.count() == 0){
            cout << "impossible" << endl;
        }
        else{
            if (bits.test(0)) cout << "stack" << endl;
            else if (bits.test(1)) cout << "queue" << endl;
            else cout << "priority queue" << endl;
        }
    }
}
