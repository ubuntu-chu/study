#include <iostream>

using namespace std;

class base{

public:
	base(){cout<<"base::constructor call"<<endl;}
//	~base(){cout<<"base::deconstructor call"<<endl;}
	virtual ~base(){cout<<"base::deconstructor call"<<endl;}
};


class dev:public base{

public:
	dev(){cout<<"dev::constructor call"<<endl;}
	~dev(){cout<<"dev::deconstructor call"<<endl;}
};

int main(void)
{
	class base *pbase = new class dev;
	class dev *pdev = new class dev;

	cout<< "--------------------------delete pbase" <<endl;
	delete pbase;
	cout<< "--------------------------delete pdev" <<endl;
	delete pdev;

	return 0;
}

