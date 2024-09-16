#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < (1 << n); i++) {
        int gray = i ^ (i >> 1);
        bitset<32> b(gray);
        string s = b.to_string();
        cout << s.substr(32-n) << endl;
    }
}