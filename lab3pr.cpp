#include<iostream>
using namespace std;
class memory{

public:
	int *arr;
	void insert(int &element,int &capacity,int &size){
		if(size>=capacity*70/100){
			resize(capacity);
		}
		arr[size]=element;
		size++;
		cout<<"Element inserted"<<endl;
	}

private:
	void resize(int &capacity){
		int newcap=2*capacity;
		int *newArrayPointer = new int[newcap];
		for (int i = 0; i < capacity; i++) {
			newArrayPointer[i] = arr[i];
		}
		delete[] arr;
		arr = newArrayPointer;
		capacity = newcap;
		for (int i = 0; i < capacity; i++) {
			cout<< newArrayPointer[i]<<endl;
		}
	}
};
int main(){
	cout<<"Enter the size of an array:"<<endl;
	int capacity;
	cin>>capacity;
	int element;
	int size=0;
	memory m;
	m.arr = new int[capacity];
	while (true) {
		cout << "Enter an element to insert : ";
		cin >> element;
		if (element < 0) {
			break;
		}
		m.insert(element,capacity,size);
	}
	return 0;
}

