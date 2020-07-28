#pragma once
#include <string>
#include <vector>
#include <memory>
#include "../ComponentManager/ComponentManager.h"

class Component;

class GameObject:public std::enable_shared_from_this<GameObject>
{
public:
	//const���t�@�����X���g�p
	//�������P�̃R���X�g���N�^�ɂ�explicit������
	explicit GameObject(const std::string& name);
	

	//const�Q�ƌ^�̖߂�l�i�d�l�p�r��const���t�@�����X�Ɠ����j
	const std::string& GetName()const;

	//�ϒ������̂Ƃ���ɂ�comst�Q�Ƃ����邱�Ƃ��ł���
	template<class T,class... Args>
	void CreateComponent(const Args&...args);

	void AddComponent(const std::weak_ptr<Component>& component);

	void Destroy();

	bool IsDead();

private:
	
	std::string m_name;

	std::vector<std::weak_ptr<Component>> m_components;

	//���S�t���O
	bool m_isDead{ false };


};

template<class T, class ...Args>
inline void GameObject::CreateComponent(const Args&...args)
{
	auto component = ComponentManager::GenerateComponent<T>(args...);
	component.lock()->SetGameObject(weak_from_this());
	m_components.push_back(component);
}
