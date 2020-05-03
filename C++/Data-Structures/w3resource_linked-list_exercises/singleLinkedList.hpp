#include <iostream>
using namespace std;

template <class T>
class SingleListNode {
    public:
        SingleListNode<T>() {
            this->value = nullptr;
            this->next = nullptr;
        }

        SingleListNode<T>(T value) {
            this->value = value;
            this->next = nullptr;
        }

        T value;
        SingleListNode<T>* next;
};

template <class T>
class SingleLinkedList {
    private:
        unsigned int length;

    public:
        SingleListNode<T>* first;
        SingleListNode<T>* last;

        SingleLinkedList() {}

        ~SingleLinkedList() {
            this->dispose();
        }

        unsigned int count() {
            return this->length;
        }

        void dispose() {
            SingleListNode<T>* current = this->first;
            SingleListNode<T>* next = current->next;
            delete current;

            while (next != nullptr) {
                current = next;
                next = current->next;
                delete current;
            }
        }

        /**
         * Add a new value to the end of the list.
         */
        void add(T newValue) {
            SingleListNode<T>* newNode = new SingleListNode<T>(newValue);

            if (this->length == 0) {
                this->first = newNode;
                this->last = newNode;

            } else {
                this->last->next = newNode;
                this->last = newNode;
            }

            ++this->length;
        }

        void addToStart(T newValue) {
            if (this->length == 0) {
                this->add(newValue);
                return;
            }

            SingleListNode<T>* newNode = new SingleListNode<T>(newValue);
            newNode->next = this->first;
            this->first = newNode;
            ++this->length;
        }

        T get(unsigned int index) {
            if (this->length == 0) {
                return;

            } else if (index >= this->length) {
                return this->last;
            }

            SingleListNode<T>* theNode = this->first;
            unsigned int i;
            for (i = 0; i != index; ++i) {
                theNode = theNode->next;
            }

            return theNode->value;
        }

        void reverseSequential() {
            SingleListNode<T>* start = this->first;
            SingleListNode<T>* nextHead = start->next;
            start->next = nullptr; // The first is now the last node, so nothing after it.

            this->first = nextHead;
            nextHead = nextHead->next;
            this->first->next = start;

            while (nextHead != nullptr) {
                start = this->first;
                this->first = nextHead;
                nextHead = nextHead->next;
                this->first->next = start;
            }
        }

        void printAllValues() {
            if (this->length == 0) {
                cout << "The list is empty" << endl;
                return;
            }

            SingleListNode<T>* currNode = this->first;

            unsigned int i;
            for (i = 0; i < this->length && currNode != nullptr; ++i) {
                cout << currNode->value << endl;
                currNode = currNode->next;
            }
        }
};
