#include <iostream>
using namespace std;

class Year {
	mutable int y;
//    static const int InitY = 1970;
static const int InitY;
    //const int InitY;
  public:
     Year(int const_y){
	y = InitY;
    };
    Year(){
	y = InitY;
    };
    int year() const {
		y++;
	return y;
    };
    void add_year(int i) {
	y = year() + i;
    };
};

    const int Year::InitY = 1970;

int main()
{
    Year y1;
    Year *const py1 = new Year(111);
    y1.add_year(1);
    py1->add_year(2);
    cout << y1.year() << ","<<py1->year() << endl;
    return 0;
}
