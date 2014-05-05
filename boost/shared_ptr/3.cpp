#include <iostream>
#include <tr1/memory>
class Foo
{
	public:
		void print()
		{
			std::cout << " foo::print" << std::endl;
		}
};
/*Function reset() decrements the shared reference counter. It then transforms the
 * shared pointer to an empty shared_ptr.
 * *
 * * output:
 * * counter sp1: 1
 * * counter sp1: 3
 * * counter sp2: 3
 * * counter sp3: 3
 * * counter sp1: 0
 * * counter sp2: 2
 * * counter sp3: 2
 * * counter sp1: 0
 * * counter sp2: 0
 * * counter sp3: 1
 * */
int main()
{
	// a shared_ptr owns the resouce, counter is 1
	std::tr1::shared_ptr<Foo> sp1(new Foo);
	std::cout << "counter sp1: " << sp1.use_count() << std::endl;
	std::tr1::shared_ptr<Foo> sp2(sp1);
	std::tr1::shared_ptr<Foo> sp3(sp1);
	std::cout << "counter sp1: " << sp1.use_count() << std::endl;
	std::cout << "counter sp2: " << sp2.use_count() << std::endl;
	std::cout << "counter sp3: " << sp3.use_count() << std::endl;
	// first shared_ptr is reset, the counter decremented and the object becomes empty
	sp1.reset();
	std::cout << "counter sp1: " << sp1.use_count() << std::endl;
	std::cout << "counter sp2: " << sp2.use_count() << std::endl;
	std::cout << "counter sp3: " << sp3.use_count() << std::endl;
	sp2.reset();
	std::cout << "counter sp1: " << sp1.use_count() << std::endl;
	std::cout << "counter sp2: " << sp2.use_count() << std::endl;
	std::cout << "counter sp3: " << sp3.use_count() << std::endl;
	return 0;
}
	
