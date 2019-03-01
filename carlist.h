#ifndef CARLIST_H
#define CARLIST_H

#include <iostream>
#include <string>
#include "node.h"
#include "car.h"

class Carlist {
    public:
        Carlist();
        Carlist(const Carlist &cl);
        ~Carlist();
        Carlist operator =(const Carlist &cl);

        void add(const Car &c);
        void showall(std::ostream &outs);
        void view_all_of_year(int targetyear);
        void view_all_of_make(std::string &targetmake);
        Car cheapest();
        double tax_value();
        void remove(const Car &c);
        double miles_per_year();

        void load(std::istream &ins);
        void save(std::ostream &outs);
    private:
        node *head;
        node *cursor;
}; // end class

#endif
