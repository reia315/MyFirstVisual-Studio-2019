#pragma once
#include <string>       //文字列
#include <forward_list> //前方配列
#include <memory>       //スマートポインタ

class GameObject;

class GameObjectManager
{
public:
	GameObjectManager();

	std::weak_ptr<GameObject> GeneratGameObject(const std::string& name);

private:
	std::forward_list<std::shared_ptr<GameObject>> m_gameObject;
};