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
//  #include <unordered_map>
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



int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 

    int n, m; 
    while(cin >> n >> m && (n+m)){
        vector<vector<int>>dp(m+1 , vector<int>(n+1,0));
        vector<vector<int>>cost(m+1 , vector<int>(n+1,0));
        vector<pair<int,int>>party(m); 
        for(auto&itr:party){
            cin >> itr.first >> itr.second;
        }
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                dp[i][j] = dp[i-1][j];
                cost[i][j] = cost[i-1][j];
                const int &remain = j-party[i-1].first;
                if(remain >=0){
                    if(dp[i][j]<dp[i-1][remain]+party[i-1].second || (dp[i][j] == dp[i-1][remain]+party[i-1].second && 
                                cost[i][j] > cost[i-1][remain]+party[i-1].first)){
                        cost[i][j] = cost[i-1][remain]+party[i-1].first;
                    }
                    dp[i][j] = max(dp[i][j] , dp[i-1][remain]+party[i-1].second);
                }
            }
        }
        printf("%d %d\n",cost[m][n],dp[m][n]);
    }

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
        << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
        << " ms" << '\n'; 
#endif 
    return 0;
}
