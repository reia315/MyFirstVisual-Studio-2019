#include "Component.h"
#include "../GameObject/GameObject.h"
#include <iostream>

using namespace std;

Component::Component()
{
}

void Component::SetGameObject(const std::weak_ptr<GameObject>& gameObject)
{
	m_gameObject = gameObject;
}
