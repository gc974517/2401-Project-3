/*********************************************
	The implementation for the functions of the Car 
class. All one-line functions have been implemented 
inline in the car.h file.
    John Dolan	Ohio University EECS	Spring 2019
***************************************************/
#include "car.h"
using namespace std;
    //Default Constructor
Car::Car(){
   year = 1908;
   make = "Ford";
   model = "Model T";
   miles = 10000;
   price = 14999;
}

    //Input / Output
void Car::input(std::istream& ins){
    if(&ins == &cin){
	cout<<"Year:";
	ins>>year;
	cout<<"Make: ";
	while(ins.peek() == '\n' || ins.peek() == '\r')
	    ins.ignore();
	getline(ins,make);
	cout<<"Model: ";
	getline(ins, model);
	cout<<"Price: ";
	ins>>price;
	cout<<"Miles: ";
	ins>>miles;
    }
    else{
        ins>>year;
        while(ins.peek() == '\n' || ins.peek() == '\r')
            ins.ignore();
        getline(ins,make);
        getline(ins, model);
        ins>>price;
        ins>>miles;
     }
}

void Car::output(std::ostream& outs)const{
     // Set up the stream for currency output
      	outs.setf(ios::fixed);
	outs.setf(ios::showpoint);
	outs.precision(2);
    if(&outs == & cout){
	outs<<"Year: "<<year<<endl;
        outs<<"Make: "<<make<<endl;
        outs<<"Model: "<<model<<endl;
        outs<<"Price: $"<<price<<endl;
        outs<<"Miles: "<<miles<<endl;
    }
    else{
        outs<<year<<endl;
        outs<<make<<endl;
        outs<<model<<endl;
        outs<<price<<endl;
        outs<<miles<<endl;
    }
}
    // Comparison operators
bool Car::operator == (const Car& c)const
{
    return (year == c.year && make == c.make && 
	model == c.model);
}
bool Car::operator != (const Car& c)const
{
    return (year != c.year || make != c.make ||
        model !=c.model);
}
bool Car::operator < (const Car& c)const{
        if(year != c.year){
	  return year < c.year;
        }
	else if(make != c.make){
	    return make<c.make;
	     }
	else
	    return model<c.model;
}

bool Car::operator > (const Car& c)const{
        if(year != c.year){
          return year > c.year;
        }
        else if(make != c.make){
            return make>c.make;
             }
        else
            return model>c.model;
}

bool Car::operator <= (const Car& c)const{
        return (*this == c || *this < c);
}
bool Car::operator >= (const Car& c)const{
        return (*this == c || *this > c);
}

std::istream& operator >>(std::istream& ins, Car& c)
{
    c.input(ins);
    return ins;
}
std::ostream& operator <<(std::ostream& outs,const Car& c)
{
    c.output(outs);
    return outs;
}
