// 문제해결프로젝트 3주차 과제 - 2B. 오름차순인가?
// 192992 이준연
#include<cstdio>
#include<iostream>

bool isOrdered(int data[], int n){
    int count = 0;

    for (int i = 0; i < n-2; i++) { // 0번째 idx부터 n-2번째 idx까지 탐색!!
        // 전체 원소에 대해서 순회하며 탐색(오름차순 여부)
        if (data[i] > data[i+1]) {
            // 이전 원소가 이후 원소보다 크다? -> 오름 차순이라고 볼 수 없음
            count += 1;
            break;
        }
    }

    if (count > 0) {
        return false;
    } else {
        return true;
    }
}

int main()
{
    int n;
    int* data;

    scanf("%d", &n); // 학생 수 n명
    data = new int[n];

    for(int i=0; i<n; i++){ // 학생 N명의 키 데이터 입력
        scanf("%d", &data[i]);
    }

    bool result = isOrdered(data, n);

    if(result){ // 오름차순 여부 출력
        printf("Yes");  // 오름차순이면 Yes
    } else{
        printf("No");   // 아니면 No
    }

    delete[] data;
    return 0;
}
