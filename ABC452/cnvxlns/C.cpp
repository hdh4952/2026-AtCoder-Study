#include<bits/stdc++.h>

#define int long long
#define endl "\n"

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
using vpii = vector<pii>;
using vs = vector<string>;

const int inf = 4e18;
const int MOD = 1e9 + 9;

vpii drc = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

pii operator+(pii A, pii B){
    return {A.first + B.first, A.second + B.second};
}
pii operator-(pii A, pii B){
    return {A.first - B.first, A.second - B.second};
}

void init(){

}

void solve(){
    int N, M;
    cin >> N;

    vi A(N), B(N);

    for(auto i = 0; i < N; ++i){
        cin >> A[i] >> B[i];
    }
    cin >> M;
    vs S(M);
    for(auto &i: S){
        cin >> i;
    }

    for(const auto &s : S){
        if(s.size() != N){
            cout << "No" << endl;
            continue;
        }
        auto flag2 = true;
        for(auto i = 0; i < s.size(); ++i){
            auto flag = false;
            for(const auto &ss: S){
                if(A[i] == ss.size() && ss[B[i] - 1] == s[i]){
                    flag = true;
                    break;
                }
            }
            flag2 = flag2 && flag;
        }
        if(flag2){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }

}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    init();
    int t = 1;
    // cin >> t;
    while(t--)
        solve();

    return 0;
}
