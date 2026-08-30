#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> count;
    
    for (string p: participant) {
        count[p]++;
    }
    
    for (string c: completion) {
        count[c]--;
    }
    
    for (string p: participant) {
        if (count[p] > 0) {
            answer = p;
            break;
        }
    }
    
    return answer;
}