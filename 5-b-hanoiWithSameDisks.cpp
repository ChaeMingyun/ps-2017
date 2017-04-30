//재귀호출 알고리즘 문제

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> stk;
vector<int> v;
vector<int> numWeight;
int check = 0;
int qweqwe = 0;

bool doReturn() {
    return check >= qweqwe;
}

void hanoi(int n, int from, int by, int to) {
    if (doReturn()) {
        return;
    }
    if (n == 1) {
        for (int i = 0; i < numWeight[n - 1]; ++i) {
            ++check;
            if (from == 2) {
                stk.pop_back();
            }
            if (to == 2) {
                stk.push_back(n);
            }
            if (doReturn()) {
                return;
            }
        }
    } else {
        hanoi(n - 1, from, to, by);
        if (doReturn()) {
            return;
        }
        for (int i = 0; i < numWeight[n - 1]; ++i) {
            ++check;
            if (from == 2) {
                stk.pop_back();
            }
            if (to == 2) {
                stk.push_back(n);
            }
            if (doReturn()) {
                return;
            }
        }
        hanoi(n - 1, by, from, to);
        if (doReturn()) {
            return;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    //[start] 테스트케이스 입력
    int t;
    cin >> t;
    //[end] 테스트케이스 입력
    //[start] 테스트
    while (t--) {
        //[start] 초기입력
        int n;
        cin >> n;
        int num = 0;
        int temp = 1;
        for (int i = 0; i < n; ++i) {
            cin >> num;
            numWeight.push_back(num);
            v.push_back(temp);
            ++temp;
        }
        cin >> qweqwe;
        // [end] 초기입력
        check = 0;
        hanoi(n, 1, 2, 3);
        if (!stk.empty()) {
            while (!stk.empty()) {
                cout << stk.back() << " ";
                stk.pop_back();
            }
        } else {
            cout << 0;
        }
        cout << "\n";
        numWeight.clear();
        v.clear();
        qweqwe = check = 0;
    }
    //[end] 테스트
    return 0;
}
