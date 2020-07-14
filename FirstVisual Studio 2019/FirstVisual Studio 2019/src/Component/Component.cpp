#include "Component.h"
#include <iostream>

using namespace std;

Component::Component()
{
}

void Component::Update()
{
	cout << "Update" << endl;
}

void Component::Draw()
{
	cout << "Draw" << endl;
}
