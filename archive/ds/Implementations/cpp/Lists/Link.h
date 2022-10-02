#ifndef __Link
#define __Link

template<typename E>
class Link {
public:
    E element;
    Link *next;

    Link(const E &elemval, Link *nextval = nullptr)
            : element(elemval), next(nextval) {}

    Link(Link *nextval = nullptr) : next(nextval) {}
};

#endif