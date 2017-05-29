//
// Created by 채민균 on 2017. 5. 24..
//
#include <iostream>

using namespace std;


int main(void) {
    std::ios::sync_with_stdio(false);
    int T, N, L, num;
    cin >> T;
    while (T--) {
        int s, f, r[2503] = {0,}, p[2503] = {0,}, input[2503];
        cin >> N >> L;
        for (int i = 1; i <= L; i++) {
            cin >> num;
            input[i] = num;
        }
        cin >> s >> f;
        p[0] = s;
        r[L + 1] = f;
        for (int i = L; i > 0; i--) {
            int first = input[i];
            if (first == r[i + 1]) {
                r[i] = input[i] + 1;
            } else if (input[i] + 1 == r[i + 1]) {
                r[i] = first;
            } else {
                r[i] = r[i + 1];
            }
        }
        for (int i = 1; i <= L; i++) {
            int first = input[i];
            if (first == p[i - 1]) {
                p[i] = input[i] + 1;
            } else if (input[i] + 1 == p[i - 1]) {
                p[i] = first;
            } else {
                p[i] = p[i - 1];
            }
        }
        int isEnd = false;
        for (int i = 1; i < L; i++) {
            int pPos = p[i];
            int rPos = r[i + 1];
            if (pPos == rPos + 1 || pPos == rPos - 1) {
                isEnd = true;
                break;
            }
        }
        if (isEnd) cout << "1" << endl;
        else cout << "0" << endl;
    }
    return 0;
}