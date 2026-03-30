#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

map<long, int> table;
vector<string> powers;

void fn(string s){
    if(s.size() >= 10) return;
    if(s!=""){
        long num = stol(s);
        if(table[num] == 1) return;
        table[num] = 1;
    }
    for(int i=0;i<30;++i){
        string new_s_right = s + powers[i];
        string new_s_left = powers[i] + s;
        fn(new_s_right);
        fn(new_s_left);
    }
    
    return;
}

int main()
{
    long i = 1;
    int cnt = 0;
    while(i<=1000000000){
        powers.push_back(to_string(i));
        i*=2;
        cnt++;
    }
    
    fn("");
    
    int n;
    cin >> n;
    long rank = 0;
    for(auto t : table){
        rank++;
        if(rank==n){
            cout << t.first;
            break;
        }
    }
    
    return 0;
}