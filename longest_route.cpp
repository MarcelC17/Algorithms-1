#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
 
// Check if it is possible to go to position (x, y) from
// the current position. The function returns false if the cell
// has a value 0, or it is already visited.
bool isSafe(vector<vector<int>> &mat, vector<vector<bool>> &visited, int x, int y)
{
    return (x >= 0 && x < (int)mat.size() && y >= 0 && y < (int)mat[0].size()) &&
            mat[x][y] == 1 && !visited[x][y];
}
 
// Find the longest possible route in a matrix `mat` from the source cell
// (i, j) to destination cell (x, y).
// `max_dist` —> keep track of the length of the longest path from source to
// destination. It is passed by reference.
// `dist` —> length of the path from the source cell to the current cell (i, j).
void findLongestPath(vector<vector<int>> &mat, vector<vector<bool>> &visited,
                int i, int j, int x, int y, int &max_dist, int dist)
{
    // if the destination is not possible from the current cell
    if (mat[i][j] == 0) {
        return;
    }
 
    // if the destination is found, update `max_dist`
    if (i == x && j == y)
    {
        max_dist = max(dist, max_dist);
        return;
    }
 
    // set (i, j) cell as visited
    visited[i][j] = 1;
 
    // go to the bottom cell
    if (isSafe(mat, visited, i + 1, j)) {
        findLongestPath(mat, visited, i + 1, j, x, y, max_dist, dist + 1);
    }
 
    // go to the right cell
    if (isSafe(mat, visited, i, j + 1)) {
        findLongestPath(mat, visited, i, j + 1, x, y, max_dist, dist + 1);
    }
 
    // go to the top cell
    if (isSafe(mat, visited, i - 1, j)) {
        findLongestPath(mat, visited, i - 1, j, x, y, max_dist, dist + 1);
    }
 
    // go to the left cell
    if (isSafe(mat, visited, i, j - 1)) {
        findLongestPath(mat, visited, i, j - 1, x, y, max_dist, dist + 1);
    }
 
    // backtrack: remove (i, j) from the visited matrix
    visited[i][j] = 0;
}
 
// Wrapper over findLongestPath() function
int findLongestPathLength(vector<vector<int>> &mat, pair<int, int> &src,
                    pair<int, int> &dest)
{
    // base case: invalid input
    if (mat.size() == 0 || mat[src.first][src.second] == 0 ||
            mat[dest.first][dest.second] == 0) {
        return -1;
    }
 
    // `M × N` matrix
    int M = mat.size();
    int N = mat[0].size();
 
    // construct an `M × N` matrix to keep track of visited cells
    vector<vector<bool>> visited;
    visited.resize(M, vector<bool>(N));
 
    int max_dist = 0;
    findLongestPath(mat, visited, src.first, src.second, dest.first, dest.second,
            max_dist, 0);
 
    return max_dist;
}
 
int main()
{
    // input matrix
    vector<vector<int>> mat =
    {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
        { 1, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 0, 1, 1 },
        { 1, 1, 0, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }
    };
 
    // (0, 0) are the source cell, and (5, 7) are the destination cell coordinates
    pair<int, int> src = make_pair(0, 0);
    pair<int, int> dest = make_pair(5, 7);
 
    cout << "The Maximum length path is " << findLongestPathLength(mat, src, dest);
 
    return 0;
}