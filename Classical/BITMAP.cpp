//  Author : Amit Kumar 

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>

  #include <iostream>
  #include <algorithm>
  #include <string>
//  #include <sstream>
//  #include <fstream>
//  #include <iomanip>
//  #include <chrono>
//  #include <numeric>
  #include <utility>

//  #include <bitset>
  #include <tuple>
  #include <queue>
//  #include <stack>
//  #include <vector>
  #include <array>
//  #include <unordered_map>
//  #include <unordered_set>
//  #include <set>
//  #include <map>
//  #include <deque>

  #include <climits>
  #include <cstring>
//  #include <cmath>
//  #include <cassert>
#include <cstdio>
using namespace std;
//  using namespace std::chrono;
//  using namespace placeholders;
//  using namespace __gnu_pbds;
//  template<typename TypeInfo>
//  using new_set = tree< // find_by_order & order_of_key
//          TypeInfo ,
//          null_type ,
//          less<TypeInfo> ,
//          rb_tree_tag ,
//          tree_order_statistics_node_update 
//  > ;
const int MAXM = (int)1e5+100;
const int MAXN = (int)200;
const int MOD = (int)1e9+7;
array<int,4>X{-1,1,0,0};
array<int,4>Y{0,0,-1,1};
string grid[MAXN];
int res[MAXN][MAXN];
int visited[MAXN][MAXN];
int n , m; 
int bfs(void){
    queue<tuple<int,int,int>>q; 
    memset(visited,0,sizeof(visited));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(grid[i][j] == '1'){
                res[i][j] = 0;
                q.push(make_tuple(i,j,0));
                visited[i][j]=true;
            }else{
                res[i][j] = INT_MAX;
            }
        }
    }
    while(!q.empty()){
        int a,b,w; tie(a,b,w) = q.front();
        q.pop();
        for(int i=0;i<X.size();++i){
            int tempx = a+X[i];
            int tempy = b+Y[i];
            if(tempx>=0 && tempy>=0 && tempx < n && tempy < m && visited[tempx][tempy] == 0) {
                if(grid[tempx][tempy]=='1'){
                    return w+1;
                }
                visited[tempx][tempy]=true;
                res[tempx][tempy] =w+1;
                q.push(make_tuple(tempx,tempy,w+1));
            }
        }
    }
    return -1; 
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//    auto initial_time = high_resolution_clock::now();
    int t; scanf("%d",&t);
    string s; 
    while(t--){
        cin >> n >> m;
        for(int i =0; i< n;++i){
            cin >> grid[i];
        }
        bfs();
        for(int i=0; i < n; ++i){
            for(int j=0;j<m;++j){
                printf("%d ",res[i][j]);
            }
            puts("");
        }
    }

//    auto final_time = high_resolution_clock::now();
//    cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
