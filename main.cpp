//============================================================================
// Name : Searching.cpp
// Author : Mahima
// Version :
// Copyright : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include "arrayList.h"
#include "linkedlist.h"
 #include "sortedArrayList.h"
using namespace std;
int main() {
unsigned int choice = 0;
arrayList<int> arrL;
arrL.insertEnd(1);
arrL.insertEnd(2);
arrL.insertEnd(3);
arrL.insertEnd(4);
arrL.insertEnd(5);
linkedlist<int> ll;
ll.insertEnd(1);
ll.insertEnd(4);
ll.insertEnd(5);
ll.insertEnd(3);
ll.insertEnd(2);
sortedArrList<int> sl;
sl.insert(5);
sl.insert(4);
sl.insert(3);
sl.insert(2);
sl.insert(1);
sl.print();
// cout<<sl.listSize()<<endl;
do {
cout << "Choose your search type:" << endl;
cout << "1. Arrays: Sequential Search without recursion" << endl;
cout << "2. Arrays: Sequential Search with recursion" << endl;
cout << "3. Ordered Arrays: Binary Search without recursion" << endl;
cout << "4. Ordered Arrays: Binary Search with recursion" << endl;
cout << "5. Linked List: Search without recursion" << endl;
cout << "6. Linked List: Search with recursion" << endl;
cout << "Enter 0 to exit" << endl;
cout << "Your choice: ";
cin >> choice;
/**************************** 
* TODO: Implement what you will do with the choice.
*****************************/
//Going to be really cool and use a switch statement
switch (choice)
{
case  1:
    cout << "Enter elem to search for an array list w/o recursion: "<<endl;
    int elem;
    cin>>elem;
    cout<<arrL.seqSearchIter(elem);
    break;
case 2:
     cout << "Enter elem to search in an array list w/ recursion: "<<endl;
    // int elem;
    cin>>elem;
    cout<<arrL.seqSearchRec(elem, 0);
    break;
case 3:
    cout << "Enter elem to use binary search on in a sorted array list w/o recursion: "<<endl;
    cin>>elem;
    cout<<sl.binarySearchIter(elem);
    break;
case 4:
    cout << "Enter elem to use binary search on in a sorted array list w recursion: "<<endl;
    cin>>elem;
    cout<<sl.binarySearchRec(elem);
    break;
case 5:
cout << "Enter elem to search in a linked list for w/o recursion: "<<endl;
    cin>>elem;
    if(ll.seqSearchIter(elem)){
        cout<<elem<<" was found in the linked list"<<endl;
    }
    else{
        cout<<elem<<" was not found"<<endl;
    }
    break;
case 6:
    cout << "Enter elem to search in a linked list for w/o recursion: "<<endl;
    cin>>elem;
    if(ll.seqSearchRec(elem)){
        cout<<elem<<" was found in the linked list"<<endl;
    }
     else{
        cout<<elem<<" was not found"<<endl;
    }
    break;
default:
    break;
}
cout<<"\nSpecify the element to be searched for: ";
} while(choice!=0);
return 0;
}