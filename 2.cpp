#include <iostream>

struct Node {
    int val;
    Node *next;
};

int main() {
    auto upperPtr{new Node{.val=9, .next = new Node{.val = 9, .next = nullptr}}};
    auto lowerPtr{new Node{.val=9, .next =new Node{.val=9, .next =new Node{.val=9, .next =nullptr}}}};
    auto baseline{lowerPtr};
    int overflow = 0;
    while (upperPtr != nullptr) {
        auto result = upperPtr->val + lowerPtr->val + overflow;
        overflow = result / 10;
        lowerPtr->val = result - overflow * 10;
        // if current node of baseline is null, just allocated it
        if (lowerPtr->next == nullptr) {
            lowerPtr->next = new Node{.val = 0, .next = nullptr};
        }
        auto obsolete = upperPtr;
        upperPtr = upperPtr->next;
        lowerPtr = lowerPtr->next;
        delete obsolete;
    }
    if (overflow != 0) {
        lowerPtr->next = new Node{.val = overflow, .next = nullptr};
    }
    while (baseline != nullptr) {
        std::cout << baseline->val;
        baseline = baseline->next;
    }
    return 0;
}