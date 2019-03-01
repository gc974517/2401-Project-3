/******************************************************
	This is the main for Project 3, which asks you to
    build a container that holds a list of Cars.
    The Cars are always kept in order, so they never need
    to be sorted since they are always inserted in the order
    where they go. You will also need the files:
	Car.h
	Car.cc
	node.h
    in order to do this project. You will be writing both the .h
    and the .cc file for the container.
	John Dolan			Spring 2019
**********************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "car.h"
#include "node.h"
#include "carlist.h"

using namespace std;

// This function displays the menu and returns the user's choice
int menu();

int main(){
    int choice;
    Car c;
    string targetmake;
    int targetyear;
    ifstream fin;
    ofstream fout;
    string username,filename, fullname;

        cout<<"Welcome to Howie's Car Inventory.\n\n";
        cout<<"Begin by entering your username: ";
        getline(cin,username);
        filename = username + ".txt";

// The default constructor is called here
	Carlist inventory;
        fin.open(filename.c_str());
    if(!fin.fail()){
        inventory.load(fin);
        fin.close();
	}
	choice = menu();
	while(choice != 0){
	    switch(choice){
	    case 1:
		cout<<"Enter a Car brought into inventory.\n";
		cin>>c;
		inventory.add(c);
		break;
	    case 2:
		inventory.showall(cout);
		break;
	    case 3:
		cout<<"Enter a year for which you would like to see Cars:";
		cin>>targetyear;
		inventory.view_all_of_year(targetyear);
		break;
	    case 4:
		cout<<"Enter a make for which you would like to see all Cars:\n";
		while(cin.peek() == '\n' || cin.peek() == '\r')
			cin.ignore();
		getline(cin,targetmake);
		inventory.view_all_of_make(targetmake);
		break;
	    case 5:
		cout<<inventory.cheapest()<<endl;
		break;
	    case 6:
		cout<<"$ "<<inventory.tax_value()<<endl;
		break;
	    case 7:{
		Carlist acopy(inventory);
  		int howmany;
		cout<<"How many Cars will you be hiding? \n";
		cin>>howmany;
		for(int i=0; i<howmany; ++i){
		    cout<<"Enter year: ";
		    cin>>targetyear;
		    c.set_year(targetyear);
		    cout<<"Enter make:";
                    while(cin.peek() == '\n' || cin.peek() == '\r')
                        cin.ignore();
                    getline(cin,targetmake);
		    c.set_make(targetmake);
		    cout<<"Enter model: ";
		    getline(cin, targetmake);
		    c.set_model(targetmake);
		    acopy.remove(c);
                }
		acopy.showall(cout);
		cout<<"With an adjusted value of $ "
				<<acopy.tax_value()<<endl;
		cout<<"But acutal value is still really: "
				<<inventory.tax_value();
		break;
		} // the copy goes out of scope here - destructor runs
	    case 8:
		cout<<"Average miles / year = ";
		cout<<inventory.miles_per_year()<<endl;
		break;
	    case 9:
		cout<<"Enter information on Car you need to remove.";
                    cout<<"Enter year: ";
                    cin>>targetyear;
                    c.set_year(targetyear);
                    cout<<"Enter make:";
                    while(cin.peek() == '\n' || cin.peek() == '\r')
                        cin.ignore();
                    getline(cin,targetmake);
                    c.set_make(targetmake);
                    cout<<"Enter model: ";
                    getline(cin, targetmake);
                    c.set_model(targetmake);
		    inventory.remove(c);
		    break;
	    case 0:
		cout<<"Thank you for managing Howie's Inventory.\n";
		break;
	    default:
		cout<<"Not an option.\n";
		break;
	    } //bottom of the switch
	    choice = menu();
	}// bottom or the while loop, which is a senteniel loop

    fout.open(filename.c_str());
    if(!fout.fail())
	inventory.save(fout);
    else
	cout<<"Problem with saving data!\n";
    fout.close();

return 0;
}

int menu(){
    int choice;
    cout<<"Choose from the following options:\n";
    cout<<"1) Add an additional Car to the inventory.\n";
    cout<<"2) Display all Cars in the inventory.\n";
    cout<<"3) View all Cars of a certain model year.\n";
    cout<<"4) View all Cars of a certain make.\n";
    cout<<"5) Find the cheapest Car on the lot.\n";
    cout<<"6) Find the tax value of the inventory.\n";
    cout<<"7) Examine the adjusted inventory.\n";
    cout<<"8) View the average number of miles per year for the inventory.\n";
    cout<<"9) Remove a Car from the inventory.\n";
    cout<<"0) Quit - saving all changes.\n";
    cin>>choice;

    return choice;
}
