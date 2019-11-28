#include <bits/stdc++.h>
using namespace std;
//#define DEBUG

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> mi;
typedef vector<vector<pair<int, int>>> w_graph;
typedef vector<vector<int>> uw_graph;


string src;
vector<vector<char>> mm(500, vector<char>(500));

string pb(int l, int r, int t, int b){
	bool k = true;
	char ex = mm[t][l];
	for (int i = t; i <= b; i++){
		for (int j = l; j <= r; j++){
			if (ex != mm[i][j]){
				k = false;
				break;
			}
		}
	}
	if (k) {
		return string(1, ex);
	}
	else{
		int hdist = r - l, vdist = b - t;
		
		int ml = l + hdist / 2;
		int mt = t + vdist / 2;
		
		if (hdist == 0 && vdist == 0) {
			string q1 = pb(l, ml, t, mt);
			return "D" + q1;
		}
		else if (hdist == 0){
			string q1 = pb(l, ml, t, mt);
			string q2 = pb(l, ml, mt + 1, b);
			return "D" + q1 + q2;
		}
		
		else if (vdist == 0){
			string q1 = pb(l, ml, t, mt);
			string q2 = pb(ml + 1, r, t, mt);
			return "D" + q1 + q2;
		}
		else{
			string q1 = pb(l, ml, t, mt);
			string q2 = pb(ml + 1, r, t, mt);
			string q3 = pb(l, ml, mt + 1, b);
			string q4 = pb(ml + 1, r, mt + 1, b);
			return "D" + q1 + q2 + q3 + q4;
		}	
	}
}

int pd (int l, int r, int t, int b, int idx){
	if (src[idx] != 'D'){
		for (int i = t; i <= b; i++){
			for (int j = l; j <= r; j++){
   				mm[i][j] = src[idx];
			}
		}
		return idx;
	}
	else{
		int hdist = r - l, vdist = b  - t;
		int ml = l + hdist / 2;
		int mt = t + vdist / 2;
		
		if (hdist == 0){
			int ni = pd (l, ml, t, mt, idx + 1);
			ni = pd(l, ml, mt + 1, b, ni + 1);
			return ni;
		}
		else if (vdist == 0){
			int ni = pd (l, ml, t, mt, idx + 1);
			ni = pd (ml + 1, r, t, mt, ni + 1);
			return ni;
		}
		else{
			int ni = pd (l, ml, t, mt, idx + 1);
			ni = pd (ml + 1, r, t, mt, ni + 1);
			ni = pd(l, ml, mt + 1, b, ni + 1);
			ni = pd(ml + 1, r, mt + 1, b, ni + 1);
			return ni;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	#ifdef DEBUG
		freopen("out.txt", "w", stdout);
		freopen("in.txt", "r", stdin);
	#endif

	char type;
	while(true){
		cin >> type;
		if (type == '#') break;
		int n, m; cin >> n >> m;
		if (type == 'B'){
			
			for (int i = 0; i < n; i++){
				for (int j = 0; j < m; j++){
					cin >> mm[i][j];
				}
			}
	
			string ans = pb(0, m - 1, 0, n - 1);
			cout << (type == 'B'? "D" : "B") 
             << right << setw(4) << n  
             << right << setw(4) << m 
             ;
			int cp = 0;
			for(int i = 0; i < ans.size(); i++){
				if (i % 50 == 0) cout << endl;
				cout << ans[i];
			}
			cout << endl;
		}
		if (type == 'D'){
	 	    cin >> src;
	 	    pd(0, m - 1, 0, n - 1, 0);
	 	    string ans;
	 	    for (int i = 0; i < n; i++){
	 	    	for (int j = 0; j < m; j++){
	 	    		ans +=  mm[i][j];
  	   			}
	 	    }
  			cout << (type == 'B'? "D" : "B") 
             << right << setw(4) << n  
             << right << setw(4) << m 
           ;
	
			for(int i = 0; i < ans.size(); i++){
				if (i % 50 == 0) cout << endl;
				cout << ans[i];
			}
			cout << endl;
		}
	}
	

	return 0;
}

