#include <iostream>

using namespace std;

template <typename T> class sortedArrList{
    private:
        T* arr;
        int size;
    public:
        sortedArrList(){
            size = 0;
            arr = new T[size];
        }
        bool isEmpty()const {
            return (size==0);
        }
        int listSize() const{
            return size;
        }
        int maxListSize const(){
            return size;
        }
        void print(){
            cout<<"Printing elements now: "<<endl;
            for(auto x: arr){
                cout<<x<<endl;
            }
        }
        bool insert(T elem){
            if(size==0){
                size++;
                arr = new T [size];
                arr[0] = elem;
                return true;
            }
            else{
                size++;
                T* temp = new T[size];
                bool found = false;
                int j = 0;
                for(int i = 0; i<size-1;i++){
                    if(arr[i]<elem||found){
                        temp[j++] = arr[i];
                    }
                    else{
                        temp[j++] = elem;
                        found = true;
                    }
                }
                if(found = false){
                    temp[j] = elem;
                }
                delete[] arr;
                arr = temp;
                return true;

            }
        }

        ~sortedArrayList(){
            delete[] arr;
        }


};