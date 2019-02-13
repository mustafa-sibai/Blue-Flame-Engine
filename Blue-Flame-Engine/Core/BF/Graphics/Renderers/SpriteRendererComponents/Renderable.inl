template<class T>
inline Renderable<T>::Renderable(const BF::Math::Vector2i& size, const BF::Math::Vector2f& pivot, unsigned int zLayer, const Color& color) :
	IRenderable(size, pivot, zLayer, color)
{
	IComponent::types.emplace_back(typeid(T).name());
}

template<class T>
inline Renderable<T>::~Renderable()
{
}