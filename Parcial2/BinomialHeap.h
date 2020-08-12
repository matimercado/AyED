// https://github.com/138paulmiller/BinomialHeap/blob/master/src/binomial_heap.hpp

#ifndef PARCIAL2_BINOMIALHEAP_H
#define PARCIAL2_BINOMIALHEAP_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ostream>
#include <string>
#include "Event.h"

//========================================== BinomialHeap ==========================================

template<typename T>
class BinomialNode;

template<typename Event>
class BinomialHeap {
private:
    int bhc;
    BinomialNode<Event> *head;

protected:
    BinomialNode<Event> *findKey(Event v);
    static int order(BinomialNode<Event> *heap);
    static BinomialNode<Event> *unionHeap(BinomialNode<Event> *heapA, BinomialNode<Event> *heapB);
    static BinomialNode<Event> *mergeHeap(BinomialNode<Event> *heapA, BinomialNode<Event> *heapB);

public:
    BinomialHeap();
    BinomialHeap(BinomialHeap &&other);
    BinomialHeap(const BinomialHeap &other);
    BinomialHeap &operator=(const BinomialHeap &other);
    ~BinomialHeap();

    int size();
    void clear();
    Event getMin();
    bool isEmpty();
    int getCompares() {return bhc;};
    Event extractMin();
    void insert(Event value);
    void deleteKey(Event value);
    void decreaseKey(Event value, Event newValue);
};

template<typename T>
class BinomialNode {
private:
    T value;
    int order;
    BinomialNode<T> *sibling, *child, *parent;

public:
    ~BinomialNode();
    int size(int &i);
    BinomialNode<T> *find(T v);
    friend class BinomialHeap<T>;
    void addTo(BinomialHeap<T> *other);
    void addChild(BinomialNode<T> *child);
    BinomialNode(T v, BinomialNode<T> *parent = nullptr);
};

template<typename T>
BinomialNode<T>::BinomialNode(T v, BinomialNode<T> *p) {
    value = v;
    parent = p;
    sibling = child = nullptr;
    order = 0;
}

template<typename T>
BinomialNode<T>::~BinomialNode() {
    delete child;
    delete sibling;
}

template<typename T>
int BinomialNode<T>::size(int &i) {
    ++i;
    if (sibling)
        sibling->size(i);
    if (child)
        child->size(i);

    return i;
}

template<typename T>
void BinomialNode<T>::addChild(BinomialNode<T> *childNode) {
    if (childNode) {
        childNode->sibling = nullptr;
        if (child) {
            BinomialNode<T> *temp = child;
            while (temp->sibling) {
                temp = temp->sibling;
            }
            temp->sibling = childNode;
        } else {
            child = childNode;
        }

        ++order;
        childNode->parent = this;
    }
}

template<typename T>
BinomialNode<T> *BinomialNode<T>::find(T v) {
    BinomialNode<T> *found = nullptr;
    if (v == value)
        return this;
    else if (sibling) {
        found = sibling->find(v);
    }
    if (value < v && !found) //if v is larger, check children,
    {
        if (child) {
            found = child->find(v);
        }
    }

    return found;
}

template<typename T>
void BinomialNode<T>::addTo(BinomialHeap<T> *other) {

    other->insert(value);
    if (sibling) {
        sibling->addTo(other);
    }

    if (child) {
        child->addTo(other);
    }
}

template<typename T>
BinomialHeap<T>::BinomialHeap() {
    head = 0;
}

template<typename T>
BinomialHeap<T>::BinomialHeap(const BinomialHeap &other) {
    *this = other;
}

template<typename T>
BinomialHeap<T>::BinomialHeap(BinomialHeap &&other) {
    head = 0;
    if (other.head)
        other.head->addTo(this);
    other.clear();
}

template<typename T>
BinomialHeap<T> &BinomialHeap<T>::operator=(const BinomialHeap &other) {
    head = 0;
    if (other.head)
        other.head->addTo(this);
}

template<typename T>
BinomialHeap<T>::~BinomialHeap() {
    clear();
}

template<typename T>
void BinomialHeap<T>::clear() {
    delete head;
    head = nullptr;
}

template<typename T>
bool BinomialHeap<T>::isEmpty() {
    return (head == 0);
}

template<typename T>
void BinomialHeap<T>::insert(T v) {
    BinomialNode<T> *p = head ? head->parent : nullptr;
    BinomialNode<T> *singleton = new BinomialNode<T>(v, p);
    head = unionHeap(singleton, head);
}

template<typename Event>
Event BinomialHeap<Event>::getMin() {
    Event min;
    if (head) {
        BinomialNode<Event> *temp = head;
        min = head->value;
        while (temp) {
            if (temp->value.get_id() < min.get_id()) {
                min = temp->value;
            }
            temp = temp->sibling;
        }
    }
    return min;
}

template<typename Event>
Event BinomialHeap<Event>::extractMin() {
    BinomialNode<Event> *prev = nullptr,
            *min = nullptr,
            *temp = nullptr,
            *next = nullptr;
    Event minValue;
    if (head) {
        BinomialNode<Event> *minPrev = nullptr; //previous node of min node
        min = head;
        temp = head->sibling;
        prev = head;
        /*
         * Find min and minPrev of heaps
         */
        while (temp) {
            bhc++;
            if (temp->value.get_id() < min->value.get_id()) {
                min = temp;
                minPrev = prev;
            }
            prev = prev->sibling;
            temp = temp->sibling;
        }
        /*
         *  If prev, assign prev sibling to min sibling.
         *  Else if no prev min->sibling is new head
         */
        if (minPrev) {
            minPrev->sibling = min->sibling;
        } else {
            head = min->sibling;
        }
        /*
         * Update all children nodes parent pointers to null
        */
        next = min->child;
        temp = next;
        while (temp) {
            temp->parent = min->parent;
            temp = temp->sibling;
        }
        /*
         * Detach and delete min
         */
        min->sibling = nullptr;
        min->child = nullptr;
        min->parent = nullptr;
        minValue = min->value;
        delete min;
        /*
         * Union the two detached heaps
         */
        head = unionHeap(head, next);
        temp = min = minPrev = next = nullptr;
    }
    return minValue;
}

template<typename T>
int BinomialHeap<T>::size() {
    int i = 0;
    if (head)
        head->size(i);
    return i;
}

template<typename T>
void BinomialHeap<T>::deleteKey(T v) {
    decreaseKey(v, getMin() - 1); //set to min
    extractMin();
}

template<typename T>
void BinomialHeap<T>::decreaseKey(T v, T newV) {
    if (head) {
        if (v > newV) {
            BinomialNode<T> *current = head->find(v),
                    *parent = nullptr;
            T temp;
            if (current) {
                current->value = newV;
                parent = current->parent;

                while (current && parent && (current->value < parent->value)) {
                    temp = current->value;
                    current->value = parent->value;
                    parent->value = temp;
                    current = parent;
                    parent = current->parent;
                }
            } else {
                cout << "Key not found!";
            }
        } else
            cout << "New Key must be less than current key!";
    } else {
        cout << "Heap is empty!";
    }
}

template<typename T>
BinomialNode<T> *BinomialHeap<T>::findKey(T v) {
    if (head) {
        return head->find(v);
    }
    return nullptr;
}

template<typename T>
int BinomialHeap<T>::order(BinomialNode<T> *heap) {
    if (!heap)
        return -1;
    int i = 0;
    BinomialNode<T> *child = heap->child;
    while (child) {
        ++i;
        child = child->sibling;
    }
    return i;
}


template<typename Event>
BinomialNode<Event> *BinomialHeap<Event>::unionHeap(BinomialNode<Event> *heapA, BinomialNode<Event> *heapB) {

    BinomialNode<Event> *heapU = mergeHeap(heapA, heapB);
    if (heapU) {
        BinomialNode<Event>
                *cur = heapU,  // current node to append before or after
        *prev = nullptr, // node with sibling equal to current
        *next = nullptr; // the next potential
        int orderA, orderB;
        while (cur && cur->sibling) {
            next = cur->sibling;
            orderA = cur->order;
            orderB = next->order;
            if (orderA == orderB && orderA != order(next->sibling)) {
                //Next becomes Current's Child
                if (cur->value.get_id() < next->value.get_id()) {
                    cur->sibling = next->sibling;
                    cur->addChild(next);
                    //tempNext->parent = cur;
                    prev = cur;
                    cur = cur->sibling;
                } else //Current becomes Next's Child
                {
                    if (prev)
                        prev->sibling = next;
                    else
                        heapU = next;
                    next->addChild(cur);
                    prev = next;
                    cur = next->sibling;
                }
            } else {
                // got to Next's Child
                if (!prev)
                    heapU = cur;
                prev = cur;
                cur = next;
            }
        }
    }

    return heapU;
}

template<typename T>
BinomialNode<T> *BinomialHeap<T>::mergeHeap(BinomialNode<T> *heapA, BinomialNode<T> *heapB) {
    BinomialNode<T> *heapM = nullptr;

    if (heapA || heapB) {
        if (heapA && !heapB) {
            heapM = heapA;
        } else if (!heapA && heapB) {
            heapM = heapB;
        } else {
            BinomialNode<T> *temp = nullptr,
                    *next = nullptr,
                    *prev = nullptr,
                    *cur = nullptr;
            //pick minimum heap root to be merged heap root
            if (heapA->order > heapB->order) {
                heapM = heapB;
                next = heapA;

            } else {
                heapM = heapA;
                next = heapB;
            }
            cur = heapM;

            while (cur && next && cur != next) {
                if (cur->order <= next->order) {
                    if (cur->sibling) {
                        temp = cur->sibling;
                        cur->sibling = next;
                        prev = cur;
                        cur = next;
                        next = temp;
                    } else {
                        cur->sibling = next;
                        cur = next; // break loop
                    }
                } else {
                    if (prev)
                        prev->sibling = next;
                    else
                        heapM = next;
                    temp = next->sibling;
                    next->sibling = cur;
                    prev = next;
                    next = temp;

                }
            }

        }
    }
    return heapM;
}

#endif //PARCIAL2_BINOMIALHEAP_H
