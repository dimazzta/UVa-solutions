#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

const int nax = 100;

vector<int> v;
bool edges[nax][nax];
int indegree[nax];
bool visited[nax];

set<vector<int>> ans;

void dfs(int ver, vector<int> us){
	if (indegree[ver] > 0) return;
	us.push_back(ver);
	visited[ver] = true;
	bool k = false;
	for (int i = 0; i < v.size(); i++){
		if (!visited[v[i]]){
			k = true;
			if (edges[ver][v[i]]){
				indegree[v[i]]--;
				assert(indegree[v[i]] >= 0);
				us.push_back(v[i]);
				dfs(v[i], us);
				us.pop_back();
				indegree[v[i]]++;
			}
			else{
				us.push_back(v[i]);
				dfs(v[i], us);
				us.pop_back();
			}
		}
	}
	visited[ver] = false;
	if (!k) ans.insert(us);
 }

void read(){
	for (int i = 0; i < nax; i++){
		indegree[i] = 0;
		visited[i] = 0;
		for (int j = 0; j < nax; j++){
			edges[i][j] = false;
		}
	}
	v.clear();

	
	string s;
	cin.ignore();
	getline(cin, s);
	stringstream ss(s);
	char k;
	while(ss >> k){
		v.push_back(k);
	}
	getline(cin, s);
	stringstream as(s);
	string ms;
	while(as >> ms){
		char f = ms[0];
		char l = ms[2];
		edges[f][l] = true;
		indegree[l]++;
	}
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while(t--){
		read();
		for (int i = 0; i < v.size(); i++){
			vi tmp;
			dfs(v[i], tmp);
		}
		for (auto & vec : ans){
			for (int j = 0; j < vec.size(); j++){
				cout << vec[j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}


