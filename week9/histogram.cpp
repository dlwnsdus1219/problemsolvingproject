// 문제해결 프로젝트 9주차 실습 과제 - 6C. 히스토그램
// 192992 이준연
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

// 히스토그램 내부에서 발생할 수 있는 직사각형 case 중, 가장 넓이가 클 경우는?

// 입력: 테스트 케이스 수 T, T개의 직사각형의 높이 입력(공백 구분)
// 출력: 각 테스트 케이스 별로 한 줄에 히스토그램 내부에 존재할 수 있는 직사각형의 최대 넓이를 계산!!

using namespace std;

// Histogram 클래스의 선언!!
class Histogram {
    public: 
        int left;
        int right;
        int height;

        Histogram() {}

        // 생성자 선언!!
        Histogram(int i, int h) {
            this -> left = i;
            this -> right = this -> left + 1;   // 히스토그램의 모든 너비는 1이기 때문!!
            this -> height = h;
        }
};

// 최대 직사각형의 넓이 구하기(by Stack)
long long getLargestRectangleArea(const vector<Histogram>& histograms) {
    long long maxwidth = 0;

    // 최대 넓이를 생성할 가능성이 있는(우측 확장 가능) 히스토그램
    stack<Histogram> stk;

    stk.push(Histogram(-1, 0)); // 구현상 편의를 위해, 가장 좌측에 높이 0까지의 가상 히스토그램을 추가한다.

    // 전체 히스토그램 대상으로 for문 돌리기
    for (int i = 0; i < histograms.size(); i++) {
        Histogram h;    // 임의의 히스토그램 변수 선언
        if (i < histograms.size()) {
            h = histograms[i];
        } else {
            // 구현상의 편의를 위해 가장 우측에 높이 0의 가상의 히스토그램 추가 ㄱㄱ
            h = Histogram(histograms.size(), 0);
        }

        // 이전에 확장 중이던 히스토그램들 중, h보다 높이가 높은 히스토그램은 더 이상 확장이 불가능!! == 최대 넓이가 결정!!
        while (stk.size() > 1 && stk.top().height > h.height) {
            // 확장 중이던 히스토그램
            Histogram lh = stk.top();   // 삭제하기 전에 lh라는 변수에 미리 저장!!
            stk.pop();

            // 계속해서 높이 높은 히스토그램 제거하다가 마지막 남은, 제일 왼쪽 히스토그램
            Histogram bh = stk.top();

            // 높이 높은 히스토그램 모두 제거하고 난 뒤, 밑에 남은 영역의 직사각형 넓이?
            long long width = abs(h.left - bh.right);     
            long long height = lh.height;
            long long area = width * height;   

            // 기존 값과 비교하여 최댓값 갱신
            maxwidth = max(maxwidth, area);
        }

        // h를 새로이 추가함
        stk.push(h);
    }
}

// 히스토그램 내부에 존재할 수 있는 직사각형의 최대 넓이 구하기
void process(int caseIndex) {
    int n;  
    cin >> n;   // 히스토그램은 몇 개의 인덱스로 구성되어 있을 것인가?

    vector<Histogram> histograms;   // Histogram 타입의 새로운 벡터 변수를 선언한다

    // 히스토그램의 인덱스와 높이를 설정한다!!
    for (int i = 0; i < n; i++) {
        int height;
        cin >> height;
        histograms.push_back(Histogram(i, height));
    }

    long long answer = getLargestRectangleArea(histograms);   // 최대 면적이 100000^2 까지 가능!!(int로 선언 시 overflow 가능성)
    cout << answer << endl;

}

int main() {
    int caseSize;
    cin >> caseSize;    // test case의 개수를 입력한다

    // 테스트 케이스만큼 process를 반복해서 선언한다!!
    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
        process(caseIndex);
    }
}


/* 3중 반복문, 시간복잡도 O(N^3)
for (int i = 0 ~ n-1)
{
    for (int j = 1 ~ n-1)
    {
        for (int k = 1~r)
        {
            // 높이의 최솟값?
            // 면적 = (r - l + 1) * 높이의 최솟값
        }
    }
}


*/