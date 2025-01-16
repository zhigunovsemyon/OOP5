#include "object.h"
#include <iostream>
#include <string_view>

class Double : public CObject {
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

	int compare(CObject const & other) const noexcept(false) override
	{
		auto cmp{dynamic_cast<selfType const *>(&other)};
		if (nullptr == cmp)
			throw Object::exceptions::NOT_MATCHING_DERIVED;

		auto diff {*n_ - *cmp->n_};
		return (diff > 0) ? 1 : (diff < 0) ? -1 : 0;
	}

private:
	double * n_;
#undef selfType
};

class Int : public CObject {
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

	int compare(CObject const & other) const noexcept(false) override
	{
		auto cmp{dynamic_cast<selfType const *>(&other)};
		if (nullptr == cmp)
			throw Object::exceptions::NOT_MATCHING_DERIVED;

		return static_cast<int>(*n_ - *cmp->n_);
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
	CObject *a{}, *b{};

	std::cout << "Тип a -- Int или Double (i|d)? ";
	switch (getchar()) {
	case 'D':
	case 'd':
		a = new Double();
		break;
	case 'I':
	case 'i':
		a = new Int();
		break;
	default:
		std::cerr << "Неправильный ввод!\n";
		return 0;
	}
	std::cout << "Значение a: ";
	std::cin >> *a;

	std::cout << "Тип b -- Int или Double (i|d)? ";
	while (getchar() != '\n')
		;
	switch (getchar()) {
	case 'D':
	case 'd':
		b = new Double();
		break;
	case 'I':
	case 'i':
		b = new Int();
		break;
	default:
		std::cerr << "Неправильный ввод!\n";
		delete a;
		return 0;
	}
	std::cout << "Значение b: ";
	std::cin >> *b;

	std::cout << "a: " << "id = " << a->id() //
		  << ", type: " << a->type()	 //
		  << ", value: " << *a << '\n';

	std::cout << "b: " << "id = " << b->id() //
		  << ", type: " << b->type()	 //
		  << ", value: " << *b << '\n';

	try {
		std::cout << std::boolalpha;
		std::cout << "a != b : " << (*a != *b) << '\n';
		std::cout << "a >= b : " << (*a >= *b) << '\n';
		std::cout << "a <= b : " << (*a <= *b) << '\n';
		delete a;
		delete b;
		return 0;
	} catch (Object::exceptions exc) {
		switch (exc) {
		case Object::exceptions::NOT_MATCHING_DERIVED:
			std::cerr << "\n!!Error: NOT_MATCHING_DERIVED!!\n";
		}
		delete a;
		delete b;
		return -1;
	}
}
