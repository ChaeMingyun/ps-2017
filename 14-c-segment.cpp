//
// Created by 채민균 on 2017. 6. 2..
//

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
int arr[10][11], t, len;
string maxi;

void func(int index, int k, string str) {
    if (k == 0) {
        if (maxi.compare(str) < 0) {
            maxi = str;
        }
        return;
    }
    if (len == index) return;
    int mini = min(k, arr[str[index] - 48][10]); //바꿀 수 있는 최대 수
    for (int j = 9; j >= 0; --j) {
        if (maxi.compare(str) > 0) return;
        int toI = str[index] - 48;
        if (arr[toI][j] <= mini) {
            char temp = str[index];
            str[index] = char(j + 48);
            func(index + 1, k - arr[toI][j], str);
            str[index] = temp;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    int digitInfo[10][7] = {{1, 1, 1, 1, 1, 1, 0},//0
                            {0, 1, 1, 0, 0, 0, 0},//1
                            {1, 1, 0, 1, 1, 0, 1},//2
                            {1, 1, 1, 1, 0, 0, 1},//3
                            {0, 1, 1, 0, 0, 1, 1},//4
                            {1, 0, 1, 1, 0, 1, 1},//5
                            {1, 0, 1, 1, 1, 1, 1},//6
                            {1, 1, 1, 0, 0, 0, 0},//7
                            {1, 1, 1, 1, 1, 1, 1},//8
                            {1, 1, 1, 1, 0, 1, 1}};//9
    for (int i = 0; i < 10; ++i) {
        int maxi = 0;
        for (int j = 0; j < 10; ++j) {
            int count = 0;
            for (int m = 0; m < 7; ++m) {
                if (digitInfo[i][m] != digitInfo[j][m]) ++count;
            }
            arr[i][j] = count;
            if (maxi < count) maxi = count;
        }
        arr[i][10] = maxi;
    }
    cin >> t;
    string dump;
    getline(cin, dump);
    while (t--) {
        string s, stringCount = "", number = "";
        getline(cin, s);
        int state = 0, size = (int) s.length(), k;
        for (int i = 0; i < size; ++i) {
            if (state == 1) {
                if (48 <= s[i] && s[i] < 58) {
                    number += s[i];
                }
            } else if (state == 2) {
                if (48 <= s[i] && s[i] < 58) {
                    stringCount += s[i];
                }
            }
            if (s[i] == ' ') {
                ++state;
            }
        }
        k = atoi(stringCount.c_str());
        len = (int) number.size();
        maxi = "";
        for (int i = 0; i < len; ++i) {
            maxi += '0';
        }
        func(0, k, number);
        cout << maxi << "\n";
    }
    return 0;
}