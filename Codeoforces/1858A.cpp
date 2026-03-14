#include <bits/stdc++.h>
using namespace std;

int main() {
    int z;
    cin >> z;

    while (z--) {
        long long a, b, c;
        cin >> a >> b >> c;

        if (a + (c % 2) > b)
            cout << "First\n";
        else
            cout << "Second\n";
    }
}
