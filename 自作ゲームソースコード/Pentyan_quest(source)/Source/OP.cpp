#include "Main.h"

void COP::Reset() {
	//�I�[�v�j���O���
	if (OP2 == 0){
		Texture = GetTexture(L"OP.png");
	}
	Scale = CVector(1.01f, 0.77f, 1.00f) * 1.1;
	//Scale = CVector(1.00f, 0.77f, 1.00f) * 0.8f;
	
}
void COP1::Reset() {
	//�Q�[���I�[�o�[���
	Texture = GetTexture(L"GAMEOVER.png");
	//Scale = CVector(1.111f, 0.836f, 1.00f) * 1;
	Scale = CVector(1.03f, 0.8f, 1.00f) * 1.1;
	Color = CColor(1, 1, 1, 1);
}
void COP2::Reset() {
	//�N���A�[���
	Texture = GetTexture(L"CLEAR.png");
	//Scale = CVector(1.111f, 0.836f, 1.00f) * 1;
	Scale = CVector(1.03f, 0.8f, 1.00f) * 1.1;
	Color = CColor(1, 1, 1, 1);
}

//�ړ�
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
//�Q�[���I�[�o�[
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
//�Q�[���N���A
void COP2::Move() {
	if (CLR == 1){
		StageList.Apply([&](CMover* s) {
			s->Type = 5;
			s->Reset();
		});
	}
}
