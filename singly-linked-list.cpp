#include <iostream>
using namespace std;

class Node {
public:
    Node* next;
    int data;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void Insert_Node(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            cout << "A new node has been added." << endl;
        } else {
            Node* n = head;
            while (n->next != nullptr) {
                n = n->next;
            }
            n->next = newNode; // Link the new node to the end of the list
            cout << "A new node has been added." << endl;
        }
    }

    void Print_List() {
        Node* n = head;
        if (n == nullptr) {
            cout << "List is Empty" << endl;
        } else {
            cout << "The List is: ";
            while (n != nullptr) {
                cout << n->data << " ";
                n = n->next;
            }
            cout << "NULL" << endl;
        }
    }

    void PrintMenu() {
        cout << "---------LinkedList--------" << endl;
        cout << "Press 1: To insert a new element" << endl;
        cout << "Press 2: To Print LinkedList" << endl;
        cout << "Print 0: To Exit" << endl;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr; // Set head to nullptr after deleting all nodes
    }
};

int main() {
    LinkedList list;
    int choice = 9;
    do {
        list.PrintMenu();
        cout << "Please enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            int val;
            cout << "Please enter an element: ";
            cin >> val;
            list.Insert_Node(val);
        } else if (choice == 2) {
            list.Print_List();
        }
    } while (choice != 0);

    return 0;
}
