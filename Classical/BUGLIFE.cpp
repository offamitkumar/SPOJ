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
typedef tree< // find_by_order & order_of_key
        int ,
        null_type ,
        less<int> ,
        rb_tree_tag ,
        tree_order_statistics_node_update 
> new_set;
#define MOD 1000000007
#define MAXN 2020
bitset<MAXN>visited;
array<vector<int> , MAXN>graph;
array<int , MAXN> color;
bool dfs(int current , int c = 0){
    visited.set(current);
    color[current] = c^1; // male 
    bool ok = true;
    for(auto&itr:graph[current]){
        if(itr==current){
            continue;
        }
        if(!visited.test(itr)){
            ok &= dfs(itr , color[current]);
        }
        if(color[current]==color[itr] || (!ok)){
            return false;
        }
    }
    return ok;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int t; scanf("%d",&t);
    for(int x= 1;x<=t;++x){
        printf("Scenario #%d:\n" , x);
        int n ,  m ; scanf("%d%d",&n , &m);
        for(int i=0;i<=n;++i){
            graph[i].clear();
        }
        visited.reset();
        fill_n(begin(color) , n+10 , -1);
        for(int u,v,i=0; i<m; ++i){
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        bool ok = true;
        for(int i=1;i<=n;++i){
            if(!visited.test(i)){
                ok &= dfs(i);
            }
            if(!ok){break;}
        }
        puts(ok?"No suspicious bugs found!":"Suspicious bugs found!");
    }
    return 0;
}
