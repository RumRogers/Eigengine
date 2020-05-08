#pragma once

// I hate Singletons, but I have it ready to use just in case...

template <class T>
class Singleton
{
public:
	static T& getInstance()
	{
		static T instance;

		return instance;
	}

private:
	Singleton();
};
