#pragma once
#include <string>       //•¶š—ñ
#include <forward_list> //‘O•û”z—ñ
#include <memory>       //std::shared_ptrEstd::weak_ptr

class GameObject;

class GameObjectManager
{
public:
	GameObjectManager();

	std::weak_ptr<GameObject> GeneratGameObject(const std::string& name);

private:
	std::forward_list<std::shared_ptr<GameObject>> m_gameObject;
};