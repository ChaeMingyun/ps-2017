//일반 구현 문제

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << 0 << "\n";
            continue;
        }
        if (n == 2) {
            cout << 1 << "\n";
            continue;
        }
        //2의 power승
        int power = 1;
        int num = 0;
        //이미 위의 n==1,n==2인 경우 두가지를 빼줘야함
        n -= 2;
        for (int j = 2; j < 9999999; ++j) {
            if (j * pow(2, power) < n) {
                n -= j * pow(2, power);
            } else {
                num = j;
                break;
            }
            ++power;
        }
        int row, column, ans;
        if (n % num == 0) {
            row = n / num - 1;
            int decimal = (int) (pow(2, num - 1) + row);
            ans = decimal & 1;
        } else {
            row = n / num;
            column = n % num;
            int decimal = (int) (pow(2, num - 1) + row);
            ans = (decimal >> (num - column)) & 1;
        }
        cout << ans << "\n";
    }
}
