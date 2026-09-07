#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(string word, vector<string> &dic) {
    dic.push_back(word);
    
    if (word.size() == 5) {
        return;
    }
    
    char vowels[5] = {'A', 'E', 'I', 'O', 'U'};
    for (char c: vowels) {
        DFS(word + c, dic);
    }
}

int solution(string word) {
    int answer = 0;
    
    vector<string> dic;
    DFS("", dic);
    
    auto it = find(dic.begin(), dic.end(), word) - dic.begin();
    answer = it;
    
    return answer;
}