#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> mi;
typedef vector<vector<pair<int, int>>> w_graph;
typedef vector<vector<int>> uw_graph;


class UF {
private:
	vi p, rank;
public:
	UF (){}
	UF(int n) { init(n); }
	void init(int n) { rank.assign(n, 0); p.resize(n); iota(p.begin(), p.end(), 0); }
	int find(int i) { 
		if (i < 0) return i;
		return i == p[i] ? i : (p[i] = find(p[i])); }

	int merge(int i, int j) {
		int x = find(i), y = find(j);
		
		if (x != y) {
			if (x == -1) {
				return y;
			}
			else if (y == -1) {
				return x;
			}

			if (rank[x] < rank[y]) {
				p[x] = y;
				return y;
			}
			else {
				p[y] = x;
				if (rank[x] == rank[y]) rank[x]++;
				return x;
			}
		}
		else {
			return x;
		}
	}

	bool same(int i, int j) { 
 		return find(i) == find(j); 
	}
} friends;
vector<int> enemies;

bool areFriends(int i, int j) {
	return friends.same(i, j);
}

bool areEnemies(int i, int j) {
	return friends.same(friends.find(i), enemies[friends.find(j)]);
}

void setFriends(int i, int j) {
	if (areEnemies(i, j)) {
		cout << -1 << endl;
		return;
	}
	int x = friends.find(i), y = friends.find(j);
	int ex = enemies[x], ey = enemies[y];

	int root = friends.merge(x, y);
	int enemy = friends.merge(ex, ey);

	enemies[root] = enemy;
	if (enemy != -1) enemies[enemy] = root;
}

void setEnemies(int i, int j) {
	if (areFriends(i, j)) {
		cout << -1 << endl;
		return;
	}
	int x = friends.find(i), y = friends.find(j);
	int ex = enemies[x], ey = enemies[y];

	int root = friends.merge(x, ey);
	int root1 = friends.merge(y, ex);
	enemies[root] = root1;
	enemies[root1] = root;
}

int main() {
	int n;
	cin >> n;
	friends.init(n);
	enemies.assign(n, -1);
	int c, i, j;
	while (cin >> c >> i >> j) {
		if (c == 0) break;
		switch (c) {
		case 1:
			setFriends(i, j);
			break;

		case 2:
			setEnemies(i, j);
			break;

		case 3:
			cout << areFriends(i, j) << endl;
			break;

		case 4:
			cout << areEnemies(i, j) << endl;
			break;
		}
	}
}
