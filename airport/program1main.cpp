//Ammar Mohamamd Khan
//CS 163 Program 1
//This is the main file
//for the program. It handles 
//ineraction between user and ADT. 

#include "program1.h"

bool again();

int main()
{
   travel_info  info;   //an object of travel info, used for reading from the file.  
   list my_list;    //an object of the list class
   admin_node admin; //an object of admin node
   dest_node dest1; //an object of the destination node
   int size = 2;
   itinerary my_itn(size); //itinerary
   //These variables are all temporaries used for transferring data.
   int a_custom = 0;
   int f_type = 0;
   int is_cust = 0;
   int is_imm = 0;
   int is_TSA = 0;
   int hours_a = 0;
   int min_a = 0;
   int hours_d = 0;
   int min_d = 0;
   char city_a[15];
   char response;
   cout << "Welcome User!" << endl;
   cout << "This is a search engine for flights." << endl;
   cout << "This will help you determine the time " << endl;
   cout << "spent at the airport for various flights. " << endl;
   if(!my_list.load_file(info))
   {
       cout << "Error, flight information not loaded! " << endl;
   }
    do
    {    
        do
        {
            cout << "Select the number of customs you are searching for " << endl;
            cout << "your flight: " << endl;
            cin >> a_custom;
            cin.ignore(100, '\n');
            if(!my_list.search(a_custom))
            {
                cout << "An item with the entered amount of customs does not exist!" << endl;
            }
            else 
            {
                cout <<"Item found! " << endl;
            }
        }while(again());

            cout << "Would you like to look at all the timings for the flights?(Y/N) " << endl;
            cin >> response;
            cin.ignore(100, '\n');
            if(response == 'Y' || response == 'y')
            {
                if(!my_list.displayLLL())
                {
                    cout << "Error. There are no timings to display! " << endl;
                }
            }
    }while(again()); 
   do
    {
        cout << "You will now be prompted to enter flight informaton. " << endl;
        cout << "Is the flight type international? (Y/N)" << endl;
        cin >> response;
        cin.ignore(100, '\n');
            if(response == 'Y' || response == 'y')
            {
                f_type = 1;  
            }
        cout << "Do customs apply? (Y/N)" << endl;
        cin >> response;
        cin.ignore(100, '\n');
            if(response == 'Y' || response == 'y')
               is_cust = 1;  
            else
            {
                is_cust = 0;
            }
        cout << "Does immigration apply? (Y/N)" << endl;
        cin >> response;
        cin.ignore(100, '\n');
            if(response == 'Y' || response == 'y')
               is_imm = 1;  
            else
            {
                is_imm = 0;
            }
        cout << "Does the travel have preTSA approval for fast pass? (Y/N)" << endl;
        cin >> response;
        cin.ignore(100, '\n');
            if(response == 'Y' || response == 'y')
               is_TSA = 1;  
            else
            {
                is_TSA = 0;
            }
            admin.create(f_type, is_cust, is_imm, is_TSA); //this transfers data from the temps, to an admin node
            cout << "Enter the departure hours: " << endl;
            cin >> hours_d;
            cin.ignore(100, '\n');
            cout << "Enter the departure minutes: " << endl;
            cin >> min_d;
            cin.ignore(100, '\n');
            cout << "Departure time: " << hours_d << ":" << min_d << endl;
            cout << "Enter the arrival hours: " << endl;
            cin >> hours_a;
            cin.ignore(100, '\n');
            cout << "Enter the arrival minutes: " << endl;
            cin >> min_a;
            cin.ignore(100, '\n');
            cout << "Arrival time: " << hours_a << ":" << min_a << endl;
            cout << "Enter the name of the city: " << endl;
            cin.get(city_a, 15, '\n');
            cin.ignore(100, '\n');
            dest1.create_dest(hours_d,min_d, hours_a, min_a, city_a); //this transfers data from temps, to dest node
            my_itn.build(admin, dest1); //This function builds the list
    
            cout << "Would you like to look at the flight route?(Y/N) " << endl;
            cin >> response;
            cin.ignore(100, '\n');
            if(response == 'Y' || response == 'y')
            {
                if(!my_itn.display_route()) //This displays the specific route
                {
                    cout << "Error. There is no route to display! " << endl;
                }
            }
        }while(again());
    return 0;

}



//Implementation of again function 
//It asks the user if they want to go again.
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
