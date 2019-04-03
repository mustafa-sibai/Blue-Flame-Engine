template<class T>
Script<T>::Script()
{
	IComponent::types.emplace_back(typeid(T).hash_code());
}

template<class T>
inline Script<T>::~Script()
{
}