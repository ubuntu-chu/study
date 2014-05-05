#include <iostream>

using std::cout;
using std::endl;

namespace aa{
	int		var = 0;
	int		m = 5;
}


namespace bb{
	int		var = 1;
	int		n = 6;
}

int main(int argc, char**argv)
{
	
	using namespace aa;
	using namespace bb;
#if 0
	{
	//using namespace aa;
	using aa::var;

	//cout << aa::var << endl;
	cout << var << endl;
	}

	{
	using bb::var;
	//using namespace bb;
	//cout << bb::var << endl;
	cout << var << endl;
	}
#endif
	cout << m << endl;
	cout << n << endl;



	return 0;
}





