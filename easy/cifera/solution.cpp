#include <iostream>

using namespace std;

int importance(int k, int l) {
    if (l % k) {
        return -1;
    }

    if (k == l) {
        return 0;
    }

    int ans = importance(k, l / k);

    if (ans < 0) {
        return -1;
    }

    return ans + 1;
}

void solution(int k, int l) { // Time: O(log(l)) | Space: O(log(l))
    int ans = importance(k, l);

    if (ans < 0) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl << ans << endl;
}

int main()
{
    solution(5, 125);
}
