#pragma once
#include <list>
#include <string>
#include <vector>
#include "../GameObject/GameObject.h"

class GameObjectManager
{
public:
	GameObjectManager();

	GameObject GeneratGameObject(const std::string& name);

private:
	std::vector<GameObject> m_gameObject;
};