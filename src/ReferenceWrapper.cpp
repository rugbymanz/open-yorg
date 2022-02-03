#include "ReferenceWrapper.hpp"

template<class T>
ReferenceWrapper<T>::ReferenceWrapper(T &&reference_): reference{ std::move(reference_) }{}

template<class T>
T& ReferenceWrapper<T>::get(){
	return reference;
}

template<class T>
ReferenceWrapper<T>& ReferenceWrapper<T>::operator=(T &&reference_){
	reference = reference_;
    return *this;
}