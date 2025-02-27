#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() { top = nullptr; }

    bool isEmpty() { return top == nullptr; }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow\n";
            return -1;
        }
        Node* temp = top;
        int poppedValue = temp->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is Empty\n";
            return -1;
        }
        return top->data;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Stack is Empty\n";
            return;
        }
        std::cout << "Stack elements: ";
        Node* temp = top;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    std::cout << "Popped: " << s.pop() << "\n";
    std::cout << "Top element: " << s.peek() << "\n";
    return 0;
}
///////////////////////////////////////////

#include <iostream>
#define MAX 100  // Maximum size of the stack

class Stack {
private:
    int top;
    int arr[MAX];

public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }

    bool isFull() { return top == MAX - 1; }

    void push(int value) {
        if (isFull()) {
            std::cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Stack is Empty\n";
            return;
        }
        std::cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            std::cout << arr[i] << " ";
        std::cout << "\n";
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    std::cout << "Popped: " << s.pop() << "\n";
    std::cout << "Top element: " << s.peek() << "\n";
    return 0;
}
