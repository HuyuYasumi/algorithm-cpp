#include <iostream>
using namespace std;

template <typename T> class Node {
public:
    T data;
    Node<T> *Left;
    Node<T> *Right;

    Node() = default;
    explicit Node(T data, Node<T> *Left = nullptr, Node<T>* Right = nullptr) : data(data), Left(Left), Right(Right) {}

    void insertAsLeft(T data) {
        Left = new Node<T>(data);
    }

    void insertAsRight(T data) {
        Right = new Node<T>(data);
    }
};

template <typename T> class BST {
    Node<T>* root;
    int size;

public:
    BST() {
        root = nullptr;
        size = 0;
    };
    BST(T data) : root(new Node<T>(data)), size(1) {}

    bool add(T data) {
        if(data == NULL)
            return false;
        Node<T>* p = root;
        while(p != nullptr) {
            if(data < p->data) {
                if(p->Left == nullptr) {
                    p->insertAsLeft(data);
                    size++;
                    return true;
                } else {
                    p = p->Left;
                }
            } else {
                if(p->Right == nullptr) {
                    p->insertAsRight(data);
                    size++;
                    return true;
                } else {
                    p = p->Right;
                }
            }
        }
        root = new Node<T>(data);
        size++;
        return true;
    }

    Node<T>* search(T data) {
        if(data == NULL) {
            return nullptr;
        }
        Node<T>* p = root;
        while(p != nullptr) {
            if(data == p->data)
                return p;
            else if(data > p->data)
                p = p->Right;
            else
                p = p->Left;
        }
        return nullptr;
    }
};

int main() {
    int size;
    cout << "The size of BST: ";
    cin >> size;
    BST<int> bst;
    for(int i = 0; i < size; i++) {
        cout << "node: ";
        int data;
        cin >> data;
        bst.add(data);
    }
    cout << "The number you want to find is: ";
    cin >> size;
    Node<int>* p = bst.search(size);
    cout << p  << "=" << (p == nullptr ? 0 : p->data);
    return 0;
}