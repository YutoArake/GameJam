#include "Model.h"
#include "WorldTransform.h"
#pragma once

enum FoodID {
	curry,
	yakiniku,
	medamayaki,
	nikujaga,
	salada
};

enum materialID {
	butaniku,
	gyuuniku,
	toriniku,
	tamago,
	retasu,
	imo,
	tomato,
	ninnjinn,
	tamanegi,
	kome
};

/// <summary>
/// 料理素材用クラス
/// </summary>
class Food {
private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;
	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;

	// 速度
	Vector3 velocity_ = { 0.0f,0.5f,0.0f };

	// 寿命<frm>
	static const int32_t kLifeTime = 60 * 5;

	// デスタイマー
	int32_t dethTimer_ = kLifeTime;
	// デスフラグ
	bool isDead_ = false;

public:
	bool IsDead() const { return isDead_; }
	void IsDeath() { isDead_ = true; }
	float r = 0.5;

public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(Model* model, const Vector3& position);

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw(const ViewProjection& viewProjection);

	/// <summary>
	/// 衝突を検知したら呼び出されるコールバック関数
	/// </summary>
	void OnCollision();

	/// <summary>
	/// ワールド座標を取得
	/// </summary>
	Vector3 GetWorldPosition();
};
