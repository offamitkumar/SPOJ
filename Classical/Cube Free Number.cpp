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
array<int,2000009>arr;
inline void pre(void){
    for(long long i=2;i*i*i<2000009;++i){
        long long k = i*i*i;
        for(long long j = k;j<2000009;j+=k){
            arr[j] = -1;
        }
    }
    long long counter = 1;
    for(long long i=1;i<2000009;++i){
        if(arr[i]==-1){
            continue;
        }
        arr[i] = counter++;
    }
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
    pre();
    int t; cin>>t;
    for(long long i=1;i<=t;++i){
        long long n; cin>>n;
        cout<<"Case "<<i<<": ";
        if(arr[n]==-1){
            cout<<"Not Cube Free"<<endl;
            continue;
        }
        cout<<arr[n]<<endl;
    }
    return 0;
}
