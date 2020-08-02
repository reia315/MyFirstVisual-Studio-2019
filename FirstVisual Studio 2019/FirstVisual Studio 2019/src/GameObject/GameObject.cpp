#include"GameObject.h"
#include "../Component/Component.h"

GameObject::GameObject(const std::string& name):m_name{name}{}

//m_componentsは必要ない気がする＜－コピーするときは空でないと無限ループしてしまう
GameObject::GameObject(const std::weak_ptr<const GameObject>& other) : m_name{ other.lock()->m_name } /*, m_components {other.lock()->m_components}*/ {}

const std::string& GameObject::GetName()const
{
	return m_name;
}

void GameObject::AddComponent(const std::weak_ptr<Component>& component)
{
	component.lock()->SetGameObject(weak_from_this());
	m_components.push_front(component);
}

void GameObject::Destroy()
{
	//自分が持っているコンポーネントの死亡フラグを立てる
	for (const auto& component : m_components)
	{
		component.lock()->Destroy();
	}

	//自分の死亡フラグをONに
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


