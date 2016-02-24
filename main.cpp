//
//  main.cpp
//  FINAL PROJECT STARTING POINT WILL
//
//  Created by William Burger on 2/16/16.
//  Copyright (c) 2016 William Burger. All rights reserved.
//

#include <iostream>
#include <string>
#define style_length 20
using namespace std;

//This is the base class for an item on the menu. It will bequeath thsese items to side dish, main dish, and drink classes through inheritance. The menus will be a linked list: the elements link to a previous and next item. Functions consist of setting member elements, printing member elements, and returning member elements or pointers to copies of those elements.
class menu_item{
protected:
    menu_item* previous_item;
    string* ingredients;
    int num_ingredients;
    char* name;
    char style[style_length];
    float price;
    int for_how_many;
    int calories;
    menu_item* next_item;
public:
    menu_item();
    ~menu_item();
    string* get_ingredients_pointer(){
        string* ingred = ingredients;
        return ingred;
    }
    void set_ingredients();
    void set_ingredients(string*,int);
    void print_ingredients();
    char* get_name(){
        char* nam;
        nam = new char[strlen(name)+1];
        return nam;
    }
    void set_name();
    void set_name(string);
    void set_name(char*);
    void print_name();
    void set_style();
    void print_style();
    string get_style(){
        return style;
    };
    void set_price(){
        cout<< "Enter a price >>";
        cin >> price;
    }
    void print_price(){
        cout << price;
    }
    float get_price(){
        return price;
    }
    void set_for_how_many(){
        cout << "Enter how many people the dish is for >>";
        cin >> for_how_many;
    }
    void print_for_how_many(){
        cout << for_how_many;
    }
    int get_for_how_many(){
        return for_how_many;
    }
    void set_calories(){
        cout << "Enter how many calories the dish is >>";
        cin >> calories;
    }
    void print_calories(){
        cout << calories;
    }
    int get_calories(){
        return calories;
    }
};

//Function definitions that were not defined in line.
string print_style_options(){
    string sty;
    cout << "chinese\n" << "diner\n" << "mexican\n" << "thai\n" << "american comfort\n" << "other\n";
    cout << "Please type the style of the restaurant from the list >>";
    getline(cin,sty);
    while(sty.compare("chinese")!=0 and sty.compare("diner")!=0 and sty.compare("thai")!=0 and sty.compare("american comfort")!=0 and sty.compare("other")!=0){
        cout <<"INVALID ENTRY PLEASE TRY AGAIN\n";
        cout <<"chinese\n" << "diner\n" << "mexican\n" << "thai\n" << "american comfort\n" << "other\n";
        cout << "Please type the style of the restaurant from the list >>";
        getline(cin,sty);
    }
    return sty;
}
void menu_item::set_ingredients(){
    int num,i=0;
    string junk;
    cout << "How many ingredients >>";
    cin >> num;
    ingredients = new string[num];
    std::getline(cin,junk);
    while (i<num){
        cout << "Enter an ingredient >>";
        std::getline(cin,ingredients[i]);
        i++;
    }
    cout << "Ingredients update complete for side_dish ";
    i=0;
    while (i<strlen(name)){
        cout<<name[i];
        i++;
    }
    cout <<"\n";
    num_ingredients = num;
};

//The set_ingredients function without user input. It takes the pointer to the first element in the array of strings and also the number of ingredients in the array.
void menu_item::set_ingredients(string* first_pointer,int num){
    int i = 0;
    num_ingredients = num;
    ingredients = new string[num];
    while(i<num){
        ingredients[i]=first_pointer[i];
        i++;
    }
}
void menu_item::print_ingredients(){
    int i=0;
    while (i<num_ingredients){
        cout << i+1 << ". " << ingredients[i] << "\n";
        i++;
    }
}
menu_item::menu_item(){
    ingredients = new string[1];
    ingredients[0] = "Unavailable";
    name = new char[7];
    strcpy(name,"holder");
    strcpy(style,"holder");
    price = 0.00;
    for_how_many = 0;
    calories = 0;
}

//Menu_item destructor will not need to delete name since it will be deleted in each child class
menu_item::~menu_item(){
}
void menu_item::set_name(){
    int i=0;
    string nam;
    cout << "Enter the side dish name >> ";
    getline(cin,nam);
    name = new char[nam.size()+1];
    while (i<nam.size()+1){
        if(i<nam.size()){
            name[i] = nam[i];
        }
        else
            name[i]=' ';
        i++;
    }
}
//set_name and set_style functions can take either a pointer to the first character or the entire string
void menu_item::set_name(char* first){
    name = new char[strlen(first)+1];
    strcpy(name,first);
}
void menu_item::set_name(string nam){
    int i =0;
    name = new char[nam.size()+1];
    while (i<strlen(name)){
        if(i<nam.size()){
            name[i] = nam[i];
        }
        else
            name[i]=' ';
        i++;
    }
}
void menu_item::print_name(){
    int i = 0;
    while(i<strlen(name)){
        cout << name[i];
        i++;
    }
}



void menu_item::set_style(){
    int i = 0;
    string sty;
    cout << "Select the style from the list below:\n";
    sty = print_style_options();
    while (i<sty.size()){
        if (i<sty.size()){
            style[i] = sty[i];
        }
        else
            style[i] = ' ';
        i++;
    }
}
void menu_item::print_style(){
    int i = 0;
    while(i<strlen(style)){
        cout << style[i];
        i++;
    }
}



class side_dish:public menu_item{
public:
    side_dish();
    ~side_dish();
};
side_dish::side_dish(){
    ingredients = new string[1];
    ingredients[0] = "Unavailable";
    name = new char[7];
    strcpy(name,"holder");
    strcpy(style,"holder");
    price = 0.00;
    for_how_many = 0;
    calories = 0;
}
side_dish::~side_dish(){
    delete name;
}

class contact{
private:
    long telephone;
    char* address;
    char* website;
public:
    contact();
    ~contact();
    void set_telephone(){
        cout << "Set the telephone number, no characters >>";
        cin >> telephone;
    }
    long get_telephone(){
        return telephone;
    }
    void print_telephone(){
        cout << telephone;
    }
    void set_address();
    char* get_address();
    void print_address();
    void set_website();
    char* get_website();
    void print_website();
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
void contact::set_address(){
    int i = 0;
    string add;
    cout << "Enter the address >> ";
    getline(cin,add);
    address = new char[add.size()+1];
    while (i<add.size()+1){
        if(i<add.size()){
            address[i] = add[i];
        }
        else
            address[i]=' ';
        i++;
    }
}
char* contact::get_address(){
    char* add;
    add = new char[strlen(address)+1];
    return add;
}
void contact::print_address(){
    int i = 0;
    while(i<strlen(address)){
        cout << address[i];
        i++;
    }
}
void contact::set_website(){
    int i=0;
    string add;
    cout << "Enter the website >> ";
    getline(cin,add);
    website = new char[add.size()+1];
    while (i<add.size()+1){
        if(i<add.size()){
            website[i] = add[i];
        }
        else
            website[i]=' ';
        i++;
    }
}
char* contact::get_website(){
    char* add;
    add = new char[strlen(website)+1];
    return add;
}
void contact::print_website(){
    int i = 0;
    while(i<strlen(website)){
        cout << website[i];
        i++;
    }
}

class drink:public menu_item{
public:
    drink();
    ~drink();
};
drink::drink(){
    ingredients = new string[1];
    ingredients[0] = "Unavailable";
    name = new char[7];
    strcpy(name,"holder");
    strcpy(style,"holder");
    price = 0.00;
    for_how_many = 0;
    calories = 0;
}
drink::~drink(){
    delete name;
}

class main_dish:public menu_item{
private:
    side_dish sidedish_pairing;
    drink drink_pairing;
public:
    main_dish();
    ~main_dish();
};

main_dish::main_dish(){
    ingredients = new string[1];
    ingredients[0] = "Unavailable";
    name = new char[7];
    strcpy(name,"holder");
    strcpy(style,"holder");
    price = 0.00;
    for_how_many = 0;
    calories = 0;
}
main_dish :: ~main_dish(){
    delete name;
}

class menu{
private:
    int num_dishes;
    int num_side_dishes;
    int num_drinks;
    main_dish* main_dishes_head;
    main_dish* main_dishes_tail;
    side_dish* side_dishes_head;
    side_dish* side_dishes_tail;
    drink* drinks_head;
    drink* drinks_tail;
public:
    menu();
    ~menu(){};
};
menu::menu(){
    num_dishes = 0;
    num_side_dishes=0;
    num_drinks=0;
    main_dishes_head = nullptr;
    main_dishes_tail = nullptr;
    side_dishes_head = nullptr;
    side_dishes_tail = nullptr;
    drinks_head = nullptr;
    drinks_tail = nullptr;
}

class date{
private:
    char day[3]; // mm/dd/yyyy
    char month[3];
    char year[5];
public:
    date current_date(); // Is there a way how to get the date from the system?
    date();
};
date::date(){
    strcpy(day,"00");
    strcpy(month,"00");
    strcpy(year,"0000");
}

class hours{
private:
    char open[6];  // hh:mm
    char close[6];  // hh:mm
public:
    hours();
};
hours::hours(){
    strcpy(open,"00:00");
    strcpy(close,"00:00");
}

class seasonal_menu:public menu{
    using menu::menu;  //Inheriting constructor from menu, no default constructor necessary for this
    date date_starts;
    date date_ends;
};


class restaurant{
private:
    menu menu;
    char style[style_length];
    char* name;
    int distance;
    date date;
    hours hours;
    contact contact_info;
public:
    restaurant();
    ~restaurant();
};
restaurant::restaurant(){
    strcpy(style,"holder");
    name = new char[7];
    strcpy(name,"holder");
}
restaurant::~restaurant(){
    delete name;
}


int main() {
    contact mollys;
    mollys.set_website();
    mollys.print_website();
}



//What functions do we need:
//Data access, Data manipulation,
