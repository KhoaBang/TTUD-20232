#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int find_max(vector<int> vt) {
    int max = vt[0];
    for (int i = 0; i < vt.size(); i++) {
        if (vt[i] > max) {
            max = vt[i];
        }
    }
    return max;
}

vector<int> sum(vector<int> row1, vector<int> row2 ) {
    vector<int> hello;
    for (int i = 0; i < row1.size(); i++) {
        if (row2[i] == 0) {
            hello.push_back(0);
        }
        else hello.push_back(row1[i]+row2[i]);
    }
    return hello;
}

vector<vector<int>> create_histogram(vector<vector<int>> matrix) {
    vector<vector<int>> histogram;
    histogram.push_back(matrix[0]);
    for (int i = 1; i < matrix.size() ; i++) {
        vector<int> temp= sum(histogram.back(), matrix[i]);
        histogram.push_back(temp);
    }
    return histogram;

}
vector<int> left_histogram(vector<int> row) {
    stack<int> temp;
    temp.push(-1);  // Push -1 as the initial index
    vector<int> l_limit;
    for (int i = 0; i < row.size(); i++) {
        while (temp.top() != -1 && row[i] <= row[temp.top()]) {
            temp.pop();
        }
        l_limit.push_back(temp.top() + 1);
        temp.push(i);
    }
    return l_limit;
}
vector<int> right_histogram(vector<int> row) {
    int n = row.size();
    stack<int> temp;
    temp.push(n);  // Push n as the initial index
    vector<int> r_limit(n, n); // Initialize r_limit with n
    for (int i = n - 1; i >= 0; i--) {
        while (temp.top() != n && row[i] <= row[temp.top()]) {
            temp.pop();
        }
        r_limit[i] = temp.top() - 1;
        temp.push(i);
    }
    return r_limit;
}
vector<int> areas_histogram(vector<int> row, vector<int> l_limit, vector<int> r_limit) {
    vector<int> areas;
    for (int i = 0; i < row.size(); i++) {
        areas.push_back(row[i] * (r_limit[i] - l_limit[i] + 1));
        
    }return areas;
}

int main() {
    vector<vector<int>> matrix;
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        vector<int> rtemp;
        for (int j = 0; j < c; j++) {
            int temp;
            cin >> temp;
            rtemp.push_back(temp);
        }
        matrix.push_back(rtemp);
    }
    vector<vector<int>> histogram = create_histogram(matrix);
    vector<int> nihao;
    for (int i = 0; i < histogram.size(); i++) {
        nihao.push_back(find_max(areas_histogram(histogram[i], left_histogram(histogram[i]), right_histogram(histogram[i]))));
    }
    cout<<find_max(nihao);
    return 0;
}
