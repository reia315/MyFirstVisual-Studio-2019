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
	
	{
		auto component = ComponentManager::GenerateComponent();
		GameObjectManager::GenerateGameObject("ObjectA").lock()->AddComponent(component);
	}
	{
		auto component = ComponentManager::GenerateComponent();
		GameObjectManager::GenerateGameObject("ObjectB").lock()->AddComponent(component);
	}

	cout << "�v���O�����J�n" << endl;

	//�R�}���h����
	while (command!="end")
	{
		cout << "�t���[���X�V" << endl;

	
		ComponentManager::update();

		cout << endl;

		ComponentManager::draw();

		cout << endl;

		//update��draw�̕\��

		cin >> command;
	

	    if (command == "add")
		{
		    string name;
			cout << "�I�u�W�F�N�g������ ->";
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
