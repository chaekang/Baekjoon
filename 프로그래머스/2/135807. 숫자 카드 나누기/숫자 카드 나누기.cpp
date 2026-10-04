#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    int g = arrayA[0];
    for (int i=1; i<arrayA.size(); i++) {
        g = gcd(g, arrayA[i]);
    }
    
    bool isAnswer = true;
    for (int i=0; i<arrayB.size(); i++) {
        if (arrayB[i] % g == 0) {
            isAnswer = false;
            break;
        }
    }
    
    if (isAnswer) {
        answer = g;
    }
    
    int gc = arrayB[0];
    for (int i=1; i<arrayB.size(); i++) {
        gc = gcd(gc, arrayB[i]);
    }
    
    isAnswer = true;
    for (int i=0; i<arrayA.size(); i++) {
        if (arrayA[i] % gc == 0) {
            isAnswer = false;
            break;
        }
    }
    
    if (isAnswer) {
        answer = max(g, gc);
    }
    
    return answer;
}