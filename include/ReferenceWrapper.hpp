#pragma once

#include <utility>

template<class T>
class ReferenceWrapper{
public:
	ReferenceWrapper(T &&reference_);
	T& get();
	ReferenceWrapper<T>& operator=(T &&reference_);

private:
    T &&reference = T();
};