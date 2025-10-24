#include <iostream>
#include <string>
using namespace std;

long long sumDigits(const string &s) {
    long long sum = 0;
    for (char c : s)
        sum += c - '0';
    return sum;
}

int main() {
    string x;
    cin >> x;

    int steps = 0;
    if (x.size() == 1) {
        cout << 0;
        return 0;
    }
    while (x.size() > 1) {
        long long s = sumDigits(x);
        x = to_string(s);
        steps++;
    }
    cout << steps;
    return 0;
}
