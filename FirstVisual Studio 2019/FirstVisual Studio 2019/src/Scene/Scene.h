#pragma once

//�V�[�����N���X
class Scene
{
public:
	//�f�X�g���N�^
	virtual ~Scene() = 0;

	//�J�n����
	virtual void State() = 0;

	//�I������
	virtual void End() = 0;

};