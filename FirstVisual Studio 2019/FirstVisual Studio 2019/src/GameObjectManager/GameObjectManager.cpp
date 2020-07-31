#include "GameObjectManager.h"
#include "../GameObject/GameObject.h"
#include "../DestoryObject/DestoryObject.h"

std::forward_list<std::shared_ptr<GameObject>>GameObjectManager::m_gameObject;

std::forward_list<std::shared_ptr<GameObject>>GameObjectManager::m_addGaneObject;



std::forward_list<std::weak_ptr<GameObject>> GameObjectManager::SearchObject(const std::string& name)
{
	std::forward_list<std::weak_ptr<GameObject>> match;

	for (const auto& gameObject : m_gameObject)
	{
		if (gameObject->GetName() == name)
		{
			match.push_front(gameObject);
		}
	}

	return match;
}

void GameObjectManager::UpdateGamObjectList()
{
	for (const auto& gameObject : m_addGaneObject)
	{
		m_gameObject.push_front(gameObject);
	}
}

std::weak_ptr<GameObject> GameObjectManager::GenerateGameObject(const std::string& name)
{
	auto gameObject =std::make_shared<GameObject>(name);
	m_gameObject.push_front(gameObject);
	return gameObject;
}

void GameObjectManager::DeleteGameObject(const std::string& name)
{	
	//const auto& gameObject = std::remove(m_gameObject.begin(), m_gameObject.end(), name);


	//ラムダ式[]ランダムチャプター（）パラメーター定義節｛｝複合ステートメント（）関数呼び出し式；
	//gameObjectの中でIsDeadがtrueになってる要素を削除する
	m_gameObject.remove_if([](const auto& gameObject) {return gameObject->IsDead(); });//ラムダ式を使用
}

std::weak_ptr<GameObject> GameObjectManager::CloneGameObject(const std::weak_ptr<GameObject>& gameObject)
{
	auto clone = std::shared_ptr<GameObject>(gameObject);

	m_addGaneObject.push_front(clone);

	return clone;
}
