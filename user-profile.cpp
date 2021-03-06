#define SIZE 256
#include <fstream>
#include <string>
#include <iostream>

using namespace std;


class myUser {
    string fname;
    string lname;
    string prefstyle[5];
    string prefdrink[5];
    string favrest[5];
public:
    void set_fname(string);
    void set_lname(string);
    void set_prefstyle(string styles[]);
    void set_prefdrink(string drinks[]);
    void set_favrest(string rests[]);

};

 void myUser::set_fname(string name){
    fname = name;
 }

 void myUser::set_lname(string name){
    lname = name;
 }

 void myUser::set_prefstyle(string styles[]){
    int done,opt,cont,n,i;
    std::ofstream wfile;

    done=cont=0;

    wfile.open("users.txt",std::ios_base::app);

    n=5;

    while(!done && cont<5){
        cout << "Please choose your preferred style(s) of food\n";
        for(i=0;i<n;i++){
        cout << i+1 << " - " << styles[i] << endl;
        }
        cout << "0 - Quit\n";
        cin >> opt;
        if (opt>=0 && opt<=n){
            if(opt!=0){
                wfile << styles[opt-1] << "\n";
                prefstyle[cont]=styles[opt-1];
                cont++;
            } else {
                done=1;
            }
        } else {
            cout << "Please enter a valid option.\n";
        }
    }
    wfile.close();
    cout << "Changes saved successfully!\n\n";

 }

  void myUser::set_prefdrink(string drinks[]){
    int done,opt,cont,n,i;
    std::ofstream wfile;

    done=cont=0;

    wfile.open("users.txt",std::ios_base::app);

    n=5;

    while(!done && cont<5){
        cout << "Please choose your preferred style(s) of beverage\n";
        for(i=0;i<n;i++){
        cout << i+1 << " - " << drinks[i] << endl;
        }
        cout << "0 - Quit\n";
        cin >> opt;
        if (opt>=0 && opt<=n){
            if(opt!=0){
                wfile << drinks[opt-1] << "\n";
                prefstyle[cont]=drinks[opt-1];
                cont++;
            } else {
                done=1;
            }
        } else {
            cout << "Please enter a valid option.\n";
        }
    }
    wfile.close();
    cout << "Changes saved successfully!\n\n";

 }

 void myUser::set_favrest(string rests[]){
    int done,opt,cont,n,i;
    std::ofstream wfile;

    done=cont=0;

    wfile.open("users.txt",std::ios_base::app);

    n=5;

    while(!done && cont<5){
        cout << "Please choose your favorite restaurant(s)\n";
        for(i=0;i<n;i++){
        cout << i+1 << " - " << rests[i] << endl;
        }
        cout << "0 - Quit\n";
        cin >> opt;
        if (opt>=0 && opt<=n){
            if(opt!=0){
                wfile << rests[opt-1] << "\n";
                prefstyle[cont]=rests[opt-1];
                cont++;
            } else {
                done=1;
            }
        } else {
            cout << "Please enter a valid option.\n";
        }
    }
    wfile.close();
    cout << "Changes saved successfully!\n\n";

 }


int main(){
    myUser a;
    string holder,line;
    int done,opt1,opt2,opt3,i,n,counter;
    std::ifstream rfile;
    std::ofstream wfile;
    string styles[]={"Italian","Japanese","Chinese","Thai","Pizza","Pasta"};
    string drinks[]={"Soda","Tea","Beer","Wine","Juice"};
    string rests[]={"Molly's","Lou's","EBAs","Sushi Ya","Orient"};

    done=opt1=opt2=0;

    cout << "Do you already have a profile?\n 1 - Yes\n 2 - No\n\nType the desired option:";
    cin >> opt1;
    std::cin.ignore(256,'\n');

    switch(opt1){
    case 1:
        cout << "Please select a profile:\n";
        // LIST OF PROFILES
        cin >> opt2;
        break;
    case 2:
        wfile.open("users.txt",std::ios_base::app);
        cout << "~~ Create new profile ~~\n";

        cout << "First name:";
        std::getline(std::cin,holder,'\n');
        a.set_fname(holder);
        wfile << holder << "\n";

        cout << "Last name:";
        std::getline(std::cin,holder,'\n');
        a.set_lname(holder);
        wfile << holder << "\n";

        wfile.close();

        a.set_prefstyle(styles);
        a.set_prefdrink(drinks);
        a.set_favrest(rests);

        cout << "Profile successfully created!\n\n";

    }

}

/* GENERAL COMMENTS

We need a function to manipulate set directly, without menus
Also, find a way to have the same amount of lines to access data from file after
Use headers to read the file
Create a file for every user

Functions we need:
-Data access
-Data manipulation
-Time funtion (get time)

Import some data from Orient and Lou's

*/
