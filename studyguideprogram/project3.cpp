//Ammar Khan
//Program 3
//Function implementation
//file. This contains the constructors
//and destructors for the ADT.

#include "project3.h"


//This function will initialize
//the variables for the book info 
//struct to 0 or their null equivalents.
int book_info::set_info()
{
    title = NULL;
    notes = NULL;
    chapter = 0;
    page = 0;
    extra_study = 0;
    return 1;
}



//This is a display function
//for the book info struct.
int book_info::display_info()
{
    cout << "The title of this chapter is: " << title << endl;
    cout << "The notes for this chapter include: " << notes << endl;
    cout << "The chapter number is: " << chapter << endl;
    cout << "The page number is: " << page << endl;
    if(extra_study == 1)
    {
        cout << "Extra study needs to be done for this section! " << endl;
    }
    else
    {
        cout << "There is no need for extra study to be done. " << endl;
    }

    return 1;
}



//This is a create function for
//the underlying data.It takes in
//temps and copies them to the 
//respective data members of the struct.
int book_info::create_info(char a_title[], char a_notes [], int a_chapter, int a_page, int extra)
{

    if(title)
    {
        delete [] title;
        title = NULL;
    }
    if(notes)
    {
        delete [] notes;
        notes = NULL;
    }
    if(!title)
    {
        title = new char[strlen(a_title)+1];
        strcpy(title, a_title);
    }
    if(!notes)
    {
        notes = new char[strlen(a_notes)+1];
        strcpy(notes, a_notes);
    }
    chapter = a_chapter;
    page = a_page;
    extra_study = extra; 

    return 1;
}



//This is a copy function that takes
//in an object of book info, and copies
//it's data members to the data members of
//book info.
int book_info::copy_info(book_info & a_book)
{
    title = new char[strlen(a_book.title) + 1];
    strcpy(title, a_book.title);

    notes = new char[strlen(a_book.notes) + 1];
    strcpy(notes, a_book.notes);

    chapter = a_book.chapter;
    page = a_book.page;
    extra_study = a_book.extra_study;

    return 1;
}



//This function updates the notes
//of the current chapter.
int book_info::update_notes(char edited[])
{
    if(notes)
    {
        delete [] notes;
        notes = NULL;
    }
    notes = new char[strlen(edited) + 1];
    strcpy(notes, edited);

    return 1;
}



//This is a remove function for the
//underlying data. It deletes the dynamic
//memory.
int book_info::remove_info()
{
    if(title)
    {
        delete [] title;
        title = NULL;
    }
    if(notes)
    {
        delete [] notes;
        notes = NULL;
    }
    return 1;
}


//This is the constructor for
//the hash table.
table::table(int size)
{
    if(size < 1)
    {
        size = 7;
    }
        hash_table_size = size;
        hash_table = new node*[hash_table_size];
        
        for (int i = 0; i < hash_table_size; ++i)
        {
            hash_table[i] = NULL;
        }


        hash_table2 = new node2*[hash_table_size];
        for (int i = 0; i < hash_table_size; ++i)
        {
            hash_table2[i] = NULL;
        }
}



//This is the destructor for
//the hash table.It deletes
//the hash table with the data,
//and it also deletes the
//pointers to the data.
table::~table()
{
    for(int i = 0; i < hash_table_size; ++i)
        {
            removal(hash_table2[i]);
        }
    delete [] hash_table2;
    hash_table2 = NULL;

    for(int i = 0; i < hash_table_size; ++i)
        {
           remove_all(hash_table[i]); 
        }
    delete [] hash_table;
    hash_table = NULL;

}



//This is a recursive remove
//for the hash table of pointers.
int table::removal(node2 * & head2)
{
    if(!head2)
        return 0;
    removal(head2->next);
    head2->info = NULL;
    delete head2;
    head2 = NULL;
    return 1;
    
}



//This is a recursive removal
//functon called in the 
//destructor.
int table::remove_all(node * & head)
{
    if(!head)
        return 0;
    remove_all(head->next);
    head->info.remove_info();
    delete head;
    head = NULL;
    return 1;
}


//This is a function to load
//the information from the file
//and store it into a book_info 
//struct, and then insert into
//the hash table.
int table::load_file(book_info & a_book)
{
    ifstream fileIn;
    fileIn.open("studyguide.txt", ios::in);
   
    if(fileIn)
    {
        fileIn.peek();
        do{
            char a_title[100];
            char a_notes[100];
            int a_chapter = 0;
            int a_page = 0;
            int extra = 0;
 
            fileIn.get(a_title, 100, ':');
            fileIn.ignore(100, ':');
            fileIn.get(a_notes, 100, ':');
            fileIn.ignore(100, ':');
            fileIn >> a_chapter;
            fileIn.ignore(100, ':');

            fileIn >> a_page;
            fileIn.ignore(100, ':');

            fileIn >> extra;
            fileIn.ignore(100, '\n');

            if(!a_book.title)
            {
                a_book.title = new char[strlen(a_title)+1];
                strcpy(a_book.title, a_title);
            }
            if(!a_book.notes)
            {
                a_book.notes = new char[strlen(a_notes)+1];
                strcpy(a_book.notes, a_notes);
            }
            a_book.chapter = a_chapter;
            a_book.page = a_page;
            a_book.extra_study = extra; 
            insert_file(a_book.title,a_book); 
            a_book.remove_info();
        }while(fileIn.peek() != EOF);
        fileIn.close();
    }
    return 1;
}



//This is a function that builds the 
//hash table. It takes an object of 
//book info, and inserts it into the list.
int table::insert_file(char * key, book_info & to_add)
{
    int hash_value = hash_func(key);
    if(hash_value < 0)
        return 0;
    if(hash_value > 0)
    {
        node * current = hash_table[hash_value];
        node * temp = new node;
        temp->info.copy_info(to_add);
        temp->next = current;
        hash_table[hash_value] = temp;

    }
    int hash_value2 = hash_func2(to_add.chapter);
    if(hash_value2 < 0)
        return 0;
    if(hash_value2 > 0)
    {
       node2 * current2 = hash_table2[hash_value2];
       node2 * temp2 = new node2;
       temp2->info = find(hash_table[hash_value], to_add);
       temp2->next = current2;
       hash_table2[hash_value2] = temp2;
    }
    return 1;
}



//This is a recursive find function to find the data
//and set a pointer in the second array of LLL to
//that data by chapter.
book_info* table::find(node * head, book_info & to_add)
{
    if(!head)
        return 0;
    if(strcmp(head->info.title, to_add.title) == 0)
    {
        return & head->info;
    }
    return find(head->next, to_add);
}



//This is a retrieve function, that finds
//the selected item, and then returns the 
//data back to the calling routine.
int table::retrieve(char * to_find, book_info to_copy)const
{
   
    int hash_value = hash_func(to_find);
    if(hash_value < 0)
        return 0;
    if(hash_value > 0)
    {
        node * current = hash_table[hash_value];
        while(current != NULL)
        {
            if(strcmp(hash_table[hash_value]->info.title, to_find) == 0)   
            {
                to_copy.remove_info();
                to_copy.copy_info(hash_table[hash_value]->info);
                return 1;
            }
            current = current -> next;
        }

    }
}



//This is a remove function in order to
//remove a certain item in the hash table.
int table::remove(char * to_remove)
{
   
    int hash_value = hash_func(to_remove);
    if(hash_value < 0)
        return 0;
    if(hash_value > 0)
    {

        if(strcmp(hash_table[hash_value]->info.title, to_remove) != 0)
        return 0;
        remove_match(hash_table[hash_value], to_remove);
        return 1;
       

    }
}




//This is a recursive remove for the 
//item found.
int table::remove_match(node * & head, char * & to_remove)
{
    if(!head)
        return 0;
    if(strcmp(head->info.title, to_remove) == 0)
    {
        node * temp = head->next;
        head->info.remove_info();
        delete head;
        head = temp;
        return 1;
    }
    
    return remove_match(head->next, to_remove);
}



//This function edits the notes
//for a particular chapter.
int table::edit(char * to_edit, char updated[])
{
    int hash_value = hash_func(to_edit);
    if(hash_value < 0)
        return 0;
    if(hash_value > 0)
    {
        if(strcmp(hash_table[hash_value]->info.title, to_edit) != 0)
            return 0;

        node * current = hash_table[hash_value];
        while(current != NULL)
        {
            if(strcmp(hash_table[hash_value]->info.title, to_edit) == 0)
            {
               hash_table[hash_value]->info.update_notes(updated);
               return 1;
            }
            current = current -> next; 
        }
    
    }

}



//This is the hash function, it adds
//all the letters of the key value 
//together.
int table::hash_func(char * key_value)const
{
    int value = 0;
    if(!key_value)
        return -1;
    for(int i= 0; i < strlen(key_value); ++i)
    {
        value += key_value[i];
    }
    return value % hash_table_size;

}



//This is the second hash function.Used for
//hashing teh chapter
int table::hash_func2(int key_value)const
{
    int numb = 0;
    if(!key_value)
        return -1;
    numb = key_value % hash_table_size;
    return numb;

}



//This function displays all the items
//in the hash table.
int table::display_all()
{

   for(int i = 0; i < hash_table_size; ++i)
   {
       disp_all(hash_table[i]);
   }

}



//This is a recursive display
//function that is called by 
//the display all.
int table::disp_all(node * head)
{
    if(!head)
        return 0;
    head->info.display_info();
    disp_all(head->next);
    return 1;
}



//This is a display function
//by chapter. It displays the
//keyword that corresponds
//to that chapter.
int table::display_chapter(int chapter)
{
   int value = hash_func2(chapter);
   if(value < 0)
       return 0;

   if(value > 0)
   {
       display(hash_table2[value], chapter);
       return 1;
   }


}


int table::display(node2 * head, int chapter)
{
    if(!head)
        return 0;
    if(chapter == head->info->chapter)
    {    
    cout << "The title for this chapter is: " << head->info->title << endl;
    return 1;
    }
    return display(head->next, chapter);
    
}
