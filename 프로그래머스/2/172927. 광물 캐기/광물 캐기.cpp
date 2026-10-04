#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Group {
    int diamond = 0;
    int iron = 0;
    int stone = 0;
};

int function(const Group& group, int pick) {
    if (pick == 0) {
        return group.diamond + group.iron + group.stone;
    }
    else if (pick == 1) {
        return group.diamond * 5 + group.iron + group.stone;
    }
    else {
        return group.diamond * 25 + group.iron * 5 + group.stone;
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    vector<Group> groups;
    
    int pickNum = picks[0]+picks[1]+picks[2];
    int limits = min(pickNum*5, (int)minerals.size());
    
    for (int i=0; i<limits; i+=5) {
        int diamond=0;
        int iron=0;
        int stone=0;
        for (int j=0; j<5 && i+j<minerals.size(); j++) {
            if (minerals[i+j] == "diamond") {
                diamond++;
            }
            else if (minerals[i+j] == "iron") {
                iron++;
            }
            else {
                stone++;
            }
        }
        
        groups.push_back({diamond, iron, stone});
    }
    
    sort (groups.begin(), groups.end(), 
         [](const Group& a, const Group& b) {
             if (a.diamond != b.diamond) {
                 return a.diamond > b.diamond;
             }
             return a.iron > b.iron;
         });
    
    for (int i=0; i<groups.size(); i++) {
        if (picks[0] > 0) {
            answer += function(groups[i], 0);
            picks[0]--;
        }
        else if (picks[1] > 0) {
            answer += function(groups[i], 1);
            picks[1]--;
        }
        else if (picks[2] > 0) {
            answer += function(groups[i], 2);
            picks[2]--;
        }
    }
    
    return answer;
}