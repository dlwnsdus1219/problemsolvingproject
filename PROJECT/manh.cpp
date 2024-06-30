#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Helper function to find the median of a vector
int findMedian(vector<int>& vec) {
    sort(vec.begin(), vec.end());
    int n = vec.size();
    if (n % 2 == 0) {
        return vec[n / 2 - 1];  // For even number of elements, we take the lower median
    } else {
        return vec[n / 2];
    }
}

pair<int, int> findOptimalPoint(queue<pair<int, int>>& points) {
    vector<int> x_coords, y_coords;

    // Extract x and y coordinates into separate vectors
    while (!points.empty()) {
        pair<int, int> point = points.front();
        points.pop();
        x_coords.push_back(point.first);
        y_coords.push_back(point.second);
    }

    // Find the median for x and y coordinates
    int x_median = findMedian(x_coords);
    int y_median = findMedian(y_coords);

    return {x_median, y_median};
}

int main() {
    int n;
    cin >> n;

    queue<pair<int, int>> points;
    cout << "Enter the points (x y):" << endl;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        points.push({x, y});
    }

    pair<int, int> optimal_point = findOptimalPoint(points);
    cout << "The point with the minimum Manhattan distance sum is: (" 
         << optimal_point.first << ", " 
         << optimal_point.second << ")" << endl;

    return 0;
}