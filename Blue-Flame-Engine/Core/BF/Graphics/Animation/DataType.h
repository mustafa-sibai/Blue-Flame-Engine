#pragma once
#include "BF/Graphics/Animation/IDataType.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			template <class T, IDataType::InternalDataType internalDataType>
			class DataType : public IDataType
			{
				friend class IDataType;

			public:
				T value;

				DataType(T value);
				~DataType();

				bool operator>(const DataType& rhs);
				bool operator>=(const DataType& rhs);
				bool operator<(const DataType& rhs);
				bool operator<=(const DataType& rhs);

				bool operator==(const DataType& rhs);
				bool operator!=(const DataType& rhs);
			};

#include "DataType.inl"

			typedef DataType<int, IDataType::InternalDataType::Int> AInt;
			typedef DataType<float, IDataType::InternalDataType::Float> AFloat;
			typedef DataType<bool, IDataType::InternalDataType::Bool> ABool;
		}
	}
}