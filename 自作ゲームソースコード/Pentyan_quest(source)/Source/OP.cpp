#include "Main.h"

void COP::Reset() {
	//オープニング画面
	if (OP2 == 0){
		Texture = GetTexture(L"OP.png");
	}
	Scale = CVector(1.01f, 0.77f, 1.00f) * 1.1;
	//Scale = CVector(1.00f, 0.77f, 1.00f) * 0.8f;
	
}
void COP1::Reset() {
	//ゲームオーバー画面
	Texture = GetTexture(L"GAMEOVER.png");
	//Scale = CVector(1.111f, 0.836f, 1.00f) * 1;
	Scale = CVector(1.03f, 0.8f, 1.00f) * 1.1;
	Color = CColor(1, 1, 1, 1);
}
void COP2::Reset() {
	//クリアー画面
	Texture = GetTexture(L"CLEAR.png");
	//Scale = CVector(1.111f, 0.836f, 1.00f) * 1;
	Scale = CVector(1.03f, 0.8f, 1.00f) * 1.1;
	Color = CColor(1, 1, 1, 1);
}

//移動
void COP::Move() {
	StageList.Apply([&](CMover* s) {
		if (s->Type == 0 && KeyState[0][DIK_SPACE] && !OldKeyState[0][DIK_SPACE]) {
			OP2++;
			if (OP2 == 1){
				Texture = GetTexture(L"OP01.png");
			}
			if (OP2 == 2){
				s->Type = 1;
				s->Reset();
			}
		}
	});
}
//ゲームオーバー
void COP1::Move() {
	if (GOV == 1){
		StageList.Apply([&](CMover* s) {
				s->Type = 4;
				s->Reset();
		});
	}
	if (RW == 1){
		Rotation = RotationZ(0.5f);
	}
}
//ゲームクリア
void COP2::Move() {
	if (CLR == 1){
		StageList.Apply([&](CMover* s) {
			s->Type = 5;
			s->Reset();
		});
	}
}
