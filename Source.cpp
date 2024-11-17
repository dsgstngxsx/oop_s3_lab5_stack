#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class Stack {
private:
    T* arr;            //��������� �� ������
    int topIndex;      //������ �������� �������� �����
    int capacity;      //����������� �����

public:
    //�����������
    Stack(int size) : capacity(size), topIndex(-1) 
    {
        arr = new T[capacity];
    }

    //����������
    ~Stack() {
        delete[] arr; 
    }

    //���������� �������� � ����
    void push(T element) {
        if (isFull()) {
            throw overflow_error("Stack is overflow");
        }
        arr[++topIndex] = element; // ����������� ������ � ��������� �������
    }

    //�������� �������� �� �����
    T pop() {
        if (isEmpty()) {
            throw underflow_error("Stack is empty");
        }
        return arr[topIndex--]; //���������� ������� � ��������� ������
    }

    //������� ������� �����
    T top() {
        if (isEmpty()) {
            throw underflow_error("Stack is empty");
        }
        return arr[topIndex]; 
    }

    //���� �� ����?
    bool isEmpty() const {
        return topIndex == -1;
    }

    //����� �� ����?
    bool isFull() const {
        return topIndex == capacity - 1;
    }

    //����� ��������� �����
    void print() const {
        if (isEmpty()) {
            throw underflow_error("Stack is empty");
        }

        cout << "Stacks elements: ";
        for (int i = topIndex; i >= 0; --i) {
            cout << arr[i] << " "; // ����� ��������� �� �������� � �������
        }
        cout << endl;
    }
};

void line()
{
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

int main() {

    Stack<float> Stack1(5); 

    try {
        Stack1.push(12);
        Stack1.push(2);
        Stack1.push(43);

        Stack1.print();
        cout << "Stacks top element: " << Stack1.top() << endl;
        line();

        cout << "Delete element: " << Stack1.pop() << endl;
        cout << "Stacks top element: " << Stack1.top() << endl; //����� �������� 
        line();

        Stack1.push(40);
        Stack1.push(9);
        Stack1.push(102);
        //Stack1.push(15); // => ������ (������������)
    }
    catch (const exception& err) {
       cerr << "Error: " << err.what() << endl;
    }
    Stack1.print();

    return 0;
}