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
#define MAXN 200009
array<int,MAXN>arr;
struct Node{
    int count;
    Node *left;
    Node *right;
};
Node* get_new(void){
    Node*temp = new Node;
    temp->count = 1;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}
long long update(Node*root , int value){
    long long counter{};
    for(int i=63; i>=0;--i){
        int ok = (value&(1<<i));
        if(ok){
            // current bit is 1
            // if there is a number on left then it is lesser then number current we have 
            // we can just add it's count to our answer
            if(root->left!=nullptr){
                counter+=root->left->count;
            }
            // check whether there is node on right or 
            if(root->right!=nullptr){
                // increase it's counter 
                root = root->right;
                root->count += 1;
            }else{
                // otherwise create a new one 
                root->right = get_new();
                root= root->right;
            }
        }else{
            // current bit is 0
            if(root->left!=nullptr){
                // increase it's counter 
                root = root->left;
                root->count += 1;
            }else{
                // otherwise create a new one 
                root->left = get_new();
                root= root->left;
            }
        }
    }
    return counter;
}
void tr(Node*root){
    if(root==nullptr){
        return;
    }
    if(root->right!=nullptr){
        tr(root->right);
        delete(root->right);
    }
    if(root->left!=nullptr){
        tr(root->left);
        delete(root->left);
    }
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int t; scanf("%d",&t);
    while(t--){
        Node *root = new Node(); 
        int n; scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d",&arr[i]);
        }
        long long counter{};
        for(int i=n-1;i>=0;--i){
            counter+=update(root , arr[i]);
        }
        printf("%lld\n",counter);
        /// you can comment below 2 lines to save some time 
        tr(root);
        delete(root);
    }
    return 0;
}
