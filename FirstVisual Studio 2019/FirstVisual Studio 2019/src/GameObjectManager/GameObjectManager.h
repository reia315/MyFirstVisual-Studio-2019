#pragma once
#include <string>       //������
#include <forward_list> //�O���z��
#include <memory>       //�X�}�[�g�|�C���^

class GameObject;

class GameObjectManager
{
public:

	static std::weak_ptr<GameObject> GenerateGameObject(const std::string& name);

private:
	static std::forward_list<std::shared_ptr<GameObject>> m_gameObject;
};