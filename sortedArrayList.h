#include <iostream>

using namespace std;

template <typename T> class sortedArrList{
    private:
        T* arr;
        int size;
    public:
    
        sortedArrList(){
            size = 0;
            arr = nullptr;
        }
        unsigned int binarySearchIter (T element){
            return bsiHelper(element, 0, size, arr);
        }
        int bsiHelper(T target, int low, int high, T* arr){
            while(low<=high){
                int mid = (low+high)/2;
                if(arr[mid]==target){
                    return mid;
                }
                if(arr[mid]>target){
                    high = mid-1;
                    continue;
                }
                else{
                    low = mid+1;
                }
            }
            return 999;
        }

        unsigned int binarySearchRec (T element){
            return bsrHelper(element, 0, size, arr);
        }

        int bsrHelper(T target, int low, int high, T* arr){
            if(low<=high){
                int mid = (low+high)/2;
                if(arr[mid]==target){
                    return mid;
                }
                if(arr[mid]>target){
                    return bsrHelper(target, low, mid-1, arr);
                }
                else{
                    return bsrHelper(target, mid+1, high, arr);
                }
            }
            return 999;
        }
        bool isEmpty()const {
            return (size==0);
        }
        int listSize() const{
            return size;
        }
        int maxListSize ()const{
            return size;
        }
        void print(){
            cout<<"Printing elements now: "<<endl;
            for(int i = 0; i<size;i++){
                cout<<arr[i]<<endl;
            }
        }
        bool insert(T elem){
            if(size==0){
                size++;
                arr = new T [1];
                arr[0] = elem;
                return true;
            }
            else{

                T* temp = new T[size+1];
                int j = 0;
                int i = 0;
                while(i<size && arr[i]<elem){
                    temp[j++] = arr[i++];
                }
                temp[j++] = elem;
                
                while(i<size){
                    temp[j++] = arr[i++];
                }
                delete[] arr;
                arr = temp;
                size++;
                return true;
            }
            return false;
        }
        void remove(T elem){
            if(size == 0){
                return;
            }
            bool contains = false;
            for(int i = 0; i<size;i++){
                if (arr[i]==elem){
                    contains = true;
                    break;
                }
            }
            if(contains){
            int j = 0;
            T* temp = new T[size-1];
            for(int i = 0; i<size; i++){
                if(arr[i]!=elem){
                    temp[j++] = arr[i];
                    }
                }
                delete[] arr;
                arr = temp;
                size--;
            }
            return;
        }

        ~sortedArrList(){
            delete[] arr;
        }


};