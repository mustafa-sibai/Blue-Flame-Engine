template<class T>
inline Renderable<T>::Renderable(const BF::Math::Vector2i& size, const BF::Math::Vector2f& pivot, int zSortingOrder, BF::Graphics::Renderers::RenderLayer& renderLayer, const BF::Graphics::Color& color) :
	IRenderable(size, pivot, zSortingOrder, renderLayer, color)
{
	IComponent::types.emplace_back(typeid(T).name());
}

template<class T>
inline Renderable<T>::~Renderable()
{
}