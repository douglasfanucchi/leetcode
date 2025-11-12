#include <vector>
using namespace std;

bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights) {
  sort(redShirtHeights.begin(), redShirtHeights.end());
  sort(blueShirtHeights.begin(), blueShirtHeights.end());

  vector<int> *back = &redShirtHeights;
  vector<int> *front = &blueShirtHeights;

  if (blueShirtHeights[0] > redShirtHeights[0]) {
    back = &blueShirtHeights;
    front = &redShirtHeights;
  }

  for(int i = 0; i < blueShirtHeights.size(); i++) {
    if ((*back)[i] <= (*front)[i]) {
      return false;
    }
  }

  return true;
}
