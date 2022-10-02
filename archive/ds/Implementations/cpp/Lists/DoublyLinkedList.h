//
// Created by ghd on 2/17/22.
//

#ifndef LISTS_DOUBLYLINKEDLIST_H
#define LISTS_DOUBLYLINKEDLIST_H

#include "DoubleLink.h"
#include "List.h"
#include "LinkedList.h"

template<typename t>
class DoublyLinkedList : public List<t> {
protected:
    DoubleLink<t> *head;
    DoubleLink<t> *current;
    DoubleLink<t> *tail;
    int count{};

    void init(const t &input) {
        head = current = tail = new DoubleLink<t>(input, nullptr, nullptr);
        count++;
    }

    void removeAll() {
        while (head != nullptr) {
            current = head;
            head = head->next;
            delete current;
        }
    }

public:
    explicit DoublyLinkedList(int size = DEFAULTSIZE) {
        head = current = tail = nullptr;
    }

    ~DoublyLinkedList() { removeAll(); }

    void clear() { removeAll(); }

    void insert(const t &item) {
        if (head == nullptr) {
            init(item);
        } else {
            current->next = current->next->prev = new DoubleLink<t>(item, current, current->next);
//            if (tail == current)
//                tail = current->next;
            count++;
        }
    }

    void append(const t &item) {
        if (head == nullptr)
            init(item);
        else {
//            tail->prev = tail->prev->next = new DoubleLink<t>(item, tail->prev, tail);
            tail->next = new DoubleLink<t>(item, tail, nullptr);
            tail = tail->next;
            count++;
        }
    }


    void moveToStart() { current = head; }

    void moveToEnd() { current = tail; }


    void prev() {
        assert(current != head);
        current = current->prev;
    }


    void next() {
        //      if(current != tail)
        current = current->next;
    }


    int length() const { return count; }

    int currPos() const {
        //    assert(current != nullptr);
        int counter;
        DoubleLink<t> *temp = head;
        for (counter = 0; temp != current; ++counter) {
            temp = temp->next;
        }
        return counter;
    }

    void moveToPos(const int &pos) {
        assert(pos < count && pos > 0);
        current = head;
        for (int i = 0; i < pos; ++i) {
            current = current->next;
        }
    }

    const t &getValue() const { return current->element; }

    t remove() {
        assert(current != nullptr);
        if (current == head) {
            DoubleLink<t> *temphead = head;
            auto val = head->element;
            head = head->next;
            head->prev = nullptr;
            delete temphead;
            return val;
        }
        DoubleLink<t> *temp = current;
        t val = current->element;
        prev();
        current->next = temp->next;
        temp->next->prev = current;
        delete temp;
        count--;
        return val;
    }
};

#endif //LISTS_DOUBLYLINKEDLIST_H
