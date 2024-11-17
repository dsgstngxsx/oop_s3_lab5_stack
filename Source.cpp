#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class Stack {
private:
    T* arr;            //указатель на массив
    int topIndex;      //индекс верхнего элемента стека
    int capacity;      //вместимость стека

public:
    //конструктор
    Stack(int size) : capacity(size), topIndex(-1) 
    {
        arr = new T[capacity];
    }

    //деструктор
    ~Stack() {
        delete[] arr; 
    }

    //добавление элемента в стек
    void push(T element) {
        if (isFull()) {
            throw overflow_error("Stack is overflow");
        }
        arr[++topIndex] = element; // увеличиваем индекс и добавляем элемент
    }

    //удаление элемента из стека
    T pop() {
        if (isEmpty()) {
            throw underflow_error("Stack is empty");
        }
        return arr[topIndex--]; //возвращаем элемент и уменьшаем индекс
    }

    //верхний элемент стека
    T top() {
        if (isEmpty()) {
            throw underflow_error("Stack is empty");
        }
        return arr[topIndex]; 
    }

    //пуст ли стек?
    bool isEmpty() const {
        return topIndex == -1;
    }

    //полон ли стек?
    bool isFull() const {
        return topIndex == capacity - 1;
    }

    //вывод элементов стека
    void print() const {
        if (isEmpty()) {
            throw underflow_error("Stack is empty");
        }

        cout << "Stacks elements: ";
        for (int i = topIndex; i >= 0; --i) {
            cout << arr[i] << " "; // вывод элементов от верхнего к нижнему
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
        cout << "Stacks top element: " << Stack1.top() << endl; //после удаления 
        line();

        Stack1.push(40);
        Stack1.push(9);
        Stack1.push(102);
        //Stack1.push(15); // => ошибка (переполнение)
    }
    catch (const exception& err) {
       cerr << "Error: " << err.what() << endl;
    }
    Stack1.print();

    return 0;
}