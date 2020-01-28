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
using namespace std;
#define MAX_I 1000001
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    array<int,MAX_I>div;
    fill(div.begin(),div.end(),1);// initial
    array<bool,MAX_I>prime;
    fill(prime.begin(),prime.end(),true);
    prime.at(0) = false;
    prime.at(1) = false;
    for(long long i=2;i<MAX_I;++i){
        if(prime.at(i)){
            div.at(i)=0; // doesn't matter because divisor of prime
            // are never greater then 3
            for(int j=i*2;j<MAX_I;j+=i){
                prime.at(j)=false;
            }
            long long sqr = i*i;
            for(long long j=1,k=sqr;k<MAX_I;++j,k=sqr*j){
                div.at(k) = 0; 
                /*
                 * sqr will have only three divisor as is it square of 
                 * a prime number ,, and prime number have only two divisor
                 *
                 * now as we know that d(sqr)=3
                 * if we multiply sqr with any integer then divisor of sqr
                 * will either be 4 or 3 and in both case our condition 
                 * will fail. Why?
                 *
                 * if we multiply sqr with 1 then number we get is sqr , which have 3 divisor 1,prime_number(whose square is this sqr) , and sqr itself.
                 * but d(prime) = 2 and here prime is divisor of sqr but d(prime) is not divisor of d(sqr)
                 *
                 * and similarly if we multiply is with let's just say 10 then divisor of result will be 4(atleast) and divisor [d(sqr)=3] which again doesn't hold that condition
                 */
            }
        }
    }
    int counter{};
    for(int i=2;i<MAX_I;++i){
        if(div.at(i)){
            counter++;
            if(counter%108==0){
                cout<<i<<endl;
            }
        }
    }
    return 0;
}
