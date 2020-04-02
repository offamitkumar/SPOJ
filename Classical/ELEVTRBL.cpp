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
#define MAXN (int)1e6+10
array<int,MAXN>dist;
array<bool,MAXN>visited;
int f, s, g, u, d;
bool bfs(void){
    if(s==g){
        dist[g] = 0;
        return true;
    }
    fill(dist.begin() , dist.end() , -1);
    queue<int>q;
    dist[s] = 0;
    q.push(s);
    while(!q.empty()){
        int current = q.front();
        q.pop();
        if(current+u<=g){
            if(!visited[current+u]){
                visited[current+u] = true;
                dist[current+u] = dist[current]+1;
                q.push(current+u);
            }
            dist[current+u] = min(dist[current+u] , dist[current]+1);
        }
        if(current-d>=1 ){
            if(!visited[current-d]){
                visited[current-d] = true;
                dist[current-d] = dist[current]+1;
                q.push(current-d);
            }
            dist[current-d] = min(dist[current-d] , dist[current]+1);
        }
    }
    return (dist[g]!=-1);
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    scanf("%d%d%d%d%d" ,&f, &s, &g, &u, &d);
    if(bfs()){
        printf("%d\n",dist[g]);
    }else{
        puts("use the stairs");
    }
    return 0;
}
