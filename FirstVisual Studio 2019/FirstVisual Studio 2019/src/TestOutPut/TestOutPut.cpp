#include "TestOutPut.h"
#include "../GameObject/GameObject.h"
#include <iostream>

using namespace std;

void TestOutPut::Update()
{
	cout << GetGameObject().lock()->GetName() << "Update" << endl;
}

void TestOutPut::Draw()
{
	cout << GetGameObject().lock()->GetName() << "Draw" << endl;
}

