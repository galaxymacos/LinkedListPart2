#include <iostream>


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *headCopy = head;
        while (headCopy->next != nullptr) {
            ListNode *nextNode = headCopy->next;
            headCopy->next = headCopy->next->next;
            nextNode->next = head;
            head = nextNode;
        }
        return head;
    }

    ListNode *removeElements(ListNode *head, int val) {
        while (head != nullptr && head->val == val)
            head = head->next;
        if (head == nullptr) {
            return nullptr;
        }
        auto headCopy = head;
        auto nextNode = head->next;
        while (nextNode != nullptr) {
            if (nextNode->val == val) {
                headCopy->next = nextNode->next;
                nextNode = headCopy->next;
            } else {
                nextNode = nextNode->next;
                headCopy = headCopy->next;
            }

        }
        return head;
    }

    ListNode *oddEvenList(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return head;
        }
        ListNode *oddHead = head;
        ListNode *evenHead = head->next;
        ListNode *evenHead2 = evenHead;
        while (oddHead->next != nullptr || evenHead->next != nullptr) {
            oddHead->next = evenHead->next;
            if (oddHead->next == nullptr) {
                break;
            }
            oddHead = oddHead->next;
            evenHead->next = oddHead->next;
            evenHead = evenHead->next;
            if (evenHead == nullptr) {
                break;
            }
        }
        oddHead->next = evenHead2;
        return head;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}