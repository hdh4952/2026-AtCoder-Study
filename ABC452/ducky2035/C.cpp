#include <iostream>
#include <string>

using namespace std;

string str[200000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int ab[10][2];
    for (int i = 0; i < n; i++) {
        cin >> ab[i][0] >> ab[i][1];
        ab[i][1]--;
    }
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> str[i];
    }

    bool exist_char[11][10][26] = {false,};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < str[i].size(); j++) {
            char letter = str[i][j]-'a';
            exist_char[str[i].size()][j][letter] = true;
        }
    }
    for (int i = 0; i < m; i++) {

        if (str[i].size() != n) {
            cout << "No\n";
            continue;
        }

        bool rst = true;
        for (int j = 0; j < n; j++) {
            char letter = str[i][j]-'a';
            if (!exist_char[ab[j][0]][ab[j][1]][letter]) {
                rst = false;
                break;
            }
        }

        if (rst) cout << "Yes\n";
        else     cout << "No\n";
    }
    return 0;
}