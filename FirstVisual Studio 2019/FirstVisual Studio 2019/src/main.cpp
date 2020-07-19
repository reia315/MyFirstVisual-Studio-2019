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

	GameObjectManager::GeneratGameObject("ObjectA").lock()->AddComponent();

	cout << "�v���O�����J�n" << endl;

	//�R�}���h����
	while (command!="end")
	{
		cout << "�t���[���X�V" << endl;

		ComponentManager::update();
        
		cout << endl;

		ComponentManager::draw();

		cout<<endl;

			//update��draw�̕\��
		cin >> command;

	    if (command == "a")
		{
			ComponentManager::update();

			cout << endl;

			ComponentManager::draw();

			cout << endl;
		}
		else if (command == "add")
		{
		    string name;
			cout << "�I�u�W�F�N�g������ ->";
			cin >> name;

			GameObjectManager::GeneratGameObject(name).lock()->AddComponent();
		}

		cout << endl;
		
	}

	//�I�����ɓ���
	cout << "�v���O�����I��" << endl;
}
