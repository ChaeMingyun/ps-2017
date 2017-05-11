//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//
//using namespace std;
//struct road;
//struct country;
//
//struct road {
//    int num;
//    country *left;
//    country *right;
//    long long cost;
//};
//struct country {
//    int num;
//    int car;
//    int amusementPark;
//    vector<road> roads;
//};
//int t, n, m;
//
////몇번째 도로인지, v[0] = rCars, v[1] = rAms, v[2] = lCars, v[3] = lAms
//void dfs(road &r, road &from, vector<long long> *v, vector<int> *isEnd) {
//    if (isEnd->at(r.left->num) == 0) {
//        v->at(2) += r.left->car;
//        v->at(3) += r.left->amusementPark;
//        isEnd->at(r.left->num) = 1;
//    }
//    int lRoadsSize = r.left->roads.size();
//    for (int i = 0; i < lRoadsSize; ++i) {
//        if (r.left->roads[i].num != r.num && r.left->roads[i].num != from.num) {
//            dfs(r.left->roads[i], r, v, isEnd);
//        }
//    }
//    if (isEnd->at(r.right->num) == 0) {
//        v->at(0) += r.right->car;
//        v->at(1) += r.right->amusementPark;
//        isEnd->at(r.right->num) = 1;
//    }
//    int rRoadsSize = r.right->roads.size();
//    for (int i = 0; i < rRoadsSize; ++i) {
//        if (r.right->roads[i].num != r.num && r.right->roads[i].num != from.num) {
//            dfs(r.right->roads[i], r, v, isEnd);
//        }
//    }
//}
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    cin >> t;
//    while (t--) {
//        cin >> n >> m;
//        int a, b, from, to;
//        vector<country> countries;
//        vector<road> roads;
//        for (int i = 0; i < n; ++i) {
//            cin >> a >> b;
//            country cntry;
//            cntry.num = i;
//            cntry.car = a;
//            cntry.amusementPark = b;
//            countries.push_back(cntry);
//        }
//        for (int i = 0; i < m; ++i) {
//            cin >> from >> to;
//            road rd;
//            rd.num = i;
//            rd.left = &countries[from - 1];
//            rd.right = &countries[to - 1];
//            rd.cost = 0;
//            roads.push_back(rd);
//            countries[from - 1].roads.push_back(rd);
//            countries[to - 1].roads.push_back(rd);
//        }
//        long long ans = 0;
//        vector<long long> v;
//        vector<int> isEnd;
//        for (int i = 0; i < m; ++i) {
//            for (int k = 0; k < 4; ++k) {
//                v.push_back(0);
//            }
//            for (int j = 0; j < n; ++j) {
//                isEnd.push_back(0);
//            }
//            //몇번째 도로인지, v[0] = rCars, v[1] = rAms, v[2] = lCars, v[3] = lAms
//            dfs(roads[i], roads[i], &v, &isEnd);
//            roads[i].cost = v[0] * v[3] + v[1] * v[2];
//            if (roads[i].cost > ans) {
//                ans = roads[i].cost;
//            }
//            isEnd.clear();
//            v.clear();
//        }
//        cout << ans << "\n";
//    }
//}