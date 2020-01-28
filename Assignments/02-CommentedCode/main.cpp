///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Mae-Jeanne Preville
// Email:            maejeanne.t.c.preville@gmail.com
// Label:            02-A02
// Title:            Comments
// Course:           CMPS 2143
// Semester:         Spring 2020
//
// Description:
//       This program pushes, pops, and inserts items in a list. It also
//       creates new memory when needed (in push function), and makes
//       allowance to join new data (in List operator+). Additionally,
//       it prints the output.
//
// Usage:
//       how to use the program if necessary
//
// Files:            main.cpp
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

int A[100];

struct Node
{
    int x;
    Node *next;
    Node()
    {
        x = -1;
        next = NULL;
    }
    Node(int n)
    {
        x = n;
        next = NULL;
    }
};

/**
 * List
 * 
 * Description:
 *      This class implements a linked list with two nodes. 
 *
 *
 *
 * 
 * Public Methods:
 *                          List()                               
 *      void                Push(int val)
 *      void                Insert(int val)
 *      void                PrintTail()
 *      string              Print()
 *      int                 Pop()
 *      List operator+(const List &Rhs)
 *      int                 operator[]
 *      friend ostream &operator<<
 *
 * Private Methods:
 *
 *
 *Files:
 *      main.cpp                          //main program driver
 *
 */

class List
{
  private:
    Node *Head;     //head node
    Node *Tail;     //tail node
    int Size;       //size var

  public:
    List()
    {
        Head = Tail = NULL;   //initializing head and tail to null
        Size = 0;             //initializing size to 0 
    }
    
    /**
     * Public : Push
     * 
     * Description:
     *      Adds item to the end of the list
     * 
     * Params:
     *      int    :  integer values
     * 
     * Returns:
     *      Nothing
     */
    void Push(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        if (!Head && !Tail)     //if head and tail is not empty
        {
            Head = Tail = Temp; //let head = tail = temp
        }
        else
        {
            Tail->next = Temp; 
            Tail = Temp;
        }
        Size++;
    }
    
    /**
     * Public : Insert
     * 
     * Description:
     *      Inserts new item to the list
     * 
     * Params:
     *      int    :  integer values
     * 
     * Returns:
     *      Nothing
     */
    void Insert(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail)
        {
            Tail = Head;
        }
        Size++;
    }
    
     /**
     * Public : PrintTail
     * 
     * Description:
     *      Displays the tail or end of the list
     * 
     * Params:
     *      
     * 
     * Returns:
     *      Nothing
     */
    void PrintTail()
    {
        cout << Tail->x << endl;
    }
    
     /**
     * Public : Print
     * 
     * Description:
     *      Displays items in list
     * 
     * Params:
     *     
     * 
     * Returns:
     *      string  :   list 
     */
    string Print()
    {
        Node *Temp = Head;
        string list;

        while (Temp != NULL)
        {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }
    
     /**
     * Public : Pop
     * 
     * Description:
     *      Removes an item from the list
     * 
     * Params:
     *      
     * 
     * Returns:
     *      int :   0
     */
    // not implemented 
    int Pop()
    {
        Size--;
        return 0; //
    }
    
     /**
     * Public : List
     * 
     * Description:
     *      Creates a new list that will be added to original list
     * 
     * Params:
     *      const    :  list
     * 
     * Returns:
     *      NewList 
     */
    List operator+(const List &Rhs)
    {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

     /**
     * Public : operator[]
     * 
     * Description:
     *      This function returns an int value
     *      as if the list were an array.
     * 
     * Params:
     *      int    :  index
     * 
     * Returns:
     *      integer
     */
    
    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
    int operator[](int index)
    {
        Node *Temp = Head;

        if (index >= Size)
        {
            cout << "Index out of bounds, exiting";
            exit(0);
        }
        else
        {

            for (int i = 0; i < index; i++)
            {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }
    
     /**
     * Public : friend ostream &operator
     * 
     * Description:
     *     Calls print function and returns value
     * 
     * Params:
     *      int    :  integer values
     * 
     * Returns:
     *      os
     */
    friend ostream &operator<<(ostream &os, List L) //ability to access private data
    {
        os << L.Print();
        return os;
    }
};

/**
*
* Main program
*
*/
int main(int argc, char **argv)
{
    List L1;
    List L2;

    for (int i = 0; i < 25; i++)
    {
        L1.Push(i);
    }

    for (int i = 50; i < 100; i++)
    {
        L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail();
    L2.PrintTail();

    List L3 = L1 + L2;
    cout << L3 << endl;

    cout << L3[5] << endl;
    return 0;
}

