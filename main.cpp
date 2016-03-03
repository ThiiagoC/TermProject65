//
//  main.cpp
//  FINAL PROJECT STARTING POINT WILL
//
//  Created by William Burger on 2/16/16.
//  Copyright (c) 2016 William Burger. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <sstream>
#include <algorithm>
#define style_length 20
#define menu_size 30
#define num_restaurants 10
using namespace std;



//This is the base class for an item on the menu. It will bequeath thsese items to side dish, main dish, and drink classes through inheritance. The menus will be a linked list: the elements link to a previous and next item. Functions consist of setting member elements, printing member elements, and returning member elements or pointers to copies of those elements.
//Indexing in database for accessing menu item: Restaurant Index|00|Menu item type index|Menu item array index|menu item member function index
class menu_item{
protected:
    string* ingredients;
    char* name;
    char style[style_length];
    float price;
    int for_how_many;
    int calories;
    int num_ingredients;
    char* restaurant;
public:
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
        char* nam;
        nam = new char[strlen(name)+1];
        strcpy(nam,name);
        return nam;
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
    name = new char[nam.size()];
    while (i<nam.size()){
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
    char get_type(){
        return type;
    }
    void operator =(menu_item item){
        string str;
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
private:
    bool hot;
    bool alcoholic;
    char type = 'd';
public:
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
        cout << "-------------------------\n";
        while (i<num_dishes){
            main_dishes[i].print_menu_item();
            cout << "-------------------------\n";
            i++;
        }
        while (j<num_side_dishes){
            side_dishes[j].print_menu_item();
            cout << "-------------------------\n";
            j++;
        }
        while(z<num_drinks){
            drinks[z].print_drink();
            cout << "-------------------------\n";
            z++;
        }
    }
    void print_main_dishes(){
        int i=0;
        cout << "-------------------------\n";
        while (i<num_dishes){
            main_dishes[i].print_menu_item();
            cout << "-------------------------\n";
            i++;
        }
    }
    void print_side_dishes(){
        int j=0;
        cout << "-------------------------\n";
        while (j<num_side_dishes){
            side_dishes[j].print_menu_item();
            cout << "-------------------------\n";
            j++;
        }
    }
    void print_drinks(){
        int z=0;
        cout << "-------------------------\n";
        while(z<num_drinks){
            drinks[z].print_drink();
            cout << "-------------------------\n";
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
    // using menu::menu;  //Inheriting constructor from menu, no default constructor necessary for this
    date date_starts;
    date date_ends;
};


class restaurant{
// private:
public:
    class menu menu; //00
    char style[style_length]; //01
    char* name;
    int distance;
    class date date;
    class hours hours;
    contact contact_info;
// public:
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
};
restaurant::restaurant(){
    strcpy(style,"holder");
    name = new char[7];
    strcpy(name,"holder");
}
restaurant::~restaurant(){
    delete name;
}


//Sorting Functions

void sort_main_dishes_price(main_dish* main_dish_menu){
    int price_1;
    int price_2;
    int i;
    bool done = false;
    while(done ==false){

    }
}

int get_option(string &opt){
    bool invalid;
    int i,number;


    cout << "Type the desired option and press enter: ";
    std::getline(std::cin,opt,'\n');

    i = number = 0;
    while(opt[i]!='\0'){
        if(isdigit(opt[i])){
            number += opt[i]-'0';
            i++;
        } else {
            invalid = 1;
        }
    }
    while(invalid){
        cout << "Please, type a valid option: ";
        std::getline(std::cin,opt,'\n');
        i = 0;
        invalid = 0;
        number = 0;
        while(opt[i]!='\0'){
            if(isdigit(opt[i])){
                number += opt[i]-'0';
                i++;
            } else {
                invalid = 1;
            }
        }
    }
    cout << "\n";
    return number;
}

int user_interface(restaurant rests[],int num_rest){ // We will probably need sizes for these lists
    string input; //user input
    int i,index,opt;
    bool valid;

    cout << " ~~ Welcome! ~~\n\n";

    cout << "Please select one of the options below: \n\n";
    cout << " 1 - Display restaurant menu\n";
    cout << " 2 - Make a search\n";
    cout << " 3 - See recommendation\n";
    cout << " 0 - Quit\n\n";
    opt = get_option(input);

    switch(opt){
        case 1:
            cout << "\n Select a restaurant from the list: \n\n";
            for (i=1;i<=num_rest;i++){ // num_rest in the number of restaurants read from the file
                cout << " " << i << " - " << rests[i-1].get_name() <<endl;
            }
            index = get_option(input)-1;
            if(index>=-1 & index<num_rest){
                if(index==-1){
                    return 1;
                }
                cout << "Select a category to display: \n";
                cout << " 1 - Main dishes\n";
                cout << " 2 - Side dishes\n";
                cout << " 3 - Drinks\n";
                opt = get_option(input);

                switch(opt){
                    case 1:
                        rests[index].menu.print_main_dishes();//rests[index].print_main_dishes();
                        break;
                    case 2:
                        rests[index].menu.print_side_dishes();
                        break;
                    case 3:
                        rests[index].menu.print_drinks();
                }
            }
    };

}

int main() {
    restaurant restaurants[num_restaurants];
    string key,str;
    string* ingredients;
    string ingred[20];
    ofstream myfile;
    ofstream restfile;
    bool done = false;
    int i=0;
    int restaurant_id=-1;
    char menu_item_id=NULL;
    char trash=NULL;
    int j=0;
    int z=0, q=0,l=0;
    int t=0;
    int num_rest = 0;
    menu_item new_menu_item;
    drink drink_menu[num_restaurants][menu_size];
    main_dish main_dish_menu[num_restaurants][menu_size];
    side_dish side_dish_menu[num_restaurants][menu_size];
    class menu new_menu;
    ifstream rfile("C:\\Database_65\\menu_items.txt");
    ifstream rrestfile("C:\\Database_65\\restaurants.txt");
    while(getline(rrestfile,str)){
        cout << str << endl;
        int i;
        string rest_name,rest_name1,rest_name2;
        istringstream iss(str);
        iss >> i >> rest_name1 >>rest_name2;
        cout << i << ":"<< rest_name1 << "+" << rest_name2 << endl;
        rest_name = rest_name1+" "+rest_name2;
        restaurants[i].set_name(rest_name);
        num_rest++;
    }
    while(getline(rfile,str)){
        if(str[0]=='&'){
            restaurants[restaurant_id].set_menu(main_dish_menu[restaurant_id], z, side_dish_menu[restaurant_id], q, drink_menu[restaurant_id], l);
            i=z=j=q=l=t=0;
        }
        if(str[0]=='@'){
            key = str;
            istringstream iss(key);
            iss >>trash>>restaurant_id>>menu_item_id;
        }
        if(str[0]!='#' and done ==false and str[0]!='@' and str[0]!='0' and str[0]!='1' and str[0]!='&'){
            ingred[i]=str;
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

    rfile.close();
    rrestfile.close();

    user_interface(restaurants,num_rest);
    cout << "RESTAURANT NAME: \n";
    restaurants[0].get_name();
}
//How to Access Data: The menus are stored in restaurants[i], where i is the index found in the index file.
//The individual items can be accessed via drink_menu[i][j]/side_dish_menu[i][j]/main_dish_menu[i][j] where i is the indexed restaurant and j is the order of the item.


//What functions do we need:
//Data access, Data manipulation,
