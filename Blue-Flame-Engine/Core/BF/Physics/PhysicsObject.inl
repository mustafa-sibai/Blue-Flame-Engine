template<class T>
inline PhysicsObject<T>::PhysicsObject(Type type) :
	IPhysicsObject(type)
{
	IComponent::types.emplace_back(typeid(T).hash_code());
}

template<class T>
inline PhysicsObject<T>::~PhysicsObject()
{
}