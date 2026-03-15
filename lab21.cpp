// COMSC-210 | Lab  21| Tianyi Cao 
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

const int  MIN_LS = 5, MAX_LS = 20;
class Goat {
public:
// Data members
    int age;
    string name;
    string color;
//genrate random goat data by replit ai
    string names[15] = {
        "Billy", "Nanny", "Goaty", "Cloud", "Snow", 
        "Shadow", "Giddy", "Butter", "Pepper", "Salt", 
        "Brownie", "Cookie", "Dancer", "Prancer", "Vixen"
    };

    string colors[15] = {
        "White", "Black", "Red", "Gold", "Mauve", 
        "Yellow", "Gray", "Silver", "Pink", "Blue", 
        "Green", "Orange", "Purple", "Cyan", "Tan"
    };

// Default constructor to initialize a goat with random attributes
Goat() {
        age = rand() % 20 + 1;
        name = names[rand() % 15];
        color = colors[rand() % 15];
    }
};


class DoublyLinkedList {
private:
    struct Node {
        Goat data;
        Node* prev;
        Node* next;
        Node(Goat val, Node* p = nullptr, Node* n = nullptr) {
            data = val;
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:

    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(Goat value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(Goat value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insert_after(Goat value, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode; 
        temp->next = newNode;
    }

    void delete_node(Goat value) {
        
        if (!head) return;

        Node* temp = head;
        while (temp && temp->data.name != value.name)
            temp = temp->next;

        if (!temp) return;

        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }

        if (temp->next) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev;
        }
        delete temp;
    }

    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty" << endl;
            return;
        }
        while (current) {
            cout << "    " << current->data.name << " (" 
                 << current->data.color << ", " << current->data.age << ")" << endl;
            current = current->next;
        }
    }

    void print_reverse() {
        Node* current = tail;
        if (current) {
            cout << "List is empty" << endl;
            return;
        }
        while (current) {
           
        }
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
};

int main() {
   srand(time(0));
   DoublyLinkedList list;
   int size = rand() % (MAX_LS - MIN_LS + 1) + MIN_LS;
   for (int i = 0; i < size; ++i) {
        list.push_back(Goat());
    }
    cout << "List forward: ";
    list.print();

    cout << "\nList backward: ";
    list.print_reverse();

    cout << "\nDeleting list, then trying to print.\n";
    list.~DoublyLinkedList();
    
    cout << "List forward: ";
    list.print();
}
