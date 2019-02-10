#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	while (getline(cin, s)) {
		if (s == "DONE") break;
		int i = 0, j = s.size() - 1;
		bool palindrom = true;
		while (i <= j) {
			if (!isalpha(s[i])) i++;
			else if (!isalpha(s[j])) j--;
			else {
				if (toupper(s[j]) != toupper(s[i])) {
					cout << "Uh oh.." << endl;
					palindrom = false;
					break;
				}
				i++;
				j--;
			}
		}
		if (palindrom) {
			cout << "You won't be eaten!" << endl;
		}
	}
}

