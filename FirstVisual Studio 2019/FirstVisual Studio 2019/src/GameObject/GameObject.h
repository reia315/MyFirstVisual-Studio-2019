#pragma once
#include <string>

#include <vector>

#include <memory>

class GameObject
{
public:
	//const���t�@�����X���g�p
	GameObject(const std::string& name);
	
	//const�Q�ƌ^�̖߂�l�i�d�l�p�r��const���t�@�����X�Ɠ����j
	const std::string& GetName();

private:

	std::string m_name;

};