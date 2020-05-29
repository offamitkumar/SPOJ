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
#include <unordered_map>
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
void increase(string&temp){
    int k = temp.size()-1;
    if(temp[k] != '9'){
        temp[k]++;
    }else{
        while(k >=0 && temp[k] == '9'){
            temp[k--] = '0';
        }
        if(k < 0){
            temp = '1'+temp;
        }else{
            temp[k]++;
        }
    }
}
void getNextPalin( string &s ) {
    if( (int)count(s.begin(), s.end(), '9') == (int)s.size() ) {
        cout << 1 << string(s.size()-1, '0') << 1 <<'\n';
        return ;
    }
    if (!(s.size() & 1)) {
        string temp = s.substr(0, s.size()/2);
        string rev = temp; reverse(rev.begin(), rev.end());
        string Rev = temp + rev;
        if (Rev > s) {
            cout << Rev << '\n';
        } else {
            increase(temp);
            cout << temp;
            reverse(temp.begin(), temp.end());
            cout << temp << '\n';
            return ;
        }
    } else {
        string temp = s.substr(0, s.size()/2);
        char ch = s[(s.size()/2)];
        string rev = temp;
        reverse(rev.begin(), rev.end());
        string Rev = temp + ch + rev;
        if ( Rev > s ) {
            cout << Rev << '\n'; 
        } else {
            temp += ch;
            increase(temp);
            rev = temp.substr(0, temp.size()-1);
            reverse(rev.begin(), rev.end());
            cout << temp << rev<<'\n';
        }
    }
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int t; cin >> t;
    while (t--) {
        string number; cin >> number;
        getNextPalin(number);
    }
    
    return 0;
}
