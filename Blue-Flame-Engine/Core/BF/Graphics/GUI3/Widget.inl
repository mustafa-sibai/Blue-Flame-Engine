template<class T>
inline Widget<T>::Widget(Type type) :
	IWidget(type)
{
	IComponent::types.emplace_back(typeid(T).hash_code());
}

template<class T>
inline Widget<T>::~Widget()
{
}