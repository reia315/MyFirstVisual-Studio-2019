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

void DestoryObject::Draw()
{
}
