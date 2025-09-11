#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

Node* reverse(Node* head, Node* tail) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != tail) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* reverseKGroup(Node* head, int k) {
    if (!head)
        return nullptr;

    Node* tail = head;
    for (int i = 0; i < k; ++i) {
        if (!tail)
            return head;
        tail = tail->next;
    }
    Node* newHead = reverse(head, tail);
    head->next = reverseKGroup(tail, k);
    return newHead;
}

void print(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, K;
    cin >> N;
    vector<int> values(N);
    for (int i = 0; i < N; ++i) {
        cin >> values[i];
    }
    cin >> K;

    Node* newNode = new Node(0);
    Node* curr = newNode;

    for (int i = 0; i < N; i++) {
        curr->next = new Node(values[i]);
        curr = curr->next;
    }

    Node* head = newNode->next;

    head = reverseKGroup(head, K);

    print(head);

    return 0;
}
