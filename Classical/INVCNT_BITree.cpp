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
#define MAXN (int)1e7+10
#define LSB(i) ((i)&(-i))
array<int , MAXN>arr , bitree;
void update(int index , int mx ){
    while(index <= mx){
        bitree[index]+=1;
        index += LSB(index);
    }
}
int query(int mx){
    int sum{};
    while(mx>0){
        sum+=bitree[mx];
        mx-=LSB(mx);
    }
    return sum;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int t; scanf("%d",&t);
    while(t--){
         int n; scanf("%d",&n);
         long long counter{};
         fill(bitree.begin() , bitree.end() , 0);
         for(int i=0;i<n;++i){
             scanf("%d",&arr[i]);
         }
         int mx = *max_element(arr.begin() , arr.begin()+n );
         for(int i=0; i<n;++i){
             counter+=(query(mx) - query(arr[i]-1));
             update(arr[i] , mx);
         }
         printf("%lld\n" , counter);
    }
    return 0;
}
