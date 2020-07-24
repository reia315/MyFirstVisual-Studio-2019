#include "Component.h"
#include "../GameObject/GameObject.h"
#include <iostream>

using namespace std;

Component::Component()
{
}

const std::weak_ptr<GameObject>& Component::GetGameObject() const
{
	return m_gameObject;
}

void Component::SetGameObject(const std::weak_ptr<GameObject>& gameObject)
{
	m_gameObject = gameObject;
}
