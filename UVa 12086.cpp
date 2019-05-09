#include <bits/stdc++.h>
using namespace std;

vector<int> st;
int left(int p){
	return (p << 1);
}
int right(int p){
	return (p << 1) + 1;
}
void print(int p, int L, int R){
	cout << "p = " << p << ": " << L << "-" << R << ": " << st[p] << endl;
	if (L == R) return;
	print(left(p), L, (L + R) / 2);
	print(right(p), (L + R) / 2 + 1, R); 
}

void build(int p, int L, int R, vector<int> & val){
	if (L == R) st[p] = val[L - 1];
	else{
		build(left(p), L, (L + R) / 2, val);
		build(right(p), (L + R) / 2 + 1, R, val);
		st[p] = st[left(p)] + st[right(p)];
	}
}

void update(int p, int L, int R, int idx, int val){
	if (L > idx || R < idx) return;
	if (L == R){
		st[p] = val;
		return;
	}
	update(left(p), L, (L + R) / 2, idx, val);
	update(right(p), (L + R) / 2 + 1, R, idx, val);
	st[p] = st[left(p)] + st[right(p)];
}

int rsq(int p, int L, int R, int UL, int UR){
	if (L > UR || R < UL) return 0;
	if (L >= UL && R <= UR){
		return st[p];
	}
	return rsq(left(p), L, (L + R) / 2, UL, UR) + rsq(right(p), (L + R) / 2 + 1, R, UL, UR);
}


int main(){
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int n;
	int t = 1;
	for(;;){
		cin >> n;
		if (n == 0) break;
		
		if (t != 1) cout << endl;
		cout << "Case " << t++ << ":" << endl;
		vector<int> values(n);
		for (int i = 0; i < n; i++){
			cin >> values[i];
		}
		st.assign(4 * n, 0);
		build(1, 1, n, values);
		string type;
		for(;;){
			
			cin >> type;
			if (type == "END") break;
			int x, y;
			cin >> x >> y;
			if (type == "M"){
				int ans = rsq(1, 1, n, x, y);
				cout << ans << endl;
			}
			if (type == "S"){
				update(1, 1, n, x, y);
			}
		}
	}
}
