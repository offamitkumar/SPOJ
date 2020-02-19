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
#include <cassert>
#include <bitset>
#include <numeric>
using namespace std;
#define mod 1000000007
#define maxN (int)3e5+10
#define BLOCK_SIZE 600 
array<int,30100>arr;
array<int,maxN>answer;
array<int,(int)1e6+100>freqency;
int size_Counter{};
struct Query{
    public:
        int left , right , index;
};
array<Query,maxN>query;
int n , q , q_start , q_end;
// sort them such that all query of same block are get separated 
// query of different block are sorted by right pointer movement 
bool compare(Query &Q1 ,Query &Q2){
    if(Q1.left/BLOCK_SIZE != Q2.left/BLOCK_SIZE){
        return Q1.left/BLOCK_SIZE < Q2.left/BLOCK_SIZE;
    }
    return Q1.right < Q2.right;
}
void add(int position){
    freqency[arr[position]]++;
    if(freqency[arr[position]]==1){
        size_Counter++;
    }
}
void remove(int position){
    freqency[arr[position]]--;
    if(freqency[arr[position]]==0){
        size_Counter--;
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    cin>>q;
    for(int i=0;i<q;++i){
        cin>>query[i].left>>query[i].right;
        query[i].index = i;
        query[i].left--;// to make query possible on 0 based Index
        query[i].right--;
    }
    sort(query.begin(),query.begin()+q,compare);
    int right_Pointer = -1 , left_Pointer = 0;
    for(int i=0;i<q;++i){
        int left = query[i].left;
        int right= query[i].right;
        while(left_Pointer > left){
            left_Pointer--;
            add(left_Pointer);
        }
        while(right_Pointer<right){
            right_Pointer++;
            add(right_Pointer);
        }
        while(left_Pointer<left){
            remove(left_Pointer);
            left_Pointer++;
        }
        while(right_Pointer>right){
            remove(right_Pointer);
            right_Pointer--;
        }
        answer[query[i].index]=size_Counter;
    }
    for(int i=0;i<q;++i){
        cout<<answer[i]<<'\n';
    }
    return 0;
}
