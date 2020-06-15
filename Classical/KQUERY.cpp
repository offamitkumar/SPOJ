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
const int MAXN = (int)3e4+100;
const int MOD = (int)1e9+7;

long long arr[MAXN];
vector<int> seg_tree[4*MAXN];

void build(int current_node , int start ,int end){
    if(start > end){
        return;
    }
    if(start == end){
        seg_tree[current_node].emplace_back(arr[start]);
        return;
    }
    int mid = (start + end) / 2;
    build(current_node * 2 , start , mid);
    build(current_node * 2 + 1 , mid+1 , end );
    merge( 
            seg_tree[current_node*2].begin(), seg_tree[current_node*2].end(), 
            seg_tree[current_node*2+1].begin(), seg_tree[current_node*2+1].end(), 
            back_inserter(seg_tree[current_node])
         );
    return;
}

int query(int current_node , int start , int end , int q_start , int q_end  , int k ){
    if(start > end  || q_start > end || start > q_end){
        return 0;
    }
    if(start >= q_start && end <= q_end){
        int temp = upper_bound(seg_tree[current_node].begin() ,seg_tree[current_node].end() ,k )
            - seg_tree[current_node].begin();
        return (end - start + 1) - temp;
    }
    int mid = (start + end) / 2;
    int left_ans = query(2*current_node , start , mid , q_start , q_end , k);
    int right_ans = query(2*current_node +1 , mid+1 , end , q_start ,q_end , k);
    return left_ans + right_ans;
}

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 

    int n; scanf("%d", &n);
    for(int i=0; i < n; ++i)  {
        cin >> arr[i];
    }
    build(1 , 0, n-1);
    int q; scanf("%d",&q);
    while(q--){
        int a,b,c; cin>> a >> b >> c; 
        --a , --b;
        int ans = query(1 , 0 , n-1 , a , b, c);
        cout << ans << '\n';
    }
#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
        << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
        << " ms" << '\n'; 
#endif 
    return 0;
}
