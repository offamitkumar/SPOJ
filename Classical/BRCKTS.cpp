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
#define MAXN 30009
string s;
struct Node{
    int right; // 1
    int left; // -1 
};
array<Node , 4*MAXN>segment;
void build(int current_Node , int start , int end){
    if(start>end){
        return ;
    }
    if(start==end){
        segment.at(current_Node).right = segment.at(current_Node).left = (s[start]=='('?1:-1);
        return ;
    }
    int mid = (start+end)/2;
    build(2*current_Node , start , mid);
    build(2*current_Node+1 , mid+1 , end);
    segment.at(current_Node).right = segment.at(current_Node*2).right + segment.at(2*current_Node+1).right;
    segment.at(current_Node).left  = min(segment.at(2*current_Node).left , segment.at(2*current_Node).right+segment.at(current_Node*2+1).left);
}
void update(int current_node , int start , int end , int index){
    if(start>end || start>index || end < index){
        return;
    }
    if(start==end){
        segment.at(current_node).right = segment.at(current_node).left = -(segment.at(current_node).right);
        return ;
    }
    int mid = (start+end)/2;
    update(2*current_node , start , mid , index );
    update(2*current_node+1 , mid+1 , end , index);
    segment.at(current_node).right = segment.at(current_node*2).right + segment.at(2*current_node+1).right;
    segment.at(current_node).left  = min(segment.at(2*current_node).left , segment.at(2*current_node).right+segment.at(current_node*2+1).left);
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n;
    int test = 1;
    while(scanf("%d",&n)==1){
        printf("Test %d:\n",test++);
        cin>>s;
        if(n&1){
            int q; scanf("%d",&q);
            int a; 
            while(q--){
                scanf("%d",&a);
                if(!a){
                    puts("NO");
                }
            }
            continue;
        }
        build(1 , 0 , n-1);
        int q; scanf("%d",&q);
        while(q--){
            int u; scanf("%d",&u);
            if(u!=0){
                --u;
                update(1 , 0 , n-1 , u);
            }else{
                if(!segment.at(1).right && !segment.at(1).left){
                    puts("YES");
                }else{
                    puts("NO");
                }
            }
        }
    }
    return 0;
}
