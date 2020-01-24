//Ammar Mohammad Khan
//CS 163 Program 1, Header File
//This file contains the classes for the ADTs, and
//structs for the underlying data.Thie first ADT is a
//LLL for travel times for a flight, while the second
//ADT is an array of LLL that handles the itinerary.

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;

const int MAX = 2;
//Structs and classes for the 1st Data Structure.
//This is a struct for the underlying data.
struct travel_info
{
    int customs;    //an int for the number of customs
    int total_customs;  //an int for the total time customs will take
    int immigration;    // an int for the number of immigration
    int total_imm;  //an int for the total time immigration will take
    int security_check; //an int for the number of security checks
    int total_security; //an int for the total time for security checks
    int gate_time;   //an int for the total time for travelling between gates
    int copy(travel_info &);    //Used to copy info from the object    
    int display(); //displays the underlying data
};
//This is a struct for the node for the LLL.
struct node
{
    node * next;    //A next pointer for the next node.
    travel_info data;   //An object of the travel information.

};
//This is a class that implements the LLL ADT.
//It will be the list that keeps track of the time 
//that requires to be processed at each of the major 
//airports. 
class list
{
    public:
    list();
    ~list();
    int load_file(travel_info &); //this function reads from the file
    int insert(travel_info &); //this function inserts into the LLL
    int search(int a_custom); //This function traverses through the list, and compares the argument
    int displayLLL(); //This function traverses through the LLL, and displays all items.
    private:
    node * head;    //head pointer for the beginning of the list.

};
//Structs and classes for the second data structure.

//Destiiation node, this contains the individual destinitation
//for a specific flight.
struct dest_node
{
    dest_node * next;
    int arrival_h;
    float arrival_m;
    int departure_h;
    float departure_m;
    char * city;
    int create_dest(int, int, int, int, char *);
    int copy_dest(dest_node &);
    int display_dest();

};
//Admin node that contains the information regarding whether
//a flight is international or not and other administrative info.
struct admin_node
{
    dest_node * next;  //has a next pointer to a destination node
    int flight_type;
    int is_custom;
    int is_imm;
    int TSA_approval;
    int create(int, int, int, int);
    int display_admin();
    int copy_admin(admin_node &);

};
//This is the itinerary class, it is the implementation of the
//Array of LLL.
class itinerary 
{
    public:
        itinerary(); //default constructor
        itinerary(const int MAX = 2); //passes in MAX for the array size
        ~itinerary();
        int build(admin_node &, dest_node &); //This is used to build the Array of LLL
        int display_route();//Displays a trip

    private:
 //       admin_node flights[MAX]; //array of admin nodes with size max
         admin_node * flights;
        int remove(dest_node * &); //recursive remove function
};
