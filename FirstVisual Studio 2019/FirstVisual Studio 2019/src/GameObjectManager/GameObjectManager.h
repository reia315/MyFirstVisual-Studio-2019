#pragma once
#include <string>
#include <forward_list>
#include <iostream>

class GameObject;

class GameObjectManager
{
public:
	GameObjectManager();

	std::weak_ptr<GameObject> GeneratGameObject(const std::string& name);

private:
	std::forward_list<std::shared_ptr<GameObject>> m_gameObject;
};