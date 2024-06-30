// 문제해결 프로젝트 4주차 과제 - 2I. 정주행
// 192992 이준연
#include<cstdio>
#include<iostream>

using namespace std;

// max - min =  n -1
// 간단하게 O(n)의 시간복잡도로 해결 가능!!

bool isConsecutive(int data[], int n){
    // 연속이면 true, 아니면 false 반환
    // 우선 min, max 모두 첫 원소로 초기화!!
    int min_data = data[0];
    int max_data = data[0];

    for (int i = 0; i < n; i++) {
        if (max_data < data[i]) {
            max_data = data[i]; // max_data 지속적으로 갱신(더 큰 값이 max_data)
        }

        if (min_data > data[i]) {
            min_data = data[i]; // min_data 지속적으로 갱신(더 작은 값이 min_data)
        }
    }

    if (max_data - min_data == n - 1) {
        return true;
    } else {
        return false;
    }
}

int main(){
    int n;
    int* data;

    scanf("%d", &n);    // 숫자 개수 입력
    data = new int[n];  // 입력받은 숫자 개수만큼 배열 메모리 설정

    for(int i = 0; i < n; i++){
        scanf("%d", &data[i]);  // 에피소드의 번호 입력(in 배열)
    }

    bool result = isConsecutive(data, n);

    if(result){
        printf("YES");
    } else{
        printf("NO");
    }


    delete[] data;
    return 0;
}