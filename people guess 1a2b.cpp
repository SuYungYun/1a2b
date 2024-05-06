#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool not_same(int a, int b, int c, int d) {
	if(a != b && b != c && c != d && d != a && a != c && b != d) {
		return true;
	}
	else {
		return false;
	}
}

bool valid(string s) {
	bool ok = true;
	if(s.size() != 4) {
		ok = false;
	}
	else if(!not_same(s[0], s[1], s[2], s[3])) {
		ok = false;
	}
	else { 
		for(int i = 0; i < 4; i++) { 
			if(s[i] > '9' || s[i] < '1') {
				ok = false;
				break;
			}
		}
	}
	return ok;
}

int main() {
	cout << "If there are n correct numbers and their place are correct too, you will get 'nA'\n";
	cout << "If there are m correct numbers but thier place are wrong, you will get 'mB'.\n";
	cout << "You will lose after 7 wrong answer.\n";
	srand(time(NULL));
	int x = rand() % 3024;
	
	int ans[3050][10], num = 0;
	for(int i = 1; i <10; i++) {
		for(int j = 1; j < 10; j++) {
			for(int k = 1; k < 10; k++) {
				for(int m = 1; m < 10; m++) {
					if(not_same(i, j, k, m)) {
						ans[num][0] = i;
						ans[num][1] = j;
						ans[num][2] = k;
						ans[num][3] = m;
						num++;
					}		
				}
			}
		}
	}
	int ok = 0;
	for(int i = 0; i < 7; i++) {
		cout << "please type in:\n";
		string s;
		getline(cin,s);
		while(!valid(s)) {
			cout << "please type in  a valid number\n";
			getline(cin,s);
		}
		for(int j = 0; j < 4; j++) {
			s[j] -= '0';
		}
		int a = 0, b = 0;
		for(int j = 0; j < 4; j++) {
			if(s[j] == ans[x][j]) {
				a++;
			}
			for(int k = 0; k < 4; k++) {
				if(s[j] == ans[x][k] && j != k) {
					b++;
				}
			}
		}
		if(a == 4) {
			cout << "Congratulations!\n";
			ok++;
			break;
		}
		else {
			cout << a << "A" << b << "B\n";
		}
	}
	if(ok == 0) {
		cout << "You losed.\nThe correct answer is ";
		for(int i = 0; i < 4; i++) {
			cout << ans[x][i];
		}
		cout << '\n';
	}
	return 0;
}
