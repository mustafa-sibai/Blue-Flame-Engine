template<class T>
inline Component <T>::Component()
{
	IComponent::types.emplace_back(typeid(T).name());
}

template<class T>
inline Component<T>::~Component()
{
}