template<class T>
inline Widget<T>::Widget()
{
	IComponent::types.emplace_back(typeid(T).name());
}

template<class T>
inline Widget<T>::~Widget()
{
}