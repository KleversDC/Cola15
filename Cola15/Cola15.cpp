#include <iostream>
using namespace std;
//1
//class StackNode {
//public:
//    int data;
//    StackNode* next;
//
//    StackNode(int value) : data(value), next(nullptr) {}
//};
//
//class Stack {
//private:
//    StackNode* top;
//
//public:
//    Stack() : top(nullptr) {}
//
//    void push(int value) {
//        StackNode* newNode = new StackNode(value);
//        newNode->next = top;
//        top = newNode;
//    }
//
//    int pop() {
//        if (isEmpty()) {
//            cout << "Erorr Stek 0" << endl;
//            return -1;
//        }
//        int value = top->data;
//        StackNode* temp = top;
//        top = top->next;
//        delete temp;
//        return value;
//    }
//
//    bool isEmpty() {
//        return top == nullptr;
//    }
//
//    int peek() {
//        if (isEmpty()) {
//            cout << "Stek 0" << endl;
//            return -1;
//        }
//        return top->data;
//    }
//
//    void print() {
//        StackNode* current = top;
//        while (current) {
//            cout << current->data << " ";
//            current = current->next;
//        }
//        cout << endl;
//    }
//
//    ~Stack() {
//        while (!isEmpty()) {
//            pop();
//        }
//    }
//};
//2
class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    ListNode* head;

public:
    LinkedList() : head(nullptr) {}
    void insert(int value) {
        ListNode* newNode = new ListNode(value);
        newNode->next = head;
        head = newNode;
    }
    LinkedList clone() const {
        LinkedList clonedList;
        if (!head) return clonedList;

        ListNode* originalCurrent = head;
        ListNode* clonedCurrent = new ListNode(originalCurrent->data);
        clonedList.head = clonedCurrent;
        originalCurrent = originalCurrent->next;

        while (originalCurrent) {
            clonedCurrent->next = new ListNode(originalCurrent->data);
            clonedCurrent = clonedCurrent->next;
            originalCurrent = originalCurrent->next;
        }
        return clonedList;
    }
    LinkedList operator+(const LinkedList& other) const {
        LinkedList result;

        ListNode* currentThis = head;
        ListNode* currentOther = other.head;

        while (currentThis) {
            result.insert(currentThis->data);
            currentThis = currentThis->next;
        }

        while (currentOther) {
            result.insert(currentOther->data);
            currentOther = currentOther->next;
        }

        return result;
    }
    LinkedList operator*(const LinkedList& other) const {
        LinkedList result;

        for (ListNode* currentThis = head; currentThis != nullptr; currentThis = currentThis->next) {
            for (ListNode* currentOther = other.head; currentOther != nullptr; currentOther = currentOther->next) {
                if (currentThis->data == currentOther->data) {
                    result.insert(currentThis->data);
                    break;
                }
            }
        }

        return result;
    }
    void print() const {
        ListNode* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    ~LinkedList() {
        while (head) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main() {
//    //1
//    //Stack stack;
//    //stack.push(1);
//    //stack.push(2);
//    //stack.push(3);
//    //stack.print();
//
//    //cout << "Deleit: " << stack.pop() << endl;
//    //stack.print();
//
//    //cout << "Deleit verh: " << stack.peek() << endl;
    //2
    LinkedList list1;
    list1.insert(1);
    list1.insert(2);
    list1.insert(3);

    LinkedList list2;
    list2.insert(3);
    list2.insert(4);
    list2.insert(5);

    LinkedList clonedList = list1.clone();
    LinkedList combinedList = list1 + list2;
    LinkedList commonList = list1 * list2;

    cout << "List 1: ";
    list1.print();
    cout << "List 2: ";
    list2.print();
    cout << "Cloned List 1: ";
    clonedList.print();
    cout << "Combined List: ";
    combinedList.print();
    cout << "Common Elements : ";
    commonList.print();
}
