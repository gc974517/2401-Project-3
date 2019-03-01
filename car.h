/**************************************************
	This class describes the data for a single car.
That data consists of year, make, model, miles and price. 
There is a full set of accessor functions, and input is 
done via the input and output operators. The comparison 
operators have also been defined, comparing by 1) year, 
2)make and 3) model. All functions longer than one line 
are implemented in car.cc.
	John Dolan	Ohio University EECS Spring 2019
********************************************************/

#include<iostream>
#include<cstdlib>
#include<string>

#ifndef CAR_H
#define CAR_H

class Car{
    public:
	Car();
    //Accessors
	int get_year(){return year;}
	std::string get_make() {return make;}
	std::string get_model(){return model;}
	double get_price(){return price;}
	int get_miles(){return miles;}
    //Mutators
	void set_year(int y){year = y;}
	void set_make(std::string mk){make=mk;}
	void set_model(std::string mod){model = mod;}
	void set_price(double p){price = p;}
	void set_miles(int m){miles = m;}
    //Input / Output
	void input(std::istream& ins);
	void output(std::ostream& outs)const;
    // Comparison operators
	bool operator == (const Car& c)const;
        bool operator != (const Car& c)const;
        bool operator < (const Car& c)const;
        bool operator > (const Car& c)const;
        bool operator <= (const Car& c)const;
        bool operator >= (const Car& c)const;
    private:
	int year;
	std::string make;
	std::string model;
	double price;
	int miles;
};

std::istream& operator >>(std::istream& ins, Car& c);
std::ostream& operator <<(std::ostream& outs, const Car& c);

#endif
