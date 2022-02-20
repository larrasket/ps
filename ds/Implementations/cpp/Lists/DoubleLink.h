//
// Created by ghd on 2/17/22.
//

#ifndef LISTS_DOUBLELINK_H
#define LISTS_DOUBLELINK_H

template<typename E>
class DoubleLink {
public:
    E element;
    DoubleLink *next;
    DoubleLink *prev;

    DoubleLink(const E &elemval, DoubleLink *prevval = nullptr, DoubleLink *nextval = nullptr)
            : element(elemval), next(nextval), prev(prevval) {}

    DoubleLink(DoubleLink *nextval = nullptr, DoubleLink *prevval = nullptr)
            : next(nextval), prev(prevval) {}
};

#endif //LISTS_DOUBLELINK_H
