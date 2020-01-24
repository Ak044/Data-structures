//Ammar Khan
//Program 3, Main file
//This handles transfering the 
//information from temps, to
//the ADT.

#include "project3.h"

bool again();



int main ()
{
    table my_table;
    book_info a_book;
    char title[100];
    char notes[100];
    char update[500];
    int chap = 0;
    int chapter = 0;
    int page = 0;
    char response;
    int extra = 0;
    cout << "Welcome User! " << endl;
    a_book.set_info();    //This function initializes a_books data members to NULL.
    my_table.load_file(a_book); //This function reads the info from the file.

    do
    {
       cout <<"Please enter a title: ";
       cin.get(title, 100); 
       cin.ignore(100,'\n');
       cout <<"Please enter the notes: ";
       cin.get(notes, 300); 
       cin.ignore(100,'\n');
       cout << "Please enter the chapter number: " << endl;
       cin >> chapter;
       cin.ignore(100, '\n');
       cout << "Please enter the page number: " << endl;
       cin >> page;
       cin.ignore(100, '\n');
       cout << "Do you need to study extra? (y/n): " << endl;
       cin >> response;
       cin.ignore(100, '\n');
       if(response == 'Y' || response == 'y')
       {
            extra = 1;
       }
       else
       {
            extra = 0;
       }
       a_book.create_info(title, notes, chapter, page, extra);
       //now insert it into the hash table
       my_table.insert_file(title, a_book);
       a_book.remove_info();
       cout << "Would you like to view the title for a certain chapter?(y/n) " << endl;
       cin >> response;
       cin.ignore(100, '\n');
       if(response == 'Y' || response == 'y')
       {
           cout <<"Please enter the chapter number: ";
           cin >> chap; 
           cin.ignore(100,'\n');
            if(!my_table.display_chapter(chap))
            {
                cout << "The title for this chapter is not available! " << endl;
            }
 
       }
       cout << "Do you want to find the notes for a chapter?(y/n) " << endl;
       cin >> response;
       cin.ignore(100, '\n');
       if(response == 'Y' || response == 'y')
       {
           cout <<"Please enter the title of the chapter: ";
           cin.get(title, 100); 
           cin.ignore(100,'\n');
           if(!my_table.retrieve(title,a_book))
           {
                cout << "Notes for that chapter are not available! " << endl;
           }
           else
           {
                cout << "The notes are found! " << endl;
           }
       }

       cout << "Do you want to change the notes for a chapter?(y/n) " << endl;
       cin >> response;
       cin.ignore(100, '\n');
       if(response == 'Y' || response == 'y')
       {
           cout <<"Please enter the title of the chapter: ";
           cin.get(title, 100); 
           cin.ignore(100,'\n');
           cout <<"Please enter your new notes: ";
           cin.get(update, 500, '\n');
           cin.ignore(100, '\n');
           if(!my_table.edit(title, update))
           {
                cout << "Notes for that chapter are not available! " << endl;
           }
           else
           {
                cout << "The notes are found! " << endl;
           }
       }
       cout << "Would you like to remove a set of notes?(y/n) " << endl;
       cin >> response;
       cin.ignore(100, '\n');
       if(response == 'Y' || response == 'y')
       {
           cout <<"Please enter the title of the chapter you'd like to remove: ";
           cin.get(title, 100); 
           cin.ignore(100,'\n');
           if(!my_table.remove(title))
           {
                cout << "Notes for this chapter do not exist! " << endl;
           }
           else
           {
                cout << "The notes have been successfully removed! " << endl;
           }
       }
       cout << "Would you like to view the contents of the table?(y/n) " << endl;
       cin >> response;
       cin.ignore(100, '\n');
       if(response == 'Y' || response == 'y')
       {
           my_table.display_all();
       }
    
    } while (again());

 






    return 0;
}

//This is an again function
bool again()
{
    char again = 'x';

    while(!(again == 'Y' || again == 'y' || again == 'n' || again == 'N'))
    {
        cout << "Would you like to go again? " << endl;
        cin >> again;
        cin.ignore(100, '\n');
    }
    if(again == 'Y' || again == 'y')
        return true;
    else
        return false;



}
