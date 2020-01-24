//Ammar Khan
//Function Implementation File
//This file contains all the implementations
//for the stack class, queue class, and 
//package struct.
#include "program2.h"



//Initializer for the char pointers
//for the package.
int package::set_data()
{
    sender = NULL;
    receiver = NULL;
    return 1;
}

//This is a display function for the 
//package data.It displays all the 
//data members of the package.
int package::display()
{
    cout << "Sender name: " << sender << endl;
    cout << "Sender's number: " << sender_numb << endl;
    cout << "recipient: " << receiver << endl;
    cout << "Package size: " << package_size << endl;

    return 1;
}



//This function will be called in the destructor to 
//delete all the data in the elements of each array.
int package::remove()
{
    if(sender)
    {
        delete [] sender;
        sender = NULL;
    }
    if(receiver)
    {
        delete [] receiver;
        receiver = NULL;
    }
    return 1;
}


//A create function that takes in temps from main,
//and copies the information into the respective 
//members of the package struct.
int package::create(char a_sender[], long phone, char a_receiver[], int pack_size)
{
   
    sender = new char[strlen(a_sender) + 1];
    strcpy(sender, a_sender);

    sender_numb = phone;

    receiver = new char[strlen(a_receiver) + 1];
    strcpy(receiver, a_receiver);
    
    package_size = pack_size;
    return 1;
}



//This is a copy function that will copy 
//the information from an object of package,
//to the specific data members of the object.
int package::copy_pack(package & a_package)
{
    if(!a_package.sender || !a_package.receiver)
        return 0;
    if(sender)
    {
        delete [] sender;
    }   
    if(receiver)
    { 
        delete [] receiver;
    }
    sender = new char[strlen(a_package.sender) + 1];
    strcpy(sender, a_package.sender);

    sender_numb = a_package.sender_numb;

    receiver = new char [strlen(a_package.receiver) + 1];
    strcpy(receiver, a_package.receiver);
    
    package_size = a_package.package_size;

    return 1;
}


//Constructor for the stack class, it
//initializes the head pointer to NULL,
//and to_index to 0.
stack::stack()
{
    head = NULL;
    top_index = 0;

}


//Destructor for the stack class
stack::~stack()
{
    if(head)
        remove_all(head);
}


//Push function for the Stack class.
//This function adds a new item to
//the top of the stack.
int stack::push(package & to_add)
{
    if(!head)
    {
        head = new s_node;
        head->packages = new package[LIMIT];
        head->packages[top_index].copy_pack(to_add);
        head->next = NULL;
        ++top_index;
    }
    else if(top_index == LIMIT)
    {
        top_index = 0;
        s_node * temp = head;
        head = new s_node;
        head->packages = new package[LIMIT];
        head->packages[top_index].copy_pack(to_add);
        head->next = temp;
        temp->next = NULL;
        ++top_index;
    }
    else
    {
        head->packages[top_index].copy_pack(to_add);
        ++top_index;
    }
    return 1;
}  



//This function pops off of the top
//of the stack.
int stack::pop()
{
    if(!head)
        return 0;
    else if(top_index == 0)
    {
        s_node * temp = head->next;
        delete [] head->packages;
        delete head;
        head = temp;
        top_index = MAX - 1;
    }
    else if(!head->next && top_index == 0)
    {
        delete [] head->packages;
        delete head;
        head = NULL;
        top_index = 0;
    }
    else
    {
        -- top_index;
    }
        return 1;
}



//This function checks to see if there is 
//data at the top to copy.
int stack::peek(package & found_at_top)
{
    if(!head)
        return 0;
    if(top_index == 0 && !head->next)
        return 0;
    if(top_index == 0)
    {
        found_at_top.copy_pack(head->packages[top_index-1]);
    }
    else
        found_at_top.copy_pack(head->packages[top_index-1]);
    return 1;
}


//Display all function for the stack
//and it calls the recursive display.
int stack::display_all()
{
    if(!head)
        return 0;
    for(int i = 0; i < top_index; ++i)
    {
        head->packages[i].display();
    }
    display(head->next);
    return 1;
}


//Recursive display function used
//to display all the items of the stack.
int stack::display(s_node * & head)
{
    if(!head)
        return 0;
    for(int i = 0; i < LIMIT; ++i)
    {
        head->packages[i].display();
    }
    return display(head->next);
}


//This will be a recursive remove function that 
//will be called in the destructor to destroy
//the list.
int stack::remove_all(s_node * & head)
{
    if(!head)
        return 0;
    remove_all(head->next);
    for(int i = 0; i < LIMIT; ++i)
    {
        head->packages[i].remove();
    }
    delete head;
    head = NULL;
    return 1;
}



//This initliazes the data to it's NULL 
//equivalents.
int q_node::set_data()
{
    recipient = NULL;
    return 1;
}



//This equation deallocates memory
//for the recipient char in the q_node.
int q_node::remove()
{
    if(recipient)
    {
        delete [] recipient;
        recipient = NULL;
    }
}



//this function takes an argument from the temp
//and copies it into the struct.
int q_node::copy(char a_receiver [])
{
    if(recipient != NULL)
    {
        delete [] recipient;
        recipient = NULL;
    }
    recipient = new char[strlen(a_receiver)+ 1];
    strcpy(recipient, a_receiver); 
    return 1;
}



//This function displays the content of the queue.
int q_node::display()
{
    if(recipient == NULL)
        return 0;
    cout << "Recipient: " << recipient << endl;
    return 1;
}

//Default constructor for
//the queue.
queue::queue()
{
    rear = NULL;
}

//Destructor for the queue.
//Checks for an empty ist, checks for
//one item, then breaks the list, and calls
//recursive function to delete the list.
queue::~queue()
{
    if(rear)
    {
        if(rear->next == rear)
        {
            rear->remove();
            delete rear;
            rear = NULL;
        }
        else
        {
        q_node * head = rear->next;
        rear->next = NULL;
        remove_all(head);
        rear = NULL;
        }
    }
}



//Recursive remove_all function that destroys
//the list.
int queue::remove_all(q_node * & head)
{
    if(!head)
        return 0;
    remove_all(head->next);
    head->remove();
    delete head;
    head = NULL;
    return 1;

}


//This function builds
//the CLL, and adds to
//the end of the list.
int queue::enqueue(char * recipient)
{
    if(!rear)
    {
        rear = new q_node;
        rear->copy(recipient);
        rear->next = rear;
    }
    else 
    {
        q_node * front;
        front = rear->next;
        rear->next = new q_node;
        rear = rear->next;
        rear->copy(recipient);
        rear->next = front;
    }
    return 1;
}



//This function removes
//from the end of the CLL.
int queue::dequeue()
{
    if(!rear)
        return 0;
    if(rear->next == rear)
    {
        delete [] rear->recipient;
        delete rear;
        rear = NULL;
    }
    else
    {
        q_node * temp;
        temp = rear->next->next;
        delete []rear->next->recipient;
        delete rear->next;
        rear->next = temp;
    }
    return 1;
}



//This function traverses
//through the List and 
//displays all.
int queue::display_all()
{
    if(!rear)
        return 0;
    if(rear->next == rear)
    {
        rear->display();
    }
    else
    {
        q_node * head = rear->next;
        rear->next = NULL;
        display(head);
        rear->next = head;
    }
    return 1;

}



//This is a recursive function
//that traverses through the list
//and displays all the items.
int queue::display(q_node * head)
{
    if(!head)
        return 0;
    head->display();
    return display(head->next);

}



//This function returns the contents
//of the most recent recipient.
int queue::peek(char recent[])
{
    if(!rear)
        return 0;
    strcpy(recent,rear->recipient); 
    return 1;
}
