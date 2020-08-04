#pragma once
#include <memory>
#include <string>

//前方宣言
class GameObject;

class Component:public std::enable_shared_from_this<Component>
{
public:
	//コンストラクタ
	Component();

	//更新処理
	virtual void Update() {};
	//描画処理
	virtual void Draw() {};
	virtual std::weak_ptr<Component>CloneComponent() const = 0;
	virtual void Input(const std::string& inputStr) {};


	//このコンポーネントのユーザーを取得する
	const std::weak_ptr<GameObject>& GetGameObject() const; 
	//このコンポーネントのユーザーを設定する
	void SetGameObject(const std::weak_ptr<GameObject>& gameObject) ;
	//死亡フラグを立てる
	void Destroy();
	//死んでいるかの状態を返す
	bool IsDead() const;

private:

	std::weak_ptr<GameObject>m_user;

	//死亡フラグ
	bool m_isDead{ false };
	
};