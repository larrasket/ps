#include "ArrayList.h"
#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include <iostream>

using std::cout;

void TestArrayLest() {
    cout << "Array List Test..." << std::endl;
    cout << "---------------" << std::endl;
    ArrayList<int> r(8);
    r.insert(12);
    r.append(11);
    r.append(1);
    r.append(4);
    r.append(5);
    r.append(4);
    r.append(8);
    cout << "Before deletion" << std::endl;
    for (r.moveToStart(); r.currPos() < r.length(); r.next()) {
        cout << r.getValue() << std::endl;
    }
    cout << "After deletion" << std::endl;
    r.moveToPos(4);
    r.remove();
    for (r.moveToStart(); r.currPos() < r.length(); r.next()) {
        cout << r.getValue() << std::endl;
    }
}

void TestLinkedList() {
    cout << "Linked List Test..." << std::endl;
    cout << "---------------" << std::endl;
    LinkedList<int> r(8);
    r.insert(12);
    r.insert(11);
    r.insert(1);
    r.insert(4);
    r.insert(5);
    r.insert(4);
    r.insert(8);
    cout << "Before deletion" << std::endl;
    for (r.moveToStart(); r.currPos() < r.length(); r.next()) {
        cout << r.getValue() << std::endl;
    }
    cout << "After deletion" << std::endl;
    r.moveToPos(4);
    r.remove();
    for (r.moveToStart(); r.currPos() < r.length(); r.next()) {
        cout << r.getValue() << std::endl;
    }
}

void TestDoubleLinkedList() {
    cout << "Linked List Test..." << std::endl;
    cout << "---------------" << std::endl;
    DoublyLinkedList<int> r(8);
    r.insert(12);
    r.append(11);
    r.append(1);
    r.append(4);
    r.append(5);
    r.append(4);
    r.append(8);
    cout << "Before deletion" << std::endl;
    for (r.moveToStart(); r.currPos() < r.length(); r.next()) {
        cout << r.getValue() << std::endl;
    }
    cout << "After deletion" << std::endl;
    r.moveToPos(4);
    r.remove();
    for (r.moveToStart(); r.currPos() < r.length(); r.next()) {
        cout << r.getValue() << std::endl;
    }
}

int main() {
//    TestArrayLest();
//    TestLinkedList();
    TestDoubleLinkedList();
}
