#include <bits/stdc++.h>

//#define FAST_INPUT_OUTPUT
//#define MORE_THAN_ONE_TESTCASE // COMMENT IT

#define vi vector<int>
#define vl vector<long long>
#define mii map<int , int>
#define mll map<long long , long long>
#define msi map<string , i>
#define msl map<string , long long>
#define umii unordered_map<int,int>
#define umll unordered_map<long long ,long long>
#define umsi unordered_map<string , int>
#define umsl map<string , long long> 
#define si set<int>
#define sl set<long long>
#define pii pair<int , int >
#define psi pair<string,int>
#define psl pair<string , long > 
#define pll pair<long long , long long>
#define vpii vector<pii>
#define vpll vector<pll>
#define vpsi vector<psi>
#define vpsl vector<psl>
#define pqi priority_queue<int>
#define pql priority_queue<long long>
#define ub upper_bound
#define lb lower_bound
#define bint long long int
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define iv(v) for(auto &i:v){cin>>i;}
#define ov(v) for(auto i:v){cout<<i<<" ";}cout<<endl;
#define ovn(v) for(auto i:v){cout<<i<<endl;}
#define euv(v) for(auto i:v){cerr<<i<<" ";}cerr<<endl;
#define eovn(v) for(auto i:v){cerr<<i<<endl;}
#define os(s) for(auto itr:s){cout<<itr<<" ";}cout<<endl;
#define osn(s) for(auto itr:s){cout<<itr<<endl;}
#define eos(s) for(auto itr:s){cerr<<itr<<" ";}cerr<<endl;
#define eosn(s) for(auto itr:s){cerr<<itr<<endl;}
#define rep(x) for(auto i=0 ; i<(x); ++i)
#define _rep(a,b) for(auto i=(a); i<(b); ++i)
#define endl '\n'
using namespace std;

vl dp(1000000);

bint ans(bint n){
    if(n>1000000){
        return max(n , ans(n/2)+ans(n/3)+ans(n/4));
    }
    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n] =max(n , ans(n/2)+ans(n/3)+ans(n/4));
    return dp[n];
} 


auto SOLUTION_FUNCTION( void ) ->void {

    // your solution goes here 
    fill(all(dp) , -1);
    dp[0] = 0;
    dp[1] = 1;
    bint n ;
    while(scanf("%lld",&n)!=EOF){
        cout<<max(n, ans(n))<<endl;
    }

    return ;
}




int main(void){
#ifdef FAST_INPUT_OUTPUT
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout<<setprecision(10);
    cout<<fixed;
    cout<<boolalpha;
#endif
#ifdef MY_LOCAL_PROJECT
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int testcase = 1;


#ifdef MORE_THAN_ONE_TESTCASE
    cin>>testcase;
#endif
    
    while(testcase--){
        SOLUTION_FUNCTION();
    }

#ifdef MY_LOCAL_PROJECT
    cout<<"Time : "<<1.0*(double)clock()/CLOCKS_PER_SEC<<endl;
#endif
    return 0;
}
