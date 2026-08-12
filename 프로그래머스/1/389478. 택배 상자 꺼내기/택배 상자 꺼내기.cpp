#include <string>
#include <vector>
#include <iostream>

using namespace std;

int Floor (int num, int w) {
    if (num % w == 0) {
        return num / w;
    }
    return (num + (w - (num % w))) / w;
}

int Pos(int floor, int num, int w) {
    int pos = 0;
    if (floor % 2 == 0) {
        if (num % w == 0) {
            pos = 1;
        }
        else {
            pos = w - (num % w) + 1;
        }
    }
    else {
        pos = num % w;
        if (pos == 0) {
            pos = w;
        }
    }
    return pos;
}

int solution(int n, int w, int num) {
    int answer = 0;
    int floor = Floor(num, w);
    int pos = Pos(floor, num, w);
    cout<< floor <<" "<<pos<<"\n";
    
    int high_floor = Floor(n, w);
    int high_pos = Pos(high_floor, n, w);
    cout<<high_floor<<" "<<high_pos<<"\n";
    
    if (high_pos != w) {
        answer = high_floor - floor;
        if (high_floor % 2 == 1 && high_pos >= pos) {
            answer++;
        }
        else if (high_floor % 2 == 0 && high_pos <= pos) {
            answer++;
        }
    }
    else {
        answer = high_floor - floor + 1;
    }
    
    return answer;
}