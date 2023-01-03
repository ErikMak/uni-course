/*
Author: ErikMak
Task:

Реализуйте кольцевой буфер с использованием статического массива или контейнеров 
std::array и std::vector

*/

#include <iostream>

class CBuffer {
    private:
        int *items, front, rear, size;
    public:
        CBuffer(int size) {
            front = -1;
            rear = -1;
            this->size = size;
            items = new int[size];
        }
        bool isFull() {
            if (front == 0 && rear == size - 1) {
                return true;
            }
            if (front == rear + 1) {
                return true;
            }
            return false;
        }
        bool isEmpty() {
            if (front == -1)
                return true;
            else
                return false;
        }
        void set(int val) {
            if (isFull()) {
                std::cout << "Queue is full" << std::endl;
            } else {
                if (front == -1) {
                    front = 0;
                }
                rear = (rear + 1) % size;
                items[rear] = val;
                std::cout << "Inserted " << val << std::endl;
            }
        }
        int get() {
            int element;
            if (isEmpty()) {
                std::cout << "Queue is empty" << std::endl;
                return (-1);
            } else {
                element = items[front];
                if (front == rear) {
                    front = -1;
                    rear = -1;
                }
                else {
                    front = (front + 1) % size;
                }
                return element;
            }
        }
        void display() {
            int i;
            int count = 0;
            if (isEmpty()) {
                std::cout << std::endl << "Empty Queue" << std::endl;
            } else {
                for (i = front; i != rear; i = (i + 1) % size) {
                    std::cout << items[i] << " | ";
                    count++;
                }
                std::cout << items[i] << " | ";
                count++;
                for(int j = 0; j < size - count; j++) {
                    std::cout << "* | ";
                }
                std::cout << std::endl;
                std::cout << "Front -> " << front << std::endl;
                std::cout << "Rear -> " << rear << std::endl;
            }
        }
};

int main() {
    CBuffer buff(3);
    buff.set(8);
    buff.set(10);
    buff.set(0);

    std::cout << "Get: " << buff.get() << std::endl;
    buff.set(22);
    std::cout << std::endl;
    buff.display();
}