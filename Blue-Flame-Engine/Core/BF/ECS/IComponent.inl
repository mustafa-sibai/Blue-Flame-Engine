template<typename T>
inline bool IComponent::IsSameType()
{
	for (size_t i = 0; i < types.size(); i++)
	{
		if (types[i] == typeid(T).name())
			return true;
	}

	return false;
}

template<typename T>
inline bool IComponent::CompareTypes(const std::string& type)
{
	if (typeid(T).name() == type)
		return true;
	else
		return false;
}

template<typename T>
inline std::string IComponent::TypeOf()
{
	return typeid(T).name();
}