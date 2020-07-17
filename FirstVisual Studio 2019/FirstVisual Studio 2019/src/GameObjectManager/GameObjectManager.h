#pragma once
#include <list>
#include <string>
#include <vector>
#include <iostream>

class GameObject;

class GameObjectManager
{
public:
	GameObjectManager();

	std::weak_ptr<GameObject> GeneratGameObject(const std::string& name);

private:
	std::vector<std::weak_ptr<GameObject>> m_gameObject;
};