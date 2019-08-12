template<class T>
inline Collider<T>::Collider(Type type) :
	ICollider(type)
{
	IComponent::types.emplace_back(typeid(T).hash_code());
}

template<class T>
inline Collider<T>::~Collider()
{
}