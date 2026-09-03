#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int find(int x, vector<int> &parent) {
    if (parent[x] == x) {
        return x;
    }
    
    return find(parent[x], parent);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    vector<int> parent(n);
    for (int i=0; i<n; i++) {
        parent[i] = i;
    }
    
    sort(costs.begin(), costs.end(), 
         [](const vector<int> &a, const vector<int> &b) {
             return a[2] < b[2];
         });
    
    for (int i=0; i<costs.size(); i++) {
        int a = costs[i][0];
        int b = costs[i][1];
        int cost = costs[i][2];
        
        int rootA = find(a, parent);
        int rootB = find(b, parent);
        
        if (rootA != rootB) {
            parent[rootA] = rootB;
            answer += cost;
        }
    }
    
    return answer;
}