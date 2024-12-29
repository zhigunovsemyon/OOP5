#include "object.h"
#include <iostream>
#include <string_view>

class Int : public Object {
public:
	~Int() override { delete n_; }

	Int(Int const & i) : n_{new int{*i.n_}} {}

	Int(int n = 0) : n_{new int{n}} {}

	Int & operator=(Int const & i)
	{
		*n_ = *i.n_;
		return *this;
	}

	Int const & print(std::ostream & ost = std::cout) const override
	{
		ost << *n_;
		return *this;
	}

	Int & read(std::istream & ist = std::cin) override
	{
		ist >> *n_;
		return *this;
	}

	std::string_view type() const override { return "Int"; }

private:
	int * n_;
};

int main()
{
	Int i1;
	std::cin >> i1;
	Object * i3{new Int{i1}};

	std::cout << i1 << ' ' << i1.id() << ' ' << i1.type() << '\n';
	std::cout << *i3 << ' ' << i3->id() << ' ' << i3->type() << '\n';
	delete i3;
	return 0;
}
