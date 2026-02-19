#include <vector>
#include <iostream>

using namespace std;

bool dfs(int v, vector<vector<int>> &edges, vector<int> &colors) {
    colors[v] = 1;

    for(int w: edges[v]) {
        if (colors[w] == 0) {
            if(dfs(w, edges, colors)) {
                return true;
            }
        }
        if (colors[w] == 1) {
            return true;
        }
    }

    colors[v] = 2;

    return false;
}

bool cycleInGraph(vector<vector<int>> edges) { // Time: O(V + E) | Space: O(V) where V = edges.size() and E is the number of edges, being up to V^2 worstcase
    vector<int> colors;

    for(int v = 0; v < edges.size(); v++)
        colors.push_back(0);

    for(int v = 0; v < edges.size(); v++) {
        if (colors[v] == 2)
            continue;
        if (dfs(v, edges, colors)) {
            return true;
        }
    }

    return false;
}
