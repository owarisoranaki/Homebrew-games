#include "Main.h"

// íeÇÃèâä˙âª
void CBullet::Reset() {
	Texture=GetTexture(L"Bullet.png");
	Scale=CVector(1, 1, 1)*0.05f;

	//à√à≈
	Texture = GetTexture(L"white.png");
	Scale = CVector(2, 2, 1);
	Color = CColor(0, 0, 0, 1);
	Life = 2;
}
void CBullet1::Reset() {
	New<CWeapon11>()->Owner = this;
	Scale = CVector(1, 1, 1)*0.08f;
	Color = CColor(1, 1, 1, 1)*1.0f;
}
void CBullet2::Reset() {
	Texture = GetTexture(L"Bullet.png");
	
	Scale = CVector(1, 1, 1)*0.08f;
	Color = CColor(1, 1, 1, 1)*0.0f;
}

// íeÇÃà⁄ìÆ
void CBullet::Move() {
	//à√à≈
	Life--;
}
void CBullet1::Move() {
	//Rotation *= RotationZ(0.02f);
	TIME++;
	if (TIME < 50){
		//Position.X += 0.001f;
		Position.Y += 0.007f;
	}
	if (TIME > 60){
		KRM = 1;
	}
	
	if (Time % 60 == 10)Texture = GetTexture(L"kurima1.png");
	if (Time % 60 == 20)Texture = GetTexture(L"kurima2.png");
	if (Time % 60 == 30)Texture = GetTexture(L"kurima3.png");
	if (Time % 60 == 40)Texture = GetTexture(L"kurima4.png");
	if (Time % 60 == 50)Texture = GetTexture(L"kurima5.png");
	Time++;
}
void CBullet2::Move() {
	/*if (KeyState[0][DIK_D] && !OldKeyState[0][DIK_D]) {
		New<CWeapon12>(Position);
	}*/
	if (BOSSHP==1) {
		if (Time % 300 == 0)New<CWeapon12>(Position);
			Time++;
	}

}

