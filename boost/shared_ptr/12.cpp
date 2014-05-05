#include <iostream>
#include <tr1/memory>
#include <vector>
/*shared_ptr can work with class hierarchies, so that shared<D> is convertible to
 * shared<B>, where D is a class (or struct) derived
 * * from B. The following class hierarchy is used to demonstrate the concept.
 * */
class Item
{
	std::string title_;
	public:
	Item(const std::string& title) :
		title_(title)
	{
	}
	virtual ~Item()
	{
	}
	virtual std::string Description() const = 0;
	std::string Title() const
	{
		return title_;
	}
};
class Book: public Item
{
	int pages_;
	public:
	Book(const std::string& title, int pages) :
		Item(title), pages_(pages)
	{
	}
	virtual std::string Description() const
	{
		return "Book: " + Title();
	}
	int Pages() const
	{
		return pages_;
	}
};
class DVD: public Item
{
	int tracks_;
	public:
	DVD(const std::string& title, int tracks) :
		Item(title), tracks_(tracks)
	{
	}
	virtual std::string Description() const
	{
		return "DVD: " + Title();
	}
	int Tracks() const
	{
		return tracks_;
	}
};
/* To convert back, from shared_ptr<B> to shared_ptr<D>, where D is a class (or structure)
 * derived from B,
 * * you can use the cast function std::tr1::dynamic_pointer_cast.
 * *
 * * output:
 * * spi counter: 1
 * * Left of the Middle, 14 tracks
 * * spi counter: 2
 * * spb counter: 0
 * * spd counter: 2
 * */
int main()
{
	std::tr1::shared_ptr<Item> spi(new DVD("Left of the Middle", 14));
	std::cout << "spi counter: " << spi.use_count() << std::endl;
	std::tr1::shared_ptr<Book> spb = std::tr1::dynamic_pointer_cast<Book>(spi);
	if (spb)
		std::cout << spb->Title() << ", " << spb->Pages() << " pages" << std::endl;
	std::tr1::shared_ptr<DVD> spd = std::tr1::dynamic_pointer_cast<DVD>(spi);
	if (spd)
		std::cout << spd->Title() << ", " << spd->Tracks() << " tracks" << std::endl;
	std::cout << "spi counter: " << spi.use_count() << std::endl;
	std::cout << "spb counter: " << spb.use_count() << std::endl;
	std::cout << "spd counter: " << spd.use_count() << std::endl;
	return 0;
}

