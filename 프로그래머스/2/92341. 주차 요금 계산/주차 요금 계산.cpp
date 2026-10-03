#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int toMinute(string time) {
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));

    return hour * 60 + minute;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    int baseTime = fees[0];
    int baseFee = fees[1];
    int unitTime = fees[2];
    int unitFee = fees[3];

    map<int, int> inTime;
    map<int, int> totalTime;

    for (int i = 0; i < records.size(); i++) {
        stringstream ss(records[i]);

        string timeString;
        string carNumber;
        string status;

        ss >> timeString >> carNumber >> status;

        int time = toMinute(timeString);
        int car = stoi(carNumber);

        if (status == "IN") {
            inTime[car] = time;
        }
        else {
            totalTime[car] += time - inTime[car];
            inTime.erase(car);
        }
    }

    int endTime = toMinute("23:59");

    for (const auto& p : inTime) {
        int car = p.first;
        int time = p.second;

        totalTime[car] += endTime - time;
    }

    for (const auto& p : totalTime) {
        int parkTime = p.second;

        if (parkTime <= baseTime) {
            answer.push_back(baseFee);
        }
        else {
            int excessTime = parkTime - baseTime;

            int count = excessTime / unitTime;

            if (excessTime % unitTime != 0) {
                count++;
            }

            int fee = baseFee + count * unitFee;

            answer.push_back(fee);
        }
    }

    return answer;
}