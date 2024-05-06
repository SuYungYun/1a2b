#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;

int all_num[3050][10], many = 0;;
bool possible[3050];
bool not_same(char a, char b, char c, char d) {
	if(a != b && b != c && c != d && d != a && a != c && b != d) {
		return true;
	}
	else {
		return false;
	}
}

void init() {
	srand(time(NULL));
	for(int i = 1; i < 10; i++) {
		for(int j = 1; j < 10; j++) {
			for(int k = 1; k < 10; k++) {
				for(int m = 1; m < 10; m++) {
					if(not_same(i, j, k, m)) {
						all_num[many][0] = i;
						all_num[many][1] = j;
						all_num[many][2] = k;
						all_num[many][3] = m;
						possible[many] = true;
						many++;
					}
				}
			}
		}
	}
	cout << "If there are n correct numbers and their place are correct too, you will get 'nA'\n";
	cout << "If there are m correct numbers but thier place are wrong, you will get 'mB'.\n";
}

bool hint_valid(string s) {
	if(s.size() != 4) {
		return false;
	}
	else if(s[0] <= '9' && s[0] >= '0' && (s[1] == 'a' || s[1] == 'A') && s[2] <= '9' && s[2] >= '0' && (s[3] == 'b' || s[3] == 'B')) {
		return true;
	}
	else {
		return false;
	}
}

bool num_valid(string s) {
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
	init();
	int games = 1;
	while(true) {
		cout << "games no. " << games << '\n';
		games++;
		many = 3024;
		for(int i = 0; i < 3024; i++) {
			possible[i] = true;
		}
		int x = rand() % 3024, ans[4];
		for(int i = 0; i < 4; i++) {
			ans[i] = all_num[x][i];
		}
		while(true) {
			
			cout << "please type in:\n";
			string s;
			getline(cin,s);
			while(!num_valid(s)) {
				cout << "please type in a valid number\n";
				getline(cin,s);
			}
			for(int j = 0; j < 4; j++) {
				s[j] -= '0';
			}
			int pa = 0, pb = 0;
			for(int j = 0; j < 4; j++) {
				if(s[j] == ans[j]) {
					pa++;
				}
				for(int k = 0; k < 4; k++) {
					if(s[j] == ans[k] && j != k) {
						pb++;
					}
				}
			}
			if(pa == 4) {
				cout << "Congratulations!\n";
				break;
			}
			else {
				cout << pa << "A" << pb << "B\n";
			}
			
			int guess_num = rand() % many;
			for(int j = 0; j <= guess_num; j++) {
				if(possible[j] == false) {
					guess_num++;
				}
			}
			for(int j = 0; j < 4; j++) {
				cout << all_num[guess_num][j];
			}
			cout << '\n';
			string reply;
			getline(cin,reply);
			while(!hint_valid(reply)) {
				cout << "Reply is unvalid.\n" << "please try again\n";
				getline(cin,reply);
			}
			int ca = reply[0] - '0', cb = reply[2] - '0';
			if(ca == 4) {
				cout << "you losed!\n" << "My correct number is ";
				for(int i = 0 ; i < 4; i++) {
					cout << ans[i];
				}
				break;
			}
			for(int j = 0; j < 3024; j++) {
				if(possible[j]) {
					int caa = 0, cbb = 0;
					for(int k = 0; k < 4; k++) {
						if(all_num[j][k] == all_num[guess_num][k]){
							caa++;
							
						}
						for(int l = 0; l < 4; l++) {
							if(all_num[j][k] == all_num[guess_num][l] && k != l) {
							 	cbb++;
							}
						}
					}
					if(caa != ca || cbb != cb) {
						possible[j] = false;
						many--;
					}
				}
			}
			if(many == 0) {
				cout << "No possible answer.\n";
				break;
			}
		}
		cout << "restart?(Y/N)\n";
		char yn;
		cin >> yn;	
		string changeline;
		getline(cin,changeline); 
		if(yn == 'N' || yn == 'n') {
			break;
		}
		while(yn != 'Y' && yn != 'y' && yn != 'N' && yn != 'n') {
			cout << "plese type in Y or N\n";
			cin >> yn;
			string changeline;
			getline(cin,changeline); 
		}
	}
	return 0;
}
