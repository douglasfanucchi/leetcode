#include <iostream>

using namespace std;

int solution(int n, int k) { // Time: O(n) | Space: O(n)
    if (n == 1) {
        return 0;
    }

    int parent = solution(
        n - 1,
        k % 2 ? (k + 1) / 2 : k / 2
    );

    int x = 1;

    if (parent) {
        x = 2;
    }

    if (k % 2) {
        return x / 2;
    }

    return x % 2;
}
