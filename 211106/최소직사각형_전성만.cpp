#include <vector>
using namespace std;
int solution(vector<vector<int>> sizes) {
    pair<int, int> maxsize = {0, 0};
    for (auto size : sizes) {
        if (size[0] > size[1]) {
            swap(size[0], size[1]);
        }
        maxsize.first = max(maxsize.first, size[0]);
        maxsize.second = max(maxsize.second, size[1]);
    }
    return maxsize.first * maxsize.second;
}