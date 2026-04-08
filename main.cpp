#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    if (!(std::cin >> n >> m)) return 0;

    if (n == 0) return 0;

    Node* head = new Node(1);
    Node* curr = head;
    for (int i = 2; i <= n; ++i) {
        curr->next = new Node(i);
        curr = curr->next;
    }
    curr->next = head;

    Node* prev = curr;
    curr = head;

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            prev = curr;
            curr = curr->next;
        }
        std::cout << curr->data << "\n";
        
        prev->next = curr->next;
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}
