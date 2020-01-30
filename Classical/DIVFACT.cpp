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
vector<int>pre(void){
    vector<bool>temp(55000,true);
    vector<int>ans;
    temp.at(0) = false;
    temp.at(1) = false;
    ans.push_back(2);
    for(long long i=3;i<(int)temp.size();i+=2){
        if(temp.at(i)){
            ans.push_back(i);
            for(long long j=i*i;j<(int)temp.size();j+=i){
                temp.at(j) = false;
            }
        }
    }
    return ans;
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
    vector<int>prime=pre();
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        long long counter{1};
        for(int i=0;prime.at(i)<=n;++i){
            long long k=prime.at(i);
            long long count{};
            while(n/k){
                count= (count+(n/k))%mod;
                k= (k*prime.at(i))%mod;
            }
            counter = (counter*((count+1))%mod)%mod;
        }
        cout<<counter<<endl;
    }
    return 0;
}
