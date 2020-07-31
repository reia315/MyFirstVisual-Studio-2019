#pragma once
#include <string>       //������
#include <forward_list> //�O���z��
#include <memory>       //�X�}�[�g�|�C���^

class GameObject;

class GameObjectManager
{
public:
	//
	static std::forward_list<std::weak_ptr<GameObject>> SearchObject(const std::string& name);
	//
	static void UpdateGamObjectList();
	//
	static void DeleteGameObject(const std::string& name);
	//
	static std::weak_ptr<GameObject> GenerateGameObject(const std::string& name);

	//�I�u�W�F�N�g����
	static std::weak_ptr<GameObject>CloneGameObject(const std::weak_ptr<GameObject>& gameObject);

private:
	static std::forward_list<std::shared_ptr<GameObject>> m_gameObject;

	static std::forward_list<std::shared_ptr<GameObject>> m_addGaneObject;
};