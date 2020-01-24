//Ammar Mohammad Khan
//CS 163 Program 1
//Function implementation file. 
//This file contains all the implementations 
//of the functions for the ADT.
#include "program1.h"

//display function for the underlying data
int travel_info::display()
{
    cout << "Total number of customs: " << customs << endl;
    cout << "Total time required for customs: " << total_customs << endl;
    cout << "Total number of immigration checkpoints: " << immigration << endl;
    cout << "Total time required for immigration checkpoints: " << total_imm << endl;
    cout << "Total number of security checks: " << security_check << endl;
    cout << "Total time required for security checks: " << total_security << endl;
    cout << "Total time required for travelling between gates: " << gate_time << endl;
    
}



//Copy function that will be used in the 
//insert function.This function copies
//the values from the temporary object,
//into the actual object.
int travel_info::copy(travel_info & info)
{
    customs = info.customs;
    total_customs = info.total_customs;
    immigration = info.immigration;
    total_imm = info.total_imm;
    security_check = info.security_check;
    total_security = info.total_security;
    gate_time = info.gate_time;
    return 1;
}



//Constructor for the LLL class,
//that initializes the pointers to NULL.
list::list()
{
    head = NULL;
}



//Destructor for the LLL class,
//will automatically called at the end
//for deallocating memory.
list::~list()
{
   if(head)
   {
       node * temp = head;
       while(head->next != NULL)//traverses with temp
       {
           temp = temp->next;   //deletes what's behind
           delete head;
           head = temp;
       }
       delete head;
       head = NULL;
   }
}



//This function is used to read in the
//information from the file.
int list::load_file(travel_info & info)
{
    ifstream fileIn;
    fileIn.open("airport.txt", ios::in);

    if(fileIn)
    {
        fileIn.peek();
        do{                         //Reads in info one at a time
            fileIn >> info.customs;
            fileIn.ignore(100, ':');
            fileIn >> info.total_customs;
            fileIn.ignore(100, ':');
            fileIn >> info.immigration;
            fileIn.ignore(100, ':');
            fileIn >> info.total_imm;
            fileIn.ignore(100, ':');
            fileIn >> info.security_check;
            fileIn.ignore(100, ':');
            fileIn >> info.total_security;
            fileIn.ignore(100, ':');
            fileIn >> info.gate_time;
            fileIn.ignore(100, '\n');
            fileIn.peek();
            insert(info);   //inserts into the LLL
        }while(!fileIn.eof());
        
        fileIn.close();
    }
    return 1;
}



//Insert function for inserting into the
//LLL. This function takes the temporary
//object and builds the LLL.
int list::insert(travel_info & info)
{
    if(!head)   //Checks for empty list, then creates new node
    {
        head = new node;
        head->data.copy(info);
        head->next = NULL;
    }
    else
    {
        node * current = head;
        while(current->next != NULL)   //Traverses through the list 
        {
            current = current->next;
        }
        current->next = new node;   //inserts at the end of the LLL
        current = current->next;
        current->data.copy(info);
        current->next = NULL; 
    }
    return 1;
}



//This function takes in an input 
//from the user, and then traverses
//through the list, and returns a 1
//if found, otherwise a 0.
int list::search(int a_custom)
{
    int found = 0;
    if(!head)
        return 0;
    node * current = head;
    while(current->next != NULL)    //Traverses through the list
    {
        if(a_custom == current->data.customs)  //Compares the data 
        {
            found = 1;
        }
        current = current->next;
    }
    return found;
}



//This is a display function for
//the LLL.
int list::displayLLL()
{
    if(!head)
        return 0;
    node * current = head;
    while(current != NULL)
    {
        current->data.display();
        current =current->next;
    }
    return 1;
}



//This function takes temps, and stores data in its
//appropriate data members.
int admin_node::create(int f_type, int is_cust, int is_imm, int is_TSA)
{
   flight_type = f_type;
   is_custom = is_cust;
   is_imm = is_imm;
   TSA_approval = is_TSA;

   return 1;
}



//Copy function used to copy the data from an admin
//object to the data members of the admin node.
int admin_node::copy_admin(admin_node & to_copy)
{
    flight_type = to_copy.flight_type;
    is_custom = to_copy.is_custom;
    is_imm = to_copy.is_imm;
    TSA_approval = to_copy.TSA_approval;

    return 1;
}



//This displays the adminisitrative information
//for the data in the admin node.
int admin_node::display_admin()
{
    if(flight_type > 0)
        cout << "Flight is International. " << endl;
    else 
        cout << "Flight is Domestic. " << endl;
    if(is_custom > 0)
        cout << "Customs apply. " << endl;
    else 
        cout << "Customs do not apply. " << endl;
    if(is_imm > 0)
        cout << "Immigration applies. " << endl;
    else 
        cout << "Immigration does not apply. " << endl;
    if(TSA_approval > 0)
        cout << "Travel has been approved for fast pass. " << endl;
    else 
    {
        cout << "Travel has not been approved for fast pass. " << endl;
    }

    return 1; 
}



//This function takes temps, and stores data in appropriate data
//members for the destination information.
int dest_node::create_dest(int hours_d, int min_d, int hours_a, int min_a, char city_a[])
{
    hours_d = departure_h;
    min_d = departure_m;
    hours_a = arrival_h;
    min_a = arrival_m;
    city = new char[strlen(city_a)+1];
    strcpy(city, city_a);
    return 1;
}



//This function copies from an object of the data,
//to it's respective data members. 
int dest_node::copy_dest(dest_node & to_add)
{
    departure_h = to_add.departure_h;
    departure_m = to_add.departure_m;
    arrival_h = to_add.arrival_h;
    arrival_m = to_add.arrival_m;
    city = new char[strlen(to_add.city)+1];
    strcpy(city, to_add.city);
    return 1;
}



//Function to display the information for the destination.
int dest_node::display_dest()
{
    cout << "Departure time: " << departure_h << ":" << departure_m << endl;
    cout << "Arrival time: " << arrival_h << ":" << arrival_m << endl;
    cout << "City: " << city << endl;
    return 1;
}



//Constructor for the itinerary
//It has a for loop that goes through
//the list and sets all next pointers
//to NULL. It also passes in the MAX
//size for the array.
itinerary::itinerary(const int MAX)
{
    flights = new admin_node[MAX];
    for(int i = 0; i < MAX; ++i)
    {
        flights[i].next = NULL;
    }
}



//Destructor  for the itinerary
itinerary::~itinerary()
{
    for(int i = 0; i < MAX; ++i)
    {
       if(flights[i].next)
       {
           dest_node * & head = flights[i].next;
           remove(head);
       }
    }
    delete [] flights;
}



//Remove function to delete dynamic memory
int itinerary::remove(dest_node * & head)
{
    if(!head)
        return 0;
    remove(head->next);
    delete [] head->city;
    delete head;
    head = NULL;
    
}


//This builds the array of LLL.
//It has a for loop that goes through the array,
//then uses a while loop to traverse through each LLL
//in each element of the array.
int itinerary::build(admin_node & to_copy, dest_node & to_add)
{
    for(int i = 0; i < MAX; ++i)
    {
        flights[i].copy_admin(to_copy);
        if(!flights[i].next)
        {
            flights[i].next = new dest_node;
            flights[i].next->copy_dest(to_add);
            flights[i].next->next = NULL;
        }
        else
        {
            dest_node * current = flights[i].next;
            while(current->next != NULL)
            {
                current = current->next;
            }
                current->next = new dest_node;
                current = current->next;
                current->copy_dest(to_add);
                current->next = NULL;
        }
    }
    return 1;
}



//Displays the LLL.
//Has a for loop that goes through the array,
//and inside it a while loop that goes through
//the LLL to display.
int itinerary::display_route()
{
    for(int i = 0; i < MAX; ++i)
    {
        if(!flights[i].next)
            return 0;
        flights[i].display_admin();
        dest_node * current = flights[i].next;
        while(current != NULL)
        {
            current->display_dest();
            current =current->next;
        }
    }
    return 1;
}
