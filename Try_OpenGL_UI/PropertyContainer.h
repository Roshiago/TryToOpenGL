#ifndef _PROPERTY_H_
#define _PROPERTY_H_

#include <cassert>

constexpr auto READ_ONLY = 1;
constexpr auto WRITE_ONLY = 2;
constexpr auto READ_WRITE = 3;

#define Type2Enum(T) std::is_same<T, float>::value ? (GL_FLOAT) : (std::is_same<T, double>::value ? GL_DOUBLE : GL_INT);

template <typename Container, typename ValueType, int nPropType = READ_WRITE>
class Property
{
public:
	using setterFunc = void (Container::*)(ValueType);
	using getterFunc = ValueType(Container::*)(void);

	Property()
	{
		m_cObject = nullptr;
		Set = nullptr;
		Get = nullptr;
	}
	Property(Container* source, setterFunc set, getterFunc get) {
		m_cObject = source;
		Set = set;
		Get = get;
	}
	void setContainer(Container* cObject)
	{
		m_cObject = cObject;
	}
	void setter(void (Container::* pSet)(ValueType value))
	{
		if ((nPropType == WRITE_ONLY) || (nPropType == READ_WRITE))
			Set = pSet;
		else
			Set = NULL;
	}
	void getter(ValueType(Container::* pGet)())
	{
		if ((nPropType == READ_ONLY) || (nPropType == READ_WRITE))
			Get = pGet;
		else
			Get = NULL;
	}
	ValueType operator =(const ValueType& value)
	{
		assert(m_cObject != NULL);
		assert(Set != NULL);
		(m_cObject->*Set)(value);
		return value;
	}

	ValueType operator->() {
		assert(m_cObject != NULL);
		assert(Get != NULL);
		return (m_cObject->*Get)();
	}
	operator ValueType()
	{
		assert(m_cObject != NULL);
		assert(Get != NULL);
		return (m_cObject->*Get)();
	}
private:
	Container* m_cObject;
	setterFunc Set;
	getterFunc Get;
};

#endif // !_PROPERTY_H_
