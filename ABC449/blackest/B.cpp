#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue> 

using namespace std;

int main(){
    int H, W, Q;
    cin >> H >> W >> Q;
    for(int i = 0; i < Q; i++){
        int q, num;
        cin >> q >> num;
        switch(q){
            case 1:
                cout << num * W << endl;
                H -= num;
                break;
            case 2:
                cout << num * H << endl;
                W -= num;
                break;
        }
    }
    return 0;
}