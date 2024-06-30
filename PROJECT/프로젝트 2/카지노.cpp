// 프로젝트 2: 카지노
// 192992 이준연
// 게임에 사람 N명이 참가, 각자에겐 1부터 10 사이의 숫자 카드 5장이 주어진다. 
// 이 중, 3장을 골라 합을 구해서 일의 자리 수가 가장 큰 사람이 승리!!
#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<time.h>    // 코드의 구동 시간 측정을 위해 해당 라이브러리를 설치해준다

using namespace std;

#define ITERATION_TIME 100000
const int CARD_NO = 5;

// 입력: 참가 인원 N, 그 다음 줄부터는 각 사람들마다 가진 5개의 정수 카드 번호를 입력한다!!(단, 입력 조건은 cin - cout 명령어를 사용!!)
// 출력: 승리한 참가자의 번호(단, 둘의 점수가 같으면 더 높은 번호를 출력!!)

// 사용자의 입력을 받아, 각각 크기가 5인 다른 벡터를 생성하는 Class
class casinoCards {
    public:
        vector<int> card;   // 

    
        // 사용자 입력을 통해 각 벡터를 초기화한다
        casinoCards() {
            for (int i = 0; i < CARD_NO; ++i) {
            int userInput;
            std::cin >> userInput;  // 카드 입력값 받기
            card.push_back(userInput);  // 벡터 내 사용자 입력 추가!!
            }
        }
        
        
};

// 일의 자리 수가 가장 크도록 조합을 구한다!!
int bigoneNumber(vector<int> &d) {
    vector<int> ones;   // 조합 후 일의 자리 수를 저장할 벡터 선언
    int n = d.size();   // 각 숫자 카드 담은 벡터(해당 함수의 input)의 size
    int sum = 0;
    int biggest = 0;

    // 3중 for문을 이용하여, 5개 숫자로 이루어진 숫자 카드 쌍에서 3개의 서로 다른 숫자 조합을 이끌어낸다
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                sum += (d[i] + d[j] + d[k]) % 10; // 3개의 숫자 조합끼리 더한 후 10을 나눈 나머지 == 각 합의 일의 자리 수
                ones.push_back(sum);
            }
        }
    }

    sort(ones.begin(), ones.end()); // 먼저 정렬부터 해 준다!!

    vector<int>::iterator uit = unique(ones.begin(), ones.end());

    // 앞에서 구한 ones 벡터 내 중복 원소 제거
    ones.erase(uit, ones.end()); // algorithm 헤더 내 unique 함수가, 벡터 내 중복값을 뒤로 모아주므로, 동떨어져 있으면 중복을 인식 못한다 --> unique 함수 적용 전에 sorting 먼저 한다!!

    // 앞에서 중복 제거한 일의 자리 합 벡터 중, 가장 큰 값을 리턴한다.
    // 이미 오름차순 정렬된 벡터 --> 제일 뒤의 원소만 반환해 주면 끝!!
    int max = ones.back(); 
    return max;
}

// 가장 일의 자리가 큰 참가자를 출력하는 함수!!
void findMax(vector<int> &vec) {
    int max_idx = 0;
    int max_num = vec[0]; // 일단 최댓값을 벡터의 최댓값으로 초기화해준다.

    for (int i = 1; i < vec.size(); ++i){
        // 가장 참가번호가 높은 참가자를 찾는다
        if (vec[i] >= max_num){
            max_num = vec[i]; // 앞에서 구한 max_num보다 해당 idx가 크면 max_num 갱신
            max_idx = i; // 그리고 최대 인덱스 역시 갱신해준다!!
        }
    }

    max_idx += 1; // 그리고 벡터의 인덱스가 (0 ~ n-1)임을 감안하여 최종 정답에는 1씩 추가해준다
    
    std::cout << max_idx << "\n";
}


int main() {
    int n;   // 참가자의 수 N을 입력받는다!!
    int max_idx = 0;
    std::cin >> n;

    vector<int> compare;    // 각 사용자별 가장 큰 일의자리 수 저장할 벡터 선언

    // 클래스 객체의 생성(각 사용자들을 클래스 배열로 정의)
    casinoCards* gamer = new casinoCards[n];


    //clock_t: clock_ticks의 자료를 담고 있는 자료형으로, clock()의 반환형이다!!
    clock_t start = clock(); // 시작 시간 저장
    
    // bigoneNumber 함수를 반복 호출함으로서 각 사용자별 가장 큰 일의자리 수를 구한다!!
    for (int j = 0; j <= n; ++j) {
        compare.push_back(bigoneNumber(gamer[j].card));
    }

    findMax(compare);   // 최종적으로 일의 자리 숫자가 가장 큰 사람을 구해준다!!(by index)
    
    clock_t end = clock(); // 코드가 끝난 시간 저장!!

    // 걸린 시간 출력
    std:cout << "걸린 시간: " <<  (double)(end - start)/CLOCKS_PER_SEC << "초" << std::endl;

    delete[] gamer;
    return 0;
}