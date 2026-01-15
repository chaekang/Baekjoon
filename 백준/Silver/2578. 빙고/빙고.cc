#include <iostream>
using namespace std;

int map[5][5];
int check_bingo(){
    int num_of_bingo = 0; //선이 몇 개 있는지 판별
   
     //첫번쨰 경우(가로로 모두 0인 경우)
    for(int i = 0;i<5;i++){
        bool valid = false;
        for(int j = 0;j<5;j++){
            if(map[i][j] != 0){
                valid = true;
                break;
            }
        }
        if(valid == false){
            num_of_bingo++;
        }
    }
   
    //두번쨰 경우(세로로 모두 0인 경우)
    for(int i = 0;i<5;i++){
        bool valid = false;
        for(int j = 0;j<5;j++){
            if(map[j][i] != 0){
                valid = true;
                break;
            }
        }
        if(valid == false){
            num_of_bingo++;
        }
    }
    //세번째 경우 (왼쪽 (1,1)부터 (5,5)까지 대각선이 모두 0인 경우)
   bool valid = false;
    for(int i = 0;i<5;i++){
        if(map[i][i] != 0){
            valid = true;
        }
        if(valid == true){
            break;
        }
    }
   
    if(valid == false){
        num_of_bingo++;
    }
   
    valid = false;
    //마지막 대각선이 모두 0인 경우
    for(int i = 4;i>=0;i--){
        if(map[i][4-i] != 0){
            valid = true;
            break;
        }
    }
    if(valid == false){
        num_of_bingo++;
    }
   
    //선이 세 개 이상이면 빙고
    if(num_of_bingo >= 3){
        return 1;
    }
    //그렇지 않으면 -1 리턴
   return -1;
}
int main(void){
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            cin >> map[i][j];
        }
    }
   
    int first = 1;
    int x;
   
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
           
            cin >> x;
            first++;
            bool is_find = false;
           
            for(int k = 0;k<5;k++){
                for(int q = 0;q<5;q++){
                    /*부른 원소를 찾아서 0으로 만든다 */
                    if(map[k][q] == x){
                        is_find = true;
                        map[k][q] = 0;

                    }
                }

            }
            //빙고를 만족 할떄,
            if(check_bingo() == 1){
                cout << first - 1;
                return 0;
            }
        }
    }
}

