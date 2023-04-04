#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Node {
  public:
    int data;
    Node* next;
    
    
    Node(int value) {
      data = value;
      next = nullptr;
    }
};
class Stack {
  private:
    Node* top;

  public:
    Stack() {
      top = nullptr;
    }
    bool push(int z) {
      Node* newNode = new Node(z);
      if (newNode == nullptr) {
        cout << "Error: Memory Allocation Failed\n";
        return false;
      } else {
        newNode->next = top;
        top = newNode;
        cout << z << " pushed to stack\n";
        return true;
      }
    }

    int pop() {
      if (isEmpty()) {
        cout << "Error: Stack Underflow\n";
        return 0;
      } else {
        int z = top->data;
        Node* temp = top;
        top = top -> next;
        delete temp;
        return z;
      }
    }

    bool isEmpty() {
      return (top == nullptr);
    }
    int StackTop() {
      if (isEmpty()) {
        cout << "Error: Stack is empty\n";
        return 0;
      } else {
        return top->data;
      }
    }

    void Display() {
      if (isEmpty()) {
        cout << "Stack is empty\n";
      } else {
        cout << "Elements in stack: ";
        Node* current = top;
        while (current != nullptr) {
          cout << current->data << " ";
          current = current->next;
        }
        cout << endl;
      }
    }
};

int main() {
  auto start_time = high_resolution_clock::now();
  Stack stack;
  stack.push(5);
  stack.push(10);
  stack.push(18);
  stack.push(9);
  stack.push(35);
  stack.push(22);
  stack.push(8);
  stack.push(28);
  stack.push(19);
  stack.push(20);
  stack.Display();
  cout << stack.pop() << " popped from stack\n";
  cout << stack.pop() << " popped from stack\n";
  cout << stack.pop() << " popped from stack\n";
  cout << stack.pop() << " popped from stack\n";
  cout << stack.pop() << " popped from stack\n";
  stack.Display();
  stack.push(7);
  stack.push(40);
  stack.push(4);
  stack.push(6);
  stack.Display();    
  auto end_time = high_resolution_clock::now();
  auto execution_time = duration_cast<nanoseconds>(end_time - start_time);
  cout << "Execution time: " << execution_time.count() << " ns" << endl;
  return 0;
}