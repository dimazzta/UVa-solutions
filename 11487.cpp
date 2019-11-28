#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<vector<vector<vector<int>>>> vvvvi;

const int inf = 1e7;
const int mod = 20437;
const int nax = 10;
int n;
char a[nax][nax];
int total;

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };
ll dp[nax][nax][30][2 * nax * nax];

int bfs(int s_row, int s_col, char end) {
	if (end == 'A') return 0;
	queue<pair<ii, int>> q;
	q.push({ { s_row, s_col }, 0 });
	vector<vector<bool>> visited(nax, vector<bool>(nax));
	visited[s_row][s_col] = 1;
	int answer = 0;
	bool can = false;
	char current_food = 'B';
	while (!q.empty() && !can) {
		pair<ii, int> t = q.front(); q.pop();
		int row = t.first.first;
		int col = t.first.second;
		int cost = t.second;

		for (int i = 0; i < 4; i++) {
			int nr = row + dr[i];
			int nc = col + dc[i];
			if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc] && a[nr][nc] != '#') {
				if (a[nr][nc] != '.' && a[nr][nc] > current_food) continue;
				visited[nr][nc] = true;
				if (a[nr][nc] == current_food) {
					answer += cost + 1;
					if (current_food == end) {
						can = true;
						break;
					}
					for (int u = 0; u < nax; u++) {
						for (int v = 0; v < nax; v++) {
							visited[u][v] = false;
						}
					}
					while (!q.empty()) q.pop();
					current_food++;
					visited[nr][nc] = 1;
					q.push({ { nr, nc }, 0 });
					break;
				}
				q.push({ { nr, nc }, cost + 1 });
			}
		}
	}
	if (!can) return -1;
	return answer;
}

int solve(int row, int col, char food, int length, vvvvi &memo) {
    if (row < 0 || col < 0 || row >= n || col >= n)
        return 0;
    
    if (length < 0)
        return 0;

    if (a[row][col] == '#')
        return 0;

    if (isalpha(a[row][col]) && a[row][col] > food)
        return 0;

    int &local = memo[row][col][food - 'A'][length];
    if (local != -1)
        return local;

    local = 0;

    if (a[row][col] == food) {
        if (food == 'A') {
            local = 1;
            return local;
        }

        food -= 1;
    }
    
    const int walk[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (int i = 0; i < 4; i++) {
        int new_row = row + walk[i][0];
        int new_col = col + walk[i][1];
        int result = solve(new_row, new_col, food, length - 1, memo);    
        local = (local + result) % 20437;
    }

    return local;
}

int main() {
	freopen("out.txt", "w", stdout);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int tc = 1;
	while (cin >> n, n) {
		ii a_coord;
		set<char> s;
		for (int i = 0; i < nax; i++) {
			for (int j = 0; j < nax; j++) {
				for (int u = 0; u < 30; u++) {
					for (int v = 0; v < 2 * nax * nax; v++) {
						dp[i][j][u][v] = -1;
					}
				}
			}
		}
		int stop_row = 0;
		int stop_col = 0;
		int mx_food = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				if (a[i][j] != '.' && a[i][j] != '#') {
					s.insert(a[i][j]);
					if (a[i][j] == 'A') a_coord = { i, j };
					if (a[i][j] - 'A' > mx_food){
						mx_food = a[i][j] - 'A';
						stop_row = i;
						stop_col = j;
					}
				}
			}
		}
		
		total = s.size();
		int len = bfs(a_coord.first, a_coord.second, 'A' + total - 1);
		if (len == -1) {
			cout << "Case " << tc++ << ": Impossible" << endl;
		}
		else {
			cout << "Case " << tc++ << ": " << len;
			char last = 'A' + total - 1;
			vvvvi memo(n, vvvi(n, vvi(last - 'A' + 1, vi(len + 1, -1))));
			int solution = solve(stop_row, stop_col, last, len, memo);
			cout << " " << solution << endl;
		}

	}
	return 0;
}


