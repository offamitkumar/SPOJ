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
vector<vector<int>>graph;
vector<bool>visited;
set<int>s;
vector<int>in;
vector<int>ans;
void topo(void){
    for(;s.size();){
        auto itr = *(s.begin());
        if(visited.at(itr) == true){
            continue;
        }
        visited.at(itr)=true;
        for(auto&itr1:graph[itr]){
            if(visited.at(itr1)==false){
                in[itr1]--;
                if(in[itr1]==0)
                    s.insert(itr1);
            }
        }
        ans.emplace_back(itr);
        s.erase(itr);
    }
    return ;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n , m ; scanf("%d%d",&n , &m);
    graph.resize(n+1);
    in.resize(n+1);
    visited.assign(n+1,false);
    for(int i=0;i<m;++i){
        int a , b; scanf("%d%d",&a ,&b);
        graph.at(a).push_back(b);
        in[b]++;
    }
    for(int i=1;i<=n;++i){
        if(in[i]==0){
            s.insert(i);
        }
    }
    topo();
    if((int)ans.size()!=n){
        puts("Sandro fails.");
    }else{
        for(auto&itr:ans){
            printf("%d ",itr);
        }
    }

    return 0;
}
