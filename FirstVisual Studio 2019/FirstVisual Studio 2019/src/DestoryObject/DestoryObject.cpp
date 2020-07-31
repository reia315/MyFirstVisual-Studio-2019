#include "DestoryObject.h"
#include "../GameObjectManager/GameObjectManager.h"
#include "../GameObject/GameObject.h"
#include "../ComponentManager/ComponentManager.h"

DestoryObject::DestoryObject(const std::string& name) :m_name{ name } {}

void DestoryObject::Update()
{
	auto object =  GameObjectManager::SearchObject(m_name);

	for (const auto& gameObject : object)
	{
		gameObject.lock()->Destroy();
	}
}

std::weak_ptr<Component> DestoryObject::CloneComponent() const
{
	return ComponentManager::GenerateComponent<DestoryObject>(m_name);
}
