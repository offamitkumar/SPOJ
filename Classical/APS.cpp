
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <array>
#include <set>
#include <climits>
#include <cassert>
#include <bitset>
using namespace std;
const long long mx = 10000000;
long long factor[mx+1];
long long a[mx+1];
void siv(void){
    a[0]=a[1]=0ll;
    for(long long i=2;i<=mx;++i){
        if(factor[i]==0){
            factor[i]=i;
            for(long long j=i*i;j<=mx;j+=i){
                if(factor[j]==0){
                    factor[j]=i;
                }
            }
        }
        a[i]=a[i-1]+factor[i];
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    siv();
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<a[n]<<endl;
    }
    return 0;
}
