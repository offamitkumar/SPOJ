//  Author : Amit Kumar 

#include <iostream>
#include <algorithm> 
#include <string> 
#include <sstream>
#include <fstream>
#include <iomanip> 
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
#include <unordered_set>
#include <set>
#include <map>
#include <deque>
#include <list>


#include <climits>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdio>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace std::chrono;
//  using namespace placeholders;
using namespace __gnu_pbds;
template<typename TypeInfo>
using new_set = tree< 
/* ob.order_of_key(element) -> number of element strictly less than element
 * *ob.find_by_order(n) ->  nth element in increasing order
 */
         TypeInfo ,
         null_type ,
         less<TypeInfo> ,
         rb_tree_tag ,
         tree_order_statistics_node_update 
 > ;

void show_me() { cerr << endl; }
 
template <typename HEAD, typename... TAIL>
void show_me(HEAD H, TAIL... T) {
  cerr << " " << (H);
  show_me(T...);
}
 
#ifdef HELL_JUDGE
#define show(...) cerr << "[" << #__VA_ARGS__ << "]:", show_me(__VA_ARGS__)
#else
#define show(...) 0
#endif

typedef int64_t Int;
 
template<typename A, typename B>
ostream& operator<<(ostream&out, const pair<A, B>&p){
    out << p.first << ' ' << p.second ;
    return out;
}

template<typename A, typename B>
istream& operator>>(istream&in, pair<A, B>&p){
    in >> p.first >> p.second ;
    return in;
}

template<typename A> 
istream& operator>>(istream&in, vector<A>&vec){
    for(auto&itr:vec){
        in >> itr;
    }
    return in;
}

template<typename A>
ostream& operator<<(ostream&out,const vector<A>&vec){
    for(auto&itr:vec){
        out << itr <<' '; // VVV 
    }
    return out;
}

const int MAXM = (int)1e5+100;
const int MAXN = (int)2*1e5+10000;
const int MOD = (int)1e9+7;

long long seg_tree[4 * MAXN];
long long arr[MAXN];
long long lazy_tree[4 * MAXN];

void build(long long current_node , long long start , long long end ){
    if(start > end){
        return ;
    }
    if(start == end ){
        seg_tree[current_node] = arr[start];
        return;
    }
    long long mid = (start + end) / 2ll;
    build(2*current_node , start , mid);
    build(2*current_node +1ll , mid + 1ll, end);
    seg_tree[current_node] = 0ll;
    lazy_tree[current_node] = 0ll;
}
void push_updates(long long current_node , long long start , long long end){
    if(start == end){
        seg_tree[current_node] = lazy_tree[current_node];
    }
    if(start != end){
        lazy_tree[2*current_node] = lazy_tree[current_node];
        lazy_tree[2*current_node + 1] = lazy_tree[current_node];
    }
    lazy_tree[current_node] = 0ll;
}
void update(long long current_node , long long start , long long end , long long q_start , long long q_end , long long value){
    if( start > q_end || end < q_start || start > end ){
        return ;
    }
    if(lazy_tree[current_node] != 0ll){
        push_updates(current_node , start , end);
    }
    if(start >= q_start && end <= q_end){
        if(start == end){
            seg_tree[current_node] = value;
        }else{
            lazy_tree[current_node]= value;
        }
        return;
    }
    long long mid = (start + end)/2;
    update(2*current_node , start , mid , q_start , q_end , value);
    update(2*current_node+1 , mid+1 ,  end , q_start , q_end , value);
}
long long query(long long current_node , long long start , long long end , long long pos){
    if(lazy_tree[current_node]!=0){
        push_updates(current_node , start , end);
    }
    if(start > pos || end < pos){
        return -1;
    }
    if(start == pos && end == pos){
        return seg_tree[current_node];
    }
    long long mid = (start + end) /2;
    if(mid >= pos){
        return query(2*current_node , start , mid , pos);
    }else{
        return query(2*current_node +1 , mid+1 , end , pos);
    }
}


signed main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    ios::sync_with_stdio(false); // FLUSH THE STREAM IF USING puts / printf / scanf/
    cin.tie(nullptr);            //
    cout.tie(nullptr);           //
#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 

    int n , q; cin >> n >> q; 
    int l,r,c; 
    while(q--){
        cin >> l >> r >> c;
        update(1 , 1, n ,l, r, c);
    }
    for(int i=1;i<=n;++i){
        cout << query(1 , 1 , n , i) <<'\n';
    }

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
