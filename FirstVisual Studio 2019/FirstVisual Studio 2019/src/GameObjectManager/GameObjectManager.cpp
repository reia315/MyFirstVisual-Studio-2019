#include "GameObjectManager.h"

GameObjectManager::GameObjectManager()
{
}

GameObject GameObjectManager::GeneratGameObject(const std::string& name)
{
	GameObject gameObject =GameObject(name);
	m_gameObject.push_back(gameObject);
	return gameObject;
}
