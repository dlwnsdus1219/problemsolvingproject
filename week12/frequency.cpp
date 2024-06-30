// 문제해결 프로젝트 12주차 실습과제 - 6J. 빈도수 세기
// 192992 이준연
#include <stdio.h>
#include <map>

// 입력: 첫 줄에 입력할 정수의 개수 N, 그 이후 줄에는 차례대로 N개의 정수 입력(고려해야 할 순서로 입력, 32비트 정수형 보장)
// 출력: N개의 각 자연수마다 처리 결과 한 줄에 처리(현재까지 입력으로 주어진 수의 종류, 해당 숫자가 등장한 횟수(공백 구분))

// ex) {5, 3, 5, 3, 2} -> {1, 1}/{2, 1}/{2, 2}/{2, 2}/{3, 1}

using namespace std;

int main() {
    int N;
    scanf("%d", &N);    // 테스트 케이스 개수 N 입력


    // 원래같으면 이중 for문 사용하여 해결할 문제, Map 통해서 쉽고 간편하게 해결 가능!!
    // 각 <정수, 빈도수> 형태로 key-value 저장할 Map을 선언한다
    // frequencyMap: 이전에 입력된 정수들의 빈도 수를 저장한다!!
    map<int, int> frequencyMap;

    for (int i = 0; i < N; i++) {
        int X; 
        scanf("%d", &X);    // 테스트 케이스 별로 각 정수 입력
        frequencyMap[X]++;  // 각 정수가 등장한 횟수(key에 대한 value값) 1씩 증가(해당 정수 입력 때마다)
        printf("%d %d\n", frequencyMap.size(), frequencyMap[X]);    // map변수는 중복을 허용하지 않으므로, size 함수 적용 시 중복되지 않는 node 수 출력한다!!
    }

    return 0; 
    /*
    // 아래와 같이 iterator를 사용하면, 각 정수에 따른 등장 빈도 횟수가 value로 등장하고 오름차순으로 출력된다!!
    map<int, int>::iterator it;

    for(it = frequencyMap.begin(); it != frequencyMap.end(); it++)
    {
        printf("%d %d\n", it->first, it->second);
    }
    // 2  1
    // 3  2
    // 5  2

    */
}