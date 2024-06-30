// 문제해결프로젝트 3주차 과제 - 2C. 다양성
// 192992 이준연
#include<cstdio>
#include<iostream>

using namespace std;

// 중복을 제외한 화보의 종류 수 세는 함수
int getElementTypeCount(int data[], int n){
    int counttype = 1;  // default 값은 1!!(우리는 2번째 인덱스부터 비교할 거기 때문에 첫번째는 default로 넣어 놓는다)

    // 이전 화보 인덱스 번호와 비교 -> 서로 다른 숫자면 중복 X -> 그만큼 숫자 증가
    for(int i = 1; i < n; i++) {
        if (data[i-1] != data[i]) {
            counttype += 1;
        }
    }

    return counttype;
}

// main 함수
int main()
{
    int n;
    int* data;

    scanf("%d", &n); // 화보의 수 n
    data = new int[n];

    for (int i=0; i<n; i++){
        scanf("%d", &data[i]); // n개 화보의 고유번호
    }

    int answer = getElementTypeCount(data, n);

    printf("%d\n", answer);

    delete[] data;
    return 0;
}
