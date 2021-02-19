#include <iostream>
#include <stack>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> matrix;
    matrix.resize(n);
    for (auto &i : matrix) i.resize(m);
    std::vector<std::vector<int>> R;
    R.resize(n);
    for (auto &i : R) i.resize(m);
    std::vector<std::vector<int>> L;
    L.resize(n);
    for (auto &i : L) i.resize(m);
    //int _matrix[n][m], R[n][m], L[n][m];
    char c;

    for (int i = 0; i < m; ++i) {
        std::cin >> c;
        matrix[0][i] = (c == '0');
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> c;
            if (c == '1') matrix[i][j] = 0;
            else matrix[i][j] = matrix[i-1][j] + 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        std::stack<int> S;
        for (int j = 0; j < m; ++j) {
            if (!S.empty()) while (matrix[i][j] < matrix[i][S.top()]) {
                    R[i][S.top()] = j-1;
                    S.pop();
                    if (S.empty()) break;
                }
            S.push(j);
        }
        while (!S.empty()) {
            R[i][S.top()] = m - 1;
            S.pop();
        }
    }

    for (int i = 0; i < n; ++i) {
        std::stack<int> S;
        for (int j = m-1; j >= 0; --j) {
            if (!S.empty()) while (matrix[i][j] < matrix[i][S.top()]) {
                    L[i][S.top()] = j+1;
                    S.pop();
                    if (S.empty()) break;
                }
            S.push(j);
        }
        while (!S.empty()) {
            L[i][S.top()] = 0;
            S.pop();
        }
    }

    /*std::cout << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << matrix[i][j];
        }
        std::cout << '\n';
    }

    std::cout << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << L[i][j];
        }
        std::cout << '\n';
    }*/

    int max = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int tmp = matrix[i][j]*(R[i][j] - L[i][j] + 1);
            if (tmp > max) max = tmp;
        }
    }
    std::cout << max << '\n';

    return 0;
}