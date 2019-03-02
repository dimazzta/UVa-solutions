#include <bits/stdc++.h>
using namespace std;


string check_decoded_result(vector< pair<string, string> > & comb, string & res){
    for (auto c : comb){
        if (c.second == res) {
            return c.first;
        }
    }
    return "";
}

set<string> lacking_element(vector< pair<string, string> > & comb, char & c){
    set<string> res;
    for (auto co : comb){
        if (co.second[0] == c || co.second[1] == c){
            res.insert(co.first);
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector< pair<string, string> > combinations = { {"A", "AA"}, {"AB", "AB"}, {"A", "AO"}, 
                                                  {"B", "BB"}, {"B", "BO"}, {"O", "OO"} };
    char p1[4], p2[4], c[4];
    int i = 1;
    while(scanf("%s %s %s", p1, p2, c)){
        string parent1 = p1, parent2 = p2, child = c;
        if (parent1 == "E") break;
        string p1_copy = parent1, p2_copy = parent2, c_copy = child;

        vector<string> possible_results;
        set<string> actual_results;
        
        if (child == "?"){
            int both_rh = !(parent1[parent1.size() - 1] == '-' && parent2[parent2.size() - 1] == '-');
            parent1.erase(--parent1.end());
            parent2.erase(--parent2.end());

            set<char> p1_abo, p2_abo;
            for (pair<string, string> p : combinations){
                if (p.first == parent1) {
                    p1_abo.insert(p.second[0]);
                    p1_abo.insert(p.second[1]);
                }
                if (p.first == parent2){
                    p2_abo.insert(p.second[0]);
                    p2_abo.insert(p.second[1]);
                }
            }
            for (auto ch : p1_abo){
                for (auto ch1 : p2_abo){
                    possible_results.push_back({ch, ch1});
                    possible_results.push_back({ch1, ch});
                }
            }
            for (auto result : possible_results){
                string s = check_decoded_result(combinations, result);
                if (s != "") {
                    actual_results.insert(s + "-");
                    if (both_rh) actual_results.insert(s + "+");
                }
            }

            cout << "Case " << i++ << ": " << p1_copy << " " << p2_copy << " ";
            if (actual_results.size() > 1) cout << "{";
            for (auto a_result : actual_results) {
                if (a_result != *(--actual_results.end()))
                    cout << a_result << ", ";
                else {
                    cout << a_result;
                    if (actual_results.size() > 1) cout << "}";
                }
            }
            cout << endl;
        }

        
        else{
            int parent_rh = 0;
            string a_parent = parent1 == "?" ? parent2 : parent1;
            if (child[child.size() - 1] == '+'){
                if (a_parent[a_parent.size() - 1] == '-') parent_rh = 2;
                else parent_rh = 3;
            }
            else{
                parent_rh = 3;
            }
            if (parent_rh == 0){
                cout << "Case " << i++ << ": " ;
                parent1 == "?" ? cout << "IMPOSSIBLE" : cout << parent1;
                cout << " ";
                parent2 == "?" ? cout << "IMPOSSIBLE" : cout << parent2;
                cout << " ";
                cout << child << endl;
            }
            else{
                set<string> c_abo;
                set<char> p_abo;
                child.erase(--child.end());
                a_parent.erase(--a_parent.end());

                for (auto p : combinations){
                    if (p.first == child){
                        c_abo.insert(p.second);
                    }
                    if (p.first == a_parent){
                        p_abo.insert(p.second[0]);
                        p_abo.insert(p.second[1]);
                    }
                }
                set<string> possible_elements;

                for (auto str : c_abo){
                    for (auto ch : p_abo){
                        if (str[0] == ch){
                            set<string> new_batch = lacking_element(combinations, str[1]);
                            possible_elements.insert(new_batch.begin(), new_batch.end()); 
                        }
                        if (str[1] == ch){
                            set<string> new_batch = lacking_element(combinations, str[0]);
                            possible_elements.insert(new_batch.begin(), new_batch.end()); 
                        }
                    }
                }
                
                for (auto result : possible_elements){
                    if (parent_rh == 1){
                        actual_results.insert(result + "-");
                    }
                    else if (parent_rh == 2){
                        actual_results.insert(result + "+");
                    }
                    else{
                        actual_results.insert(result + "-");
                        actual_results.insert(result + "+");
                    }
                }
                cout << "Case " << i++ << ": ";
                if (parent1 != "?"){
                    cout << p1_copy << " ";
                }
                if (actual_results.empty()) cout << "IMPOSSIBLE ";
                else{
                    cout << "{";
                    for (auto a_result : actual_results) {
                        if (a_result != *(--actual_results.end()))
                            cout << a_result << ", ";
                        else
                            cout << a_result << "} ";
                    }
                }
                if (parent2 != "?"){
                    cout << p2_copy << " ";
                }
                cout << c_copy << endl;
            }
        }
    }

    return 0;
}
 
