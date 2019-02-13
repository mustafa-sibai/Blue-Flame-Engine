template<typename T>
inline bool IComponent::IsSameType()
{
	std::string type = typeid(T).name();

	for (size_t i = 0; i < types.size(); i++)
	{
		if (types[i] == type)
			return true;
	}

	return false;
}

template<typename T>
inline bool IComponent::CompareTypes(std::string type)
{
	std::string typeT = typeid(T).name();

	if (typeT == type)
		return true;
	else
		return false;
}

template<typename T>
inline std::string IComponent::TypeOf()
{
	return typeid(T).name();
}