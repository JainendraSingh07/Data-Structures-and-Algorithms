/*
Skyline Real Estate Developers is planning to demolish a number of old, unoccupied buildings and construct a shopping mall in their place. Your task is to find the largest solid area in which the mall can be constructed.

There are a number of buildings in a certain two-dimensional landscape. Each building has a height, given by . If you join  adjacent buildings, they will form a solid rectangle of area .

Example

A rectangle of height  and length  can be constructed within the boundaries. The area formed is .

Function Description

Complete the function largestRectangle int the editor below. It should return an integer representing the largest rectangle that can be formed within the bounds of consecutive buildings.

largestRectangle has the following parameter(s):

int h[n]: the building heights
Returns
- long: the area of the largest rectangle that can be formed within the bounds of consecutive buildings

Input Format

The first line contains , the number of buildings.
The second line contains  space-separated integers, each the height of a building.

Constraints

Sample Input

STDIN       Function
-----       --------
5           h[] size n = 5
1 2 3 4 5   h = [1, 2, 3, 4, 5]
Sample Output

9
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

long largestRectangle(vector<int>& h) {
    int n = h.size();
    stack<int> s;
    long maxArea = 0;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && h[i] < h[s.top()]) {
            int height = h[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, static_cast<long>(height) * width);
        }
        s.push(i);
    }

    while (!s.empty()) {
        int height = h[s.top()];
        s.pop();
        int width = s.empty() ? n : n - s.top() - 1;
        maxArea = max(maxArea, static_cast<long>(height) * width);
    }

    return maxArea;
}

int main() {
    vector<int> histogram = {2, 1, 5, 6, 2, 3};
    cout << "Largest rectangle area: " << largestRectangle(histogram) << endl;
    return 0;
}
