//  Author : Amit Kumar 
//  Date   : Tuesday 21 July 2020 02:31:19 PM IST

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define int int64_t

signed main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    ios::sync_with_stdio(false); // FLUSH THE STREAM IF USING puts / printf / scanf/
    cin.tie(nullptr);            // DISABLE FOR INTERACTIVE PROBLEMS
    cout.tie(nullptr);           //
#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 
    
    while(true){
        vector<int>v(3); 
        vector<int>a(2); 
        set<int>s;
        for(auto&itr:v){
            cin >> itr;
            s.insert(itr);
        }
        for(auto&itr:a){
            cin >> itr;
            s.insert(itr);
        }
        if(accumulate(s.begin() , s.end() , 0) == 0){
            break;
        }
        int counter{};
        sort(v.begin() , v.end()); 
        for(auto&itr:a){
            for(auto&i:v){
                if(i > itr){
                    i = -1;
                    counter++;
                    break;
                }
            }
        }
        if(counter==2){
            cout << -1 << '\n' ;
        }else if(counter == 0){
            for(int i=1;i<=52;++i){
                if(s.find(i)==s.end()){
                    cout << i << '\n'; 
                    break;
                }
            }
        }else if(counter == 1){
            int not_used =-1;
            for(auto&itr:v){
                if(itr!=-1){
                    if(not_used == -1){
                        not_used = itr;
                    }else{
                        not_used = max(not_used , itr);
                    }
                }
            }
            int ans = 55;
            for(int i=52;i>=0;--i){
                if(not_used > i){
                    continue;
                }
                if(s.find(i)==s.end()){
                    ans = i; 
                }
            }
            if(ans == 55 || ans < not_used){
                cout <<-1 << '\n'; 
            }else{
                cout << ans << '\n'; 
            }
        }


    }

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
