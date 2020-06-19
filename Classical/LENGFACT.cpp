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

const int MAXM = (int)1e5+100;
const int MAXN = (int)1e5+100;
const int MOD  = (int)1e9+7;

int64_t factorial_digit(int64_t n) 
{ 
    if (n < 0) 
        return 0; 
    if (n <= 1) 
        return 1; 
  
    // Use Kamenetsky formula to calculate 
    // the number of digits 
    double x = ((n * log10(n / M_E) +  log10(2ll * M_PI * n) / 2.0)); 
  
    return floor(x) + 1; 
}


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
        int64_t n; cin >> n; 
        cout <<factorial_digit(n) << '\n';  
    }

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
