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
    int t; cin >> t; 
    while (t--) {
        int n; cin >> n; 
        vector<int>dist(n); 
        vector<vector<pair<int,int>>>graph(n);
        map<string , int>index_of;
        for (int i=0; i<n; ++i) {
            string city_name; cin >> city_name; 
            index_of[city_name] = i;
            int connection; cin >> connection; 
            while (connection--) {
                int nr, cost; cin >> nr >> cost; 
                nr--; 
                graph[i].push_back({nr , cost});
            }
        }
        int query; cin >> query; 
        while (query--) {
            string city1 , city2; cin >> city1 >> city2; 
            fill(dist.begin() , dist.end(), INT_MAX);
            vector<bool>visited(n, false);
            int u = index_of[city1]; 
            int v = index_of[city2]; 
            dist[u] = 0; 
            priority_queue<pair<int,int>, vector<pair<int,int>> , function<bool(pair<int,int>&, pair<int,int>&)>>pq(compare); 
            pq.push({dist[u] , u});
            while (!pq.empty()) {
                u = pq.top().second; 
                if ( u == v) {
                    break;
                }
                int cost =pq.top().first;
                pq.pop();
                visited[u] = true;
                for (auto&itr:graph[u]) {
                    if (visited[itr.first]) {
                        continue;
                    }
                    if (dist[u]+itr.second < dist[itr.first]) {
                        dist[itr.first] = dist[u]+itr.second;
                        pq.push({dist[itr.first] , itr.first});
                    }
                }
            }
            cout << dist[v] << '\n'; 
        }
    }
    return 0;
}
