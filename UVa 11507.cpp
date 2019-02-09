#include <bits/stdc++.h>
using namespace std;

int main() {
	int l;
	while (scanf("%d", &l), l) {
		string res = "+x";
		string curr = "";
		l--;
		while (l--) {
			cin >> curr;
			if (curr == "No") continue;
			else {
				if (curr[1] == res[1]) {
					if (curr[0] == res[0]) {
						res = "-x";
					}
					else {
						res = "+x";
					}
				}
				else {
					if (res == "-x") {
						res[0] = curr[0] == '-' ? '+' : '-';
						res[1] = curr[1];
					}
					if (res == "+x"){
						res = curr;
					}
				}
				
			}

		}
		cout << res << endl;
	}

}

