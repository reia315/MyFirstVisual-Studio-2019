#pragma once
#include <string>       //文字列
#include <forward_list> //前方配列
#include <memory>       //スマートポインタ

class GameObject;

class GameObjectManager
{
public:
	
	static std::forward_list<std::weak_ptr<GameObject>> SearchObject(const std::string& name);

	static std::weak_ptr<GameObject> GenerateGameObject(const std::string& name);

	static void DeleteGameObject(const std::string& name);

private:
	static std::forward_list<std::shared_ptr<GameObject>> m_gameObject;
};