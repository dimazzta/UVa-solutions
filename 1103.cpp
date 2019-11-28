#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;

int n, m;
vector<string> a;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void fill(int r, int c, char replace, char with){
	if (r < 0 || c < 0 || r >= n || c >= m){
		return;
	}
	if (a[r][c] != replace) return;
	a[r][c] = with;
	for (int i = 0; i < 4; i++){
		fill(r + dr[i], c + dc[i], replace, with);
	}
}


void print(){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cout << a[i][j];
		}
		cout << endl;
	}
}

ii get_symbol(){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (a[i][j] == '1'){
				return {i, j};
			}
		}
	}
	return {-1, -1};
}

int main(){
	freopen("out.txt", "w", stdout);
	freopen("test.txt", "r", stdin);
	map<char, string> hex;
	map<int, char> decode;
	
	hex['0'] = "0000"; hex['1'] = "0001"; 
	hex['2'] = "0010"; hex['3'] = "0011"; 
	hex['4'] = "0100"; hex['5'] = "0101"; 
	hex['6'] = "0110"; hex['7'] = "0111"; 
	hex['8'] = "1000"; hex['9'] = "1001"; 
	hex['a'] = "1010"; hex['b'] = "1011"; 
	hex['c'] = "1100"; hex['d'] = "1101"; 
	hex['e'] = "1110"; hex['f'] = "1111";
	
	decode[0] = 'W'; 
	decode[1] = 'A';
	decode[2] = 'K';
	decode[3] = 'J';
	decode[4] = 'S';
	decode[5] = 'D';
	
	int tc = 1;
	while(cin >> n >> m, n || m){
		a.clear();
		a.resize(n);
		for (int i = 0; i < n; i++){
			string s; cin >> s;
			for (int j = 0; j < s.size(); j++){
				a[i] += hex[s[j]];
			}
		}
		m*=4;

		//print();
		
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (i == 0 || j == 0 || i == n - 1 || j == m - 1){
					fill(i, j, '0', '.');
				}
			}
		}
		
		//print();
		
		vector<char> answer;
		
		while(true){
			ii pos = get_symbol();
			if (pos.first == -1) break;
			fill(pos.first, pos.second, '1', '.');
			//print();
			int cnt = 0;
			
			for (int i = 0; i < n; i++){
				for (int j = 0; j < m; j++){
					if (a[i][j] == '0'){
						if (i > 0 && a[i - 1][j] == '.'){
							cnt++;
							fill(i, j, '0', '.');
						}
						else if (i < n - 1 && a[i + 1][j] == '.'){
							cnt++;
							fill(i, j, '0', '.');
						}
						else if (j > 0 && a[i][j - 1] == '.'){
							cnt++;
							fill(i, j, '0', '.');
						}
						else if (j < m - 1 && a[i][j + 1] == '.'){
							cnt++;
							fill(i, j, '0', '.');
						}
					}
				}
			}
			answer.push_back(decode[cnt]);
		}
		
		sort(answer.begin(), answer.end());
		cout << "Case " << tc++ << ": ";
		for (auto &s: answer){
			cout << s;
		}
		cout << endl;
	}

	return 0;
}

