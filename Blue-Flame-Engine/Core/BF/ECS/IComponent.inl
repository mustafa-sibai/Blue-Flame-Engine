template<typename T>
inline bool IComponent::IsSameType()
{
	for (size_t i = 0; i < types.size(); i++)
	{
		if (types[i] == typeid(T).hash_code())
			return true;
	}

	return false;
}

template<typename T>
inline bool IComponent::CompareTypes(const size_t& type)
{
	if (typeid(T).hash_code() == type)
		return true;
	else
		return false;
}

template<typename T>
inline const size_t& IComponent::TypeOf()
{
	return typeid(T).hash_code();
}