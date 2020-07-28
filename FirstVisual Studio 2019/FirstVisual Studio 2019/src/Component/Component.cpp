#include "Component.h"
#include "../GameObject/GameObject.h"
#include <iostream>


Component::Component()
{
}

const std::weak_ptr<GameObject>& Component::GetGameObject() const
{
	return m_user;
}

void Component::SetGameObject(const std::weak_ptr<GameObject>& gameObject)
{
	m_user = gameObject;
}

void Component::Destroy()
{
	m_isDead = true;
}

bool Component::IsDead() const
{
	return m_isDead;
}
