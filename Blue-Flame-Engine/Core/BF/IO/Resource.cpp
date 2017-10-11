#include "Resource.h"

namespace BF
{
	namespace IO
	{
		using namespace std;

		Resource::Resource(Type type) :
			type(type)
		{
		}

		Resource::~Resource()
		{
		}
	}
}