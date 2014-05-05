#include<boost/enable_shared_from_this.hpp>
#include<boost/shared_ptr.hpp>
#include<cassert>

using namespace std;

class Y;

void dothis(boost::shared_ptr<class Y>py, int i);

class Y:public boost::enable_shared_from_this < Y > {
  public:
    boost::shared_ptr < Y > f() {
		dothis(shared_from_this(), 1);
	return shared_from_this();
    } 
	
	Y *f2() {
	return this;
    }
};

void dothis(boost::shared_ptr<class Y>py, int i){

    std::cout << "in dothis py.use_count = " << py.use_count() << std::endl;	//2

}

int main(void)
{
	string a = new char[1];
	int b(5);
	class Y *py = new Y;

	cout << "b = " << b << endl;

	a = "sadfsdf";
	cout << "a = " << a << endl;
    boost::shared_ptr < Y > p(new Y);
    //boost::shared_ptr < Y > q = p->f();
    boost::shared_ptr < Y > q(py);       //ok
    //boost::shared_ptr < Y > q=py;       //error

	Y &r = *p;
    //boost::shared_ptr < Y > q = r.f2();
    std::cout << "p.use_count = " << p.use_count() << std::endl;	//2
    r.f();

    std::cout << "p.use_count = " << p.use_count() << std::endl;	//2

    boost::shared_ptr < Y > m = r.f();
    //std::cout << "q.use_count = " << q.use_count() << std::endl;	//2
    std::cout << "m.use_count = " << m.use_count() << std::endl;	//2
    std::cout << "p.use_count = " << p.use_count() << std::endl;	//2
	/*
    Y *r = p->f2();
    assert(p == q);
    assert(p.get() == r);

    std::cout << p.use_count() << std::endl;	//2
    boost::shared_ptr < Y > s(r);
    std::cout << s.use_count() << std::endl;	//1
    //assert(p == s);           //断言失败
	*/

    return 0;
}
