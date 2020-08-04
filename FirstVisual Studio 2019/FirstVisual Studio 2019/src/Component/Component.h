#pragma once
#include <memory>
#include <string>

//�O���錾
class GameObject;

class Component:public std::enable_shared_from_this<Component>
{
public:
	//�R���X�g���N�^
	Component();

	//�X�V����
	virtual void Update() {};
	//�`�揈��
	virtual void Draw() {};
	virtual std::weak_ptr<Component>CloneComponent() const = 0;
	virtual void Input(const std::string& inputStr) {};


	//���̃R���|�[�l���g�̃��[�U�[���擾����
	const std::weak_ptr<GameObject>& GetGameObject() const; 
	//���̃R���|�[�l���g�̃��[�U�[��ݒ肷��
	void SetGameObject(const std::weak_ptr<GameObject>& gameObject) ;
	//���S�t���O�𗧂Ă�
	void Destroy();
	//����ł��邩�̏�Ԃ�Ԃ�
	bool IsDead() const;

private:

	std::weak_ptr<GameObject>m_user;

	//���S�t���O
	bool m_isDead{ false };
	
};