#include "GameObjectManager.h"

GameObjectManager::GameObjectManager()
{
}

std::weak_ptr<GameObject> GameObjectManager::GeneratGameObject(const std::string& name)
{
	auto gameObject =std::make_shared<GameObject>(name);
	m_gameObject.push_front(gameObject);
	return gameObject;
}
