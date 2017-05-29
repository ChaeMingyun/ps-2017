#include <iostream>
#include <vector>

using namespace std;

int t, n, d, num, c[18][18] = {0,};
vector<int> v;

int func(int depth, int pNum, int remainder) {
    if (remainder == 0) return 1;
    int mid = 0;
    if (depth < v.size()) {
        mid = func(depth + 1, v[depth], remainder - v[depth]) * c[pNum + v[depth] - 1][v[depth]];
    } else {
        for (int i = 1; i <= remainder; ++i) {
            mid += func(depth + 1, i, remainder - i) * c[pNum + i - 1][i];
        }
    }
    return mid;
}

int main() {
    ios::sync_with_stdio(false);
    c[0][0] = 1;
    for (int i = 1; i < 18; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0) {
                c[i][j] = 1;
            } else {
                c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            }
        }
    }
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> d;
        for (int i = 0; i <= d; i++) {
            cin >> num;
            v.push_back(num);
        }
        cout << func(1, v[0], n - v[0]) << "\n";
        v.clear();
    }
    return 0;
}