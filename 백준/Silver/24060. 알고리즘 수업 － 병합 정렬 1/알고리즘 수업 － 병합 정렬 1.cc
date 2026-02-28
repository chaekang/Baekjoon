#include <iostream>
using namespace std;


int *temp, *numbers, cnt = 1;

void merge(int A[], int p, int q, int r);
void merge_sort(int A[], int p, int r) {
    
    if (p < r) {
        int q = ((p + r) / 2);
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    
    }
}

void merge(int A[], int p, int q, int r) {
    
    int i = p, j = q + 1, t = 1;
    while (i <= q && j <= r) {
        if (A[i] <= A[j]) {
            temp[t++] = A[i++];
            numbers[cnt++] = temp[t - 1];
        }
        else {
            temp[t++] = A[j++];
            numbers[cnt++] = temp[t - 1];
        }
    }

    while (i <= q) {
        temp[t++] = A[i++];
        numbers[cnt++] = temp[t - 1];
    }

    while (j <= r) {
        temp[t++] = A[j++];
        numbers[cnt++] = temp[t - 1];
    }

    i = p, t = 1;

    while (i <= r)
        A[i++] = temp[t++];

}

int main() {
    

    ios_base::sync_with_stdio(false); cin.tie(NULL); //백준에 코드를 제출할 때, 경과시간을 줄일 수 있는 방법.

    int A_size=0, K=0;
    
    cin >> A_size >> K;
    int* A = new int[A_size+1];
    temp = new int[A_size + 1];
    numbers = new int[100000000];

    for (int i = 0; i < A_size; i++) {
        cin >> A[i];
    }
    

    merge_sort(A, 0, A_size-1);
    if (K < cnt)
        cout << numbers[K];
    else
        cout << -1;


    delete[] A, temp, numbers;

}