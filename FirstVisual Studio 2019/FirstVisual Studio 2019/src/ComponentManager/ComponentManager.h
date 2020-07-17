#pragma once
#include <list>�@�@//�O���z��
#include <memory>�@�@�@�@�@//�X�}�[�g�|�C���^

class Component;

class ComponentManager
{
public:

	//�X�V
	static void update();
	//�`��
	static void draw();
	//�R���|�[�l���g�N���X�̐���
	static std::weak_ptr<Component> GeneratComponent();


private:

	static std::list<std::shared_ptr<Component>>m_component;
};