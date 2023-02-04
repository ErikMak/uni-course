/*
Author: ErikMak
Task:

Напишите программу, которая выводит на экран графическое
представление двоичного дерева. Дерево состоит из N вершин, 
пронумерованных от 1 до N.

На вход программы кроме числа N поступает также информация о 
структуре дерева в виде последовательности пар чисел,
кодирующих связи. В каждой паре первое число обозначает номер
предка, а второе — номер связанного с ним потомка.
Дерево нужно вывести, обозначая вершины соответствующими
числами, а связи с помощью символов «прямой слэш» и «обратный
слэш»

*/

#include <iostream>
#include <windows.h>

class Tree {
    private:
        void gotoxy(int x, int y) {
            COORD pos = { x, y };
            HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleCursorPosition(output, pos);
        }
    public:
        ~Tree() {
            deleteNode(root);
        }

        struct Node {
            int data;
            Node *left, *right;

            Node(int data) {
                this->data = data;
                this->right = nullptr;
                this->left = nullptr;
            }
        };

        int getTreeHeight(Node *n) {
            int left_height, right_height;

            if(n == nullptr) {
                return 1;
            } else {
                left_height = getTreeHeight(n->left);
                right_height = getTreeHeight(n->right);
                return 1 + (left_height > right_height ? left_height : right_height);
            }
        }

        Node *findNode(Node *n, int data) {
            if (!root || !n) {
                return 0;
            }
            if(n->data == data) {
                return n;
            }
            
            Node *left_node = findNode(n->left, data);
            if (left_node) return left_node;
            Node *right_node = findNode(n->right, data);
            return right_node;
        }

        void addNode(int _parent, int _child) {
            // Если нету корня
            if (!root) {
                root = new Node{_parent};
                root->left = new Node{_child};
                return;
            }
            Node *parent = findNode(root, _parent);

            if (parent->left == nullptr) {
                parent->left = new Node(_child);
            } else if(parent->right == nullptr) {
                parent->right = new Node(_child);
            }
        }

        void deleteNode(Node *n) {
            if(n != nullptr) {
                if(n->left != nullptr) {
                    deleteNode(n->left);
                }
                if(n->right != nullptr) {
                    deleteNode(n->right);
                } 
                delete n;
            }
        }

        void printNode(Node* n, int x, int y, int height) {
            if (n != nullptr) {
                gotoxy(x, y); 
                std::cout << n->data;
                for (int i = 1; i <= height; i++) {
                    if (n->left) { 
                        gotoxy(x - i, y + i); 
                        std::cout << '/'; 
                    }
                    if (n->right) { 
                        gotoxy(x + i, y + i); 
                        std::cout << "\\"; 
                    }
                }
                if (n->left) {
                    printNode(n->left,x - height - 1,y + height + 1,(height - 1) >> 1);
                }
                if (n->right) {
                    printNode(n->right, x + height + 1, y + height + 1, (height - 1) >> 1);
                }
            }
        }

        void printTree(Node *root) {
            int tree_height = getTreeHeight(root);
            int height = 1;
            for (int i = 0; i < tree_height - 2; ++i) {
                height = (height << 1) + 1;       
            }
            printNode(root, 50, 0, height);
            std::cout << std::endl;
        }
        
        Node *getRoot() {
            return root;
        }
    private: 
        Node *root = nullptr;
};

int main() {
    // Дерево 
    Tree tree;

    int count  = 0;
    std::cout << "Elements amount: ";
    std::cin >> count;

    for (int i = 0; i < count - 1; ++i) {
        int parent; 
        std::cout << "Parent => ";
        std::cin >> parent;
        std::cout << "Child => ";
        int child; std::cin >> child;
        tree.addNode(parent, child);
    }

    tree.printTree(tree.getRoot());
}