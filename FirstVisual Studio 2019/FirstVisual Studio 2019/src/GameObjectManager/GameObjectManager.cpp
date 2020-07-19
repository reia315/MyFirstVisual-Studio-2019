#include "GameObjectManager.h"
#include "../GameObject/GameObject.h"

std::forward_list<std::shared_ptr<GameObject>>m_gameObject;

GameObjectManager::GameObjectManager()
{
}

std::weak_ptr<GameObject> GameObjectManager::GeneratGameObject(const std::string& name)
{
	auto gameObject =std::make_shared<GameObject>(name);
	m_gameObject.push_front(gameObject);
	return gameObject;
}
