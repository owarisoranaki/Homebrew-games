#include "..\Main\Main.h"

// 武器の初期化(ブレード)
void CWeapon::Reset() {
	//Model = GetModel(L"WEAPON\\blade.x");
	//Scale = CVector(1.0f, 1, 1)*0.6f;//0.6f
	Model = GetModel(L"WEAPON\\sword.x");
	Scale = CVector(1.5f, 1, 1)*2.7f;//0.6f
	Color = CColor(1, 1, 1, 0.0f);//0.0
}

// 武器の移動(ブレード)
void CWeapon::Move() {
	//ブレード左手に持たせる
	if (blade_hand_chang==left_hand){
		CModelBone* b = Owner->GetBone(L"L_kobusi_Joint");
		//順手持ち
		if (blade_hold == blade_hold_normal){
			Rotation = RotationY(0.0f)*RotationX(-0.25f)*RotationY(-0.02f)*b->Rotation;
			Position = b->Position + CVector(-0.05f, -0.3f, 0.12f)*b->Rotation;
		}
		//逆手持ち
		if (blade_hold == blade_hold_reverse){
			Rotation = RotationY(-0.025f)*RotationX(-0.23f)*RotationY(-0.5f)*b->Rotation;
			Position = b->Position + CVector(-0.05f, -0.3f, 0.12f)*b->Rotation;
		}
	}
	//ブレード右手に持たせる
	if (blade_hand_chang==right_hand){
		CModelBone* b = Owner->GetBone(L"R_kobusi_Joint");
		//順手持ち
		if (blade_hold == blade_hold_normal){
			Rotation = RotationY(0.0f)*RotationX(-0.25f)*RotationY(-0.02f)*b->Rotation;
			Position = b->Position + CVector(-0.05f, -0.3f, 0.12f)*b->Rotation;
		}
	}
	
	if (blade == blade_on){
		//ブレード出現
		Color = CColor(1, 1, 1, 1.0f);
	}
	if (blade == blade_off){
		//ブレード出現
		Color = CColor(1, 1, 1, 0.0f);
	}
	//ブレード光
	EmissiveColor = CColor(1, 1, 1, 1);

	//--------当たり判定-------------------------------------------------------------------------------------------------------
	//クリア条件にになっていない
	if (clear == clear_off){
		//ブレード出現中
		if (blade == blade_on){
			//メカペン
			CMover *HIT_ENEMY = NULL;
			CMover *HIT_ENEMY3 = NULL;
			EnemyList.Apply([&](CMover* e){
				CHit hit;
				if (e->BladeHitState == 1){
					if (ENEMY_BLADE_HIT == 0 && hit.SegmentAndModel(Position, Position - AxisY() * 13.8f, e, e->Model)){//中心・半径・ポインタ・アローモデル
						HIT_ENEMY = e;
						ENEMY_BLADE_HIT = 1;
					}
					if (ENEMY_BLADE_HIT == 1 && HIT_ENEMY){
						New<CEffect_zan_position>(CVector(HIT_ENEMY->Position.X, HIT_ENEMY->Position.Y, HIT_ENEMY->Position.Z));
						HIT_ENEMY->Life -= 50.0f;
						ENEMY_BLADE_HIT = 2;
						Blade_hit_se();//ブレードヒット効果音
					}
					if (ENEMY_BLADE_HIT == 2 && !hit.SegmentAndModel(Position, Position - AxisY() * 13.8f, e, e->Model)){//中心・半径・ポインタ・アローモデル
						ENEMY_BLADE_HIT = 3;
					}
					if (ENEMY_BLADE_HIT == 3){
						ENEMY_TIME++;
						if (ENEMY_TIME == 5){
							ENEMY_TIME = 0;
							ENEMY_BLADE_HIT = 0;
						}
					}
				}
			});

			//多脚ロボ
			Enemy_takyakuList.Apply([&](CMover* et){
				CHit hit1;
				if (et->BladeHitState == 1){
					if (ENEMY_BLADE_HIT2 == 0 && hit1.SegmentAndModel(Position, Position - AxisY() * 13.8f, et, et->Model)){//中心・半径・ポインタ・アローモデル13.8
						HIT_ENEMY = et;
						ENEMY_BLADE_HIT2 = 1;
					}
					if (ENEMY_BLADE_HIT2 == 1 && HIT_ENEMY){
						New<CEffect_zan_position>(CVector(HIT_ENEMY->Position.X, HIT_ENEMY->Position.Y, HIT_ENEMY->Position.Z));
						HIT_ENEMY->Life -= 50.0f;
						ENEMY_BLADE_HIT2 = 2;
						Blade_hit_se();//ブレードヒット効果音
					}
					if (ENEMY_BLADE_HIT2 == 2 && !hit1.SegmentAndModel(Position, Position - AxisY() * 13.8f, et, et->Model)){//中心・半径・ポインタ・アローモデル
						ENEMY_BLADE_HIT2 = 3;
					}
					if (ENEMY_BLADE_HIT2 == 3){
						ENEMY_TIME2++;
						if (ENEMY_TIME2 == 10){
							ENEMY_TIME2 = 0;
							ENEMY_BLADE_HIT2 = 0;
						}
					}
				}
			});

			//BOSS
			Enemy_BossList.Apply([&](CMover* eb){
				CHit hit2;
				if (eb->BladeHitState == 1){
					if (ENEMY_BLADE_HIT3 == 0 && hit2.SegmentAndModel(Position, Position - AxisY() * 100.8f, eb, eb->Model)){//中心・半径・ポインタ・アローモデル13.8
						HIT_ENEMY3 = eb;
						ENEMY_BLADE_HIT3 = 1;
					}
					if (ENEMY_BLADE_HIT3 == 1 && HIT_ENEMY3){
						New<CEffect_zan_position>(CVector(HIT_ENEMY3->Position.X, HIT_ENEMY3->Position.Y, HIT_ENEMY3->Position.Z));
						HIT_ENEMY3->Life -= 50.0f;
						Blade_hit_se();//ブレードヒット効果音
						ENEMY_BLADE_HIT3 = 2;
					}
					if (ENEMY_BLADE_HIT3 == 2 && !hit2.SegmentAndModel(Position, Position - AxisY() * 100.8f, eb, eb->Model)){//中心・半径・ポインタ・アローモデル
						ENEMY_BLADE_HIT3 = 3;
					}
					if (ENEMY_BLADE_HIT3 == 3){
						ENEMY_TIME3++;
						if (ENEMY_TIME3 == 10){
							ENEMY_TIME3 = 0;
							ENEMY_BLADE_HIT3 = 0;
						}
					}
				}
			});
		}
	}
}
//==================================================================================================================================
// 武器の初期化(ガン)
void CWeapon_Gun::Reset() {
	Model = GetModel(L"GUN\\GUN1.x");
	Scale = CVector(1, 1, 1)*2.5f;
	Color = CColor(1, 1, 1, 1.0f);
}

// 武器の移動(ガン)
void CWeapon_Gun::Move() {
	//ブレード左手に持たせる
	CModelBone* b = Owner->GetBone(L"R_kobusi_Joint");
	//地上攻撃角度
	if (gun_hande_Angle == normal_on){
		Rotation = RotationY(0.027f)*RotationX(0.245f)*RotationY(-0.02f)*b->Rotation;
		Position = b->Position + CVector(0.23f, -2.0f, 0.5f)*b->Rotation;
	}
	//空中攻撃角度
	if (gun_hande_Angle == air_on){
		Rotation = RotationY(0.043f)*RotationX(0.22f)*RotationZ(0.0025f)*b->Rotation;
		Position = b->Position + CVector(0.23f, -2.0f, 0.5f)*b->Rotation;
	}

	if (gun != 0){
		//ガン出現
		Color = CColor(1, 1, 1, 1.0f);
	}
	else if (gun == 0){
		//ガン透明
		Color = CColor(1, 1, 1, 0.0f);
	}
	if (beam_launch == beam_on){
		Weapon_GunList.Apply([&](CMover* g){
			New<CBullet>(Position + CVector(0.0f, 0.0f, 5.2f)*g->Rotation);
		});
	}
}

