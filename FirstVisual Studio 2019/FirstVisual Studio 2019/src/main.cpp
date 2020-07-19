#include <iostream>
#include <memory>
#include "GameObject/GameObject.h"
#include "ComponentManager/ComponentManager.h"
#include "GameObjectManager/GameObjectManager.h"

using namespace std;

int main()
{
	//コマンド入力値
	string command="";

	GameObjectManager::GeneratGameObject("ObjectA").lock()->AddComponent();

	cout << "プログラム開始" << endl;

	//コマンド判別
	while (command!="end")
	{
		cout << "フレーム更新" << endl;

		ComponentManager::update();
        
		cout << endl;

		ComponentManager::draw();

		cout<<endl;

			//updateとdrawの表示
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
			cout << "オブジェクト名入力 ->";
			cin >> name;

			GameObjectManager::GeneratGameObject(name).lock()->AddComponent();
		}

		cout << endl;
		
	}

	//終了時に入力
	cout << "プログラム終了" << endl;
}
