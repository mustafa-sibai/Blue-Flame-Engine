#pragma once
#include "string"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			class IDataType
			{
			public:
				enum class InternalDataType { None, Int, Float, Bool };

			protected:
				std::string name;
				InternalDataType dataType;

				IDataType(InternalDataType dataType) : dataType(dataType) { };

			public:
				inline const InternalDataType& GetInternalDataType() const { return dataType; }
			};
		}
	}
}