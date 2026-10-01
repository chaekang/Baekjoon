#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> m;

bool allZero() {
    for (const auto& p: m) {
        if (p.second != 0) {
            return false;
        }
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    for (int i=0; i<want.size(); i++) {
        m[want[i]] = number[i];
    }
    
    for (int i=0; i<10; i++) {
        if (m.find(discount[i]) != m.end()) {
            m[discount[i]]--;
        }
    }
    
    if (allZero()) {
        answer++;
    }
    
    for (int i=10; i<discount.size(); i++) {        
        if (m.find(discount[i-10]) != m.end()) {
            m[discount[i-10]]++;
        }
        
        if (m.find(discount[i]) != m.end()) {
            m[discount[i]]--;
        }
        
        if (allZero()) {
            answer++;
        }
    }
    
    return answer;
}