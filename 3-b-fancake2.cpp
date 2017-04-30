//일반 구현 문제

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int k;
        cin >> k;
        vector<int> v;
        vector<int> sortedV;
        for (int j = 0; j < k; ++j) {
            int num;
            cin >> num;
            v.push_back(num);
            sortedV.push_back(num);
        }
        //내림차순 정렬
        sort(sortedV.rbegin(),sortedV.rend());
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            if(sortedV[i] == v[i]) {
                continue;
            } else {
                for (int j = i+1; j < k; ++j) {
                    if(sortedV[i] == v[j]) {
                        if(j != k-1) {
                            //j인덱스 k-1인덱스까지 한번 reverse
                            ++ans;
                            vector<int> temp;
                            for (int l = j; l < k; ++l) {
                                temp.push_back(v[l]);
                            }
                            for (int l = j; l < k; ++l) {
                                v[l] = temp.back();
                                temp.pop_back();
                            }

                        }
                        //i인덱스부터 k-1인덱스까지 한번 reverse
                        ++ans;
                        vector<int> temp;
                        for (int l = i; l < k; ++l) {
                            temp.push_back(v[l]);
                        }
                        for (int l = i; l < k; ++l) {
                            v[l] = temp.back();
                            temp.pop_back();
                        }
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}