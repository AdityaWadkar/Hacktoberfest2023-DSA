#include <iostream>
#include <stack>

class MyQueue {
private:
    std::stack<int> inStack;  // Stack for enqueue operations
    std::stack<int> outStack; // Stack for dequeue operations

public:
    // Constructor
    MyQueue() {}

    // Push element x to the back of the queue.
    void push(int x) {
        inStack.push(x);
    }

    // Removes the element from the front of queue and returns that element.
    int pop() {
        if (outStack.empty()) {
            // Transfer elements from inStack to outStack to reverse the order
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        int front = outStack.top();
        outStack.pop();
        return front;
    }

    // Get the front element.
    int peek() {
        if (outStack.empty()) {
            // Transfer elements from inStack to outStack to reverse the order
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        return outStack.top();
    }

    // Returns whether the queue is empty.
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    std::cout << "Front element: " << q.peek() << std::endl; // Output: 1
    std::cout << "Dequeue: " << q.pop() << std::endl;        // Output: 1
    std::cout << "Is empty? " << (q.empty() ? "Yes" : "No") << std::endl; // Output: No
    return 0;
}
