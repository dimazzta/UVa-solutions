#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

int main(){
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vll ans;
	int n;
	int cnt = 0;
	
	for (int i = 0; i < 35; i++){
		for (int j = 0; j < 30; j++){
			for (int k = 0; k < 30; k++){
				for (int f = 0; f < 30; f++){
					ll cur = pow(2, i) * pow(3, j) * pow(5, k) * pow(7, f);
					if (cur > 0){
						ans.push_back(cur);
				
					}
					
				}
			}
		}
	}
	sort(ans.begin(), ans.end());
	int k; 
	while(cin >> k, k){
		string post = "th";
		if (k % 10 == 1 && k % 100 != 11) post = "st";
		if (k % 10 == 2 && k % 100 != 12 ) post = "nd";
		if (k % 10 == 3 && k % 100 != 13) post = "rd";
		
		cout << "The " << k << post << " humble number is " << ans[k - 1] << "." << endl;
	}
	return 0;
}


