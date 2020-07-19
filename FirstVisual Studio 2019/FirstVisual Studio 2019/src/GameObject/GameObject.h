#pragma once
#include <string>
#include <vector>
#include <memory>

class Component;

class GameObject:public std::enable_shared_from_this<GameObject>
{
public:
	//constリファレンスを使用
	GameObject(const std::string& name);
	

	//const参照型の戻り値（仕様用途はconstリファレンスと同じ）
	const std::string& GetName()const;

	void AddComponent();

private:

	std::string m_name;

	std::vector<std::weak_ptr<Component>> m_components;


};