#include <bits/stdc++.h>
using namespace std;
#define int int64_t

bool compare(pair<int,int>&a, pair<int,int>&b) {
    return a.first > b.first;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n , m , q; cin >> n >> m >> q; 
    vector<vector<pair<int,int>>>graph(n); 
    for (int i=0; i<m; ++i) {
        int a,b,l; cin >> a >> b >> l; 
        graph[a].push_back({b,l}); 
        graph[b].push_back({a,l});
    }
    map<int,pair<int,int>>dp;
    while (q--) {
        int current_city; cin >> current_city; 
        auto itr = dp.find(current_city);
        if (itr != dp.end()) {
            cout << itr->second.first << ' ' << itr->second.second << '\n'; 
            continue;
        }
        int temp = current_city;
        vector<int>dis(n, INT_MAX); 
        vector<bool>visited(n ,false);
        dis[current_city] = 0; 
        priority_queue<pair<int,int> , vector<pair<int,int>> , function<bool(pair<int,int>&,pair<int,int>&)>>pq(compare);
        pq.push({dis[current_city] , current_city});
        int max_dis=0;
        map<int,int>dis_freq;
        while (!pq.empty()) {
            int dist_cur = pq.top().first; 
            current_city = pq.top().second; 
            pq.pop(); 
            if (visited[current_city]) continue;
            visited[current_city]=true;
            if (max_dis < dist_cur) {
                max_dis = dist_cur; 
            }
            dis_freq[dist_cur]++;
            for (auto&city:graph[current_city]) {
                if (visited[city.first]) continue;
                if (dis[city.first] > dist_cur + city.second) {
                    dis[city.first] = dist_cur + city.second; 
                    pq.push({dis[city.first] , city.first});
                }
            }
        }
        dp[temp] = make_pair(max_dis, dis_freq[max_dis]);
        cout << max_dis << ' ' << dis_freq[max_dis] << '\n'; 
    }
    return 0;
}
