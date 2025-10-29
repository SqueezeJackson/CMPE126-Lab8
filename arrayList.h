#include <iostream>
using namespace std; //Opted for 4 functions with a template and dynamic memory

template <typename T> class arrayList{
    private:
        T* list; // Dynamic array base
        int size;
    public:
        arrayList(){ //default constructor
            size = 0;
            list = new T[size];
        }
        int seqSearchIter (T element){
            for(unsigned int i = 0; i<size; i++){
                if(list[i]==element){
                    return i;
                }
            }
            throw "itemNotFound";
        }
        int seqSearchRec(T element, unsigned int idx = 0){
            if(idx>=size){
                throw "itemNotFound";
                return 0;
            }
            if(list[idx]!=element){
                return seqSearchRec(element, idx+1);
            }
            return idx;
        }
        bool isEmpty(){ //checks if size is = 0
            if(size==0){
                return true;
            }
            return false;
        }
        bool isFull(){ //Using dynamic memory but still added this funciton
            cout<<"Using dynamic memory so array is always \"full\" but size is size is currently: "<<size<<endl;
            return true;
        }
        int listSize(){ //return size
            return size;
        }
        int maxListSize(){ //returns max size, exact same as size
            return size;
        }
        void print(){ //Basic print function
            for(int i = 0; i<size;i++){
                cout<<list[i]<<endl;
            }
            return;
        }
        bool isItemAtEqual(int pos, T element){ //Checks bounds then returns true of item is == to parameter at pos passed in
        if(pos<size&&pos>=0){
        if(list[pos]==element){
            return true;
        }
        return false;
        }
        else{
            cout<<"Error, pos out of bounds\nExiting now"<<endl;
            exit(1);
        }

        }
        bool insertEnd(T element){ //copies over old vals into a temp dynamic array and then adds 1 to size and deletes old list, also checks bounds
            T* temp = new T [size+1];
            for(int i = 0; i<size;i++){
                temp[i] = list[i];
            }
            temp[size] = element;
            delete list;
            list = temp;
            size++;
	    return true;
        }
        T retreiveAt(int pos){ //Returns val at pos if it is in bounds
            if(pos<size&&pos>=0){
                return list[pos];
            }
            else{
                cout<<"Error, pos out of bounds\nExiting now"<<endl;
                exit(1);
            }
	    return false;
        }
        void clearList(){ //deletes list values and sets size = 0 to support new append operations
            delete[] list;
            size = 0;
            return;
        }
        bool removeAt(int pos){ //remove at function that decrements size by one by creating and copying over old vals in a temp list
            if(pos>=0&&pos<size){
                T* temp = new T[size-1]; //temp arr 1 element smaller
                int i = 0;
                bool cont = false; //extra logic to support while loop
                while(i<size){ 
                    if(i!=pos||!cont){ //if regular, add and continue
                        temp[i] = list[i];
                        i++;
                        continue;
                    }
                    else{ //else dont increment I but change cont to true
                        cont = true;
                        continue;
                    }
                }
                delete[] list;
                list = temp;
                size--; //actual decrement of size
                return true;
            }
            else{
                cout<<"Error, pos out of bounds\nExiting now"<<endl;
                exit(1);
            }
            return false;
        }
        ~arrayList(){
            delete[] list;
        }
};
