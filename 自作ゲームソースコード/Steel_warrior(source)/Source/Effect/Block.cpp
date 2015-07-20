#include "..\Main\Main.h"

// ブロックの初期化
void CBlock::Reset() {
	Model = GetModel(L"LOCK\\triangle.x");
	Scale = CVector(1, 1, 1)*0.01f;
	Color = CColor(1, 1, 1, 0.0f);
	Life = 2;
	New<CEffect22>()->Owner = this;//OwnerはEnemy

}

// ブロックの移動
void CBlock::Move() {
	CameraList.Apply([&](CMover* c) {
		CVector p = Position;//最初に座標を保存しておくのがミソ
		Position.Homing(c->Position, 0.0001f);
		Rotation = CQuaternion(AXIS_Z, Position - p, -AXIS_Y);
		Position = Owner->Position + CVector(0, 0.3f, 0)*c->Rotation;
	});
	State = Owner->State;
	TargetState = Owner->TargetState;
	if (Owner->Life<=0){
		Life = 0;
	}
}

// ランプの初期化
void CLamp::Reset() {
	Model = GetModel(L"PATIKOMA\\ranpu.x");
	Scale = CVector(1, 1, 1)*0.7f;
	Color = CColor(1, 0.2f, 0.2f, 0.7f);
}

// ランプの移動
void CLamp::Move() {
	Position = Owner->Position;
	Rotation = Owner->Rotation;
	EmissiveColor = CColor(1, Random(0.2, 0.2f), Random(0.2f, 0.2f), Random(1.0f,0.0f));
	//SpecularColor = CColor(1, 1, 1, Random(9,1));
}
