#include <optional>
#include <unordered_map>

using namespace std;

class UnionFind {
    protected:
        unordered_map<int, int> parents;
        unordered_map<int, int> ranks;

    public:
        void createSet(int value) { // Time: O(1) | Space: O(1)
            if (parents.find(value) == parents.end()) {
                parents[value] = value;
                ranks[value] = 0;
            }
        }

        optional<int> find(int value) { // Time: O(α(n)) | Space: O(α(n)) where O(α(n)) is approximately O(1)
            if (parents.find(value) == parents.end()) {
                return nullopt;
            }

            if (parents[value] != value) {
                parents[value] = *find(parents[value]);
            }

            return parents[value];
        }

        void createUnion(int valueOne, int valueTwo) { // Time: O(α(n)) | Space: O(α(n)) where O(α(n)) is approximately O(1)
            if (parents.find(valueOne) == parents.end() || parents.find(valueTwo) == parents.end()) {
                return;
            }

            optional<int> r1 = find(valueOne);
            optional<int> r2 = find(valueTwo);

            if (ranks[*r1] > ranks[*r2]) {
                parents[*r2] = *r1;
            } else if (ranks[*r1] < ranks[*r2]) {
                parents[*r1] = ranks[*r2];
            } else {
                parents[*r2] = *r1;
                ranks[*r1]++;
            }
        }
};
