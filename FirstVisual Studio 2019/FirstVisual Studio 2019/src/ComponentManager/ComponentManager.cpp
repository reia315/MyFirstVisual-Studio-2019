#include "ComponentManager.h"
#include "../Component/Component.h"

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

std::weak_ptr<Component> ComponentManager::GeneratComponent()
{
	auto component = std::make_shared<Component>();
	m_component.push_back(component);
	return component;
}
