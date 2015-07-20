#include "Main.h"

// Œø‰Ê‚Ì‰Šú‰»
void CEffect::Reset() {
	Texture=GetTexture(L"Effect.png");
	Scale=CVector(1, 1, 1)*0.1f;
	Texture = GetTexture(L"Hit.png");
	Scale = CVector(1, 1, 1)*0.4f;
	Color = CColor(1, 1, 1, 0.01f);
	Life = 2;
}
void CEffect1::Reset() {
	//”š”­
	GetWave(L"se_maoudamashii_explosion06.wav")->Play(1);
	GetWave(L"se_maoudamashii_explosion06.wav")->SetVolume(0.07f);
}
void CEffect2::Reset() {
	//”wŒi
	Texture = GetTexture(L"haikei.png");
	Scale = CVector(2.55f, 0.65f, 1)*2;
	Color = CColor(2, 1, 1, 1);
	Time++;
}
void CEffect3::Reset() {
	Texture = GetTexture(L"Block3-2.png");
	//•XŠ„‚ê‚é
	GetWave(L"sei_ge_wareru03.wav")->Play(1);
	GetWave(L"sei_ge_wareru03.wav")->SetVolume(0.05f);
}
void CEffect4::Reset() {
	//•XŠ„‚ê‚é
	GetWave(L"sei_ge_wareru03.wav")->Play(1);
	GetWave(L"sei_ge_wareru03.wav")->SetVolume(0.07f);
}
void CEffect5::Reset() {
	//”š”­
	GetWave(L"se_maoudamashii_explosion06.wav")->Play(1);
	GetWave(L"se_maoudamashii_explosion06.wav")->SetVolume(0.07f);
}
void CEffect6::Reset() {
	//•XŠ„‚ê‚é
	GetWave(L"sei_ge_wareru03.wav")->Play(1);
	GetWave(L"sei_ge_wareru03.wav")->SetVolume(0.07f);
}
void CEffect7::Reset() {
	//”š”­
	GetWave(L"se_maoudamashii_explosion06.wav")->Play(1);
	GetWave(L"se_maoudamashii_explosion06.wav")->SetVolume(0.07f);
}
void CEffect8::Reset() {
	//”wŒi2
	Texture = GetTexture(L"okasimen.png");
	Scale = CVector(15.9f, 1.1, 1);
	Color = CColor(1, 1, 1, 1);
}
void CEffect9::Reset() {
	//”wŒi3
	Texture = GetTexture(L"suisyoumen.png");
	Scale = CVector(15.9f, 1.1, 1);
	Color = CColor(1, 1, 1, 1);
}
void CEffect10::Reset() {
	//”wŒi4

	if (CS != 3 || CS != 4){
		Texture = GetTexture(L"suisyoumen2.png");
		Color = CColor(1, 1, 1, 1);
	}

	if (CS == 3 || CS == 4){
		Texture = GetTexture(L"suisyoumen2.png");
		Color = CColor(1, 0, 0, 1);
	}
	Scale = CVector(15.9f, 1.1, 1);
	
}
void CEffect11::Reset() {
	//”wŒi5
	Texture = GetTexture(L"okasimen2.png");
	Scale = CVector(15.9f, 1.1, 1);
	Color = CColor(1, 1, 1, 1);
}
void CEffect12::Reset() {
	//ƒAƒCƒeƒ€˜g
	//Texture = GetTexture(L"bukiwaku.png");
	Scale = CVector(1, 1, 1)*0.1f;
	//Color = CColor(1, 1, 1, 1);
}
void CEffect13::Reset() {
	//ƒAƒCƒeƒ€•XŽè— Œ•
	Texture = GetTexture(L"Weapon2.png");
	Scale = CVector(1, 1, 1)*0.1f;
	//Color = CColor(1, 1, 1, 1);
}
void CEffect14::Reset() {
	//ƒAƒCƒeƒ€”š’e
	Texture = GetTexture(L"bom.png");
	Scale = CVector(1, 1, 1)*0.06f;
	//Color = CColor(1, 1, 1, 1);
}
void CEffect15::Reset() {
}
void CEffect16::Reset() {
	//ƒAƒCƒeƒ€“ƒu[ƒƒ‰ƒ“
	Texture = GetTexture(L"momobuki.png");
	Scale = CVector(1, 1, 1)*0.06f;
	//Color = CColor(1, 1, 1, 1);
}
void CEffect17::Reset() {
	//•\Ž¦ƒuƒƒbƒN
	
	Scale = CVector(1, 1, 1)*0.045f;
	Color = CColor(1, 1, 1, 1);
}
void CEffect18::Reset() {
	Texture = GetTexture(L"pen-l6.png");
	Scale = CVector(1, 1, 1)*0.07f;
	Color = CColor(1, 1, 1, 1)*0.8f;
}
void CEffect19::Reset() {
	Texture = GetTexture(L"pen-r6.png");
	Scale = CVector(1, 1, 1)*0.07f;
	Color = CColor(1, 1, 1, 1)*0.8f;
}
void CEffect20::Reset() {
	Texture = GetTexture(L"boss_kao1.png");
	Scale = CVector(1.07f, 1, 1)*0.30f;
	//Scale = CVector(1, 1, 1)*0.07f;
	if (BOSSC == 0)Color = CColor(1, 1, 1, 1)*0.8f;
	if (BOSSC == 1)Color = CColor(1, 0, 0, 1)*0.8f;
	
}
void CEffect21::Reset() {
	Texture = GetTexture(L"kurima1.png");
	//Scale = CVector(1, 1, 1)*0.07f;
	Color = CColor(1, 1, 1, 1);
	Scale = CVector(1, 1, 1)*0.05f;
}
void CEffect22::Reset() {
	Texture = GetTexture(L"kurima2.png");
	//Scale = CVector(1, 1, 1)*0.07f;
	Color = CColor(1, 1, 1, 1);
	Scale = CVector(1, 1, 1)*0.03f;
}
void CEffect23::Reset() {
	Texture = GetTexture(L"iwa.png");
	//Scale = CVector(1, 1, 1)*0.07f;
	Color = CColor(1, 1, 1, 1)*0.7f;
	Scale = CVector(1, 1, 1)*0.2f;
}
//--------------------------------------------------------------------------------------------
// Œø‰Ê‚ÌˆÚ“®
void CEffect::Move() {
	Life--;
}
void CEffect1::Move() {
	if (Time % 30 == 0)Texture = GetTexture(L"bakuha1.png");
	if (Time % 30 == 10)Texture = GetTexture(L"bakuha2.png");
	if (Time % 30 == 15)Texture = GetTexture(L"bakuha3.png");
	if (Time % 30 == 20)Texture = GetTexture(L"bakuha4.png");
	if (Time % 30 == 25){ Life = 0; }
	Scale = CVector(1, 1, 1)*0.1f;
	Color = CColor(1, 1, 1, 0.9f);
	Time++;
}
	
void CEffect2::Move() {

}
void CEffect3::Move() {
	//Life--;
	if (Time % 40 == 10){ Life = 0; }
	Time++;
	Scale = CVector(1, 1, 1)*0.1f;
	Color = CColor(1, 1, 1, 0.9f);
}
void CEffect4::Move() {
	Texture = GetTexture(L"Block3-2.png");
	if (Time % 40 == 8){ Life = 0; }
	Time++;
	Scale = CVector(1, 1, 1)*0.15f;
	Color = CColor(1, 1, 1, 0.9f);
}
void CEffect5::Move() {
	if (Time % 40 == 0)Texture = GetTexture(L"bom_ha1.png");
	if (Time % 40 == 10)Texture = GetTexture(L"bom_ha2.png");
	if (Time % 40 == 15)Texture = GetTexture(L"bom_ha3.png");
	if (Time % 40 == 20)Texture = GetTexture(L"bom_ha4.png");
	if (Time % 40 == 25)Texture = GetTexture(L"bom_ha5.png");
	if (Time % 40 == 30)Texture = GetTexture(L"bom_ha6.png");
	if (Time % 40 == 35){ Life = 0; }
	if (Time % 40 == 36){ ef = 1; }
	Scale = CVector(1, 1, 1)*0.15f;
	Color = CColor(1, 1, 1, 0.9f);
	Time++;
}
void CEffect6::Move() {
	Texture = GetTexture(L"Block3-2.png");
	if (Time % 40 == 8){ Life = 0; }
	Time++;
	Scale = CVector(1, 1, 1)*0.1f;
	Color = CColor(1, 1, 1, 0.9f);
}
void CEffect7::Move() {
	if (Time % 30 == 0)Texture = GetTexture(L"bakuha1.png");
	if (Time % 30 == 10)Texture = GetTexture(L"bakuha2.png");
	if (Time % 30 == 15)Texture = GetTexture(L"bakuha3.png");
	if (Time % 30 == 20)Texture = GetTexture(L"bakuha4.png");
	if (Time % 30 == 25){ Life = 0; }
	Scale = CVector(1, 1, 1)*0.4f;
	Color = CColor(1, 1, 1, 0.9f);
	Time++;
}
void CEffect8::Move() {

}
void CEffect9::Move() {

}
void CEffect10::Move() {

}
void CEffect11::Move() {

}
void CEffect12::Move() {//ƒAƒCƒeƒ€˜g
	Texture = GetTexture(L"bukiwaku.png");
	if (RW == 0){
		Position = CVector(Camera->Position.X, Camera->Position.Y + 0.72f, 0);
	}
	if (RW == 1){
		Position = CVector(Camera->Position.X, Camera->Position.Y - 0.72f, 0);
	}
}
void CEffect13::Move() {//Žè— Œ•
	if (SI == 0 && RW==0){
		Position = CVector(Camera->Position.X - 0.007,Camera->Position.Y + 0.73f,0);
	}
	if (SI == 0 && RW == 1){
		Position = CVector(Camera->Position.X - 0.007, Camera->Position.Y - 0.71f, 0);
	}
	if (SI == 1){
		Life = 0;
		if (Life == 0) { New<CEffect14>(Position); }
	}
	if (SI == 2){
		Life = 0;
		if (Life == 0) { New<CEffect16>(Position); }
	}
}
void CEffect14::Move() {//”š’e
	if (SI == 1 && RW == 0){
		Position = CVector(Camera->Position.X - 0.005,Camera->Position.Y + 0.72f,0);
	}
	if (SI == 1 && RW == 1){
		Position = CVector(Camera->Position.X - 0.005, Camera->Position.Y - 0.71f, 0);
	}
	if (SI == 0){
		Life = 0;
		if (Life == 0) { New<CEffect13>(Position); }
	}
	if (SI == 2){
		Life = 0;
		if (Life == 0) { New<CEffect16>(Position); }
	}
}
void CEffect15::Move() {
	Texture = GetTexture(L"Block3-2R.png");
	if (Time % 40 == 8){ Life = 0; }
	Time++;
	Scale = CVector(1, 1, 1)*0.1f;
	Color = CColor(1, 1, 1, 0.9f);
}
void CEffect16::Move() {//”š’e
	if (SI == 2 && RW == 0){
		Position = CVector(Camera->Position.X - 0.005, Camera->Position.Y + 0.72f, 0);
	}
	if (SI == 2 && RW == 1){
		Position = CVector(Camera->Position.X - 0.005, Camera->Position.Y - 0.71f, 0);
	}
	if (SI == 0){
		Life = 0;
		if (Life == 0) { New<CEffect13>(Position); }
	}
	if (SI == 1){
		Life = 0;
		if (Life == 0) { New<CEffect14>(Position); }
	}
}
void CEffect17::Move() {//•\Ž¦•XƒuƒƒbƒN//BT:ƒuƒƒbƒNƒ^ƒCƒviNƒL[j
	
	if (RW == 0&&BT==0){
		Texture = GetTexture(L"Block_DD.png");
		Position = CVector(Camera->Position.X-0.84, Camera->Position.Y + 0.61f, 0);
	}

	if (RW == 0 && BT == 1){
		Texture = GetTexture(L"Block_RR.png");
		Position = CVector(Camera->Position.X - 0.84, Camera->Position.Y + 0.61f, 0);
		
	}
	
	if (RW == 0 && BT == 2){
		Texture = GetTexture(L"Block_LL.png");
		Position = CVector(Camera->Position.X - 0.84, Camera->Position.Y + 0.61f, 0);
	}

	if (RW == 1){
		Position = CVector(Camera->Position.X, Camera->Position.Y - 0.72f, 0);
	}


	if (RW == 1 && BT == 0){
		Texture = GetTexture(L"Block_DD1.png");
		Position = CVector(Camera->Position.X + 0.84, Camera->Position.Y - 0.61f, 0);
	}

	if (RW == 1 && BT == 1){
		Texture = GetTexture(L"Block_RR.png");
		Position = CVector(Camera->Position.X + 0.84, Camera->Position.Y - 0.61f, 0);
	}

	if (RW == 1 && BT == 2){
		Texture = GetTexture(L"Block_LL.png");
		Position = CVector(Camera->Position.X + 0.84, Camera->Position.Y - 0.61f, 0);
	}
}
void CEffect18::Move() {
	Color.A -= 0.05f;
	if (Color.A <= 0) Life = 0;
}
void CEffect19::Move() {
	Color.A -= 0.05f;
	if (Color.A <= 0) Life = 0;
}
void CEffect20::Move() {
	Color.A -= 0.05f;
	if (Color.A <= 0) Life = 0;
}
void CEffect21::Move() {

	Color.A -= 0.02f;
	if (Color.A <= 0) Life = 0;
}
void CEffect22::Move() {
	Rotation = Owner->Rotation;
	Position = Owner->Position + Owner->AxisY()*Time*0.01f;
	Time++;
}
void CEffect23::Move() {
	Color.A -= 0.05f;
	if (Color.A <= 0) Life = 0;
}