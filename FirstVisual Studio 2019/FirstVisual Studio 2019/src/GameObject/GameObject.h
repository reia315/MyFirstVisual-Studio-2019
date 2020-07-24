#pragma once
#include <string>
#include <vector>
#include <memory>

class Component;

class GameObject:public std::enable_shared_from_this<GameObject>
{
public:
	//const���t�@�����X���g�p
	//�������P�̃R���X�g���N�^�ɂ�explicit������
	explicit GameObject(const std::string& name);
	

	//const�Q�ƌ^�̖߂�l�i�d�l�p�r��const���t�@�����X�Ɠ����j
	const std::string& GetName()const;

	template<class T,class... Args>
	void CreateComponent(Args...args);

	void AddComponent(const std::weak_ptr<Component>& component);

private:

	std::string m_name;

	std::vector<std::weak_ptr<Component>> m_components;


};

template<class T, class ...Args>
inline void GameObject::CreateComponent(Args...args)
{
	auto component = ComponentManager::GenerateComponent<T>(args...);
	component.lock()->SetGameObject(weak_from_this());
	m_components.push_back(component);
}
