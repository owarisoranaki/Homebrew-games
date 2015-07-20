#include "Main.h"

// カメラの初期化
void CCamera::Reset() {
	Scale = CVector(1, 1, 1)*0.9f;
	//Scale = CVector(1, 1, 1)*0.13f;
}

// カメラの移動
void CCamera::Move() {

	MyShipList.Apply([&](CMover* m) {
		Position=m->Position+CVector(0, 0,-10);
		//菓子カメラ
		if (CS == 0&&CP==0&&GOV==0){
			if (Position.X<1) Position.X = 1;
			if (Position.X>31) Position.X = 31;
			if (Position.Y < -1.6f) Position.Y = -1.6f;
			if (Position.Y < -1.7) CS = 1;
		}

		//洞窟カメラ1
		if (CP == 1 && CS != 1 && GOV == 0){
			if (Position.X<1) Position.X = 1;
			if (Position.X>31) Position.X = 31;
			if (Position.Y < -2.05f) Position.Y = -2.05f;
			if (Position.Y > -1.0f) Position.Y = -0.8f;
		}

		//洞窟カメラ2
		if (CS == 1 && GOV == 0){
			if (Position.X<1) Position.X = 1;
			if (Position.X>31) Position.X = 31;
			if (Position.Y < -3.1f) Position.Y = -4.2f;
		}

		//Boss部屋カメラ
		if (CS == 3 && GOV == 0){
			if (Position.X<1) Position.X = 1;
			if (Position.X>5.2f) Position.X = 5.2f;
			if (Position.Y < -1.6f) Position.Y = -1.6f;
			if (Position.Y < -1.7) CS = 1;
			if (Position.Y > -1) CS = 4;
		}
		//Boss反転カメラ
		if (CS == 4 && GOV == 0){
			if (Position.X<1) Position.X = 1;
			if (Position.X>5.2f) Position.X = 5.2f;
			if (Position.Y < -1.6f) Position.Y = -2.05f;
			if (Position.Y > -2.2) CS = 3;
			if (Position.Y > -0.9f) Position.Y = -0.8;
		}
		
	});

	//	オープニングカメラ
	OPList.Apply([&](CMover* o) {
		Position = o->Position + CVector(0, 0, -10);
		if (CP == 3 && GOV == 0){
			if (Position.X<1) Position.X = 1;
			if (Position.X>31) Position.X = 31;
			if (Position.Y < -1.6f) Position.Y = -1.6f;
			if (Position.Y < -1.7) CS = 1;
		}
	});
	//	ゲームオーバーカメラ
	OP1List.Apply([&](CMover* o) {
		Position = o->Position + CVector(0, 0, -10);
		if (GOV==1){
			if (Position.X<1) Position.X = 1;
			if (Position.X>31) Position.X = 31;
			if (Position.Y < -1.6f) Position.Y = -1.6f;
			if (Position.Y < -1.7) CS = 1;
		}
	});
	//	クリアーカメラ
	OP2List.Apply([&](CMover* o) {
		Position = o->Position + CVector(0, 0, -10);
		if (CLR == 1){
			if (Position.X<1) Position.X = 1;
			if (Position.X>31) Position.X = 31;
			if (Position.Y < -1.6f) Position.Y = -1.6f;
			if (Position.Y < -1.7) CS = 1;
		}
	});
	


	//キャラ逆転（上下）
	if (KeyState[0][DIK_H]) {
		//Rotation = RotationZ(0.5f);
	}

	
}
