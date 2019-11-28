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
	
	int n, l, c;
	while(cin >> n >> l >> c){
		int c_lines = 1;
		int c_chars = 0;
		int c_pages = 1;
		for (int i = 0; i < n; i++){
			string w; cin >> w;
			int size = w.size();
			if (c_chars == 0) c_chars += size;
			else {
				int space = c - c_chars;
				if (space >= size + 1){
					c_chars += size + 1;
				}
				else{
					c_lines++;
					if (c_lines > l){
						c_pages++;
						c_lines = 1;
					}
					c_chars = size;
				}
			}
		}
		cout << c_pages << endl;
	}



	return 0;
}

