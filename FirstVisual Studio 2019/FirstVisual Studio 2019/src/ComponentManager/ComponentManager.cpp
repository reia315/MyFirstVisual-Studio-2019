#include "ComponentManager.h"
#include "../Component/Component.h"

//静的変数のときは.cppで再定義する必要がある
std::list<std::shared_ptr<Component>>ComponentManager::m_component;

std::list<std::shared_ptr<Component>>ComponentManager::m_addComponent;

void ComponentManager::Update()
{
	for (const auto& component : m_component)
	{
		component->Update();
	}
}

void ComponentManager::Draw()
{
	for (const auto& component : m_component)
	{
		component->Draw();
	}
}

void ComponentManager::UpdateComponentList()
{
	for (const auto& component : m_addComponent)
	{
		m_component.push_back(component);
	}

	m_addComponent.clear();
}



void ComponentManager::DeleteComponent()
{
	m_component.remove_if([](const auto& component) {return component->IsDead(); });
}