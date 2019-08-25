template<class T>
inline Renderable<T>::Renderable(Type type, int zSortingOrder, BF::Graphics::Renderers::RenderLayer* renderLayer, const BF::Graphics::Color& color) :
	IRenderable(type, zSortingOrder, renderLayer, color)
{
	IComponent::types.emplace_back(typeid(T).hash_code());
}

template<class T>
inline Renderable<T>::~Renderable()
{
}