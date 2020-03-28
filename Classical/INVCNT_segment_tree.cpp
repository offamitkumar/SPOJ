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
#define MOD 1000000007
#define MAXN 10000009
array<int,MAXN>arr;
array<int,4*MAXN>te;

void update(int current_Node , int start , int end , int element){
    if(start==element && end == element){
        te[current_Node] = 1;
        return;
    }
    if(start>element || end<element){
        return;
    }
    int mid = (start+end)/2;
    update(2*current_Node , start , mid , element);
    update(2*current_Node+1 , mid+1 , end , element);
    te[current_Node] = te[2*current_Node] + te[2*current_Node +1 ];
    return;
}
int query(int current_Node , int start , int end , int qs , int qe){
    if(start>=qs && qe>=end){
        return te[current_Node];
    }
    if(start>end || qe<start || end<qs){
        return 0;
    }
    int mid = (start+end)/2;
    return query(2*current_Node , start , mid , qs , qe) + query(2*current_Node+1 , mid+1 , end , qs , qe);
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int t;scanf("%d",&t);
    while(t--){
        // write you code here
        int n;scanf("%d",&n);
        long long counter{};
        for(int i=0;i<n;++i){
            scanf("%d",&arr[i]);
        }
        int mx = *max_element(arr.begin() , arr.begin()+n );
        fill(te.begin() , te.end() , 0);
        for(int i=0;i<n;++i){
            counter += query(1 , 0 , mx , arr[i]+1 , mx);
            update(1 , 0 , mx , arr[i]);
        }
        printf("%lld\n",counter);
    }
    return 0;
}
