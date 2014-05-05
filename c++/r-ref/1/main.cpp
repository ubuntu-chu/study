#include <iostream>
#include <utility>

using namespace std;

struct sbclass{
	sbclass(){cout << "sb constructing" << endl;}
	sbclass(sbclass &sb){cout << "sb copy constructing" << endl;}
//	sbclass(sbclass &&sb){cout << "sb move constructing" << endl;}
};

sbclass fck()
{
	sbclass   sb;
	return sb;
}

//void sck(sbclass &&sb){ cout << "move here" << endl;}
void sck(const sbclass &sb){ cout << "ref here" << endl;}

int main(void){

	sck(fck());
	const int &b = 1;
	int &&c = 2;

	cout << b << endl;

	return 0;
}

