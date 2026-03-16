#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue> 

using namespace std;

int main(){
    int N, L, R;
    long long int cnt = 0;
    string s;
    cin >> N >> L >> R;
    cin >> s;
    for(int i = L; i <= R; i++){
        for(int j = 0; j + i < N; j++){
            if(s[j] == s[j+i]) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}