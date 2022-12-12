#include <iostream>

using namespace std;

class Mobile {
    string modelName;
    string serialNum;
    int inches;
    int ramSize;
    int storageSize;
public:
    Mobile(const string &modal, const string &serial, int inches, int ram, int storage) {
        modelName = modal;
        serialNum = serial;
        this->inches = inches;
        ramSize = ram;
        storageSize = storage;
    }

    void displayAll() const {
        cout << "Mobile Model: " << modelName << endl;
        cout << "Serial Number: " << serialNum << endl;
        cout << "Screen : " << inches << " inches\n";
        cout << "Ram Size : " << ramSize << " GB\n";
        cout << "Storage Size : " << storageSize << " GB\n";
        cout << "_________________________________________\n\n";
    }
};

struct Node {
    Node *next;
    Mobile *data;

    Node(const string &modal, const string &serial, int inches, int ram, int storage) {
        data = new Mobile(modal, serial, inches, ram, storage);
    }

};

class Linked_list {
    Node *head;
public:
    void addNode(const string &, const string &, int, int, int);

    void display() const;
};

void Linked_list::addNode(const string &modal, const string &serial, int inches, int ram, int storage) {
    if (head == nullptr) {
        head = new Node(modal, serial, inches, ram, storage);
        head->next = nullptr;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = new Node(modal, serial, inches, ram, storage);
    temp->next->next = nullptr;
}

void Linked_list::display() const {
    cout << "Display function called\n";
    Node *temp = head;
    while (temp != nullptr) {
        temp->data->displayAll();
        temp = temp->next;
    }
}

int main() {
    Linked_list linked_Lists{};
    linked_Lists.addNode("Samsung", "7C-E5-E6-BD-FB-26", 11, 2, 8);
    linked_Lists.addNode("xiaomi", "95-8C-D6-0F-13-29", 9, 4, 16);
    linked_Lists.addNode("Apple", "FF-34-5D-5E-AF-08", 7, 8, 32);
    linked_Lists.addNode("Oppo", "E9-29-09-32-24-65", 5, 16, 64);
    linked_Lists.addNode("Lenovo ", "D3-66-DB-A0-84-89", 3, 32, 128);
    linked_Lists.addNode("Google", "AD-F4-6A-32-A9-FE", 1, 64, 256);
    linked_Lists.display();
}
