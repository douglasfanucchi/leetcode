#include <iostream>

using namespace std;

bool isDivisibleByLuckyNumber(int n, int lucky_number) {
    if (n < lucky_number) {
        return false;
    }

    if (n != 0 && n % lucky_number == 0) {
        return true;
    }

    bool ans = isDivisibleByLuckyNumber(n, lucky_number * 10 + 4);
    if (ans) {
        return ans;
    }

    return isDivisibleByLuckyNumber(n, lucky_number * 10 + 7);
}

void solution(int n) { // Time: O(∛n) | Space: O(log(n))
    if (isDivisibleByLuckyNumber(n, 0)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
