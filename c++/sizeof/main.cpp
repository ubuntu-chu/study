#include <stdio.h>

#include <iostream>
using namespace std;

//=================================================  //
class Component			//抽象组件，即对象的接口  
{
  public:virtual void prtTicket() = 0;
};

class test{
public:
	int print()
	{
		cout << "print" << endl;
	}
};

//================================================= //具体组件，即被装饰者   
class SalesTicket:public Component {
  public:void prtTicket() {
	cout << "具体组件SalesTicket打印票据正文/n" << endl;
}};
//================================================//装饰者（也是抽象组件的子类）
class TicketDecorator:public Component {
public:
	TicketDecorator(Component * myComponent):m_pTrailer(myComponent){

	}
    //是否需要释放pMyTrailer??????        //如果遵循“谁申请，谁释放”的原则，则不需要  
	virtual void prtTicket(){
		m_pTrailer->prtTicket();	
	}

protected:
	Component *m_pTrailer;
};   
//=================================================    
//具体装饰者Header（是装饰者的子类）    
//功能：打印表头    
    class Header:public TicketDecorator {
      public:
	Header(Component * myComponent):TicketDecorator(myComponent){
	    cout << "构造具体装饰者Header/n" << endl;
	} void prtTicket() {
	    //功能：在表的前面加个头部            //注意这行代码的位置，在callTrailer()之前            //这是装饰者添加的功能 
	    cout << "具体装饰者Header打印表头/n" << endl;
		TicketDecorator::prtTicket();
	}
    };

//具体装饰者Footer（是装饰者的子类）    
//功能：打印表尾    
class Footer:public TicketDecorator {
public:
	Footer(Component * myComponent):TicketDecorator(myComponent){
	    cout << "构造具体装饰者Footer/n" << endl;
	} 
	void prtTicket() {
		TicketDecorator::prtTicket();
	    cout << "具体装饰者Footer打印表尾/n" << endl;
	}
    };

//=================================================
    class Factory		//工厂   
{   
  public: Component * m_pMyComponent;
    Component *m_pMyFooter;
    Component *m_pMyHeader;

    Factory() {
	Component *m_pMyComponent = NULL;
	Component *m_pMyFooter = NULL;
	Component *m_pMyHeader = NULL;
    }

    Component *getComponent() {
	m_pMyComponent = new SalesTicket();
	m_pMyFooter = new Footer(m_pMyComponent);
	m_pMyHeader = new Header(m_pMyFooter);
	return m_pMyHeader;	//返回最后一个指针       
	}   

	~Factory()		//别忘了释放空间 
	{   
	delete m_pMyComponent;
	delete m_pMyFooter;
	delete m_pMyHeader;
    }
};

//=================================================      
int main(void)
{
    Factory myFactory;

	cout << "sizeof = " << sizeof(class Component) << endl;
	cout << "sizeof = " << sizeof(class test) << endl;
    Component *pMyComponent = myFactory.getComponent();
    pMyComponent->prtTicket();	//打印         
    return 0;
}
