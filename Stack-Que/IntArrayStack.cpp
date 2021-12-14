#include <iostream>

using namespace std;

void print_error_msg() {
    cout << "Stackte o kadar eleman yok!" << endl;
}

class Stack {
private:
    enum {
        SIZE = 100
    };
    int stack[SIZE];
    int tail;
public:
    Stack() {
        tail = 0;
    }

    void push(int data) {
        if (tail == SIZE) {
            tail = 0;
        }
        stack[tail] = data;
        tail++;
    }

    int pop() {
        if(tail <= 0){
            print_error_msg();
            exit(-1);
        }else{
            tail--;
            return stack[tail];
        }

    }
};


int main() {
    Stack s;

    s.push(3);
    s.push(6);
    s.push(9);
    cout << s.pop() << endl;
    s.push(4);
    s.push(7);

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;


    return 0;
}
