#include <vector>
#include <algorithm>

using namespace std;

int bestSeat(vector<int> seats) { // Time: O(n) | Space: O(1)
    vector<int> pos;
    int i = 0, left, right;

    while (i < seats.size()) {
        left = right = i;
        if (seats[i]) {
            i++;
            continue;
        }
        while (left > 0 && !seats[left - 1]) {
            left--;
        }
        while (right < seats.size() - 1 && !seats[right + 1]) {
            right++;
        }
        if (!pos.size()) {
          pos.push_back(left);
          pos.push_back(right);
        } else if ((right - left + 1) > (pos[1] - pos[0] + 1)) {
            pos[0] = left;
            pos[1] = right;
        }

        i = right + 1;
    }

    if (!pos.size()) {
        return -1;
    }

    return (pos[1] + pos[0]) / 2;
}
