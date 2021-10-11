#ifndef BUTTON_FUNCTION_INCLUDE
#define BUTTON_FUNCTION_INCLUDE

#include <functional>

class ButtonFunction
{
public:
	ButtonFunction() {}

	virtual void call() = 0;
};

template <typename T>
class ClassFunction : public ButtonFunction
{
public: 
	ClassFunction(std::function<void(T*)> t_func, T* t_caller) :
		m_caller(t_caller),
		m_func(t_func)
	{
	}

	virtual void call()override
	{
		if (m_caller != nullptr && m_func != nullptr)
		{
			m_func(m_caller);
		}
	}

private:
	T* m_caller;
	std::function<void(T*)> m_func;
};

template <typename T, typename U>
class ArgsFunction : public ButtonFunction
{
public:
	ArgsFunction(std::function<void(T*, U)> t_func, T** t_caller, U t_args) :
		m_caller(t_caller),
		m_func(t_func),
		m_args(t_args)
	{
	}

	virtual void call()override
	{
		if (m_caller != nullptr && m_func != nullptr)
		{
			m_func(*m_caller, m_args);
		}
	}

private:
	T** m_caller;
	std::function<void(T*, U)> m_func;
	U m_args;
};

#endif