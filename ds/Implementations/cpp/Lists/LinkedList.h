
#ifndef LinkedList__
#define LinkedList__

#include "Link.h"
#include "List.h"
#include <cassert>

template<typename t>
class LinkedList : public List<t> {
protected:
    Link<t> *head;
    Link<t> *current;
    Link<t> *tail;
    int count;

    void init(const t &input) {
        head = current = tail = new Link<t>(input, nullptr);
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
    explicit LinkedList(int size = DEFAULTSIZE) {
        head = current = tail = nullptr;
        count = 0;
    }

    ~LinkedList() { removeAll(); }

    void clear() { removeAll(); }

    void insert(const t &item) {
        if (head == nullptr) {
            init(item);
        } else {
            current->next = new Link<t>(item, current->next);
            if (tail == current)
                tail = current->next;
            count++;
        }
    }

    void append(const t &item) {
        if (head == nullptr)
            init(item);
        else {
            tail = tail->next = new Link<t>(item, nullptr);
            count++;
        }
    }

    void moveToStart() { current = head; }

    void moveToEnd() { current = tail; }

    void prev() {
        assert(current != head);
        Link<t> *temp = head;
        while (temp->next != current)
            temp = temp->next;
        current = temp;
    }

    void next() {
        //      if(current != tail)
        current = current->next;
    }

    int length() const { return count; }

    int currPos() const {
        //    assert(current != nullptr);
        int counter;
        Link<t> *temp = head;
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
        //        remove the nuxt to current;
        //        assert(current->next != nullptr);
        //        t value = current->next->element;
        //        Link<t> *temp = current->next;
        //        if (tail == current->next) tail = current;
        //        current->next = current->next->next;
        //        delete temp;
        //        count--;
        //        return value;
        //
        //

        assert(current != nullptr);
        if (current == head) {
            Link<t> *temphead = head;
            auto val = head->element;
            head = head->next;
            delete temphead;
            return val;
        }
        Link<t> *temp = current;
        t val = current->element;
        prev();
        current->next = temp->next;
        delete temp;
        count--;
        return val;
    }
};

#endif
