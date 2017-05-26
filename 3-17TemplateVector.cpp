#pragma once

template <class T>
class Vector
{
public:
	typedef T ValueType;
	typedef ValueType* Pointer;
	typedef const ValueType* ConstPointer;
	typedef ValueType* Iterator;
	typedef const 
protected:
	Iteraor _start;
	Iterator _end;
	Iterator _endOfStorage;
};