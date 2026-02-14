#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<vector<int>> stableInternships(
  vector<vector<int>> interns, vector<vector<int>> teams
) { // Time: O(n^2) | Space: O(n^2)
    queue<int> freeInterns;
    vector<int> internChoices;
    unordered_map<int, int> ans;
    vector<vector<int>> vecAns;
    vector<unordered_map<int, int>> teamsPreferences;

    for(int i = 0; i < teams.size(); i++) {
        teamsPreferences.push_back({});
        for(int j = 0; j < teams[i].size(); j++) {
            teamsPreferences[i][teams[i][j]] = j;
        }
    }

    for(int i = 0; i < interns.size(); i++) {
        internChoices.push_back(0);
        freeInterns.push(i);
    }

    while (freeInterns.size()) {
        int intern = freeInterns.front();
        int choice = interns[intern][internChoices[intern]];

        if (ans.find(choice) == ans.end()) {
            ans[choice] = intern;
        } else {
            int current = ans[choice];
            if (teamsPreferences[choice][current] < teamsPreferences[choice][intern]) {
                freeInterns.push(intern);
                internChoices[intern]++;
            } else {
                freeInterns.push(current);
                internChoices[current]++;
                ans[choice] = intern;
            }
        }

        freeInterns.pop();
    }

    for(pair<int, int> t: ans) {
        vecAns.push_back({t.second, t.first});
    }

    return vecAns;
}
