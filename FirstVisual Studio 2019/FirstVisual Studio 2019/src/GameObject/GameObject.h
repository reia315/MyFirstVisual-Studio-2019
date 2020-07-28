#pragma once
#include <string>
#include <vector>
#include <memory>
#include "../ComponentManager/ComponentManager.h"

class Component;

class GameObject:public std::enable_shared_from_this<GameObject>
{
public:
	//constリファレンスを使用
	//引数が１つのコンストラクタにはexplicitをつける
	explicit GameObject(const std::string& name);
	

	//const参照型の戻り値（仕様用途はconstリファレンスと同じ）
	const std::string& GetName()const;

	//可変長引数のところにもcomst参照をつけることができる
	template<class T,class... Args>
	void CreateComponent(const Args&...args);

	void AddComponent(const std::weak_ptr<Component>& component);

	void Destroy();

	bool IsDead();

private:
	
	std::string m_name;

	std::vector<std::weak_ptr<Component>> m_components;

	//死亡フラグ
	bool m_isDead{ false };


};

template<class T, class ...Args>
inline void GameObject::CreateComponent(const Args&...args)
{
	auto component = ComponentManager::GenerateComponent<T>(args...);
	component.lock()->SetGameObject(weak_from_this());
	m_components.push_back(component);
}
