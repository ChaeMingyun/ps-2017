#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    //[start] 테스트
    while (t--) {
        //[start] 초기입력
        int n, m, x, y;
        cin >> n;
        set<pair<int, int>> finger, comp;
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            finger.insert(pair<int, int>(x, y));
        }
        cin >> m;
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            comp.insert(pair<int, int>(x, y));
        }
        //[end] 초기입력
        set<pair<int, int>>::iterator fingerIter = finger.begin();
        bool flag = true;
        set<pair<int, int>>::iterator compIter = comp.begin();
        for (; compIter != comp.end(); ++compIter) {
            int count = 0;
            int dx = fingerIter->first - compIter->first;
            int dy = fingerIter->second - compIter->second;
            set<pair<int, int>>::iterator newIter = compIter;
            for (; newIter != comp.end(); ++newIter) {
                if (finger.find(pair<int, int>(newIter->first + dx, newIter->second + dy)) != finger.end()) {
                    ++count;
                }
            }
            //10*비교대상 지문 중 일치하는 좌표 수(count) >= 9*등록지문의 좌표 수
            if (10 * count >= 9 * n) {
                //일치하면 1 출력
                cout << "1\n";
                flag = false;
                break;
            }
        }
        //일치한다고 출력하지 않았으면 불일치이므로 0 출력
        if (flag) {
            cout << "0\n";
        }
    }
    //[end] 테스트
    return 0;
}
