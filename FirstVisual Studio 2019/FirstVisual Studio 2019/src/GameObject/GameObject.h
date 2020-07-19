#pragma once
#include <string>
#include <vector>
#include <memory>

class Component;

class GameObject:public std::enable_shared_from_this<GameObject>
{
public:
	//const���t�@�����X���g�p
	GameObject(const std::string& name);
	

	//const�Q�ƌ^�̖߂�l�i�d�l�p�r��const���t�@�����X�Ɠ����j
	const std::string& GetName()const;

	void AddComponent();

private:

	std::string m_name;

	std::vector<std::weak_ptr<Component>> m_components;


};