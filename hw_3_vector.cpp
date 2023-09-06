//
// ========================================
// HW3: Implement a Vector Class
// ========================================
// 
// In this assignment, we will implement 
// a vector class based on array, pointer 
// and dynamic memory allocation. 
// 
// The class has two private member 
// variables and some member functions. 
// Their designs are explained below. 
// 
// You can add new member functions 
// but not new member variables. In 
// addition, you cannot use any existing 
// vector-related library or function. 
// 
// 


#include <iostream>
using namespace std;

// 
// ======= Task =======
// Design and implement all member 
// functions of the MyVector class. 
// 
class MyVector {

public:

	// The "vsize" function returns the size 
	// of the current vector.  
	int vsize();

	// The "empty" function returns 1 if the 
	// current vector has no element and 0 otherwise. 
	int empty();

	// The "at" function returns the idx_th element 
	// of the vector. It also returns -1 if "idx" 
	// is outside the range of the current vector.
	int at(int idx);

	// The "resize" function resizes the current 
	// vector into a vector of size n. Note there 
	// are two scenarios (in lecture slides) which 
	// may need to be addressed separately. 
	void resize(int n);

	// The "push_back" function adds a new element 
	// "x" to the end of the current vector. Note 
	// the vector size increases after addition. 
	void push_back(int x);

	// The "pop_back" function removes the last 
	// element from the current vector, but does 
	// nothing if the current vector is empty. 
	// Note the vector size decreases after pop. 
	void pop_back();

	// The "insert" function inserts a new element 
	// "x" as the idx_th element in the current vector.
	// It also does nothing if "idx" is outside the 
	// range of the current vector. 
	void insert(int idx, int x);

	// The "erase" function removes the idx_th element 
	// from the vector. It also does nothing if the 
	// current vector is empty or if "idx" is outside 
	// the range of the current vector. 
	void erase(int idx);

	// The constructor should initialize 
	// pointer "p" to NULL and "size" to 0. 
	MyVector();

private:

	int* p; // This pointer holds the vector (or,essentially, 
	// address of an array that holds the vector elements.)
	// Do remember to update it after some vector operations.

	int size; // This integer holds the size of the current 
	// vector. Do remember to update it after some 
	// vector operations. 
};

//Implementations

int MyVector::vsize(){
	return size;
}

int MyVector::empty(){
	//If size is 0, the vector is empty, so return 1
	if(size == 0) return 1;

	//If the size is not 0, the vector is not empty, so return 0
	else return 0;
}

int MyVector::at(int idx){
	//If the idx is greater than or equal to size, the index is out of range
	if(idx >= size) return -1;

	//If the idx is not greater than or equal to size, return the element at idx.
	else return p[idx];
}

void MyVector::resize(int n){
	//Create a temporary int pointer that the first int of an int array of n size
	int* temp = new int[n];

	//For loop that steps through the elements in the array pointed at by temp. 
	for(int i = 0; i < n; i++){
		//If i is less then the current size, copy other elements from p to temp
		if(i < size) temp[i] = p[i];

		//If i has exceeded the current size, the vector was enlarged. Fill extra space with zeros.
		else temp[i] = 0;
	}

	//Update the size
	size = n;

	//Delete the data pointed to by p
	delete p;

	//Reassign p to temp
	p = temp;
}

void MyVector::push_back(int x){
	//Create a temporary int pointer that the first int of an int array of size + 1
	int* temp = new int[size + 1];

	//Copy elements from p to temp
	for(int i = 0; i < size; i++){
		temp[i] = p[i];
	}

	//Append x to end of temp
	temp[size] = x;

	//Increase size
	size++;

	//Delete data at p
	delete p;

	//Reassign
	p = temp;
}

void MyVector::pop_back(){
	//pop_back only works if vector has elements
	if(empty() == 0){
		//Create a temporary int pointer that the first int of an int array of size - 1
		int* temp = new int[size - 1];

		//Copy every element from p to temp except for the last element
		for(int i = 0; i < size - 1; i++){
			temp[i] = p[i];
		}

		//Decrement size
		size--;

		//Delete data pointed at by p
		delete p;
	
		//Reassign
		p = temp;
	}

}

void MyVector::insert(int idx, int x){
	//insert only does something if idx is in range of the currnt vector
	if(idx >= size){
		//Create a temporary int pointer that the first int of an int array of size + 1
		int* temp = new int[++size];

		//Create two indexes for p and for temp
		int pindx = 0;
		int tindx = 0;

		//Step through int array pointed to by temp
		for(tindx = 0; tindx < size; tindx++){
			//Copy elements from p to temp if if tindx does not equal idx. Increment pindx
			if(tindx != idx){
				temp[tindx] = p[pindx];
				pindx++;
			}
			//If tidx and idx equal, insert x
			else temp[tindx] = x;
		}

		//Delete data pointed at by p
		delete p;

		//Reassign
		p = temp;

	}
	
}

void MyVector::erase(int idx){
	//Erase only works if idx is in range of current size
	if(idx >= size){
		//Create a temporary int pointer that the first int of an int array of size - 1
		int* temp = new int[size - 1];

		//Create two indexes for p and for temp
		int pindx = 0;
		int tindx = 0;

		//Step through p
		for(pindx = 0; pindx < size; pindx++){
			//If pindx does not equal idx, copy elements from p to temp, increment tindx
			if(pindx != idx) temp[tindx++] = p[pindx];
		}

		//Decrement size
		size--;

		//Delete data pointed at by p
		delete p;

		//Reassign
		p = temp;
	}
}

MyVector::MyVector(){
	p = NULL;
	size = 0;
}


// The main function has been completed for you. 
// It is used to test your implmentation. 
// You should not modify it (unless there is typo).
int main()
{
	MyVector x;

	int mode;
	int new_size, idx, data;
	int temp;

	cin >> mode; // This decides which function to test. 
	cin >> new_size >> idx >> data;

	// Mode 0: test push_back(), vsize() and at()
	if (mode == 0) {

		while (cin >> temp) {
			x.push_back(temp);
		}

		cout << x.vsize() << '\n';

		for (int i = 0; i < x.vsize(); i++) {
			cout << x.at(i) << '\n';
		}
	}
	// Mode 1: test resize()
	else if (mode == 1)
	{
		while (cin >> temp) {
			x.push_back(temp);
		}

		x.resize(new_size);

		cout << x.vsize() << '\n';

		for (int i = 0; i < x.vsize(); i++) {
			cout << x.at(i) << '\n';
		}
	}
	// Mode 2: test pop_back()
	else if (mode == 2) {

		while (cin >> temp) {
			x.push_back(temp);
		}

		x.pop_back();

		cout << x.vsize() << '\n';

		for (int i = 0; i < x.vsize(); i++) {
			cout << x.at(i) << '\n';
		}
	}
	// Mode 3: test insert()
	else if (mode == 3) {

		while (cin >> temp) {
			x.push_back(temp);
		}

		x.insert(idx, data);

		cout << x.vsize() << '\n';

		for (int i = 0; i < x.vsize(); i++) {
			cout << x.at(i) << '\n';
		}
	}
	// Mode 4: test erase()
	else if (mode == 4) {

		while (cin >> temp) {
			x.push_back(temp);
		}

		x.erase(idx);

		cout << x.vsize() << '\n';

		for (int i = 0; i < x.vsize(); i++) {
			cout << x.at(i) << '\n';
		}
	}
	else {
		cout << "Wrong Mode Input!";
	}

	return 0;
}
