template<class T>
inline TransformComponent<T>::TransformComponent()
{
	IComponent::types.emplace_back(typeid(T).hash_code());
}


template<class T>
inline TransformComponent<T>::~TransformComponent()
{
}