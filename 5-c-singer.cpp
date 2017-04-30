//위상정렬 알고리즘 문제

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    //[start] 테스트케이스 입력
    int t;
    cin >> t;
    //[end] 테스트케이스 입력
    //[start] 테스트
    while (t--) {
        //[start] 초기입력
        int n, m;
        cin >> n >> m;
        //[info] receive는 자기정점으로 올 수 있는 정점을 저장하는 벡터
        vector<vector<int> > receive(n + 1);
        //[info] give는 자기정점에서 갈 수 있는 정점을 저장하는 벡터
        vector<vector<int> > give(n + 1);
        while (m--) {
            int k;
            cin >> k;
            vector<int> vec;
            int num;
            for (int i = 0; i < k; ++i) {
                cin >> num;
                vec.push_back(num);
                if (i > 0) {
                    receive[vec[i]].push_back(vec[i - 1]);
                    give[vec[i - 1]].push_back(vec[i]);
                }
            }
        }
        // [end] 초기입력
        vector<int> ans;
        // [info] arr는 정점을 이미 처리했는지를 나타내는 배열
        int arr[1005] = {0,};

        while (true) {
            bool flag = true;
            for (int i = 1; i <= n; ++i) {
                if (receive[i].size() == 0 && arr[i] != 1) {
                    flag = false;
                    ans.push_back(i);
                    arr[i] = 1;
                    //자기 정점에서 갈 수 있는 정점을 지워줘야한다
                    int giveSize = give[i].size();
                    for (int j = 0; j < giveSize; ++j) {
                        int receiveSize = receive[give[i][j]].size();
                        for (int k = 0; k < receiveSize; ++k) {
                            if (receive[give[i][j]][k] == i) {
                                receive[give[i][j]].erase(receive[give[i][j]].begin() + k);
                                --receiveSize;
                                --k;
                            }
                        }
                    }
                    break;
                }
            }
            if (flag) {
                break;
            }

        }
        if (ans.size() == n) {
            int ansSize = ans.size();
            for (int i = 0; i < ansSize; ++i) {
                cout << ans[i] << " ";

            }
        } else {
            cout << 0;
        }
        cout << "\n";
    }
    //[end] 테스트
    return 0;
}