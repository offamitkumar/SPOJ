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
#include <cassert>
#include <bitset>
#include <numeric>
using namespace std;
#define mod 1000000007
#define maxN (int)1e5+100
long long n, q;
vector<long long>segment(4*maxN);
vector<long long>arr(maxN);
void build(long long current_node , long long start, long long end){
    if(start==end){
        segment.at(current_node)=arr[start];
    }else{
        long long mid = (start+end)>>1;
        build(2*current_node,start,mid);
        build(2*current_node+1,mid+1,end);
        segment.at(current_node) = min(segment.at(2*current_node),segment.at(2*current_node+1));
    }
}
long long query(long long current_node , long long start , long long end , long long qs , long long qe ){
    if(qs > end or qe<start){
        return LONG_MAX;
    }
    if(qs==start and qe==end){
        return segment.at(current_node);
    }
    if(start==end){
        return segment.at(current_node);
    }
    long long mid = (start+end)>>1;
    return min(query(2*current_node,start,mid,qs,min(mid,qe)),query(2*current_node+1,mid+1,end,max(qs,mid),qe));
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    build(1ll,0ll,n-1ll);
    cin>>q;
    while(q--){
        long long qs,qe;cin>>qs>>qe;
        cout<<query(1ll,0ll,n-1ll,qs,qe)<<endl;
    }
    return 0;
}
