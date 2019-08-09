template<class T>
inline AstarComponent<T>::AstarComponent(Type type) :
	IAstarComponent(type)
{
	IComponent::types.emplace_back(typeid(T).hash_code());
}

template<class T>
inline AstarComponent<T>::~AstarComponent()
{
}