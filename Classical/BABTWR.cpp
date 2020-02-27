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
struct Box{
    array<long long,3>dim;
    long long height; // for use at last
    bool operator<(const Box &b1)const{
        return (dim[1]*dim[0]<b1.dim[0]*b1.dim[1]); // sort them with max base area 
    }
};
Box make_Box(array<long long,3>&arr){
    Box temp; 
    for(long long i=0;i<3;++i){
        temp.dim[i] = arr[i];
    }
    temp.height = 0;
    return temp;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    long long n; 
    while(true){
        scanf("%lld",&n);
        if(n==0){
            return 0;
        }
        vector<Box>Boxes;
        for(long long i=0;i<n;++i){
            array<long long,3>a; // for the dimension of nth box
            for(auto&itr:a){
                cin>>itr; // taking dimension
            }
            sort(a.begin(),a.end()); // sort increasing order 
            do{
                Boxes.push_back(make_Box(a)); // return Box object and insert in Boxes List 
            }while(next_permutation(a.begin(),a.end()));
        }
        sort(Boxes.begin(),Boxes.end()); // sort them with max base area see compare code above in structure 
        //cout<<"Size = "<<Boxes.size()<<endl;
        long long ans{};
        for(long long i=0;i<(long long)Boxes.size();++i){
            Boxes[i].height = Boxes[i].dim[2];
            for(long long j=0;j<i;++j){
                if(Boxes[j].dim[0]<Boxes[i].dim[0] and Boxes[j].dim[1]<Boxes[i].dim[1]){
                    Boxes[i].height = max(Boxes[i].height , Boxes[j].height+Boxes[i].dim[2]);
                }
            }
            ans = max(ans , Boxes[i].height);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
