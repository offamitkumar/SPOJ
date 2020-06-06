//  Author : Amit Kumar 

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>

//  #include <iostream>
  #include <algorithm>
//  #include <string>
//  #include <sstream>
//  #include <fstream>
//  #include <iomanip>
//  #include <chrono>
//  #include <numeric>
//  #include <utility>

//  #include <bitset>
//  #include <tuple>
//  #include <queue>
//  #include <stack>
//  #include <vector>
//  #include <array>
//  #include <unordered_map>
//  #include <unordered_set>
//  #include <set>
//  #include <map>
//  #include <deque>

//  #include <climits>
  #include <cstring>
//  #include <cmath>
//  #include <cassert>
#include <cstdio>
using namespace std;
//  using namespace std::chrono;
//  using namespace placeholders;
//  using namespace __gnu_pbds;
//  template<typename TypeInfo>
//  using new_set = tree< // find_by_order & order_of_key
//          TypeInfo ,
//          null_type ,
//          less<TypeInfo> ,
//          rb_tree_tag ,
//          tree_order_statistics_node_update 
//  > ;
const int MAXM = (int)1e5+100;
const int MAXN = 2400;
const int MOD = (int)1e5+100;
long long n; 

long long arr[MAXN], dp[MAXN][MAXN];
long long best(long long right_position , long long left_position){
    if(right_position >  left_position){
        return 0;
    }
    if(dp[right_position][left_position] != -1){ 
        return dp[right_position][left_position]; 
    }
    long long day = n - (left_position - right_position +1)+1;
    dp[right_position][left_position] = arr[right_position]*day + best(right_position+1,left_position);
    dp[right_position][left_position] = max(dp[right_position][left_position] , arr[left_position]*day + best(right_position, left_position-1));
    return dp[right_position][left_position];
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//    auto initial_time = high_resolution_clock::now();
    scanf("%lld",&n);
    memset(dp,-1,sizeof(dp));
    for(long long i=0;i<n;++i){
        scanf("%lld",&arr[i]);
    }
    printf("%lld\n",best(0,n-1));
//    auto final_time = high_resolution_clock::now();
//    cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
