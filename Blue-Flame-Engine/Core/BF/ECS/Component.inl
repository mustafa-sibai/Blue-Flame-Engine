template<class T>
inline Component <T>::Component(IComponent::Type type) :
	IComponent(type)
{
	IComponent::types.emplace_back(typeid(T).hash_code());
}

template<class T>
inline Component<T>::~Component()
{
}