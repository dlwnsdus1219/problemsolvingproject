// 문제해결 프로젝트 13주차 실습과제 - 깊이 우선 탐색(DFS)
// 192992 이준연
#include <iostream>

// 입력: 첫 번째 줄에 간선 총 개수, 그 이후 줄에 간선의 시작점 끝점 차례로 입력
// 출력: DFS 결과

using namespace std;

int maps[10][10];   // 인접 행렬(노드 사이 간선 시작점 + 끝점 정보 저장)
int visited[10] = {0};  // 각 노드 사이의 간선?
int num;

// 인접 행렬 maps의 초기화
void init() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            maps[i][j] = 0;
        }
    }
}

// 본격적인 DFS 메커니즘 시작!!
void dfs(int v) {
    cout << v << endl;
    visited[v] = 0; // 한번 순회한 점에 대해서는 더이상 dfs를 수행하지 않겠다!!
    for (int i = 0; i <= num; i++) {
        if (maps[v][i] == 1 && visited[i] == 1) {
            // 재귀 함수 형태로 호출!!(연결된 간선이 있고, 순회하지 않은 점일 경우) --> 둘다 해당되어야 하므로 && 연산자 사용!!
            dfs(i);
        }
    }
}

int main(void) {
    int v1, v2; 
    init(); // 일단 먼저 초기화!!
    cin >> num; // 간선 개수를 먼저 입력
    for (int i = 0; i < num; i++) {
        cin >> v1 >> v2;
        // 무방향 그래프이기 때문에, 시작점과 끝점이 같으면 같은 간선 취급한다!!
        maps[v1][v2] = maps[v2][v1] = 1;    
        visited[v1] = visited[v2] = 1;
    }
    dfs(1); // 1번 점부터 8번 점까지 모두 dfs 연산 돌리기

    return 0;
}