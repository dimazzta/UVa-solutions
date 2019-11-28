#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

const int inf = 1e8;
const int nax = 40;
int res[nax][nax];
vector<bool> vis;
vector<int> p;
int mf;
int f;


void clear(){
	for (int i = 0; i < nax; i++){
		for (int j = 0; j < nax; j++){
			res[i][j] = 0;
		}
	}
}

void augment(int v, int min_edge){
	if (v == 36){
		f = min_edge;
		return;
	}
	if (p[v] != -1) {
		augment(p[v], min(min_edge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}

void m_flow(){
	mf = 0;
	while(true){
		f = 0;
		vis.assign(nax, false);
		p.assign(nax, -1);
		vis[36] = 1;
		queue<int> q;
		q.push(36);
		while(!q.empty()){
			int u = q.front(); q.pop();
			if (u == 37) break;
			for (int i = 0; i < nax; i++){
				if (res[u][i] > 0 && !vis[i]){
					vis[i] = true;
					q.push(i);
					p[i] = u;
				}
			}
		}
		augment(37, inf);
		if (f == 0){
			break;
		}
		mf += f;
		
	}
}


int main(){
	//freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	clear();
	while(getline(cin, s)){
		int app_cnt = 0;
		do{
			char app = s[0];
			int cnt = s[1] - '0';
			app_cnt += cnt;
			res[36][app - 'A'] = cnt;
			for (int i = 3; i < s.size() - 1; i++){
				int num = s[i] - '0';
				res[app - 'A'][num + 26] = inf;
			}
			getline(cin, s);
		}
		while(!s.empty());
		for (int i = 26; i < 36; i++){
			res[i][37] = 1;
		}
		m_flow();
		if (mf == app_cnt){
			for (int i = 26; i < 36; i++){
				bool found = false;
				for (int j = 0; j < 26; j++){
					if (res[i][j] == 1){
						cout << (char)(j + 'A');
						found = true;
						break;
					} 
				}
				if (!found) cout << "_";
				
			}
			cout << endl;
		}
		else{
			cout << "!" << endl;
		}
		clear();
		
	}
	return 0;
}


