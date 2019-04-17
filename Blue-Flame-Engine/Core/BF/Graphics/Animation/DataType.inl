template<class T, IDataType::InternalDataType internalDataType>
inline BF::Graphics::Animation::DataType<T, internalDataType>::DataType(T value) :
	value(value),
	IDataType(internalDataType)
{
}

template<class T, IDataType::InternalDataType internalDataType>
inline DataType<T, internalDataType>::~DataType()
{
}

template<class T, IDataType::InternalDataType internalDataType>
inline bool DataType<T, internalDataType>::operator>(const DataType& rhs)
{
	return value > rhs.value;
}

template<class T, IDataType::InternalDataType internalDataType>
inline bool DataType<T, internalDataType>::operator>=(const DataType& rhs)
{
	return value >= rhs.value;
}

template<class T, IDataType::InternalDataType internalDataType>
inline bool DataType<T, internalDataType>::operator<(const DataType& rhs)
{
	return value < rhs.value;
}

template<class T, IDataType::InternalDataType internalDataType>
inline bool DataType<T, internalDataType>::operator<=(const DataType& rhs)
{
	return value <= rhs.value;
}

template<class T, IDataType::InternalDataType internalDataType>
inline bool DataType<T, internalDataType>::operator==(const DataType& rhs)
{
	return value == rhs.value;
}

template<class T, IDataType::InternalDataType internalDataType>
inline bool DataType<T, internalDataType>::operator!=(const DataType& rhs)
{
	return value != rhs.value;
}
