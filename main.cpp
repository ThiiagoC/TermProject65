//
//  main.cpp
//  FINAL PROJECT STARTING POINT WILL
//
//  Created by William Burger on 2/16/16.
//  Copyright (c) 2016 William Burger. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#define style_length 20
#define menu_size 30
#define num_restaurants 10
#define num_unique_ingredients 30
using namespace std;


//This is the base class for an item on the menu. It will bequeath thsese items to side dish, main dish, and drink classes through inheritance. The menus will be a linked list: the elements link to a previous and next item. Functions consist of setting member elements, printing member elements, and returning member elements or pointers to copies of those elements.
//Indexing in database for accessing menu item: Restaurant Index|00|Menu item type index|Menu item array index|menu item member function index
class ingredient{
public:
    string name;
    int restaurant_ID[num_restaurants];
    int menu_ID[num_restaurants];
    char type;
    ingredient(){
        name = "";
        for(int i=0;i<num_restaurants;i++){
            restaurant_ID[i]=i;
        }
        for(int i=0;i<num_restaurants;i++){
            menu_ID[i] = -1;
        }
        type = NULL;
    }
};

class menu_item{
protected:
    string* ingredients;
    char* name;
    char style[style_length];
    float price;
    int for_how_many;
    int calories;
    int num_ingredients;
    int rest_id;
    int position_in_restaurant;
    char* restaurant;
public:
    void set_rest_id(int id){
        rest_id = id;
    }
    void set_position_in_restaurant(int pos){
        position_in_restaurant=pos;
    }
    int get_rest_id(){
        return rest_id;
    }
    int get_position_in_rest(){
        return position_in_restaurant;
    }
    void set_restaurant(char* restauran){
        restaurant = new char[strlen (restauran)];
        strcpy(restaurant,restauran);
    }
    char* get_restaurant(){
        char* copy;
        strcpy(copy,restaurant);
        return copy;
    }
    void print_restaurant(){
        int i = 0;
        while (i<strlen(restaurant)){
            cout << restaurant[i];
            i++;
        }
    }
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
        return name;
    }
    void set_name();
    void set_name(string);
    void set_name(char*);
    void print_name();
    void set_style();
    void set_style(char*);
    void set_style(string);
    void print_style();
    string get_style(){
        return style;
    };
    void set_price(){
        cout<< "Enter a price >>";
        cin >> price;
    }
    void set_price (float pric){
        price=pric;
    }
    void print_price(){
        cout << "Price: $"<<price<<"\n";
    }
    float get_price(){
        return price;
    }
    void set_for_how_many(int hmany){
        for_how_many = hmany;
    }
    void set_for_how_many(){
        cout << "Enter how many people the dish is for >>";
        cin >> for_how_many;
    }
    void print_for_how_many(){
        cout << "Portion size for ";
        cout << for_how_many;
        cout << " person\n";
    }
    int get_for_how_many(){
        return for_how_many;
    }
    void set_calories(int cal){
        calories = cal;
    }
    void set_calories(){
        cout << "Enter how many calories the dish is >>";
        cin >> calories;
    }
    void print_calories(){
        cout <<"Total Calories: ";
        cout << calories;
        cout << "\n";
    }
    int get_calories(){
        return calories;
    }
    void print_menu_item();
    int get_num_ingredients(){
        return num_ingredients;
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
    cout << "Ingredients: \n";
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
    name = new char[nam.length()];
    while (i<nam.length()){
        if(i<nam.length()){
            name[i] = nam[i];
            i++;
        }
    }
}
void menu_item::print_name(){
    int i = 0;
    cout << "Name: ";
    while(i<strlen(name)){
        cout << name[i];
        i++;
    }
    cout << "\n";
}


void menu_item::set_style(char* first){
    strcpy(style,first);
}
void menu_item::set_style(string sty){
    int i =0;
    while (i<strlen(style)+1){
        if(i<sty.size()){
            style[i] = sty[i];
        }
        else
            style[i]=NULL;
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
    cout << "Style: ";
    int i = 0;
    while(i<strlen(style)){
        cout << style[i];
        i++;
    }
    cout << "\n";
}

void menu_item::print_menu_item(){
    print_name();
    print_ingredients();
    print_price();
    print_style();
    print_for_how_many();
    print_calories();
}

class side_dish:public menu_item{
private:
    char type = 's';
public:
    side_dish();
    ~side_dish();
    void print_type(){
        cout << type;
    }
    char get_type(){
        return type;
    }
    void operator =(menu_item item){
        string str;
        rest_id = item.get_rest_id();
        position_in_restaurant = item.get_position_in_rest();
        ingredients =item.get_ingredients_pointer();
        name = item.get_name();
        price = item.get_price();
        calories = item.get_calories();
        for_how_many = item.get_for_how_many();
        num_ingredients = item.get_num_ingredients();
        str = item.get_style();
        for(int i =0;i<style_length;i++){
            style[i] = str[i];
        }
    }
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
private:
    bool hot;
    bool alcoholic;
    char type = 'd';
public:
    void print_type(){
        cout << type;
    }
    char get_type(){
        return type;
    }
    bool get_temperature(){
        return hot;
    }
    void set_temperature(bool temp){
        hot = temp;
    }
    bool is_alcoholic(){
        return alcoholic;
    }
    void set_alcohol(bool alc){
        alcoholic = alc;
    }
    drink();
    ~drink();
    void print_drink(){
        print_menu_item();
        cout << hot << "\n";
        cout << alcoholic << "\n";
    }
    void operator =(menu_item item){
        string str;
        rest_id = item.get_rest_id();
        position_in_restaurant = item.get_position_in_rest();
        ingredients =item.get_ingredients_pointer();
        name = item.get_name();
        price = item.get_price();
        calories = item.get_calories();
        for_how_many = item.get_for_how_many();
        num_ingredients = item.get_num_ingredients();
        str = item.get_style();
        for(int i =0;i<style_length;i++){
            style[i] = str[i];
        }
    }
};
drink::drink(){
    ingredients = new string[1];
    ingredients[0] = "Unavailable";
    name = new char[7];
    strcpy(name,"holder");
    strcpy(style,"holder");
    price = 0.00;
    for_how_many =0;
    calories = 0;
    hot = false;
    alcoholic = false;
}
drink::~drink(){
}

class main_dish:public menu_item{
private:
    side_dish sidedish_pairing;
    drink drink_pairing;
    char type = 'm';
public:
    void print_type(){
        cout << type;
    }
    char get_type(){
        return type;
    }
    main_dish();
    ~main_dish();
    void set_side(side_dish sd){
        sidedish_pairing = sd;
    }
    side_dish get_side(){
        return sidedish_pairing;
    }
    void set_drink(drink d){
        drink_pairing = d;
    }
    drink get_drink(){
        return drink_pairing;
    }
    void operator =(menu_item item){
        string str;
        rest_id = item.get_rest_id();
        position_in_restaurant = item.get_position_in_rest();
        ingredients =item.get_ingredients_pointer();
        name = item.get_name();
        price = item.get_price();
        calories = item.get_calories();
        for_how_many = item.get_for_how_many();
        num_ingredients = item.get_num_ingredients();
        str = item.get_style();
        for(int i =0;i<style_length;i++){
            style[i] = str[i];
        }
    }
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
}

class menu{
private:
    main_dish main_dishes[menu_size]; //00|00-99 are indexes of
    side_dish side_dishes[menu_size];
    drink drinks[menu_size];
    int num_dishes;
    int num_side_dishes;
    int num_drinks;
public:
    main_dish* get_main_dishes(){
        return main_dishes;
    }
    side_dish* get_side_dishes(){
        return side_dishes;
    }
    drink* get_drinks(){
        return drinks;
    }
    int get_num_drinks(){
        return num_drinks;
    }
    int get_num_side_dishes(){
        return num_side_dishes;
    }
    int get_num_main_dishes(){
        return num_dishes;
    }
    menu();
    menu(main_dish md[],int num1,side_dish sd[],int num2,drink d[], int num3){
        num_dishes = num1;
        num_side_dishes = num2;
        num_drinks = num3;
        int i=0,j=0,z=0;
        while (i<num1){
            main_dishes[i] = md[i];
            i++;
        }
        while (j<num2){
            side_dishes[j] = sd[j];
            j++;
        }
        while(z<num3){
            drinks[z]=d[z];
            z++;
        }
    }
    void print_menu(){
        int i=0,j=0,z=0;
        while (i<num_dishes){
            cout << "-------------------\n";
            main_dishes[i].print_menu_item();
            i++;
        }
        while (j<num_side_dishes){
            cout << "-------------------\n";
            side_dishes[j].print_menu_item();
            j++;
        }
        while(z<num_drinks){
            cout << "-------------------\n";
            drinks[z].print_drink();
            z++;
        }
    }
    ~menu(){};
};
menu::menu(){
    num_dishes = 0;
    num_side_dishes=0;
    num_drinks=0;
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
    menu menu; //00
    char style[style_length]; //01
    char* name;
    int distance;
    date date;
    hours hours;
    contact contact_info;
public:
    restaurant();
    ~restaurant();
    void set_menu(main_dish* md,int num1,side_dish* sd,int num2,drink* d, int num3){
        class menu men(md,num1,sd,num2,d,num3);
        menu =men;
    }
    void print_name(){
        int i=0;
        while(i<strlen(name)){
            cout << name[i];
            i++;
        }
    }
    void print_menu(){
        menu.print_menu();
    }
    void set_name(string nam){
        int i=0;
        name = new char[nam.length()+1];
        while(i<nam.length()){
            name[i]=nam[i];
            i++;
        }
    }
    char* get_name(){
        return name;
    }
    class menu get_menu(){
        return menu;
    }
};
restaurant::restaurant(){
    strcpy(style,"holder");
    name = new char[7];
    strcpy(name,"holder");
}
restaurant::~restaurant(){
}


//Sorting Functions

main_dish* sort_main_dishes_price(restaurant* restaurants,int total_restaurants,main_dish* main_dish_price){
    class menu this_menu;
    main_dish* temporary;
    main_dish hold;
    int total_number_main_dishes=0;
    int i=0;
    bool done = false;
    while(i<total_restaurants){
        this_menu = restaurants[i].get_menu();
        total_number_main_dishes += this_menu.get_num_main_dishes();
        i++;
    }
    main_dish_price = new main_dish[total_number_main_dishes];
    i = 0;
    int z = 0;
    while(i<total_restaurants){
        this_menu = restaurants[i].get_menu();
        int j=0;
        while(j<this_menu.get_num_main_dishes()){
            temporary = this_menu.get_main_dishes();
            main_dish_price[z] = temporary[j];
            j++;
            z++;
        }
        i++;
    }
    while(done==false){
        int p = 0;
        int count = 0;
        while (p<total_number_main_dishes-1){
            if(main_dish_price[p].get_price()>main_dish_price[p+1].get_price()){
                hold = main_dish_price[p];
                main_dish_price[p] = main_dish_price[p+1];
                main_dish_price[p+1]=hold;
                count++;
            }
            p++;
        }
        if(count ==0){
            done = true;
        }
    }
    return main_dish_price;
}
main_dish* sort_main_dishes_calories(restaurant* restaurants,int total_restaurants,main_dish* main_dish_price){
    class menu this_menu;
    main_dish* temporary;
    main_dish hold;
    int total_number_main_dishes=0;
    int i=0;
    bool done = false;
    while(i<total_restaurants){
        this_menu = restaurants[i].get_menu();
        total_number_main_dishes += this_menu.get_num_main_dishes();
        i++;
    }
    main_dish_price = new main_dish[total_number_main_dishes];
    i = 0;
    int z = 0;
    while(i<total_restaurants){
        this_menu = restaurants[i].get_menu();
        int j=0;
        while(j<this_menu.get_num_main_dishes()){
            temporary = this_menu.get_main_dishes();
            main_dish_price[z] = temporary[j];
            j++;
            z++;
        }
        i++;
    }
    while(done==false){
        int p = 0;
        int count = 0;
        while (p<total_number_main_dishes-1){
            if(main_dish_price[p].get_calories()>main_dish_price[p+1].get_calories()){
                hold = main_dish_price[p];
                main_dish_price[p] = main_dish_price[p+1];
                main_dish_price[p+1]=hold;
                count++;
            }
            p++;
        }
        if(count ==0){
            done = true;
        }
    }
    return main_dish_price;
}
main_dish* sort_main_dishes_name(restaurant* restaurants,int total_restaurants,main_dish* main_dish_price){
    class menu this_menu;
    main_dish* temporary;
    main_dish hold;
    int total_number_main_dishes=0;
    int i=0;
    bool done = false;
    while(i<total_restaurants){
        this_menu = restaurants[i].get_menu();
        total_number_main_dishes += this_menu.get_num_main_dishes();
        i++;
    }
    main_dish_price = new main_dish[total_number_main_dishes];
    i = 0;
    int z = 0;
    while(i<total_restaurants){
        this_menu = restaurants[i].get_menu();
        int j=0;
        while(j<this_menu.get_num_main_dishes()){
            temporary = this_menu.get_main_dishes();
            main_dish_price[z] = temporary[j];
            j++;
            z++;
        }
        i++;
    }
    while(done==false){
        int p = 0;
        int count = 0;
        while (p<total_number_main_dishes-1){
            if(strcmp(main_dish_price[p].get_name(),main_dish_price[p+1].get_name())>0){
                hold = main_dish_price[p];
                main_dish_price[p] = main_dish_price[p+1];
                main_dish_price[p+1]=hold;
                count++;
            }
            p++;
        }
        if(count ==0){
            done = true;
        }
    }
    return main_dish_price;
}
main_dish* sort_main_dishes_style(restaurant* restaurants,int total_restaurants,main_dish* main_dish_price){
    class menu this_menu;
    main_dish* temporary;
    main_dish hold;
    int total_number_main_dishes=0;
    int i=0;
    bool done = false;
    while(i<total_restaurants){
        this_menu = restaurants[i].get_menu();
        total_number_main_dishes += this_menu.get_num_main_dishes();
        i++;
    }
    main_dish_price = new main_dish[total_number_main_dishes];
    i = 0;
    int z = 0;
    while(i<total_restaurants){
        this_menu = restaurants[i].get_menu();
        int j=0;
        while(j<this_menu.get_num_main_dishes()){
            temporary = this_menu.get_main_dishes();
            main_dish_price[z] = temporary[j];
            j++;
            z++;
        }
        i++;
    }
    while(done==false){
        int p = 0;
        int count = 0;
        while (p<total_number_main_dishes-1){
            if(main_dish_price[p].get_style().compare(main_dish_price[p+1].get_style())>0){
                hold = main_dish_price[p];
                main_dish_price[p] = main_dish_price[p+1];
                main_dish_price[p+1]=hold;
                count++;
            }
            p++;
        }
        if(count ==0){
            done = true;
        }
    }
    return main_dish_price;
}

side_dish* sort_side_dishes_price(restaurant* restaurants,int total_restaurants,side_dish* side_dish_price){
    class menu this_menu;
    side_dish* temporary;
    side_dish hold;
    int total_number_side_dishes=0;
    int i=0;
    bool done = false;
    while(i<total_restaurants){
        this_menu = restaurants[i].get_menu();
        total_number_side_dishes += this_menu.get_num_side_dishes();
        i++;
    }
    side_dish_price = new side_dish[total_number_side_dishes];
    i = 0;
    int z = 0;
    while(i<total_restaurants){
        this_menu = restaurants[i].get_menu();
        int j=0;
        while(j<this_menu.get_num_main_dishes()){
            temporary = this_menu.get_side_dishes();
            if (temporary[j].get_price()!=0){
                side_dish_price[z] = temporary[j];
                z++;
            }
            j++;
        }
        i++;
    }
    while(done==false){
        int p = 0;
        int count = 0;
        while (p<total_number_side_dishes-1){
            if(side_dish_price[p].get_price()>side_dish_price[p+1].get_price()){
                hold = side_dish_price[p];
                side_dish_price[p] = side_dish_price[p+1];
                side_dish_price[p+1]=hold;
                count++;
            }
            p++;
        }
        if(count ==0){
            done = true;
        }
    }
    return side_dish_price;
}
side_dish* sort_side_dishes_calories(restaurant* restaurants,int total_restaurants,side_dish* side_dish_price){
    class menu this_menu;
    side_dish* temporary;
    side_dish hold;
    int total_number_side_dishes=0;
    int i=0;
    bool done = false;
    while(i<total_restaurants){
        this_menu = restaurants[i].get_menu();
        total_number_side_dishes += this_menu.get_num_side_dishes();
        i++;
    }
    side_dish_price = new side_dish[total_number_side_dishes];
    i = 0;
    int z = 0;
    while(i<total_restaurants){
        this_menu = restaurants[i].get_menu();
        int j=0;
        while(j<this_menu.get_num_main_dishes()){
            temporary = this_menu.get_side_dishes();
            if (temporary[j].get_price()!=0){
                side_dish_price[z] = temporary[j];
                z++;
            }
            j++;
        }
        i++;
    }
    while(done==false){
        int p = 0;
        int count = 0;
        while (p<total_number_side_dishes-1){
            if(side_dish_price[p].get_calories()>side_dish_price[p+1].get_calories()){
                hold = side_dish_price[p];
                side_dish_price[p] = side_dish_price[p+1];
                side_dish_price[p+1]=hold;
                count++;
            }
            p++;
        }
        if(count ==0){
            done = true;
        }
    }
    return side_dish_price;
}
side_dish* sort_side_dishes_name(restaurant* restaurants,int total_restaurants,side_dish* side_dish_price){
    class menu this_menu;
    side_dish* temporary;
    side_dish hold;
    int total_number_side_dishes=0;
    int i=0;
    bool done = false;
    while(i<total_restaurants){
        this_menu = restaurants[i].get_menu();
        total_number_side_dishes += this_menu.get_num_side_dishes();
        i++;
    }
    side_dish_price = new side_dish[total_number_side_dishes];
    i = 0;
    int z = 0;
    while(i<total_restaurants){
        this_menu = restaurants[i].get_menu();
        int j=0;
        while(j<this_menu.get_num_main_dishes()){
            temporary = this_menu.get_side_dishes();
            if (temporary[j].get_price()!=0){
                side_dish_price[z] = temporary[j];
                z++;
            }
            j++;
        }
        i++;
    }
    while(done==false){
        int p = 0;
        int count = 0;
        while (p<total_number_side_dishes-1){
            if(strcmp(side_dish_price[p].get_name(),side_dish_price[p+1].get_name())>0){
                hold = side_dish_price[p];
                side_dish_price[p] = side_dish_price[p+1];
                side_dish_price[p+1]=hold;
                count++;
            }
            p++;
        }
        if(count ==0){
            done = true;
        }
    }
    return side_dish_price;
}
side_dish* sort_side_dishes_style(restaurant* restaurants,int total_restaurants,side_dish* side_dish_price){
    class menu this_menu;
    side_dish* temporary;
    side_dish hold;
    int total_number_side_dishes=0;
    int i=0;
    bool done = false;
    while(i<total_restaurants){
        this_menu = restaurants[i].get_menu();
        total_number_side_dishes += this_menu.get_num_side_dishes();
        i++;
    }
    side_dish_price = new side_dish[total_number_side_dishes];
    i = 0;
    int z = 0;
    while(i<total_restaurants){
        this_menu = restaurants[i].get_menu();
        int j=0;
        while(j<this_menu.get_num_main_dishes()){
            temporary = this_menu.get_side_dishes();
            if (temporary[j].get_price()!=0){
                side_dish_price[z] = temporary[j];
                z++;
            }
            j++;
        }
        i++;
    }
    while(done==false){
        int p = 0;
        int count = 0;
        while (p<total_number_side_dishes-1){
            if(side_dish_price[p].get_style().compare(side_dish_price[p+1].get_style())>0){
                hold = side_dish_price[p];
                side_dish_price[p] = side_dish_price[p+1];
                side_dish_price[p+1]=hold;
                count++;
            }
            p++;
        }
        if(count ==0){
            done = true;
        }
    }
    return side_dish_price;
}

drink* sort_drinks_price(restaurant* restaurants,int total_restaurants,drink* drinks_price){
    class menu this_menu;
    drink* temporary;
    drink hold;
    int total_number_drinks=0;
    int i=0;
    bool done = false;
    while(i<total_restaurants){
        this_menu = restaurants[i].get_menu();
        total_number_drinks += this_menu.get_num_drinks();
        i++;
    }
    drinks_price = new drink[total_number_drinks];
    i = 0;
    int z = 0;
    while(i<total_restaurants){
        this_menu = restaurants[i].get_menu();
        int j=0;
        while(j<this_menu.get_num_drinks()){
            temporary = this_menu.get_drinks();
            if (temporary[j].get_price()!=0){
                drinks_price[z] = temporary[j];
                z++;
            }
            j++;
        }
        i++;
    }
    while(done==false){
        int p = 0;
        int count = 0;
        while (p<total_number_drinks-1){
            if(drinks_price[p].get_price()>drinks_price[p+1].get_price()){
                hold = drinks_price[p];
                drinks_price[p] = drinks_price[p+1];
                drinks_price[p+1]=hold;
                count++;
            }
            p++;
        }
        if(count ==0){
            done = true;
        }
    }
    return drinks_price;
}
drink* sort_drinks_calories(restaurant* restaurants,int total_restaurants,drink* drinks_price){
    class menu this_menu;
    drink* temporary;
    drink hold;
    int total_number_drinks=0;
    int i=0;
    bool done = false;
    while(i<total_restaurants){
        this_menu = restaurants[i].get_menu();
        total_number_drinks += this_menu.get_num_drinks();
        i++;
    }
    drinks_price = new drink[total_number_drinks];
    i = 0;
    int z = 0;
    while(i<total_restaurants){
        this_menu = restaurants[i].get_menu();
        int j=0;
        while(j<this_menu.get_num_drinks()){
            temporary = this_menu.get_drinks();
            if (temporary[j].get_price()!=0){
                drinks_price[z] = temporary[j];
                z++;
            }
            j++;
        }
        i++;
    }
    while(done==false){
        int p = 0;
        int count = 0;
        while (p<total_number_drinks-1){
            if(drinks_price[p].get_calories()>drinks_price[p+1].get_calories()){
                hold = drinks_price[p];
                drinks_price[p] = drinks_price[p+1];
                drinks_price[p+1]=hold;
                count++;
            }
            p++;
        }
        if(count ==0){
            done = true;
        }
    }
    return drinks_price;
}
drink* sort_drinks_name(restaurant* restaurants,int total_restaurants,drink* drinks_price){
    class menu this_menu;
    drink* temporary;
    drink hold;
    int total_number_drinks=0;
    int i=0;
    bool done = false;
    while(i<total_restaurants){
        this_menu = restaurants[i].get_menu();
        total_number_drinks += this_menu.get_num_drinks();
        i++;
    }
    drinks_price = new drink[total_number_drinks];
    i = 0;
    int z = 0;
    while(i<total_restaurants){
        this_menu = restaurants[i].get_menu();
        int j=0;
        while(j<this_menu.get_num_drinks()){
            temporary = this_menu.get_drinks();
            if (temporary[j].get_price()!=0){
                drinks_price[z] = temporary[j];
                z++;
            }
            j++;
        }
        i++;
    }
    while(done==false){
        int p = 0;
        int count = 0;
        while (p<total_number_drinks-1){
            if(strcmp(drinks_price[p].get_name(),drinks_price[p+1].get_name())>0){
                hold = drinks_price[p];
                drinks_price[p] = drinks_price[p+1];
                drinks_price[p+1]=hold;
                count++;
            }
            p++;
        }
        if(count ==0){
            done = true;
        }
    }
    return drinks_price;
}
drink* sort_drinks_style(restaurant* restaurants,int total_restaurants,drink* drinks_price){
    class menu this_menu;
    drink* temporary;
    drink hold;
    int total_number_drinks=0;
    int i=0;
    bool done = false;
    while(i<total_restaurants){
        this_menu = restaurants[i].get_menu();
        total_number_drinks += this_menu.get_num_drinks();
        i++;
    }
    drinks_price = new drink[total_number_drinks];
    i = 0;
    int z = 0;
    while(i<total_restaurants){
        this_menu = restaurants[i].get_menu();
        int j=0;
        while(j<this_menu.get_num_drinks()){
            temporary = this_menu.get_drinks();
            if (temporary[j].get_price()!=0){
                drinks_price[z] = temporary[j];
                z++;
            }
            j++;
        }
        i++;
    }
    while(done==false){
        int p = 0;
        int count = 0;
        while (p<total_number_drinks-1){
            if(drinks_price[p].get_style().compare(drinks_price[p+1].get_style())>0){
                hold = drinks_price[p];
                drinks_price[p] = drinks_price[p+1];
                drinks_price[p+1]=hold;
                count++;
            }
            p++;
        }
        if(count ==0){
            done = true;
        }
    }
    return drinks_price;
}

void print_sort_to_file(int sortby,string file_name, restaurant* restaurants,int total_restaurants,drink*drinksort,main_dish*mainsort,side_dish*sidesort){
    class menu this_menu;
    ofstream myfile;
    myfile.open(file_name);
    int total_number_drinks=0;
    int total_number_main_dishes=0;
    int total_number_side_dishes=0;
    int i=0;
    while(i<total_restaurants){
        this_menu = restaurants[i].get_menu();
        total_number_drinks += this_menu.get_num_drinks();
        i++;
    }
    i=0;
    while(i<total_restaurants){
        this_menu = restaurants[i].get_menu();
        total_number_side_dishes += this_menu.get_num_side_dishes();
        i++;
    }
    i=0;
    while(i<total_restaurants){
        this_menu = restaurants[i].get_menu();
        total_number_main_dishes += this_menu.get_num_main_dishes();
        i++;
    }
    i=0;
    while(i<total_number_drinks){
        myfile<<i<<" ";
        myfile<<drinksort[i].get_type()<<" ";
        myfile<<drinksort[i].get_rest_id()<<" ";
        myfile<<drinksort[i].get_position_in_rest()<<" ";
        if (sortby==0){
            myfile<<drinksort[i].get_price()<<"\n";
        }
        if (sortby==1){
            int j =0;
            char* nam;
            nam = drinksort[i].get_name();
            while (j<strlen(drinksort[i].get_name())) {
                myfile<<nam[j];
                j++;
            }
            myfile<<"\n";
        }
        if (sortby==2){
            int j=0;
            string sty;
            sty = drinksort[i].get_style();
            while(j<sty.length()){
                myfile<<sty[j];
                j++;
            }
            myfile<<"\n";
        }
        if(sortby==3){
            myfile<<drinksort[i].get_calories()<<"\n";
        }
        i++;
    }
    i=0;
    while(i<total_number_main_dishes){
        myfile<<i<<" ";
        myfile<<mainsort[i].get_type()<<" ";
        myfile<<mainsort[i].get_rest_id()<<" ";
        myfile<<mainsort[i].get_position_in_rest()<<" ";
        if (sortby==0){
            myfile<<mainsort[i].get_price()<<"\n";
        }
        if (sortby==1){
            int j =0;
            char* nam;
            nam = new char[strlen(mainsort[i].get_name())];
            nam = mainsort[i].get_name();
            while (j<strlen(mainsort[i].get_name())) {
                myfile<<nam[j];
                j++;
            }
            myfile<<"\n";
        }
        if (sortby==2){
            int j=0;
            string sty;
            sty = mainsort[i].get_style();
            while(j<sty.length()){
                myfile<<sty[j];
                j++;
            }
            myfile<<"\n";
        }
        if(sortby==3){
            myfile<<mainsort[i].get_calories()<<"\n";
        }
        i++;
    }
    i=0;
    while(i<total_number_side_dishes){
        myfile<<i<< " ";
        myfile<<sidesort[i].get_type()<< " ";
        myfile<<sidesort[i].get_rest_id()<<" ";
        myfile<<sidesort[i].get_position_in_rest()<<" ";
        if (sortby==0){
            myfile<<sidesort[i].get_price()<<"\n";
        }
        if (sortby==1){
            int j =0;
            char* nam;
            nam = new char[strlen(sidesort[i].get_name())];
            nam = sidesort[i].get_name();
            while (j<strlen(sidesort[i].get_name())) {
                myfile<<nam[j];
                j++;
            }
            myfile<<"\n";
        }
        if (sortby==2){
            int j=0;
            string sty;
            sty = sidesort[i].get_style();
            while(j<sty.length()){
                myfile<<sty[j];
                j++;
            }
            myfile<<"\n";
        }
        if(sortby==3){
            myfile<<sidesort[i].get_calories()<<"\n";
        }
        i++;
    }
    
}

void print_and_sort_ingredients(int total,class ingredient*array,string file_name){
    ofstream myfile;
    myfile.open(file_name);
    int i =0;
    class ingredient holder;
    int j=0;
    bool done = false;
    while(done == false){
        int swaps = 0;
        j=0;
        while(j<total-1){
            if(array[j].name.compare(array[j+1].name)>0){
                holder = array[j];
                array[j]=array[j+1];
                array[j+1]=holder;
                swaps++;
            }
            j++;
        }
        if(swaps==0){
            done = true;
        }
    }
    i=0;
    while(i<total){
        int j=0;
        while (j<num_restaurants){
            if (array[i].menu_ID[j]>-1){
                myfile<<i<<" ";
                myfile<<array[i].type<<" ";
                myfile<<array[i].restaurant_ID[j]<<" ";
                myfile<<array[i].menu_ID[j]<<" ";
                myfile<<array[i].name<<"\n";
            }
            j++;
        }
        i++;
    }
}

int add_ingredient_restaurant(string ingredient, class ingredient*array,int restID, int location,char type){
    int i =0;
    int num_ingredients=0;
    bool check = false;
    while(i<num_unique_ingredients){
        if(ingredient==array[i].name){
            if(array[i].menu_ID[restID]!=location){
                array[i].menu_ID[restID]=location;
                check = true;
            }
        }
        i++;
    }
    if(check ==false){
        int j=0;
        while(array[j].name!=""){
            j++;
        }
        array[j].name = ingredient;
        array[j].menu_ID[restID]=location;
        array[j].type = type;
        num_ingredients++;
    }
    return num_ingredients;
}

int main() {
    restaurant restaurants[num_restaurants];
    string key,str;
    string* ingredients;
    string ingred[20];
    ingredient ingred_array[num_unique_ingredients];
    ofstream myfile;
    ofstream restfile;
    bool done = false;
    int i=0;
    int position = -1;
    int restaurant_id=-1;
    char menu_item_id=NULL;
    char trash=NULL;
    int total_restaurants=0;
    int j=0;
    int z=0, q=0,l=0;
    int t=0;
    int number_of_ingredients=0;
    main_dish* main_price_sort;
    side_dish* side_price_sort;
    drink* drink_price_sort;
    menu_item new_menu_item;
    drink drink_menu[num_restaurants][menu_size];
    main_dish main_dish_menu[num_restaurants][menu_size];
    side_dish side_dish_menu[num_restaurants][menu_size];
    ifstream rfile("/Users/williamburger/Desktop/ES65/ES_65_Database/menu_items.txt");
    ifstream rrestfile("/Users/williamburger/Desktop/ES65/ES_65_Database/restaurants.txt");
    //Scan in menu file
    while(getline(rrestfile,str)){
        int i;
        string rest_name,rest_name1,rest_name2;
        istringstream iss(str);
        iss >> i >> rest_name1 >>rest_name2;
        rest_name = rest_name1+" "+rest_name2;
        restaurants[i].set_name(rest_name);
    }
    //Scan in all menus file
    while(getline(rfile,str)){
        if(str[0]=='&'){
            restaurants[restaurant_id].set_menu(main_dish_menu[restaurant_id], z, side_dish_menu[restaurant_id], q, drink_menu[restaurant_id], l);
            i=z=j=q=l=t=0;
            total_restaurants++;
        }
        if(str[0]=='@'){
            key = str;
            istringstream iss(key);
            iss >>trash>>restaurant_id>>menu_item_id>>position;
            new_menu_item.set_position_in_restaurant(position);
            new_menu_item.set_rest_id(restaurant_id);
        }
        if(str[0]!='#' and done ==false and str[0]!='@' and str[0]!='0' and str[0]!='1' and str[0]!='&'){
            ingred[i]=str;
            number_of_ingredients+=add_ingredient_restaurant(ingred[i],ingred_array,restaurant_id, position, menu_item_id);
            i++;
        }
        if(str[0]=='#'){
            done = true;
        }
        if(done==true and str[0]!='#'){
            if(j==0){
                new_menu_item.set_name(str);
            }
            if(j==1){
                new_menu_item.set_style(str);
            }
            if(j==2){
                istringstream iss(str);
                float price;
                iss >> price;
                new_menu_item.set_price(price);
            }
            if(j==3){
                istringstream iss(str);
                int how_many;
                iss >> how_many;
                new_menu_item.set_for_how_many(how_many);
            }
            if(j==4){
                istringstream iss(str);
                int calories;
                iss >> calories;
                new_menu_item.set_calories(calories);
            }
            j++;
        }
        if (j==5 and (menu_item_id =='m' or menu_item_id == 's')){
            ingredients = new string[i];
            int p=0;
            while (p<i){
                ingredients[p]=ingred[p];
                p++;
            }
            new_menu_item.set_ingredients(ingredients,i);
            if (menu_item_id=='m'){
                main_dish_menu[restaurant_id][z] = new_menu_item;
                main_dish_menu[restaurant_id][l].set_restaurant(restaurants[restaurant_id].get_name());
                z++;
            }
            if (menu_item_id == 's'){
                side_dish_menu[restaurant_id][q] = new_menu_item;
                side_dish_menu[restaurant_id][l].set_restaurant(restaurants[restaurant_id].get_name());
                q++;
            }
            done = false;
            j=0;
            i=0;
        }
        if (j==5 and menu_item_id == 'd' and t==0){
            ingredients = new string[i];
            int p=0;
            while (p<i){
                ingredients[p]=ingred[p];
                p++;
            }
            new_menu_item.set_ingredients(ingredients,i);
            drink_menu[restaurant_id][l] = new_menu_item;
            istringstream iss(str);
            bool temperature;
            iss >> temperature;
            drink_menu[restaurant_id][l].set_temperature(temperature);
            getline(rfile,str);
            istringstream is(str);
            bool alcoholic;
            is >> alcoholic;
            drink_menu[restaurant_id][l].set_alcohol(alcoholic);
            drink_menu[restaurant_id][l].set_restaurant(restaurants[restaurant_id].get_name());
            j++;
            l++;
            j=0;
            i=0;
            done = false;
        }
    }
    //sort_dishes_price(restaurants,total_restaurants);
    main_price_sort = sort_main_dishes_price(restaurants,total_restaurants,main_price_sort);
    side_price_sort = sort_side_dishes_price(restaurants,total_restaurants, side_price_sort);
    drink_price_sort = sort_drinks_price(restaurants,total_restaurants,drink_price_sort);
    //Print all sorts to appropriate file name
    print_sort_to_file(0,"/Users/williamburger/Desktop/ES65/ES_65_Database/sort_price.txt", restaurants, total_restaurants, drink_price_sort, main_price_sort, side_price_sort);
    main_price_sort = sort_main_dishes_name(restaurants,total_restaurants,main_price_sort);
    side_price_sort = sort_side_dishes_name(restaurants,total_restaurants, side_price_sort);
    drink_price_sort = sort_drinks_name(restaurants,total_restaurants,drink_price_sort);
    print_sort_to_file(1,"/Users/williamburger/Desktop/ES65/ES_65_Database/sort_name.txt", restaurants, total_restaurants, drink_price_sort, main_price_sort, side_price_sort);
    main_price_sort = sort_main_dishes_style(restaurants,total_restaurants,main_price_sort);
    side_price_sort = sort_side_dishes_style(restaurants,total_restaurants, side_price_sort);
    drink_price_sort = sort_drinks_style(restaurants,total_restaurants,drink_price_sort);
    print_sort_to_file(2,"/Users/williamburger/Desktop/ES65/ES_65_Database/sort_style.txt", restaurants, total_restaurants, drink_price_sort, main_price_sort, side_price_sort);
    main_price_sort = sort_main_dishes_calories(restaurants,total_restaurants,main_price_sort);
    side_price_sort = sort_side_dishes_calories(restaurants,total_restaurants, side_price_sort);
    drink_price_sort = sort_drinks_calories(restaurants,total_restaurants,drink_price_sort);
    print_sort_to_file(3,"/Users/williamburger/Desktop/ES65/ES_65_Database/sort_calories.txt", restaurants, total_restaurants, drink_price_sort, main_price_sort, side_price_sort);
    
    print_and_sort_ingredients(number_of_ingredients,ingred_array,"/Users/williamburger/Desktop/ES65/ES_65_Database/sort_ingredients.txt");
    
}

//How to Access Data: The menus are stored in restaurants[i], where i is the index found in the index file.
//The individual items can be accessed via drink_menu[i][j]/side_dish_menu[i][j]/main_dish_menu[i][j] where i is the indexed restaurant and j is the order of the item.


//What functions do we need:
//Data access, Data manipulation,
