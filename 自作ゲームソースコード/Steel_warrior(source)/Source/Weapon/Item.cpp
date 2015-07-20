#include "..\Main\Main.h"

// パチコマキャノンの初期化
void CItem::Reset() {
	Model = GetModel(L"PATIKOMA\\pati_canon.x");
	Scale = CVector(1, 1.0f, 1)*0.05f;
	Color = CColor(1, 1, 1,1);
}

// パチコマキャノンの移動
void CItem::Move() {
	EmissiveColor = CColor(0.5f, 0.5f, 0.5f, 0.2f);
	if (Owner){
		Position = Owner->Position + CVector(0, 7, -5)*Owner->Rotation;
	}
	//消滅
	if (Owner){
		if (Owner->Life <= 0){
			Life = 0;
		}
	}
	if (enemy_startup == Enemy_startup_on){
		//回転補正
		MyShipList.Apply([&](CMover* m) {
			if (SHOT_COUNT == 0){
				CVector p = m->Position;//最初に座標を保存しておくのがミソ
				Rotation.Interpolate(CQuaternion(AXIS_Z, p - Position, AXIS_Y), 0.05f);
			}
		});
		if (Owner){
			if (Owner->AttackState == 2){
				if (SHOT_COUNT == 0){
					TIME_COUNT++;
				}
				if (SHOT_COUNT == 1){
					TIME_COUNT++;
				}
				if (SHOT_COUNT == 0 && TIME_COUNT == 120){
					SHOT_COUNT = 1;
					New<CBullet8>(Position + CVector(0.0f, 0.0f, 8.0f)*Rotation)->Owner = this;
					//自機がいるときだけ
					if (myship_death == myship_death_off){
						E_beam();//ビーム発射音
					}
					TIME_COUNT = 0;
				}
				if (SHOT_COUNT == 1 && TIME_COUNT == 120){
					SHOT_COUNT = 0;
					TIME_COUNT = 0;
				}
			}
		}
	}
}
//===========================================================================================================================================
// パチコマキャノンジョイントの初期化
void CItem2::Reset() {
	Model = GetModel(L"PATIKOMA\\pati_canonjoint.x");
	Scale = CVector(1, 1.0f, 0.8f)*0.05f;
	Color = CColor(1, 1, 1, 1);
}

// パチコマキャノンジョイントの移動
void CItem2::Move() {
	if (Owner){
		Position = Owner->Position + CVector(0, 5.5f, -5)*Owner->Rotation;
		Rotation = Owner->Rotation;
	}
	if (Owner){
		if (Owner->Life <= 0){
			Life = 0;
		}
	}
}
//===========================================================================================================================================
// パチコマブレードの初期化
void CItem3::Reset() {
	Model = GetModel(L"ET_weapon\\ET_weapon.x");
	Scale = CVector(1, 1.0f, 0.8f)*0.06f;
	Color = CColor(1, 1, 1, 0.1f);
}

// パチコマキャノンブレードの移動
void CItem3::Move() {
	if (Owner){
		if (Owner->AttackState == 1){
			if (Scale.Z <= 0.18f){//0.048
				Scale.Z += 0.06f;
			}
		}
		
	}
	if (Owner){
		Position = Owner->Position + CVector(0.03f, -1.6f, 4)*Owner->Rotation;
		Rotation = RotationX(0.02f)*Owner->Rotation;
	}
	//消滅
	if (Owner){
		if (Owner->Life <= 0){
			Life = 0;
		}
		if (Owner->AttackState!=1){
			Life = 0;
		}
	}
	Color = CColor(1, 1, 0, 0.35f);
	ToonInkColor = CColor(1, 1, 0, 1.0f);
	EmissiveColor = CColor(1, 1, Random(0.5f, 0.2f), 0.3f);
	ToonInkSize = 0.002f;
	ToonInkEmissiveColor = CColor(1, 1, Random(0.5f, 0.2f), 1);

}
//===========================================================================================================================================
// ボスガンの初期化
void CItem4::Reset() {
	Model = GetModel(L"BOSS_WEAPON\\Boss_gun.x");
	Scale = CVector(1, 1.0f, 1.0f)*0.2f;
	Color = CColor(1, 1, 1, 1);
	GetWave(L"ENEMY_ATACK\\littleshot.wav")->Play(-1);
	GetWave(L"ENEMY_ATACK\\littleshot.wav")->SetVolume(0.0f);
}

// ボスガンの移動
void CItem4::Move() {
	if (clear == clear_good_on){
		Color = CColor(1, 1, 1, 0);
	}
	Time++;
	Enemy_Boss_modelList.Apply([&](CMover*bm){
		CModelBone* bl = Owner->GetBone(L"L_hand_Joint");
		CModelBone* br = Owner->GetBone(L"R_hand_Joint");
		//左手
		if (Type == 1){
			Rotation = RotationY(0.0f)*RotationX(-0.1f)*RotationY(0.0f)*bl->Rotation;
			Position = bl->Position;
			if (bm->AttackState == 1){
				if (Time % 10 == 0){
					New<CBullet9>(Position + CVector(0, 0, -7)*Rotation)->Owner = this;
					//自機がいるときだけ
					if (myship_death == myship_death_off){
						GetWave(L"ENEMY_ATACK\\littleshot.wav")->SetVolume(0.2f);
					}
					else if (myship_death == myship_death_on){
						GetWave(L"ENEMY_ATACK\\littleshot.wav")->SetVolume(0.0f);
					}
				}
				if (bm->AttackState != 1){
					GetWave(L"ENEMY_ATACK\\littleshot.wav")->SetVolume(0.0f);
				}
			}
		}
		//右手
		if (Type == 2){
			Rotation = RotationY(0.0f)*RotationX(-0.1f)*RotationY(0.0f)*br->Rotation;
			Position = br->Position;
			if (bm->AttackState == 1){
				if (Time % 10 == 0){
					New<CBullet9>(Position + CVector(0, 0, -7)*Rotation)->Owner = this;
					//自機がいるときだけ
					if (myship_death == myship_death_off){
						GetWave(L"ENEMY_ATACK\\littleshot.wav")->SetVolume(0.2f);
					}
					else if (myship_death == myship_death_on){
						GetWave(L"ENEMY_ATACK\\littleshot.wav")->SetVolume(0.0f);
					}
				}
			}
			if (bm->AttackState != 1){
				GetWave(L"ENEMY_ATACK\\littleshot.wav")->SetVolume(0.0f);
			}
		}
	});
	/*if (Owner){
		if (Type == 1){
			Rotation = RotationY(0.0f)*RotationX(-0.1f)*RotationY(0.0f)*Owner->Rotation;
			Position = Owner->Position + CVector(-5.5f, -4.0, -2)*Owner->Rotation;
		}
		if (Type == 2){
			Rotation = RotationY(0.0f)*RotationX(-0.1f)*RotationY(0.0f)*Owner->Rotation;
			Position = Owner->Position + CVector(5.5f, -4.0, -2)*Owner->Rotation;
		}
		Time++;
		if (Time % 10 == 0){
			if (Type == 1){
				//New<CBullet9>(Position + CVector(0, 0, -7)*Rotation)->Owner = this;
			}
			if (Type == 2){
				//New<CBullet9>(Position + CVector(0, 0, -7)*Rotation)->Owner = this;
			}
		}
	}*/

}