#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    int b, sb, sg;
    scanf("%d", &n);
    while(n--){
        scanf("%d %d %d", &b, &sg, &sb);
        multiset<int> green_army, blue_army;
        int sldr;
        while(sg--){
            scanf("%d", &sldr);
            green_army.insert(sldr);
        }

        while(sb--){
            scanf("%d", &sldr);
            blue_army.insert(sldr);
        }

        while(!blue_army.empty() && !green_army.empty()){
            int battles_count = min(b, min((int)green_army.size(), (int)blue_army.size()));
            vector<int> green_to_insert, blue_to_insert;
            for(int i = 0; i < battles_count; i++){
                int diff = *(--green_army.end()) - *(--blue_army.end());
                green_army.erase(--green_army.end());
                blue_army.erase(--blue_army.end());
                if (diff > 0) {
                    
                    green_to_insert.push_back(diff);
                }
                else if (diff < 0){
                    blue_to_insert.push_back(diff * - 1);
                }
            }
            for (int i = 0; i < green_to_insert.size(); ++i) green_army.insert(green_to_insert[i]);
            for (int i = 0; i < blue_to_insert.size(); ++i) blue_army.insert(blue_to_insert[i]);
        }


        if (blue_army.empty() && green_army.empty()){
            cout << "green and blue died" << endl;
        }
        else if (blue_army.empty()){
            cout << "green wins" << endl;
            for(auto it = green_army.rbegin(); it != green_army.rend(); it++){
                cout << *it << endl;
            }
        }
        else{
            cout << "blue wins" << endl;
            for(auto it = blue_army.rbegin(); it != blue_army.rend(); it++){
                cout << *it << endl;
            }          
        }
        if (n > 0) cout << endl; 
    }
}
