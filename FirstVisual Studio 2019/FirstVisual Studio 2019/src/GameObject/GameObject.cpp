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
	m_components.push_back(component);
}

void GameObject::Destroy()
{
	//Ž©•ª‚ÌŽ€–Sƒtƒ‰ƒO‚ðON‚É
	m_isDead = true;
}

bool GameObject::IsDead()
{
	return m_isDead;
}


