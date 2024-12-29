#include <istream>
#include <ostream>
#include <string_view>

/* Предусмотреть:
 * 	+1.Загрузку объекта из текстовой строки.
 * 	+2.Выгрузки объекта в текстовую строку в динамической памяти.
 * 	+3.Возврат уникального идентификатора класса.
 * 	+4.Возврат указателя на строку с именем класса.
 * 	5.Сравнение двух объектов.
 * 	6."Сложение" (Объединение) двух объектов.
 * 	7.Создание динамической копии объекта.
 * Сделать разработанный класс производным от абстрактного базового класса
 * object. Взять любой другой простой класс (например, класс целых чисел) и
 * также сделать его производным от абстрактного базового класса object. Создать
 * статическую структуру данных, содержащую указатели object* на объекты обоих
 * классов. Показать возможность одновременной работы через виртуальные функции.
 */
class Object {
public:
	virtual ~Object() = default;

	int id() const { return id_; }

	virtual std::string_view type() = 0;

	virtual Object const & print(std::ostream & ost) const = 0;
	virtual Object & read(std::istream & ist) = 0;

	friend std::istream & operator>>(std::istream & ist, Object & obj)
	{
		obj.read(ist);
		return ist;
	}

	friend std::ostream & operator<<(std::ostream & ost, Object const & obj)
	{
		obj.print(ost);
		return ost;
	}

protected:
	Object() : id_{count_++} {}

private:
	static inline int count_;
	int id_; // Идентификатор класса
};
