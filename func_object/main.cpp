#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

// function object that adds the value with which it is initialized
class AddValue {
  private:
    int theValue;    // the value to add
  public:
    // constructor initializes the value to add
    AddValue(int v) : theValue(v) {
		cout<<"constructor call" <<endl;
    }

    // the ``function call'' for the element adds the value
    void operator() (int& elem) {
        //elem += theValue;
        theValue +=         elem;
		cout<<"elem"<<elem<<"the value = "<<theValue<<endl;
    }
	operator int()const {return theValue;}
};

int main()
{
    list<int> coll;
	AddValue add(10);

    // insert elements from 1 to 9
    for (int i=1; i<=9; ++i) {
        coll.push_back(i);
    }

    //PRINT_ELEMENTS(coll,"initialized:                ");

    // add value 10 to each element
    add = for_each (coll.begin(), coll.end(),    // range
              add);               // operation

	cout << add;
//    PRINT_ELEMENTS(coll,"after adding 10:            ");

    // add value of first element to each element
    for_each (coll.begin(), coll.end(),    // range
              AddValue(*coll.begin()));    // operation
	cout << add;

 //   PRINT_ELEMENTS(coll,"after adding first element: ");
}

