//
// Created by 채민균 on 2017. 6. 2..
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int>> v;
vector<int> vec;
int ans, len, t;

void vSort() {
    sort(v.begin(), v.end());
}

void vecSort() {
    sort(vec.begin(), vec.end());
}

void func45() {
    vSort();
    for (int i = len - 1; i > 0; --i) {
        for (int j = i - 1; j >= 0; --j) {
            if (v[i].second >= v[j].second) ++ans;
//            if(v[i].first == v[j].first && v[i].second == v[j].second) --ans;
        }
    }
}

void func225() {
    vSort();
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (v[i].second <= v[j].second) ++ans;
//            if(v[i].first == v[j].first && v[i].second == v[j].second) --ans;
        }
    }
}

void func90360() {
    vecSort();
    for (int i = len - 1; i > 0;) {
        int x = 0, ind = i - 1;
        for (int j = i; j >= 0; --j) {
            if (vec[i] == vec[j]) ++x;
            else {
                ind = j;
                break;
            }
        }
        ans += x * i;
        i = ind;
    }
}

void func180270() {
    vecSort();
    for (int i = 0; i < len - 1;) {
        int x = 0, ind = i + 1;
        for (int j = i; j < len; ++j) {
            if (vec[i] == vec[j]) ++x;
            else {
                ind = j;
                break;
            }
        }
        ans += x * (len - 1 - i);
        i = ind;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        len = m;
        if (n == 90 || n == 180 || n == 270 || n == 360 || n == 0) {
            vec.clear();
            if (n == 180 || n == 360) {
                for (int i = 0; i < len; ++i) {
                    int x, y;
                    cin >> x >> y;
                    vec.push_back(y);
                }
            } else {
                for (int i = 0; i < len; ++i) {
                    int x, y;
                    cin >> x >> y;
                    vec.push_back(x);
                }
            }
        } else {
            v.clear();
            if ((90 < n && n < 180) || (270 < n && n < 360)) {
                for (int i = 0; i < len; ++i) {
                    int x, y;
                    cin >> x >> y;
                    v.push_back(pair<int, int>(x, -y));
                }
            } else {
                for (int i = 0; i < len; ++i) {
                    int x, y;
                    cin >> x >> y;
                    v.push_back(pair<int, int>(x, y));
                }
            }
        }
        ans = 0;
        if ((0 < n && n < 90) || (90 < n && n < 180)) {
            func45();
        } else if (n == 315 || n == 225) {
            func225();
        } else if (n == 90 || n == 360 || n == 0) {
            func90360();
        } else if (n == 180 || n == 270) {
            func180270();
        }
        cout << ans << "\n";
    }
    return 0;
}