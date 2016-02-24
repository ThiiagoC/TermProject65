#define SIZE 256
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>

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
    void set_prefstyle(string,string styles[]);
    void set_prefstyle(string styles[]);
    void set_prefdrink(string,string drinks[]);
    void set_prefdrink(string drinks[]);
    void set_favrest(string,string rests[]);
    void set_favrest(string rests[]);

};

 void myUser::set_fname(string name){
    fname = name;
 }

 void myUser::set_lname(string name){
    lname = name;
 }

 void myUser::set_prefstyle(string namefile,string styles[]){
    int done,opt,cont,n,i;
    std::ofstream wfile;

    done=cont=0;

    wfile.open(namefile.c_str(),std::ios_base::app);

    // n = sizeof(*styles)/sizeof(styles[0]); DOESNT WORK
    n = 6;

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

    while (cont<5){
        wfile << "99\n";
        cont++;
    }

    wfile.close();
    cout << "Changes saved successfully!\n\n";

 }

  void myUser::set_prefstyle(string styles[]){
    int cont=0;

    while (cont<5){
        prefstyle[cont]=styles[cont];
        cont++;
    }
  }


  void myUser::set_prefdrink(string namefile,string drinks[]){
    int done,opt,cont,n,i;
    std::ofstream wfile;

    done=cont=0;

    wfile.open(namefile.c_str(),std::ios_base::app);

    n = 6;

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
                prefdrink[cont]=drinks[opt-1];
                cont++;
            } else {
                done=1;
            }
        } else {
            cout << "Please enter a valid option.\n";
        }
    }

    while (cont<5){
        wfile << "99\n";
        cont++;
    }

    wfile.close();
    cout << "Changes saved successfully!\n\n";

 }

  void myUser::set_prefdrink(string drinks[]){
    int cont=0;

    while (cont<5){
        prefdrink[cont]=drinks[cont];
        cont++;
    }
  }

 void myUser::set_favrest(string namefile,string rests[]){
    int done,opt,cont,n,i;
    std::ofstream wfile;

    done=cont=0;

    wfile.open(namefile.c_str(),std::ios_base::app);

    n = 6;

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
                favrest[cont]=rests[opt-1];
                cont++;
            } else {
                done=1;
            }
        } else {
            cout << "Please enter a valid option.\n";
        }
    }

    while (cont<5){
        wfile << "99\n";
        cont++;
    }

    wfile.close();
    cout << "Changes saved successfully!\n\n";

 }

  void myUser::set_favrest(string rests[]){
    int cont=0;

    while (cont<5){
        favrest[cont]=rests[cont];
        cont++;
    }
  }

void createProfile(myUser &a,string styles[],string drinks[],string rests[]){
    std::ofstream wfile;
    string holder;
    string fname;
    string lname;
    string namefile;

    cout << "\n~~ Create new profile ~~\n\n";

    cout << "First name:";
    std::getline(std::cin,holder,'\n');
    fname = holder;

    namefile = "C:\\Database_65\\Users\\";
    namefile.append(fname);
    a.set_fname(fname);


    namefile.append("_");

    cout << "Last name:";
    std::getline(std::cin,holder,'\n');
    lname = holder;
    namefile.append(lname);
    a.set_lname(lname);

    std::replace(namefile.begin(),namefile.end(),' ','_');
    namefile.append(".txt");

    wfile.open(namefile.c_str(),std::ios_base::app);
    if (wfile.is_open()){
        wfile << fname << "\n";
        wfile << lname << "\n";
        wfile.close();
        a.set_prefstyle(namefile,styles);
        a.set_prefdrink(namefile,drinks);
        a.set_favrest(namefile,rests);
        cout << "Profile successfully created!\n\n";
    } else {
        cout << "Error opening file.\n";
    }
}

void openProfile(myUser &a){
    string filename,line;
    string templist[5];
    int cont;
    std::ifstream rfile;

    cout << "\n~~ Access profile ~~\n\n";
    cout << "Please type your full name: ";
    std::getline(std::cin,filename,'\n');

    std::replace(filename.begin(),filename.end(),' ','_');

    filename = "C:\\Database_65\\Users\\"+filename+".txt";

    rfile.open(filename.c_str());

    if (rfile.is_open()){
        getline(rfile,line);
        a.set_fname(line);
        getline(rfile,line);
        a.set_lname(line);
        cont=0;
        while (cont<5){
            getline(rfile,line);
            templist[cont]=line;
            cont++;
        }
        a.set_prefstyle(templist);
        cont=0;
        while (cont<5){
            getline(rfile,line);
            templist[cont]=line;
            cont++;
        }
        a.set_prefdrink(templist);
        cont=0;
        while (cont<5){
            getline(rfile,line);
            templist[cont]=line;
            cont++;
        }
        a.set_favrest(templist);
    } else {
        cout << "\nThis profile doesn't exist, please try again.\n\n";
    }
}

int main(){
    myUser a;
    string holder,line;
    int done,opt1,opt2,opt3,i,n,counter;
    std::ifstream rfile;
    std::ofstream wfile;
    string styles[]={"Italian","Japanese","Chinese","Thai","Pizza","Pasta"};
    string drinks[]={"Soda","Tea","Beer","Wine","Juice","Cider"};
    string rests[]={"Molly's","Lou's","EBAs","Sushi Ya","Orient"};

    done=opt1=opt2=0;

    cout << "Do you already have a profile?\n 1 - Yes\n 2 - No\n\nType the desired option:";
    cin >> opt1;
    std::cin.ignore(256,'\n');

    switch(opt1){
    case 1:
        openProfile(a);
        break;
    case 2:
        createProfile(a,styles,drinks,rests);
        break;
    }

    return 42;

}

/* GENERAL COMMENTS

We need a function to manipulate set directly, without menus
Also, find a way to have the same amount of lines to access data from file after
Use headers to read the file
Create a file for every user

Functions we need:
-Data access
-Data manipulation
-Time function (get time)

Import some data from Orient and Lou's

Solve problem for size of the styles, drinks and rests lists.

See if there's a way to separate menu options with comma and get it to work too.

Ask professor if how this works:
(http://stackoverflow.com/questions/609203/read-file-names-from-a-directory)


vector<CStdString> filenames;
CStdString directoryPath("C:\\foo\\bar\\baz\\*");

WIN32_FIND_DATA FindFileData;
HANDLE hFind = FindFirstFile(directoryPath, &FindFileData);

if (hFind  != INVALID_HANDLE_VALUE)
{
    do
    {
        if (FindFileData.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY)
              filenames.push_back(FindFileData.cFileName);
    } while (FindNextFile(hFind, &FindFileData));

    FindClose(hFind);
}
This gives you a vector with all filenames in a directory. It only works on Windows of course.

Ask about how to read from files more efficiently

Consider using profile functions inside class (to avoid private/public issues)

Remember to not print elements equal to 99.

*/

