#include <vector>
#include <stack>

using namespace std;

bool twoColorable(vector<vector<int>> edges) { // Time: O(V + E) | Space: O(E) where V is the number of vertices and E number of edges
    vector<int> colors;
    stack<int> stack;

    for(int v = 0; v < edges.size(); v++) {
        colors.push_back(0);
    }

    stack.push(0);
    colors[0] = 1;
    while (stack.size()) {
        int v = stack.top();
        stack.pop();
        for(int w: edges[v]) {
            if (colors[w] == 0) {
                if (colors[v] == 1)
                    colors[w] = 2;
                else {
                    colors[w] = 1;
                }
                stack.push(w);
            } else if (colors[w] == colors[v]) {
                return false;
            }
        }
    }

    return true;
}
