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

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	#ifdef DEBUG
		freopen("out.txt", "w", stdout);
	#endif

	int n, m, r, c;
	while(cin >> n >> m >> r >> c, n || m || r || c){
        vector<vector<char>> a(n, vector<char>(m));
        vector<vector<char>> b(n, vector<char>(m));
        
        for (int i = 0; i < n; i++){
        	for (int j = 0; j < m; j++){
        		cin >> a[i][j];
       			b[i][j] = '0';
			}
        }
        int cnt = 0;
        for (int i = 0; i + r <= n; i++){
        	for (int j = 0; j + c <= m; j++){
        		if (a[i][j] != b[i][j]){
        			cnt++;
        			for (int i1 = i; i1 < i + r; i1++){
        				for (int j1 = j; j1 < j + c; j1++){
       						if (b[i1][j1] == '0') b[i1][j1] = '1'; 
       						else b[i1][j1] = '0';
        				}
        			}
        		}
			}
        }
        
        bool t = true;
        for (int i = 0; i < n; i++){
        	for (int j = 0; j < m; j++){
        		if (a[i][j] != b[i][j]) {
        			t = false;
        		}
			}
        }
        if (!t){
        	cout << -1 << endl;
        }
        else{
        	cout << cnt << endl;
        }
	}


	return 0;
}

