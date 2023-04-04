#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define MAX_SIZE 300

class Stack {
    
  private:
    int top;
    int arr[MAX_SIZE];

  public:
    Stack() {
      top = -1;
    }

    bool push(int z) {
      if (top >= (MAX_SIZE - 1)) {
        cout << "Error: Stack Overflow\n";
        return false;
      } else {
        arr[++top] = z;
        cout << z << " pushed to stack\n";
        return true;
      }
    }
    int pop() {
      if (top < 0) {
        cout << "Error: Stack Underflow\n";
        return 0;
        
      } else {
        int z = arr[top--];
        return z;
      }
    }

    bool isEmpty() {
      return (top < 0);
    }

    bool isFull() {
      return (top >= (MAX_SIZE - 1));
    }

    int StackTop() {
      if (isEmpty()) {
        cout << "Error: stack is empty\n";
        return 0;
      } else {
        return arr[top];
      }
    }
    void Display() {
      if (isEmpty()) {
        cout << "Stack is empty\n";
      } else {
        cout << "Elements in stack: ";
        for (int j = top; j >= 0; j--) {
          cout << arr[j] << " ";
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