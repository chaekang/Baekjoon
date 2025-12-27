#include <iostream>

using namespace std;

bool isRight (int g, int a, int b) { 
	// a, b 두 수의 최대공약수가 g가 맞는지 검증
    for (int i=g*2, j=3 ; i<=a ; i=g*j, j++) {  
        if (a%i==0 and b%i==0) return false;
    }
    
    return true;
}

int main() {
    long long G, L;
    scanf("%lld %lld", &G, &L);
    
    long long min = 200000001; //min이 될 수 있는 최댓값+1을 초기값으로.
    int resultA=0, resultB=0;
    
    for (long long a=G ; a<=L ; a+=G) {
        long long b = L*G/a;
        if (L%a==0 && L%b==0 && b%G==0) { //a와 b가 모두 L의 약수이며, G가 b의 약수이고, 
            if (isRight(G, a, b)) { //a와 b의 최소공배수가 G가 맞다면 정답.
                if (min>a+b) { //a+b가 가장 작은 값을 저장한다. 
                    min = a+b;
                    resultA=a;
                    resultB=b;
                }
            }
        }
    }
    
    printf("%d %d", resultA, resultB);
}