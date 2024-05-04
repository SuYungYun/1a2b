#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;
int main() {
	srand(time(NULL));
	int all_num[3050][10], many = 0;;
	bool possible[3050];
	for(int i = 1; i < 10; i++) {
		for(int j = 1; j < 10; j++) {
			for(int k = 1; k < 10; k++) {
				for(int m = 1; m < 10; m++) {
					if(i != j && j != k && k != m && m != i && m != j && k != i) {
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
	int games = 1;
	while(true) {
		cout << "games no." << games << '\n';
		games++;
		for(int i = 1; ; i++) {
			cout << i << '\n';
			int guess_num = rand() % many;
			for(int j = 0; j < guess_num; j++) {
				if(possible[j] == false) {
					guess_num++;
				}
			}
			for(int j = 0; j < 4; j++) {
				cout << all_num[guess_num][j];
			}
			cout << '\n';
			string reply;
			cin >> reply;
			int a = reply[0] - '0', b = reply[2] - '0';
			if(a == 4) {
				cout << "I got it ouo!\n";
				break;
			}
			for(int j = 0; j < 3024; j++) {
				if(possible[j]) {
					int aa = 0, bb = 0;
					for(int k = 0; k < 4; k++) {
						if(all_num[j][k] == all_num[guess_num][k]){
							aa++;
							
						}
						for(int l = 0; l < 4; l++) {
							if(all_num[j][k] == all_num[guess_num][l] && k != l) {
							 	bb++;
							}
						}
					}
					if(aa != a || bb != b) {
						possible[j] = false;
						many--;
					}
				}
			}
		}
		cout << "again?(Y/N)\n";
		char yn;
		cin >> yn;
		if(yn == 'N') {
			break;
		}
	}
	return 0;
}
