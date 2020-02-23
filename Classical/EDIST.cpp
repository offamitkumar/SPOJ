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
long long arr[2001][2001];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int t; cin>>t;
    while(t--){
        memset(arr , 0 , sizeof(arr));
        string a , b; cin>>a>>b;
        for(int i=0;i<a.size();++i){
            arr[i][0] = i;
        }
        for(int j=0;j<b.size();++j){
            arr[0][j] = j;
        }
        for(int i=1;i<=a.size();++i){
            for(int j=1;j<=b.size();++j){
                if(a[i-1]==b[j-1]){
                    arr[i][j] = arr[i-1][j-1];
                }else{
                    arr[i][j] = min({arr[i-1][j] , arr[i][j-1],arr[i-1][j-1]})+1;
                }
            }
        }
        cout<<arr[a.size()][b.size()]<<endl;
    }

    return 0;
}
