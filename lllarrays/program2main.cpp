//Ammar Khan
//Program 2 Main File 
//This is where the information will be read to
//the package. Also, is where the interaciton between
//the client and the application will take place.
#include "program2.h"

bool again();


int main()
{
    cout << "Welcome to the Package delivery program! "<< endl;
    package a_package; //creates an object ob package
    q_node my_node; //creates an object of a q_node to copy the info
    stack my_stack; //object of stack
    queue my_queue; //object of queue
    //temporary variables for reading the information into
    //the package struct.
    char a_sender[MAX];
    long phone;
    char a_receiver[MAX];
    int pack_size; 
    char response;
    char recent[100];
    a_package.set_data();
    my_node.set_data();
    do
    {
            cout << "Enter your name: " << endl;
            cin.get(a_sender, MAX, '\n');
            cin.ignore(100, '\n');
            cout << "Enter the your phone number: " << endl;
            cin >> phone;
            cin.ignore(100, '\n');
            cout << "Enter the recipient's name: " << endl;
            cin.get(a_receiver, MAX, '\n');
            cin.ignore(100, '\n');
            cout << "Enter your package size(number): " << endl;
            cin >> pack_size;
            cin.ignore(100, '\n');
            a_package.create(a_sender, phone, a_receiver, pack_size); //this transfers all the temps into the package
            my_node.copy(a_receiver);
        
        cout << "Would you like to add a package?(y/n) " << endl;
        cin >> response;
        cin.ignore(100, '\n');
            if(response == 'Y' || response == 'y')
            {
                if(!my_stack.push(a_package))
                {
                    cout << "Cannot add this package! " << endl;
                }
                if(!my_queue.enqueue(my_node.recipient))
                {
                    cout << "Cannot add this package! " << endl;
                }
            }
        cout << "Would you like to look at the most recent package?(y/n) " << endl;
        cin >> response;
        cin.ignore(100, '\n');
            if(response == 'Y' || response == 'y')
            {
                if(my_stack.peek(a_package))
                {
                    a_package.display();        
                }
            }
        
    }while(again());
    do
    {
        cout << "Would you like to see the packages added?(y/n) " << endl;
        cin >> response;
        cin.ignore(100, '\n');   
        if(response == 'Y' || response == 'y')
        {
            if(!my_stack.display_all())
            {
                cout << "There are no packages to display! " << endl;
            }
        }
        cout << "Would you like to see the most recent recipient? " << endl;
        cin >> response;
        cin.ignore(100, '\n');   
        if(response == 'Y' || response == 'y')
        {
            if(my_queue.peek(recent))
            {
                cout << "Most recent recipient: " << recent << endl;
            }
        }
        cout << "Would you like to see the list of recipients? " << endl;
        cin >> response;
        cin.ignore(100, '\n');   
        if(response == 'Y' || response == 'y')
        {
            if(!my_queue.display_all())
            {
                cout <<"There are no recipients! " << endl;
            }
        }
        cout << "Would you like to send a package? " << endl;
        cin >> response;
        cin.ignore(100, '\n');   
        if(response == 'Y' || response == 'y')
        {
            if(!my_stack.pop())
            {
                cout << "There are no packages to send! " << endl;
            }
            if(!my_queue.dequeue())
            {
                cout << "There are no recipients! " << endl;
            }

        }
        cout << "Contents of remaining packages : " << endl;
        if(!my_stack.display_all())
            {
                cout << "There are no packages to display! " << endl;
            }
        cout << "The recipients remaining include: " << endl;
        if(!my_queue.display_all())
        {
            cout << "There are no recipients remaining! " << endl;
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
