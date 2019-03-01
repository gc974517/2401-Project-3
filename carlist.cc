#include <iostream>
#include <string>
#include "node.h"
#include "car.h"
#include "carlist.h"
using namespace std;

Carlist::Carlist() {
    head = cursor = NULL;
} // end function

Carlist::Carlist(const Carlist &cl) {
    node *clcursor;

    head = new node;
    cursor = head;
    clcursor = cl.head;

    while (clcursor != NULL) {
        cursor->set_data(clcursor->data());
        cursor->set_link(new node);

        cursor = cursor->link();
        clcursor = clcursor->link();
    } // end while

    cursor = NULL;
} // end function

Carlist::~Carlist() {
    node *trash;
    trash = head;
    cursor = head->link();

    do {
        delete trash;
    } while (cursor != NULL);
} // end function

Carlist Carlist::operator =(const Carlist &cl) {
    if (this == &cl) return *this;

    node *trash;
    trash = head;
    cursor = head->link();

    do {
        delete trash;
    } while (cursor != NULL);

    node *clcursor;

    head = new node;
    cursor = head;
    clcursor = cl.head;

    while (clcursor != NULL) {
        cursor->set_data(clcursor->data());
        cursor->set_link(new node);

        cursor = cursor->link();
        clcursor = clcursor->link();
    } // end while

    cursor = NULL;
    return *this;
} // end function

void Carlist::add(const Car &c) {
    cursor = head;
    while (cursor->link() != NULL)
        cursor = cursor->link();

    cursor->set_link(new node);
    cursor = cursor->link();

    cursor->set_data(c);
    cursor->set_link(NULL);
} // end function

void Carlist::showall(ostream &outs) {
    cursor = head;
    while (cursor != NULL) {
        outs << cursor->data() << endl;
        cursor = cursor->link();
    } // end while
} // end function

void Carlist::view_all_of_year(int targetyear) {
    cursor = head;
    while (cursor != NULL) {
        if ((cursor->data()).get_year() == targetyear)
            cout << cursor->data() << endl;

        cursor = cursor->link();
    } // end while
} // end function

void Carlist::view_all_of_make(string &targetmake) {
    // Start iterator ptr at beginning of list.
    cursor = head;
    while (cursor != NULL) {
        // Grab Car obj and make string as seperate vars for clarity.
        Car c(cursor->data());
        string data = c.get_make();

        // Print data, targetmake, and their comparison.
        // Prints individually just fine.
        cout << "Object Make: " << data << endl;
        cout << "Target Make: " << targetmake << endl;
        // Breaks here.
        cout << "Make Comparison: " << data << " =? " << targetmake << endl << endl;

        // Never evals to true.
        if (data == targetmake)
            cout << c << endl;

        cursor = cursor->link();
    } // end while
} // end function

Car Carlist::cheapest() {
    Car min;
    double cheapest = 2147483647.0;

    cursor = head;
    while (cursor != NULL) {
        if ((cursor->data()).get_price() < cheapest)
            min = cursor->data();

        cursor = cursor->link();
    } // end while

    return min;
} // end function

double Carlist::tax_value() {
    double sum = 0;

    cursor = head;
    while (cursor != NULL) {
        sum += (cursor->data()).get_price();
        cursor = cursor->link();
    } // end while

    return (sum * 0.7);
} // end function

void Carlist::remove(const Car &c) {
    node *prev;

    cursor = head;
    if (cursor->data() == c) {
        head = head->link();
        delete cursor;
    } // end if

    cursor = head;
    prev = cursor;
    cursor = head->link();

    while (cursor != NULL) {
        if (cursor->data() == c) prev->set_link(cursor->link());
        else prev = cursor;

        cursor = cursor->link();
    } // end while
} // end function

double Carlist::miles_per_year() {
    int sum;
    double count = 0.0;

    cursor = head;
    while (cursor != NULL) {
        sum += (cursor->data()).get_miles();
        count++;

        cursor = cursor->link();
    } // end while

    return (sum / count);
} // end function

void Carlist::load(istream &ins) {
    head = new node;
    cursor = head;

    Car c;
    c.input(ins);

    while (!ins.eof()) {
        cursor->set_data(c);
        cursor->set_link(new node);

        c.input(ins);
        if (!ins.eof())
            cursor = cursor->link();
    } // end while

    cursor->set_link(NULL);
} // end function

void Carlist::save(ostream &outs) {
    cursor = head;
    while (cursor != NULL) {
        (cursor->data()).output(outs);
        cursor = cursor->link();
    } // end function
} // end function
