//일반 구현 문제

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct player {
    int hp;
    int i;
    int j;
};

struct cell {
    int value;
    int i;
    int j;
};

bool cmp(cell a, cell b) {
    return a.value < b.value;
}

vector<cell> cellV;

cell findValue(int low, int high, int value) {
    int mid = (low + high) / 2;
    if (cellV[mid].value < value) {
        return findValue(mid + 1, high, value);
    } else if (cellV[mid].value > value) {
        return findValue(low, mid - 1, value);
    } else {
        return cellV[mid];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int m, n, num, k;
        cin >> m >> n;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> num;
                cell c = {num, i, j};
                cellV.push_back(c);
            }
        }
        sort(cellV.begin(), cellV.end(), cmp);
        cin >> k;
        while (k--) {//start while문
            int l, healthPoint, x, y, dummy;
            cin >> l;
            vector<int> deck_of_a;
            vector<int> deck_of_b;
            for (size_t i = 0; i < l; i++) {
                cin >> dummy;
                deck_of_a.push_back(dummy);
            }
            for (size_t i = 0; i < l; i++) {
                cin >> dummy;
                deck_of_b.push_back(dummy);
            }
            cin >> healthPoint >> x >> y;
            player A = {healthPoint, x, y};
            player B = {healthPoint, x, y};
            bool turn = true;//A 차례
            int index = 0, next;
            while (true) {
                if (turn) {
                    next = (index + 1) % l;
                    cell p = findValue(0, m * n - 1, deck_of_a[index] * deck_of_a[next]);
                    B.hp = B.hp - (abs(B.i - p.i) + abs(B.j - p.j));
                    if (B.hp <= 0) {
                        cout << "A\n";
                        break;
                    }
                    B.i = p.i;
                    B.j = p.j;
                    turn = false;
                } else {
                    cell p = findValue(0, m * n - 1, deck_of_b[index] * deck_of_b[next]);
                    A.hp = A.hp - (abs(A.i - p.i) + abs(A.j - p.j));
                    if (A.hp <= 0) {
                        cout << "B\n";
                        break;
                    }
                    A.i = p.i;
                    A.j = p.j;
                    index = (index + 2) % l;
                    turn = true;
                }
            }
        }//end while문
        cellV.clear();
    }
    return 0;
}