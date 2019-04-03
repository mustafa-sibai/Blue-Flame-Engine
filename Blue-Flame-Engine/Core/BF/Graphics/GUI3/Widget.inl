template<class T>
inline Widget<T>::Widget()
{
	IComponent::types.emplace_back(typeid(T).hash_code());
}

template<class T>
inline Widget<T>::~Widget()
{
}