#include"GameObject.h"
#include "../Component/Component.h"

GameObject::GameObject(const std::string& name):m_name{name}{}

const std::string& GameObject::GetName()const
{
	return m_name;
}

void GameObject::AddComponent(const std::weak_ptr<Component>& component)
{
	//auto component = ComponentManager::GeneratComponent();
	component.lock()->SetGameObject(weak_from_this());
	m_components.push_front(component);
}

void GameObject::Destroy()
{
	//�����������Ă���R���|�[�l���g�̎��S�t���O�𗧂Ă�
	for (const auto& component : m_components)
	{
		component.lock()->Destroy();
	}

	//�����̎��S�t���O��ON��
	m_isDead = true;
}

bool GameObject::IsDead() const
{
	return m_isDead;
}

const std::forward_list<std::weak_ptr<Component>>& GameObject::GetComponentAll() const
{
	return m_components;
}


