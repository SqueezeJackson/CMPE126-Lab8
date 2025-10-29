#include <iostream>

using namespace std;

template <typename T> class linkedlist{
	private:
	  struct Node{
		 T data;
		 struct Node* next = nullptr; //Next node initialzed to nullptr
	  };
	  Node* head;
	  int size;
	public:
	  linkedlist(){
		size = 0;
		head = nullptr; //head also init ot nullptr
	  }
	  bool isEmpty(){
		if(size == 0){
			return true; //These were kinda weird since linked list isnt really full or empty
		}				// but I returned empty only if size  = 0
		return false;
	  }
	  bool isFull(){
		if(size == 0){
			return false; //Same as before but opposite
		}
		return true;
	  }
	  int listSize(){
		return size; //Returns size var
	  }
	  int maxListSize(){ //same as above
		return size;
	  }
	  void print(){ //Print func: iterates through list and prints the data
		Node* temp = head;
		while(temp!=nullptr){
			cout<<temp->data<<endl;
			temp = temp->next;
		}
		return;
	  }
	  bool isItemAtEqual(int pos, T elem){ //Iterates to a pos, assuming it is in bounds, and checks if the param
		if(pos>size){						// is equal at that pt.
			cout<<"Error, pos > size"<<endl;
			exit(1);
		}
		else{
			Node* temp = head;
			int tSize = pos-1;
			while(tSize>0){
				temp = temp->next;
				tSize--;
			}
			if(temp->data == elem){
				cout<<"Elems are equal at pos\n";
				return true;
			}
			else{
				cout<<"Elems are not equal at pos\n";
			}
			return false;
		}
	  }
	  void insertAt(int pos, T elem){ //Checks if pos is within size, then iterates to pos and inserts element
		if (pos>size){
			cout<<"Error, pos > size"<<endl;
			exit(1);
		}
		else if(pos ==1 ){
			head->data = elem;
			return;
		}
		else{
			Node* newNode = new Node;
			newNode -> data = elem;
			Node* temp  = head;
			int ts = pos - 1;
			while(ts>0){
				temp = temp->next;
				ts--;
			}
			newNode-> next = temp->next;
			temp-> next = newNode;
			size++;
			return;
		}
	  }
	  void insertEnd(T elem){ //If head is null, insert that element as head
		Node* newNode = new Node; //Else, iterate to the end insert it there
		newNode -> data = elem;
		newNode -> next = nullptr;
		if(head == nullptr){
			head = newNode;
			size++;
			return;
		}
		else{
			//  cout<<"this is getting hit\n";
			Node* temp = head;
			while(temp->next!=nullptr){
				temp = temp->next;
			}
			temp->next = newNode;
			size++;
			return;
		}
	  }
	  void removeAt(int pos){ //If pos is within size, iterates to that pos then remoevs that
		if (pos>size||pos<=0){ // node + frees its dynamic mem
			cout<<"Error, pos > size"<<endl;
			exit(1);
		}
		else if (pos == 1){
			Node* temp = head;
			head = temp -> next;
			delete temp;
			size--;
		}
		else{
			int ts = pos - 1;
			Node* temp = head;
			Node* prev = temp;
			while(ts>0){
				prev = temp;
				temp = temp->next;
				ts--;
			}
			prev -> next = temp ->next;
			size--;
			delete temp;
	  }
	}
	  T retrieveAt(int pos){ // Iterates through list and returns the data of the element at pos
			if (pos>size||pos<=0){
			cout<<"Error, pos > size"<<endl;
			exit(1);
		}
		else{
			int ts = pos - 1;
			Node* temp = head;
			while(ts>0){
				temp = temp->next;
				ts--;
			}
			return temp->data;
	  }
	}
	  void clearList(){ //Travereses list and deletes all dynamic mem of nodes
		Node* curr = head;
		Node* nextN = nullptr;
		while(curr!=nullptr){
			nextN = curr->next;
			delete curr;
			curr = nextN;
		}
		size = 0;
		head = nullptr;
	  }
	  void replaceAt(int pos, T elem){ //Similar logic to retrieve at but replaces data instead of returning node->data
			if (pos>size||pos<=0){
				cout<<"Error, pos > size"<<endl;
				exit(1);
			}
			else{
				int ts = pos - 1;
				Node* temp = head;
				while(ts>0){
					temp = temp->next;
					ts--;
				}
				temp->data = elem;
			}
			return;
	  }
	  ~linkedlist(){ //Destrutor; similar to clearList
		Node* curr = head;
		while(curr!=nullptr){
			Node* nextNode = curr->next;
			delete curr;
			curr = nextNode;
		}
		size = 0;
	  }
	linkedlist&  operator =(linkedlist& obj){ //Checks self assignment then copies over elements to lhs
		if(this == &obj){
			return *this;
		}
		else{
			clearList();
			Node* temp = obj.head;
			while(temp!=nullptr){
				insertEnd(temp->data);
				temp=temp->next;
			}
			return *this;
		}
	}
};