#pragma once
#include <memory>

//前方宣言
class GameObject;

class Component
{
public:
	//コンストラクタ
	Component();

	//更新処理
	virtual void Update() {};
	//描画処理
	virtual void Draw() {};

	void SetGameObject(const std::weak_ptr<GameObject>& gameObject) ;

//private:

	std::weak_ptr<GameObject>m_gameObject;
	
};