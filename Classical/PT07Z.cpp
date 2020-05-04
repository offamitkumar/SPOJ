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
vector<vector<int>>graph;
vector<bool> visited;
pair<int,int> getMax( int node ){
    pair<int,int>currentBest , temp , currentAns;
    currentBest = make_pair(0 , 0);
    currentAns = make_pair(0 , 0);
    visited[node] = true;
    for(auto&itr:graph[node]){
        if(!visited[itr]){
            temp = getMax( itr );
            currentAns.first = max({ currentAns.first , currentBest.second+temp.second , temp.first }); // take this a longest path
            currentAns.second = max(currentAns.second , max(currentBest.second , temp.second)); // longest single path till now
            currentBest.first = max(currentBest.first  , temp.first);
            currentBest.second = max(currentBest.second , temp.second);
        }
    }
    return make_pair(max(1,currentAns.first) , currentAns.second+1);
}
int getDia( int node ){
    pair<int,int>p = getMax(node);
    if(p.first >= p.second){
        return p.first;
    }else{
        return p.second-1;
    }
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n; cin>>n;
    graph.resize(n+10);
    visited.resize(n+10);
    fill(visited.begin() , visited.end() , false);
    for(int u,v,i=0;i<n-1;++i){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout<<getDia(1)<<'\n';
    return 0;
}
