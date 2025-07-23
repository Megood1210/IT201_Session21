#include <stdio.h>
#define MAX 3

// Hàm thêm cạnh giữa 2 node trong đồ thị vô hướng
void addEdge(int graph[MAX][MAX], int node1, int node2) {
    graph[node1][node2] = 1;
    graph[node2][node1] = 1;
}

// Hàm in ma trận kề theo format yêu cầu
void printGraph(int graph[MAX][MAX]) {
    printf("[\n"); // In ký tự mở đầu
    // Duyệt từng hàng ma trận
    for (int i = 0; i < MAX; i++) {
        printf(" "); // In khoảng trắng thụ đầu hàng
        // Duyệt từng cột
        for (int j = 0; j < MAX; j++) {
            printf("%d", graph[i][j]); // In giá trị tại [i][j]
            // In dấu phảy nếu là phần tử cuối
            if (j < MAX - 1) {
                printf(",  ");
            }
        }
        printf("\n");
    }
    printf("]\n"); // Kết thúc ma trận
}

int main() {
    int graph[MAX][MAX] = {0}; // Khởi tạo ma trận 3x3

    // Thêm cạnh giữa node A và B
    addEdge(graph, 0, 1);

    // In kết quả
    printGraph(graph);

    return 0;
}
