template<typename T>
inline T* GameObject::GetComponent()
{
	for (size_t i = 0; i < components.size(); i++)
	{
		if (components[i]->IsSameType<T>())
			return (T*)components[i];
	}
	return nullptr;
}