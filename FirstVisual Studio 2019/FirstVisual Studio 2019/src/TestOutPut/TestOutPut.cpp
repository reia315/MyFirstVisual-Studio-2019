#include "TestOutPut.h"
#include "../GameObject/GameObject.h"
#include <iostream>

using namespace std;

void TestOutPut::Update()
{
	cout << m_gameObject.lock()->GetName() << "Update" << endl;
}

void TestOutPut::Draw()
{
	cout << m_gameObject.lock()->GetName() << "Draw" << endl;
}

