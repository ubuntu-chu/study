#include <iostream>
#include <tr1/memory>
/* To modify the value of the pointer object the const specifier must be removed. This
 * is shown below.
 * *
 * * output:
 * * csp counter: 1
 * * 15
 * * 15
 * * csp counter: 2
 * * sp counter: 2
 * */
int main()
{
	std::tr1::shared_ptr<const int> csp(new int(5));
	std::cout << "csp counter: " << csp.use_count() << std::endl;
	std::tr1::shared_ptr<int> sp = std::tr1::const_pointer_cast<int>(csp);
//	*csp = 12;
	*sp += 10;
	std::cout << *csp << std::endl;
	std::cout << *sp << std::endl;
	std::cout << "csp counter: " << csp.use_count() << std::endl;
	std::cout << "sp counter: " << sp.use_count() << std::endl;
	return 0;
}

