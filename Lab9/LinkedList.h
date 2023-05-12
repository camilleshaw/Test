
#include "LinkedListInterface.h"
#include <sstream>
#include <string>

template <class T>
class LinkedList : public LinkedListInterface<T>
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(const T &the_data, Node *next_val = NULL) : data(the_data)
        {
            next = next_val;
        }
    };

    Node *mylist;
    int num_items;

public:
    LinkedList(void)
    {
        mylist = NULL;
        num_items = 0;
    };
    ~LinkedList(void)
    {
        clear();
    };

    /*
    insertHead

    A node with the given value should be inserted at the beginning of the list.

    Do not allow duplicate values in the list.
    */
    void insertHead(T value)
    {
        for (Node *ptr = mylist; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->data == value)
                return;
        }
        if (mylist == NULL)
        {
            mylist = new Node(value);
            mylist->next = NULL;
            return;
        }
        else if (mylist->data == value)
            return;
        else
        {
            Node *ptr = mylist;
            mylist = new Node(value);
            mylist->next = ptr;
            // delete ptr;
        }
        // Node *ptr = mylist;
        // mylist = new Node(value);
        // mylist->next = ptr;
    }

    /*
    insertTail

    A node with the given value should be inserted at the end of the list.

    Do not allow duplicate values in the list.
    */
    void insertTail(T value)
    {
        Node *ptr = mylist;
        if (ptr == NULL)
        {
            mylist = new Node(value);
            mylist->next = NULL;
            return;
        }
        else if (ptr->data == value)
            return;
        else
        {
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
                if (ptr->data == value)
                    return;
            }
            ptr->next = new Node(value);
        }
        // while (ptr->next != NULL)
        // {
        //     ptr = ptr->next;
        //     if (ptr->data == value)
        //         return;
        // }
        // ptr->next = new Node(value);
    }

    /*
    insertAfter

    A node with the given value should be inserted immediately after the
    node whose value is equal to insertionNode.

    A node should only be added if the node whose value is equal to
    insertionNode is in the list. Do not allow duplicate values in the list.
    */
    void insertAfter(T value, T insertionNode)
    {
        for (Node *ptr = mylist; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->data == value)
                return;
        }
        Node *ptr = mylist;
        while (ptr != NULL)
        {
            if (ptr->data == value)
                return;
            else if (ptr->data == insertionNode)
            {
                Node *temp = ptr->next;
                ptr->next = new Node(value);
                ptr->next->next = temp;
                return;
            }
            ptr = ptr->next;
        }
    }

    /*
    remove

    The node with the given value should be removed from the list.

    The list may or may not include a node with the given value.
    */
    void remove(T value)
    {
        if (mylist == NULL)
            return;
        else if (mylist->data == value)
        {
            Node *temp = mylist;
            mylist = mylist->next;
            // temp = NULL;
            delete temp;
            return;
        }
        else
        {
            Node *ptr = mylist;
            Node *prev = NULL;
            while (ptr != NULL)
            {
                if (ptr->data == value)
                {
                    prev->next = ptr->next;
                    // ptr = NULL;
                    delete ptr;
                    return;
                }
                prev = ptr;
                ptr = ptr->next;
            }
        }
        // Node *ptr = mylist;
        // Node *prev = NULL;
        // while (ptr != NULL)
        // {
        //     if (ptr->data == value)
        //     {
        //         if (prev == NULL)
        //         {
        //             mylist = ptr->next;
        //         }
        //         else
        //         {
        //             prev->next = ptr->next;
        //         }
        //         delete ptr;
        //         return;
        //     }
        //     prev = ptr;
        //     ptr = ptr->next;
        // }
    }

    /*
    clear

    Remove all nodes from the list.
    */
    void clear()
    {
        Node *ptr = mylist;
        Node *prev = NULL;
        while (ptr != NULL)
        {
            prev = ptr;
            ptr = ptr->next;
            // prev = NULL;
            delete prev;
        }
        mylist = NULL;
    }

    /*
    at

    Returns the value of the node at the given index. The list begins at
    index 0.

    If the given index is out of range of the list, throw an out of range exception.
    */
    T at(int index)
    {
        Node *ptr = mylist;
        for (int i = 0; i < index + 1; i++)
        {
            if (ptr == NULL)
                throw out_of_range("index");
            else if (i == index)
                return ptr->data;
            else
                ptr = ptr->next;
        }
        throw out_of_range("index");
    }

    /*
    size

    Returns the number of nodes in the list.
    */
    int size()
    {
        Node *ptr = mylist;
        int count = 0;
        while (ptr != NULL)
        {
            count++;
            ptr = ptr->next;
        }
        return count;
    }

    /*
    toString

    Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
    There should be no trailing space at the end of the string

    For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
    "1 2 3 4 5"
    */
    string toString()
    {
        stringstream ss;
        if (mylist == NULL)
            return "";
        for (Node *ptr = mylist; ptr != NULL; ptr = ptr->next)
        {
            ss << ptr->data;
            if (ptr->next != NULL)
            {
                ss << " ";
            }
        }
        return ss.str();
    }
};