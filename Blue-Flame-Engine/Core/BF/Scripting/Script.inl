template<class T>
Script<T>::Script()
{
	IComponent::types.emplace_back(typeid(T).name());
}

template<class T>
inline Script<T>::~Script()
{
}