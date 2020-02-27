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
    long long pref;
    long long suff;
    long long ans;
    long long sum;
    Node(){
    }
    Node(long long v){
        pref=suff=ans=sum=v;
    }
};
array<long long,MAXN>arr;
array<Node,4*MAXN>seg;
Node combine(const Node&N1 , const Node&N2){
    Node temp;
    temp.sum = N1.sum+N2.sum;
    temp.pref = max(N1.pref , N2.pref+N1.sum);
    temp.suff = max(N1.suff+N2.sum , N2.suff);
    temp.ans = max({N1.ans , N2.ans , N1.suff+N2.pref});
    return temp;
}
void build(int current_Node , int start , int end ){
    if(start>end){
        return ;
    }
    if(start==end){
        Node temp(arr[start]);
        seg[current_Node] = temp;
        return ;
    }
    int mid = (start + end)/2;
    build(2*current_Node , start , mid);
    build(2*current_Node+1,mid+1, end);
    seg.at(current_Node) = combine(seg.at(2*current_Node)  , seg.at(2*current_Node+1));
}
Node  query(int current_Node , int start , int end , int qs , int qe){
    if(start>end || qs>end || start>qe){
        Node temp(LLONG_MIN);
        return temp;
    }
    if(start>=qs and end<=qe){
        return seg.at(current_Node);
    }
    int mid = (start+end)/2;
    Node left_ans = query(2*current_Node , start , mid , qs , qe);
    Node right_ans = query(2*current_Node+1,mid+1,end,qs,qe);
    if(left_ans.ans==LLONG_MIN){
        return right_ans;
    }else if(right_ans.ans==LLONG_MIN){
        return left_ans;
    }
    return combine(left_ans,right_ans);
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    long long n; scanf("%lld",&n);
    for(int i=0;i<(int)n;++i){
        scanf("%lld",&arr[i]);
    }
    build(1 , 0 , n-1);
    int q;scanf("%d",&q);
    while(q--){
        long long l , r; scanf("%lld%lld",&l,&r);
        l--;r--;
        Node temp = query(1 , 0 , n-1 , l , r);
        printf("%lld\n",temp.ans);
    }
    return 0;
}
