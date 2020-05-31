#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <vector>
#include <array>
#include <set>
#include <climits>
#include <sstream>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <numeric>
using namespace std;
using namespace __gnu_pbds;
typedef tree< // find_by_order & order_of_key
        long long ,
        null_type ,
        less<long long> ,
        rb_tree_tag ,
        tree_order_statistics_node_update 
> new_set;
#define MOD 1000000007
#define MAXN (long long)(1e5+100)
array<long long, 4*MAXN>seg_tree;
array<long long, 4*MAXN>lazy;
void update(long long current_node, long long start, long long end , long long qs, long long qe, long long value){

    if (lazy[current_node] != 0) {
        seg_tree[current_node] += (end-start+1)*lazy[current_node];
        if(start != end ) {
            lazy[2*current_node] += lazy[current_node];
            lazy[2*current_node+1] += lazy[current_node];
        }
        lazy[current_node] = 0;
    }

    if(start > qe || end < qs || start > end) {
        return;
    }
    
    if(start >= qs && end <= qe){
        seg_tree[current_node] += (end-start+1)*value;
        if(start != end){
            lazy[2*current_node] += value;
            lazy[2*current_node+1] += value;
        }
        return;
    }

    long long mid = (start + end)/2;
    update(2*current_node, start, mid, qs, qe, value);
    update(2*current_node+1, mid+1, end, qs, qe, value);
    seg_tree[current_node] = seg_tree[2*current_node] + seg_tree[2*current_node+1];
    return;
}

long long query(long long current_node, long long start, long long end, long long qs, long long qe) {
    if( lazy[current_node] != 0 ) {
        seg_tree[current_node] += (end-start+1)*lazy[current_node];
        if ( start != end ) {
            lazy[2*current_node] += lazy[current_node];
            lazy[2*current_node+1] += lazy[current_node];
        }
        lazy[current_node] = 0;
    }

    if ( start > qe || end < qs || start > end ) {
        return 0;
    }

    if (start >= qs && qe >= end) {
        return seg_tree[current_node];
    }

    long long mid = (start + end) /2;
    long long left_ans = query(2*current_node, start , mid, qs , qe );
    long long right_ans = query(2*current_node+1,mid+1,end,qs,qe);
    return left_ans + right_ans;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    long long t; scanf("%lld",&t);
    while(t--){
        long long n, c; scanf("%lld %lld", &n, &c);
        fill(seg_tree.begin(), seg_tree.end(), 0ll);
        fill(lazy.begin(), lazy.end(), 0ll);
        long long left, right,value;
        while(c--){
            long long qt; scanf("%lld %lld %lld",&qt,&left,&right);
            --left;--right;
            if (qt == 0){
                scanf("%lld",&value);
                update(1,0 , n-1, left,right,value);
            } else {
                printf("%lld\n",query(1,0,n-1,left,right));
            }
        }
    }
    return 0;
}
