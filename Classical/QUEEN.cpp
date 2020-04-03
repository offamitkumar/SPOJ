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
#define MAXN 1001
int n, m;
char grid[MAXN][MAXN];
array<array<int,MAXN>,MAXN>dist , visited;
pair<int,int>start,final;
array<int,8>X{-1,-1,-1,0,0 ,1,1,1};
array<int,8>Y{-1, 0, 1,1,-1,1,-1,0};
bool check(pair<int,int>&p){
    return (p.first>=0 && p.first<n && p.second>=0 && p.second<m && grid[p.first][p.second]!='X');
}
void bfs(void){
    queue<pair<int,int>>q;
    q.push(start);
    visited[start.first][start.second] = true;
    while(!q.empty()){
        int row , col;
        tie(row,col) = q.front();
        q.pop();
        for(int i=0;i<8;++i){
            pair<int,int>current{row+X[i],col+Y[i]};
            while(check(current)){
                if(visited[current.first][current.second]==false){
                    dist[current.first][current.second] = dist[row][col]+1;
                    q.push(current);
                    visited[current.first][current.second]=true;
                }else if(dist[current.first][current.second]!=dist[row][col]+1){
                    break;
                }
                current.first+=X[i];
                current.second+=Y[i];
            }
        }
    }
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int t; scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i){
            scanf("%s",grid[i]);
            for(int j=0;j<m;++j){
                dist[i][j] = 0;
                visited[i][j] = false;
                if(grid[i][j]=='S'){
                    start = make_pair(i,j);
                    dist[i][j] = 1;
                }else if(grid[i][j]=='F'){
                    final = make_pair(i,j);
                }
            }
        }
        bfs();
        printf("%d\n",dist[final.first][final.second]-1);
    }
    return 0;
}
