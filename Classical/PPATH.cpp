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

vector<vector<int>>v(9999+10);
vector<int>dist;
bool isprime(int j){
    for(int i=2;i*i<=j;++i){
        if(j%i==0){
            return false;
        }
    }
    return true;
}
bool valid(int a,int b){
    int counter{};
    while(a){
        if(a%10!=b%10){
            counter++;
        }
        a/=10;
        b/=10;
    }
    return counter==1;
}
void pre(void){
    vector<int>prime;
    for(int i=1000;i<=9999;++i){
        if(isprime(i)){
            cerr<<"prime = "<<i<<endl;
            for(auto&itr:prime){
                if(valid(itr,i)){
                    v[i].push_back(itr);
                    v[itr].push_back(i);
                }
            }
            prime.push_back(i);
        }
    }
}
void bfs(int start){
    dist[start]=1;
    queue<int>q;
    q.push(start);
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(auto&itr:v[current]){
            if(dist[itr]==0){
                dist[itr]=dist[current]+1;
                q.push(itr);
            }
        }
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
    while(t--){
        dist.clear();
        dist.resize(9999+10);
        fill(dist.begin(),dist.end(),0);
        int a , b;cin>>a>>b;
        bfs(a);
        cout<<dist[b]-1<<endl;
    }

    return 0;
}
