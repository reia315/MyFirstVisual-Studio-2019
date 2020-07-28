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