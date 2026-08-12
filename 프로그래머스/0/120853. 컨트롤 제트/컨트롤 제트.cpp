#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int prev = 0;
    
    stringstream ss(s);
    string token;
    
    while (ss >> token) {
        if (token == "Z") {
            answer -= prev;
        }
        else {
            prev = stoi(token);
            answer += prev;
        }
    }
    
    return answer;
}