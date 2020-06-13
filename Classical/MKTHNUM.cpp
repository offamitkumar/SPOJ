//  Author : Amit Kumar 

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>

  #include <iostream>
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
  #include <vector>
//  #include <array>
//  #include <unordered_map>
//  #include <unordered_set>
//  #include <set>
//  #include <map>
//  #include <deque>

//  #include <climits>
//  #include <cstring>
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
const int MAXN = (int)1e5+100;
const int MOD = (int)1e9+7;

struct Node{
    int value;
    int index; 
};

vector<int>ori_arr(MAXN);
vector<Node>arr(MAXN);

bool comparator(const Node&a , const Node &b){
    return a.value < b.value; 
}
vector<int> seg[4*MAXN];
void build(int current_node , int start , int end){
    if(start > end){
        return ;
    }
    if(start == end){
        seg[current_node].push_back(arr[start].index);
        return ;
    }
    int mid = (start + end) /2;
    build(current_node*2 , start , mid );
    build(current_node*2+1 , mid+1 , end);
    merge(
            seg[current_node*2].begin() , seg[current_node*2].end() , 
            seg[current_node*2+1].begin() , seg[current_node*2+1].end() , 
            back_inserter(seg[current_node])
         );
    return ;
}

int query(int current_node , int start , int end , int q_start , int q_end , int k ){
    if(start == end){
        return seg[current_node].back();
    }
    int temp_value = upper_bound(
            seg[2*current_node].begin() , seg[2*current_node].end(), q_end
            ) - lower_bound(
                seg[current_node*2].begin() , seg[2*current_node].end(), q_start
                );
    int mid = (start + end) /2; 
    if(temp_value >= k){
        return query(current_node*2 , start ,mid , q_start , q_end , k);
    }else{
        return query(current_node*2+1, mid+1 , end , q_start , q_end , k-temp_value);
    }
}

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//    auto initial_time = high_resolution_clock::now();
    int n , q; scanf("%d %d",&n,&q);
    for(int i=1;i<=n;++i){
        scanf("%d ",&ori_arr[i]);
        arr[i].value = ori_arr[i];
        arr[i].index = i;
    }
    sort(arr.begin()+1, arr.begin()+n+1, comparator);
    build(1,1,n);
    while(q--){
        int a, b,c; scanf("%d %d %d",&a,&b,&c);
        int index = query(1, 1 , n , a, b, c);
        printf("%d\n",ori_arr[index]);
    }
//    auto final_time = high_resolution_clock::now();
//    cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
