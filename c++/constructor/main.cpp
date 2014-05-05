#include <iostream>

using namespace std;

template <typename type>
class temp{
public:
#if 0
	temp(type d)
	{
		m_d = d;
		cout << "-----" << endl;
	}
#endif
	template <typename R>
	temp(temp<R>&tmp)
	{
		m_d = tmp.m_d;
		cout << "sdfsdfsd" <<endl;

	}
#if 0
	temp<type>& temp(type d)
	{
		m_d = d;
		cout << "+++++" << endl;
		return *this;
	}
#endif
private:
	type	m_d;
};

template <typename type>
temp<type>::temp<type>(type d)
{
	m_d = d;
	cout << "-----" << endl;
}
#if 0
template <typename type>
template <typename R>
temp<type>(temp<R>&tmp)
{
	m_d = tmp.m_d;
	cout << "sdfsdfsd" <<endl;

//	return *this;
}
#endif

int main(void)
{
	temp<int> aa(4);
	temp<int> bb(aa);


	return 0;
}
