//일반 구현 문제

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int arr[202][202] = {0,};
int t, n, m, total;
vector<string> tokens;
vector<string>::iterator tokens_it;

void Tokenize(const string &str, vector<string> &tokens, const string &delimiters = " ") {
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    string::size_type pos = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos) {
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        lastPos = str.find_first_not_of(delimiters, pos);
        pos = str.find_first_of(delimiters, lastPos);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    string s;
    //[start] 테스트 케이스 수 입력
    cin >> t;
    //[end] 테스트 케이스 수 입력
    //[start] 테스트
    while (t--) {
        //[start] 초기입력
        cin >> n >> m;
        string str;
        getline(cin, str);
        total = 2 * n - 1;
        for (int i = 1; i <= m; ++i) {
            getline(cin, str);
            Tokenize(str, tokens, " ");
            for (tokens_it = tokens.begin(); tokens_it != tokens.end(); tokens_it++) {
                if (arr[i][atoi(tokens_it->c_str())] == 1) {
                    arr[i][atoi(tokens_it->c_str())] = 0;
                    total -= 2;
                    --arr[i][0];
                } else {
                    arr[i][atoi(tokens_it->c_str())] = 1;
                    ++arr[i][0];
                }
            }
            tokens.clear();
        }
//        for (int k = 1; k <= m; ++k) {
//            for (int i = 1; i <= n; ++i) {
//                if (arr[k][i] == 1) {
//                    cout << "(" << k << "," << i << ")";
//                }
//            }
//            cout << "\n";
//        }
        //[end] 초기입력
        while (true) {
            for (int i = 1; i <= m; ++i) {
                if (total == 1) {
                    break;
                }
                if (arr[i][0] == 0) {
                    continue;
                }
                int j = i;
                while (true) {
                    j = (j + 1) % (m + 1);
                    if (arr[j][0] == 0) {
                        continue;
                    }
                    if (arr[j][0] <= i) {
                        for (int k = n; k >= 0; --k) {
                            if (arr[j][k] == 1) {
                                arr[j][k] = 0;
                                --arr[j][0];
                                if (arr[i][k] == 1) {
                                    arr[i][k] = 0;
                                    --arr[i][0];
                                    total -= 2;
                                } else {
                                    arr[i][k] = 1;
                                    ++arr[i][0];
                                }
                                break;
                            }
                        }
                    } else {
                        int count = 0;
                        for (int k = 1; k <= n; ++k) {
                            if (arr[j][k] == 1) {
                                ++count;
                                if (count == i) {
                                    arr[j][k] = 0;
                                    arr[j][0] -= 1;
                                    if (arr[i][k] == 1) {
                                        arr[i][k] = 0;
                                        --arr[i][0];
                                        total -= 2;
                                    } else {
                                        arr[i][k] = 1;
                                        ++arr[i][0];
                                    }
                                    break;
                                }
                            }
                        }
                    }
                    break;
                }
            }
            if (total == 1) {
                break;
            }
        }
        for (int i = 1; i <= m; ++i) {
            if (arr[i][0] != 0) {
                cout << i << "\n";
                arr[i][0] = 0;
                for (int j = 1; j <= n; ++j) {
                    if (arr[i][j] != 0) {
                        arr[i][j] = 0;
                        break;
                    }
                }
                break;
            }
        }
    }
    //[end] 테스트
    return 0;
}