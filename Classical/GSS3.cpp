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
#define MOD 1000000007
#define MAXN 50009
struct Node{
    int pref , suff , ans , sum;
    Node(){}
    Node(int v){
        pref = suff = ans = sum = v;
    }
};
array<Node,4*MAXN>seg;
array<long long,MAXN>arr;
Node get_node(int v){
    Node temp(v);
    return temp;
}
Node merge(Node &n1 , Node&n2){
    Node temp;
    temp.sum = n1.sum+n2.sum;
    temp.ans = max({n1.ans , n2.ans , n1.suff+n2.pref});
    temp.pref = max(n1.pref , n1.sum+n2.pref);
    temp.suff = max(n2.suff , n2.sum+n1.suff);
    return temp;
}
void build(int current_node , int start , int end){
    if(start>end){
        return ;
    }
    if(start==end){
        seg.at(current_node)= get_node(arr[start]);
        return;
    }
    int mid = (start+end)/2;
    build(2*current_node , start , mid);
    build(2*current_node+1  , mid+1 , end);
    seg.at(current_node) = merge(seg.at(2*current_node) , seg.at(2*current_node+1));
}
void update(int current_node , int start , int end , int left , int value){
    if(start>end or end<left or left<start){
        return ;
    }
    if(start==end){
        seg.at(current_node) = get_node(value);
        return;
    }
    int mid = (start+end)/2;
    update(2*current_node , start , mid , left , value);
    update(2*current_node+1  , mid+1 , end , left , value);
    seg.at(current_node) = merge(seg.at(2*current_node) , seg.at(2*current_node+1));
    return;
}
Node query(int current_node , int start , int end , int left , int right){
    if(start>end or end<left or start>right){
        return get_node(-90000000);
    }
    if(start>=left and end<=right){
        return seg.at(current_node);
    }
    int mid = (start+end)/2;
    Node left_ans = query(2*current_node , start ,mid , left , right);
    Node right_ans = query(2*current_node+1 , mid+1 , end , left , right);
    return merge(left_ans , right_ans);
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    long long n; scanf("%lld",&n);
    for(long long i=0;i<n;++i){
        scanf("%lld",&arr[i]);
    }
    build(1 , 0 , n-1 );
    long long q; scanf("%lld",&q);
    while(q--){
        int t , x ,y; scanf("%d%d%d",&t , &x , &y);
        if(t==0){
            --x;
            update(1 , 0 , n-1 , x , y);
        }else{
            --x; --y;
            Node ans = query(1 , 0 , n-1 , x , y).ans;
            printf("%d\n",ans.ans);
        }
    }
    return 0;
}
