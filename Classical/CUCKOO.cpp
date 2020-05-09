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
#define MAXN 10009
array<int,MAXN>ans,visited;
array<pair<int,int>,MAXN>v;

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int t; scanf("%d",&t);
    while(t--){
        int m,n; cin>>m>>n;
        fill(ans.begin() , ans.begin()+n , -1);
        bool possible = true;
        for(int i = 0; i<m ; ++i){
            cin>>v[i].first>>v[i].second;
            fill(visited.begin() , visited.begin()+n, 0); // count number of visits 
            int current_node{-1} , prev_node{-1} , j = i;
            while(visited[i]<2 && possible){
                if(ans[v[i].first] == -1){
                    ans[v[i].first] = i; // set value acc to first hash function
                    goto hell;
                }else if(ans[v[i].second]==-1){
                    ans[v[i].second]=i; // set value acc to second hash function
                    goto hell;
                }else{
                    // collision situation 
                    ++visited[i];
                    if(prev_node == v[i].first){
                        current_node = v[i].second;
                    }else{
                        current_node = v[i].first;
                    }
                    prev_node = current_node; 
                    int temp = ans[current_node];
                    ans[current_node] = i;
                    i = temp;
                }
            }
hell:
            if(visited[i]>=2){
                possible = false;
            }
            i = j;
        }
        puts((possible)?"successful hashing":"rehash necessary");
    }
    return 0;
}
