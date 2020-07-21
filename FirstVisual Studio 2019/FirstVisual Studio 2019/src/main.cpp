#include <iostream>
#include <memory>
#include "GameObject/GameObject.h"
#include "ComponentManager/ComponentManager.h"
#include "GameObjectManager/GameObjectManager.h"

using namespace std;

int main()
{
	//�R�}���h���͒l
	string command="";
	bool count = true;
	
	{
		auto component = ComponentManager::GenerateComponent();
		GameObjectManager::GenerateGameObject("ObjectA").lock()->AddComponent(component);
	}
	{
		auto component = ComponentManager::GenerateComponent();
		GameObjectManager::GenerateGameObject("ObjectB").lock()->AddComponent(component);
	}

	std::cout << "�v���O�����J�n" << endl;

	//�R�}���h����
	while (command!="end")
	{
		std::cout << "�t���[���X�V" << endl;

		if (command == "a" || count == true)
		{
			ComponentManager::update();

			std::cout << endl;

			ComponentManager::draw();

			std::cout << endl;

			//update��draw�̕\��
			
			count = false;
		}

		cin >> command;
	

	    if (command == "add")
		{
		    string name;
			std::cout << "�I�u�W�F�N�g������ ->";
			cin >> name;

			{
				auto component = ComponentManager::GenerateComponent();
				GameObjectManager::GenerateGameObject(name).lock()->AddComponent(component);
			}		

			ComponentManager::update();

			std::cout << endl;

			ComponentManager::draw();

			std::cout << endl;
		}

		std::cout << endl;
		
	}

	//�I�����ɓ���
	std::cout << "�v���O�����I��" << endl;
}
