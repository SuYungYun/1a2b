#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
	cout << "規則:\nn個數字正確且位置正確 = nA\nm個數字正確但位置錯誤 = mB\n\n數字不重複，沒有0\n7次猜不到答案則失敗。\n\n"; 
	srand(time(NULL));
	int x = rand() % 3024;
	
	int ans[3050][10], num = 0;
	for(int i = 1; i <10; i++) {
		for(int j = 1; j < 10; j++) {
			for(int k = 1; k < 10; k++) {
				for(int m = 1; m < 10; m++) {
					if(i == j || j == k || k == m || m == i || j == m || k == i) {
						continue;
					}
					else {
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
		cout << "請輸入\n";
		string s;
		cin >> s;
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
			cout << "恭喜!!猜對了OuOb\n";
			ok++;
			break;
		}
		else {
			cout << a << "A" << b << "B\n";
		}
	}
	if(ok == 0) {
		cout << "你輸了OnOq\n正確答案為: ";
		for(int i = 0; i < 4; i++) {
			cout << ans[x][i];
		}
		cout << '\n';
	}
	return 0;
}
