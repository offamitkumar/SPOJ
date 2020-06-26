//  Author : Amit Kumar 

#include <iostream>
#include <algorithm> 
#include <string> 
#include <sstream>
#include <fstream>
#include <iomanip> 
#include <chrono> 
#include <numeric> 
#include <utility>
#include <functional>

#include <bitset>
#include <tuple>
#include <queue>
#include <stack>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <deque>
#include <list>


#include <climits>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdio>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace std::chrono;
//  using namespace placeholders;
using namespace __gnu_pbds;
template<typename TypeInfo>
using new_set = tree< 
/* ob.order_of_key(element) -> number of element strictly less than element
 * *ob.find_by_order(n) ->  nth element in increasing order
 */
         TypeInfo ,
         null_type ,
         less<TypeInfo> ,
         rb_tree_tag ,
         tree_order_statistics_node_update 
 > ;

void show_me() { cerr << endl; }
 
template <typename HEAD, typename... TAIL>
void show_me(HEAD H, TAIL... T) {
  cerr << " " << (H);
  show_me(T...);
}
 
#ifdef HELL_JUDGE
#define show(...) cerr << "[" << #__VA_ARGS__ << "]:", show_me(__VA_ARGS__)
#else
#define show(...) 0
#endif

typedef int64_t Int;
 
template<typename A, typename B>
ostream& operator<<(ostream&out, const pair<A, B>&p){
    out << p.first << ' ' << p.second ;
    return out;
}

template<typename A, typename B>
istream& operator>>(istream&in, pair<A, B>&p){
    in >> p.first >> p.second ;
    return in;
}

template<typename A> 
istream& operator>>(istream&in, vector<A>&vec){
    for(auto&itr:vec){
        in >> itr;
    }
    return in;
}

template<typename A>
ostream& operator<<(ostream&out,const vector<A>&vec){
    for(auto&itr:vec){
        out << itr <<' '; // VVV 
    }
    return out;
}

const int MAXM = (int)1e5+100;
const int MAXN = (int)1e5+100;
const int64_t MOD  = (int64_t)1e9+7ll;

struct Road{
    Int start;
    Int end_ ;
    Int cost;
    bool operator()(Road &a , Road&b){
        return a.cost > b.cost;
    }
};

signed main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    ios::sync_with_stdio(false); // FLUSH THE STREAM IF USING puts / printf / scanf/
    cin.tie(nullptr);            //
    cout.tie(nullptr);           //
#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 

    int t; cin >> t; 
    while(t--){
        Int n , m , s , d; 
        cin >> n >> m >> s >> d;
        priority_queue<Road , vector<Road> , Road>q;
        vector<vector<Road>>graph(n+1);
        Road r;
        while(m--){
            cin >> r.start >> r.end_ >> r.cost;
            r.cost += 12;
            graph[r.start].push_back(r);
            if(r.start == s){
                q.push(r);
            }
            swap(r.start , r.end_);
            if(r.start == s){
                q.push(r);
            }
            graph[r.start].push_back(r);
        }
        vector<Int>dist(n+1,LONG_MAX);
        dist[s] = 0ll;
        while(!q.empty()){
            Int sp = q.top().start;
            Int cost = q.top().cost;
            Int ep = q.top().end_;
            dist[ep] = min(dist[ep] ,dist[sp]+cost );
            q.pop();
            for(auto&itr:graph[ep]){
                if(dist[itr.end_] > dist[itr.start] + itr.cost){
                    dist[itr.end_] = dist[itr.start] + itr.cost;
                    itr.cost = dist[itr.end_];
                    q.push(itr);
                }
            }
        }
        cout << dist[d] << '\n'; 
    }

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
