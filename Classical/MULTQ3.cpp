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
#define MAXN 100009
struct Node{
    int reminder[3];
    int lazy;
};
Node seg[4*MAXN];
void build(int current_node , int start ,int end){
    if(start>end){
        return;
    }
    if(start==end){
        seg[current_node].reminder[0] = 1;
        seg[current_node].reminder[1] = 0;
        seg[current_node].reminder[2] = 0;
        seg[current_node].lazy = 0;
        return;
    }
    int mid = (start+end)/2;
    build(2*current_node , start , mid);
    build(2*current_node+1,mid+1,end);
    seg[current_node].reminder[0] = seg[2*current_node].reminder[0] + seg[2*current_node+1].reminder[0];
    seg[current_node].reminder[1] = seg[2*current_node].reminder[1] + seg[2*current_node+1].reminder[1];
    seg[current_node].reminder[2] = seg[2*current_node].reminder[2] + seg[2*current_node+1].reminder[2];
    seg[current_node].lazy = 0;
}
void update(int current_node , int start , int end , int right , int left , int value){
    if(seg[current_node].lazy){// if current node is lazy 
        int reminder = seg[current_node].lazy%3;
        if(reminder==1){
            int temp = seg[current_node].reminder[0];
            swap(seg[current_node].reminder[0] , seg[current_node].reminder[2]);
            swap(seg[current_node].reminder[2] , seg[current_node].reminder[1]);
            swap(seg[current_node].reminder[1] , temp);
        }else if(reminder==2){
            int temp = seg[current_node].reminder[1];
            swap(seg[current_node].reminder[1] , seg[current_node].reminder[2]);
            swap(seg[current_node].reminder[2] , seg[current_node].reminder[0]);
            swap(seg[current_node].reminder[0] , temp);           
        }
        if(start!=end){
            seg[2*current_node].lazy += reminder;
            seg[2*current_node+1].lazy += reminder;
        }
        seg[current_node].lazy = 0;
    }
    if(start > end || start > left || right > end){
        return ;
    }
    if(start >= right and end<=left){
        int reminder = seg[current_node].reminder[0];
        swap(seg[current_node].reminder[0],seg[current_node].reminder[2]);
        swap(seg[current_node].reminder[2],seg[current_node].reminder[1]);
        swap(seg[current_node].reminder[1],reminder);
        if(start!=end){
            seg[2*current_node].lazy+=value;
            seg[2*current_node+1].lazy+=value;
        }
        return;
    }
    int mid = (start+end)/2;
    update(2*current_node , start , mid , right , left , value);
    update(2*current_node+1 , mid+1, end , right , left , value);
    seg[current_node].reminder[0] = seg[2*current_node].reminder[0] + seg[2*current_node+1].reminder[0];
    seg[current_node].reminder[1] = seg[2*current_node].reminder[1] + seg[2*current_node+1].reminder[1];
    seg[current_node].reminder[2] = seg[2*current_node].reminder[2] + seg[2*current_node+1].reminder[2];
    return ;
}
int query(int current_node , int start , int end , int right , int left){
    if(start>end || start>left || end < right){
        return 0;
    }
    if(seg[current_node].lazy){
        int reminder = seg[current_node].lazy%3;
        if(reminder==1){
            int temp = seg[current_node].reminder[0];
            swap(seg[current_node].reminder[0] , seg[current_node].reminder[2]);
            swap(seg[current_node].reminder[2] , seg[current_node].reminder[1]);
            swap(seg[current_node].reminder[1] , temp);
        }else if(reminder==2){
            int temp = seg[current_node].reminder[1];
            swap(seg[current_node].reminder[1] , seg[current_node].reminder[2]);
            swap(seg[current_node].reminder[2] , seg[current_node].reminder[0]);
            swap(seg[current_node].reminder[0] , temp);           
        }
        if(start!=end){
            seg[2*current_node].lazy += reminder;
            seg[2*current_node+1].lazy += reminder;
        }
        seg[current_node].lazy = 0;
    }
    if(start>=right and end<=left){
        return seg[current_node].reminder[0];
    }
    int left_ans = query(2*current_node , start , (start+end)/2 , right , left);
    int right_ans = query(2*current_node+1 ,1+(start+end)/2,end , right , left);
    return left_ans+right_ans;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n , q;scanf("%d%d",&n,&q);
    build(1 , 0  , n-1);
    while(q--){
        int t , l , r; scanf("%d%d%d",&t , &l , &r);
        if(t==0){
            update(1 , 0 , n-1 , l , r , 1);
        }else{
            printf("%d\n",query(1 , 0 , n-1 , l , r));
        }
    }
    return 0;
}
