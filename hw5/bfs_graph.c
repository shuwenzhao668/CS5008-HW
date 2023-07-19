#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100000
#define MAX_NUM_VERTICES 100

struct Node {
    int vertex;
    struct Node *next;
};

struct Queue {
    int front, rear;
    int items[MAX_QUEUE_SIZE];
};

void enqueue(struct Queue *queue, int item) {
    if (queue->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    queue->items[++queue->rear] = item;
}

int dequeue(struct Queue *queue) {
    if (queue->front == queue->rear) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->items[++queue->front];
}

bool is_empty(struct Queue *queue) {
    return queue->front == queue->rear;
}

void add_edge(struct Node *adj_list[], int from, int to) {
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->vertex = to;
    new_node->next = adj_list[from];
    adj_list[from] = new_node;
}

void BFS(struct Node *adj_list[], int start_vertex, int num_vertices) {
    bool visited[num_vertices];
    for (int i = 0; i < num_vertices; i++) {
        visited[i] = false;
    }
    struct Queue queue;
    queue.front = queue.rear = -1;
    enqueue(&queue, start_vertex);
    visited[start_vertex] = true;
    while (!is_empty(&queue)) {
        int current_vertex = dequeue(&queue);
        printf("%d ", current_vertex);
        for (int adj_vertex = 0; adj_vertex < num_vertices; adj_vertex++) {
            struct Node *temp = adj_list[current_vertex];
            while (temp != NULL) {
                if (temp->vertex == adj_vertex) {
                    if (!visited[adj_vertex]) {
                        enqueue(&queue, adj_vertex);
                        visited[adj_vertex] = true;
                    }
                    break;
                }
                temp = temp->next;
            }
        }
    }
}

void free_graph(struct Node *adj_list[], int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        struct Node *temp = adj_list[i];
        while (temp != NULL) {
            struct Node *node_to_free = temp;
            temp = temp->next;
            free(node_to_free);
        }
        adj_list[i] = NULL; 
    }
}

int main() {
    struct Node *adj_list[MAX_NUM_VERTICES];
    for (int i = 0; i < MAX_NUM_VERTICES; i++) {
        adj_list[i] = NULL;
    }
    add_edge(adj_list, 0, 1);
    add_edge(adj_list, 0, 3);
    add_edge(adj_list, 1, 2);
    add_edge(adj_list, 1, 4);
    add_edge(adj_list, 2, 5);
    add_edge(adj_list, 3, 4);
    add_edge(adj_list, 3, 6);
    add_edge(adj_list, 4, 7);
    add_edge(adj_list, 5, 8);
    add_edge(adj_list, 6, 7);
    add_edge(adj_list, 7, 8);
    int start_vertex = 0;
    int num_vertices = 9;
    BFS(adj_list, start_vertex, num_vertices);
    free_graph(adj_list, num_vertices);
    return 0;
}