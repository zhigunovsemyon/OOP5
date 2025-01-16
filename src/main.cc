#include "object.h"
#include <iostream>
#include <string_view>

class Double : public Object {
public:
#define selfType Double

	~selfType() override { delete n_; }

	selfType(selfType const & i) : n_{new double{*i.n_}} {}

	selfType(double n = 0) : n_{new double{n}} {}

	selfType & operator=(selfType const & i)
	{
		*n_ = *i.n_;
		return *this;
	}

	selfType const & print(std::ostream & ost = std::cout) const override
	{
		ost << *n_;
		return *this;
	}

	selfType & read(std::istream & ist = std::cin) override
	{
		ist >> *n_;
		return *this;
	}

	std::string_view type() const override { return "Double"; }

	bool equal(Object const & i) const noexcept(false) override
	{
		auto cmp{dynamic_cast<selfType const *>(&i)};
		if (nullptr == cmp)
			throw Object::exceptions::NOT_MATCHING_DERIVED;

		return *n_ == *(cmp->n_);
	}

private:
	double * n_;
#undef selfType
};

class Int : public Object {
public:
#define selfType Int

	~selfType() override { delete n_; }

	selfType(selfType const & i) : n_{new int{*i.n_}} {}

	selfType(int n = 0) : n_{new int{n}} {}

	selfType & operator=(selfType const & i)
	{
		*n_ = *i.n_;
		return *this;
	}

	selfType const & print(std::ostream & ost = std::cout) const override
	{
		ost << *n_;
		return *this;
	}

	selfType & read(std::istream & ist = std::cin) override
	{
		ist >> *n_;
		return *this;
	}

	std::string_view type() const override { return "Int"; }

	bool equal(Object const & i) const noexcept(false) override
	{
		auto cmp{dynamic_cast<selfType const *>(&i)};
		if (nullptr == cmp)
			throw Object::exceptions::NOT_MATCHING_DERIVED;

		return *n_ == *(cmp->n_);
	}

private:
	int * n_;
#undef selfType
};

int main()
{
	Int i1;
	Double i2{10};
	std::cin >> i1;
	Object * i3{new Int{i1}};

	std::cout << i1 << ' ' << i1.id() << ' ' << i1.type() << '\n';
	std::cout << i2 << ' ' << i2.id() << ' ' << i2.type() << '\n';
	std::cout << *i3 << ' ' << i3->id() << ' ' << i3->type() << '\n';

	try {
		std::cout << i1 << " != " << i2 << ' ' << std::boolalpha
			  << (i1 != i2) << '\n';
		delete i3;
		return 0;
	} catch (Object::exceptions exc) {
		switch (exc) {
		case Object::exceptions::NOT_MATCHING_DERIVED:
			std::cerr << "\n!!Error: NOT_MATCHING_DERIVED!!\n";
		}
		delete i3;
		return -1;
	}
}
