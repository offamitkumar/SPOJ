//  Author : Amit Kumar 

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>

#include <iostream>
#include <algorithm> 
#include <string> 
//  #include <sstream> 
//  #include <fstream>
//  #include <iomanip> 
#include <chrono> 
#include <numeric>
#include <utility>
#include <functional>

#include <bitset>
#include <tuple>
#include <queue>
#include <stack>
#include <vector>
#include <array>
  #include <unordered_map>
//  #include <unordered_set>
#include <set>
#include <map>
//  #include <deque>

#include <climits>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdio>
using namespace std;
using namespace std::chrono;
//  using namespace placeholders;
//  using namespace __gnu_pbds;
//  template<typename TypeInfo>
//  using new_set = tree< // find_by_order & order_of_key
//                   TypeInfo ,
//                   null_type ,
//                   less<TypeInfo> ,
//                   rb_tree_tag ,
//                   tree_order_statistics_node_update 
//       > ;

void debug_out() { cerr << endl; }
 
template <typename HEAD, typename... TAIL>
void debug_out(HEAD H, TAIL... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef HELL_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 0
#endif
 

const int MAXM = (int)1e5+100;
const int MAXN = (int)1e5+100;
const int MOD = (int)1e9+7;

vector<int>in_deg;
vector<vector<int>>graph;
queue<int>zero_;
map<int , set<int>>ans;

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 

    int t; scanf("%d",&t);
    for(int x=1;x<=t;++x){
        in_deg.clear();
        graph.clear();
        ans.clear();
        int n,m; scanf("%d %d",&n,&m);
        in_deg.resize(n);
        graph.resize(n);
        for(int i=0;i<m;++i){
            int u ,v; scanf("%d %d",&u,&v);
            graph[v].push_back(u);
            ++in_deg[u];
        }
        for(int i=0;i<n;++i){
            if(in_deg[i]==0){
                zero_.push(i);
            }
        }
        int Rank = 1;
        zero_.push(-1); 
        while(!zero_.empty()){
            if(zero_.front() == -1){
                ++Rank;
                zero_.pop();
                zero_.push(-1);
            }
            int node = zero_.front(); zero_.pop();
            if(node == -1){
                break;
            }
            ans[Rank].insert(node);
            for(auto&itr:graph[node]){
                --in_deg[itr];
                if(in_deg[itr]==0){
                    zero_.push(itr);
                }
            }
        }
        printf("Scenario #%d:\n",x);
        for(auto&itr:ans){
            for(auto&it:itr.second){
                printf("%d %d\n",itr.first, it);
            }
        }
    }

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
        << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
        << " ms" << '\n'; 
#endif 
    return 0;
}
