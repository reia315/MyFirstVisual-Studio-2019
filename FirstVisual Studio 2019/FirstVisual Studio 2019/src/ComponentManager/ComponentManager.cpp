#include "ComponentManager.h"
#include "../Component/Component.h"

//静的変数のときは.cppで再定義する必要がある
std::list<std::shared_ptr<Component>>ComponentManager::m_component;

void ComponentManager::update()
{
	for (const auto& component : m_component)
	{
		component->Update();
	}
}

void ComponentManager::draw()
{
	for (const auto& component : m_component)
	{
		component->Draw();
	}
}

//std::weak_ptr<Component> ComponentManager::GenerateComponent()
//{
//	auto component = std::make_shared<Component>();
//	m_component.push_back(component);
//	return component;
//}
