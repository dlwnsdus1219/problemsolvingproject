// 문제해결 프로젝트 13주차 실습과제 - 깊이우선 탐색(BFS)
// 192992 이준연
#include <iostream>
#include <queue>    // BFS는 큐를 이용하여 탐색 가능하다!!

using namespace std;

int nodes[10][10];    // 인접 행렬(노드와 노드 간 연결)
int visit[10] = {0};    // 각 간선의 방문 여부?

queue<int> q;   // 탐색 대상이 되는 노드를 집어넣는 큐
int num, edge_num;  // 노드, 엣지의 개수

// 인접 행렬 map의 초기화!!
void init() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            nodes[i][j] = 0;
        }
    }
}

void bfs(int v) {
    cout << v << "\n";
    q.push(v);  // 일단 노드에 집어 넣는다(첫 수)

    while(!q.empty()) {
        // 뒤에 탐색할 노드가 아예 0개가 될 때까지 계속 실행!!
        int nn = q.front();
        q.pop();    // 이미 탐색한 노드는 뺀다
        for (int i = 0; i < num; i++) {
            // 그 외 다른 노드들에 대하여 탐색
            if (nodes[nn][i] == 1 && visit[i] == 0) {
                // 간선이 서로 연결되어 있고, 방문이 안 되어있는 상태이면 계속해서 BFS를 실행한다!!
                visit[nn] = 1;    // 해당 노드는 이미 방문했다
                visit[i] = 1;   // 그리고 한 개의 노드에 대해 중복 방문을 막고자 다음과 같이 선언!!
                cout << i << "\n";  // 그리고 아까 그 노드를 출력 ㄱㄱ
                q.push(i);  // 큐에 push 한다 == 계속 BFS를 실시한다.
            }
        }
    }
}

// main 함수 선언
int main() {
    cin >> num >> edge_num; // 노드, 엣지의 개수 각각 입력!!
    init();

    for (int i = 0; i < edge_num; i++) {
        int v1, v2;
        cin >> v1 >> v2;    // 두 노드의 연결을 위와 같이 for문을 통해 해 준다
        nodes[v1][v2] = nodes[v2][v1] = 1;
    }

    bfs(1); // 1부터 차례대로 bfs 알고리즘을 시전한다.

    return 0;
    
}