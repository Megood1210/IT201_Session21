#include <stdio.h>
#include <stdlib.h>

#define MAX 3

// Cấu trúc node trong danh sách kề
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Tạo node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Thêm cạnh vào đồ thị vô hướng
void addEdge(Node* graph[], int startNode, int endNode) {
    // Thêm endNode vào danh sách của startNode
    Node* newNode = createNode(endNode);
    // Gán node mới vào đầu danh sách kề của startNode
    newNode->next = graph[startNode];
    graph[startNode] = newNode;

    // Thêm startNode vào danh sách của endNode
    newNode = createNode(startNode);
    // Gán node mới vào đầu danh sách kề của endNode
    newNode->next = graph[endNode];
    graph[endNode] = newNode;
}

// In danh sách kề
void printGraph(Node* graph[]) {
    for (int i = 0; i < MAX; i++) {
        printf("%d ->", i); // In số thứ tự của node
        Node* temp = graph[i]; // Trỏ tới đầu danh sách của node thú i
        // Duyệt danh sách
        while (temp != NULL) {
            printf(" %d", temp->value); // In giá trị
            temp = temp->next; // Di chuyển đến node tiếp
        }
        printf(" -> NULL\n"); // Kết thúc hàng
    }
}

int main() {
    // Khởi tạo mảng danh sách kề với NULL
    Node* graph[MAX] = {NULL};

    // TH1 trong ảnh: thêm cạnh từ 1 đến 2
    addEdge(graph, 1, 2);

    // In kết quả
    printGraph(graph);

    // Xóa đồ thị sau khi dùng
    for (int i = 0; i < MAX; i++) {
        Node* temp = graph[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }

    return 0;
}