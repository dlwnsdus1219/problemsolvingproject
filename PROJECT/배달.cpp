// 문제해결 프로젝트 프로젝트4 - 2. 배달
// 192992 이준연
#include <iostream> // C++ 표준 입력 라이브러리
#include <vector>
#include <algorithm>
#include <cmath>
#include <time.h>    // 코드의 구동 시간 측정을 위해 해당 라이브러리를 설치해준다


using namespace std;


int main() {
    int n;  // 전체 소포의 수
    int dmin = 0;   // 델타 시퀀스 내 최솟값
    int dmax = 0;   // 델타 시퀀스 내 최댓값
    int sum = 0;    // 델타 시퀀스 원소들의 합
    std::cin >> n;

    vector<int> delta;  // 델타 인코딩 된 소포의 번호
    vector<int> answer; // 정답을 저장할 벡터 선언

    // 전체 소포 수 - 1만큼 델타 시퀀스를 먼저 입력받는다
    for (int i = 0; i < n - 1; ++i) {   
        int k;
        std::cin >> k;
        delta.push_back(k);
    }

    
    //clock_t: clock_ticks의 자료를 담고 있는 자료형으로, clock()의 반환형이다!!
    clock_t start = clock(); // 시작 시간 저장


    // 델타 시퀀스 전체 탐색하여 sum, dmax, dmin 값 업데이트!!
    for (int j = 0; j < delta.size(); ++j) {
        sum += delta[j];
        dmax = max(sum, dmax);
        dmin = min(sum, dmin);
    }


    // dmax - dmin은 고로 델타 시퀀스의 값이 어느 범위에 있는지 나타내므로, 기존 라벨 번호가 1부터 N 사이에 있는지 판단하는 좋은 지표가 된다.
    if (dmax - dmin != n - 1) {
        answer.push_back(-1);
    } else {
        int firstnum = n - dmax;    // 첫 라벨번호는, 전체 시퀀스 수 - 델타 시퀀스의 최댓값으로!!
        answer.push_back(firstnum);
        for (int j = 1; j < n; j++) {
            answer.push_back(answer[j - 1] + delta[j - 1]); // 기존 델타 시퀀스와의 차를 이용하여 차례대로 뒤의 원소들을 구해 나간다
        }
    }

    // 기존 소포 번호들을 차례대로 출력한다
    for (int k = 0; k < answer.size(); k++) {
        if (k > 0) {
            std::cout << " ";
        }
        std::cout << answer[k];
    }

    clock_t end = clock(); // 코드가 끝난 시간 저장!!

    // 걸린 시간 출력
    std::cout << "걸린 시간: " <<  (double)(end - start)/CLOCKS_PER_SEC << "초" << std::endl;

    return 0;
}