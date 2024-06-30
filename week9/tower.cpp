// 문제해결 프로젝트 9주차 실습 과제 - 6B. 탑
// 192992 이준연
#include <iostream>
#include <vector>
#include <stack>

// 일직선 위에 N개의 높이가 서로 다른 탑을 수평 직선의 왼쪽부터 오른쪽으로 설치!!
// 각 탑 꼭대기에 레이저 송신기 설치(지표면과 평행하게 수평 직선의 왼쪽으로 발사)
// 하나의 레이저 신호는 가장 먼저 만나는 단 하나의 탑에서 수신 가능

// 입력: 탑의 수(첫째 줄), N개의 탑의 높이가 직선상의 순서로 주어진다(빈칸 하나 기준)
// 출력: 주어진 탑들의 순서대로, 각각의 탑들에서 발사한 레이저 신호를 수신한 탑들의 번호를 공백 구분하여 출력(단, 없으면 0 출력한다!!)

using namespace std;

class Tower {
    public:
        int index;  // 타워의 인덱스
        int height; // 타워의 높이
        int targetTowerindex;   // 타워의 레이저 수신하는 대상 타워

        // 생성자의 선언 
        Tower(int index, int height) {
            this -> index = index;
            this -> height = height;
            this -> targetTowerindex = 0;   // 일단 초기값은 0으로!!
        }

        // 별도의 함수로 target tower index를 설정해 줄 경우
        void setTargetIndexTowers(int targetTowerIndex) {
            this -> targetTowerindex = targetTowerIndex;
        }

        // 앞서 선언한 target tower index를 반환하는 함수!!
        int getTargetTowerIndex() {
            return this -> targetTowerindex;
        }
};

// 직접 타워의 레이저를 수신하는 타워를 계산한다(feat. 스택)
void findTargetTower(vector<Tower>& towers) {
    stack<Tower> stk;   // 현재 다른 타워의 신호를 수신할 가능성이 있는 타워(제일 왼쪽부터 순차적으로 탐색한다)

    // 각각 타워에 대해 연산 
    // 시간 복잡도 O(N)
    for (int i = 0; i < towers.size(); i++) {
        Tower& t = towers[i];   // 임의의 tower 벡터의 원소를 가리키는 포인터 선언!!
        int targetTowerIndex = 0;   // 각 타워의 신호를 수신할 타워(없으면 0을 반환)

        while (stk.empty() == false && t.height > stk.top().height) {
            // t보다 높이가 낮은 타워들은 모두 현재 타워의 신호를 수신할 가능성 zero --> 스택에서 제거한다!!
            stk.pop();
        } 

        // t 이상의 높이를 가진 타워가 아직 남아있다면? -> 얘를 해당 타워의 타깃으로 정한다!!
        if (stk.size() > 0) {
            targetTowerIndex = stk.top().index;
        }

        t.setTargetIndexTowers(targetTowerIndex);   // 앞에서 계산한 타깃 정보를 해당 객체 내 원소로 세팅해준다!!

        // 그리고 자신도 나중에 나온 타워의 신호를 수신할 수 있으므로, 일단 스택에 저장해 놓는다(나중에 빠지는 한이 있을지라도)
        stk.push(t);
    }
}

// main 함수 선언
int main() {
    int n;  // 탑의 개수를 나타내는 정수 n
    cin >> n;

    vector<Tower> towers;   // Tower 클래스 타입으로 벡터를 선언(레이저 신호 수신 여부 측정 타워)

    for (int i = 0; i < n; i++) {
        int hi;
        cin >> hi;
        towers.push_back(Tower(i + 1, hi)); // 앞서 입력받은 인덱스 번호(i+1)랑 높이 정보를 벡터 내에 삽입 및 입력
    }

    // 각 타워가 송신하는 레이저에 대한 타깃 계산
    findTargetTower(towers);

    for (int i = 0; i < towers.size(); i++) {
        if (i > 0) {
            cout << " ";
        }
        Tower& t = towers[i];
        int targetIndex = t.getTargetTowerIndex();
        cout << targetIndex;
    }
}
/* 시간복잡도가 O(N^2)
for (i=0~N-1)
{
    int target = 0;
    for(j = i-1~0)
    {
        if(h[j]>h[i])
        {
            target=j;
            break;
        }
    }
}
*/