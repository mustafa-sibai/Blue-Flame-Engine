#include "GameObject.h"

namespace BF
{
	namespace ECS
	{
		using namespace std;

		int GameObject::globalID = 0;

		GameObject::GameObject(const std::string& name) :
			Active(true), Name(name), id(0), added(false)
		{
			GameObject::globalID++;
			id = globalID;
		}

		GameObject::~GameObject()
		{
		}
	}
}