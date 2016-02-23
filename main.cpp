//
//  main.cpp
//  FINAL PROJECT STARTING POINT WILL
//
//  Created by William Burger on 2/16/16.
//  Copyright (c) 2016 William Burger. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


class side_dish{
public:
    string* ingredients;
    char* name;
    char* style;
    float price;
    int for_how_many;
    int calories;
    side_dish();
    ~side_dish();
};


side_dish::side_dish(){
    ingredients = new string[1];
    ingredients[0] = "Unavailable";
    name = new char[7];
    strcpy(name,"holder");
    style = new char[7];
    strcpy(style,"holder");
    price = 0.00;
    for_how_many = 0;
    calories = 0;
}


side_dish::~side_dish(){
    delete name;
    delete style;
}


class contact{
public:
    int telephone;
    char* address;
    char* website;
    contact();
    ~contact();
};
contact::contact(){
    telephone = 0;
    address = new char[7];
    strcpy(address,"holder");
    website = new char[7];
    strcpy(website,"holder");
}
contact::~contact(){
    delete address;
    delete website;
}




class drink{
public:
    string* ingredients;
    char* name;
    char* style;
    float price;
    int for_how_many;
    int calories;
    drink();
    ~drink();
};

drink::drink(){
    ingredients = new string[1];
    ingredients[0] = "Unavailable";
    name = new char[7];
    strcpy(name,"holder");
    style = new char[7];
    strcpy(style,"holder");
    price = 0.00;
    for_how_many = 0;
    calories = 0;
}

drink::~drink(){
    delete name;
    delete style;
}




class main_dish{
public:
    string* ingredients;
    char* name;
    char* style;
    float price;
    int for_how_many;
    int calories;
    side_dish* sidedish_pairings;
    drink* drink_pairings;
    main_dish();
    ~main_dish();
};

main_dish::main_dish(){
    ingredients = new string[1];
    ingredients[0] = "Unavailable";
    name = new char[7];
    strcpy(name,"holder");
    style = new char[7];
    strcpy(style,"holder");
    price = 0.00;
    for_how_many = 0;
    calories = 0;
    sidedish_pairings = new side_dish;
    drink_pairings = new drink;
}

main_dish :: ~main_dish(){
    delete name;
    delete style;
}



class menu{
public:
    int num_dishes;
    int num_side_dishes;
    int num_drinks;
    main_dish* main_dishes;
    side_dish* side_dishes;
    drink* drinks;
    menu();
    ~menu();
    };

menu::menu(){
    num_dishes = 0;
    num_side_dishes=0;
    num_drinks=0;
    main_dishes = nullptr;
    side_dishes = nullptr;
    drinks = nullptr;
}

menu::~menu(){
}

class date{
public:
    char day[3]; // mm/dd/yyyy
    char month[3];
    char year[5];
    date current_date(); // Is there a way how to get the date from the system?
    date();
};
date::date(){
    strcpy(day,"00");
    strcpy(month,"00");
    strcpy(year,"0000");
}

class hours{
public:
    char open[6];  // hh:mm
    char close[6];  // hh:mm
    hours();
};
hours::hours(){
    strcpy(open,"00:00");
    strcpy(close,"00:00");
}

class seasonal_menu:public menu{
    using menu::menu; //Inheriting constructor from menu, no default constructor necessary for this
    date date_starts;
    date date_ends;
};



class restaurant{
public:
    menu menu;
    char* style;
    char* name;
    int distance;
    date date;
    hours hours;
    contact contact_info;
    restaurant();
};
restaurant::restaurant(){
    style = new char[7];
    strcpy(style,"holder");
    name = new char[7];
    strcpy(name,"holder");
}

int main() {
    restaurant mollys;
    cout << mollys.menu.num_drinks;
}



//What functions do we need:
//Data access, Data manipulation,
