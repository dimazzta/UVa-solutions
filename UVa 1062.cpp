#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int k = 1;
    while(true){
        cin >> s;
        if (s == "end") break;
        vector<stack<char>> stacks;
        for (int i = 0; i < s.size(); i++){
            bool f = false;
            char c = s[i];
            for (int j = 0; j < stacks.size(); j++){
                if (stacks[j].top() >= c){
                    stacks[j].push(c);
                    f = true;
                    break;
                }
            }
            if (!f){
                stack<char> st;
                st.push(c);
                stacks.push_back(st);
            }
        }

        cout << "Case " << k++ << ": " << stacks.size() << endl;
    }
}



