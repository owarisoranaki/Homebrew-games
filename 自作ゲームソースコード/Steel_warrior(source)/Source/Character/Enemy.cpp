#include "..\Main\Main.h"

// メカペンの初期化
void CEnemy::Reset() {
	//Model=GetModel(L"ZAKO_PEN\\meka_pen2.x");
	Model = GetModel(L"BEAM\\sphere.x");
	Scale = CVector(1, 1.0f, 1)*0.08f;//1
	SCALE_COPY = Scale;
	Life = 200;
	Rotation = RotationY(0.5f);
	MOVE_CHANGE_TIME2 = Random(180, 300);
	HOMING_SP = Random(0.001f,0.001f);//0.1,0.05
	SHOT_TIME = Random(180, 180);//80,210
	New<CEnemy_obj>(Position)->Owner = this;
	Color = CColor(1, 1, 1, 0.0f);
	New<CBlock>(Position)->Owner=this;
	POSITION = Random(0, 10);
	MOVE_CHANGE_COUNT = Random(0,5);
	VELO_Y_SP = Random(0.02f, 0.008f);
}

// メカペンの移動
void CEnemy::Move() {
	if (all_combat_type == all_combat_on){
		if (enemy_startup == Enemy_startup_on){
			//回転補正
			MyShipList.Apply([&](CMover* m) {
				CVector p = Position;//最初に座標を保存しておくのがミソ
				//Position.Homing(m->Position, 0.001f);
				Position.Homing(m->Position + CVector(POSITION, POSITION, POSITION), HOMING_SP);
				Rotation.Interpolate(CQuaternion(m->AxisZ() + m->AxisX()*0.001f, Velocity), 0.10f);
				Rotation = CQuaternion(AXIS_Z, Position - p, -AXIS_Y);
			});

			//移動チェンジ
			if (IMPACT_COUNT < 1){
				MOVE_CHANGE_TIME++;
				if (MOVE_CHANGE_TIME%MOVE_CHANGE_TIME2 == 0){
					COS_SIN_TIME = 0;
					MOVE_CHANGE_COUNT = Random(0, 5);
				}

				switch (MOVE_CHANGE_COUNT){
				case 0:
					Position.X += 0.4f*cos(COS_SIN_TIME*Random(0.02f, 0.02f));
					Position.Y += 0.1f*sin(COS_SIN_TIME*Random(0.02f, 0.02f));
					Position.Z += 0.4f*cos(COS_SIN_TIME*Random(0.02f, 0.02f));
					COS_SIN_TIME++;
					break;
				case 1:
					Position.X += 0.4f*sin(COS_SIN_TIME*Random(0.04f, 0.04f));
					Position.Z += 0.4f*cos(COS_SIN_TIME*Random(0.02f, 0.02f));
					COS_SIN_TIME++;
					break;
				case 2:
					Position.X += -0.4f*sin(COS_SIN_TIME*Random(0.02f, 0.02f));
					Position.Z += 0.4f*cos(COS_SIN_TIME*Random(0.06f, 0.06f));
					COS_SIN_TIME++;
					break;
				case 3:
					Position.Y += sin(COS_SIN_TIME*Random(0.2f, 0.2f));
					COS_SIN_TIME++;
					break;
				case 4:
					Position.Z += 0.4f*sin(COS_SIN_TIME*Random(0.06f, 0.06f));
					Position.Y += 0.4f*cos(COS_SIN_TIME*Random(0.06f, 0.06f));
					COS_SIN_TIME++;
					break;
				}
			}

			//最初の生成時（防衛機能作動前）
			ENEMY_ATTACK_STARTTIME++;
			if (ENEMY_ATTACK_STARTTIME >= 120)enemy_start_attack = enemy_start_attack_on;
			//攻撃開始（EneMy起動ムービー終了後）
			if (enemy_start_attack == enemy_start_attack_on){
			//距離＆攻撃
			MyShipList.Apply([&](CMover* m) {
				//＜近距離＞
				if (Length(m->Position - Position) <= 30.0f){
					//色
					EmissiveColor = CColor(Random(0.5f, 0.8f), Random(0.5f, 0.8f), Random(0.5f, 0.8f), Random(0.3f, 0.4f));
					//EmissiveColor_State = 3;
					//拡大
					SCALE_TIME++;
					if (IMPACT_COUNT < 3 && SCALE_TIME < 30){
						Scale += 0.004f;
					}
					//縮小
					if (IMPACT_COUNT < 3 && SCALE_TIME >= 30){
						Scale -= 0.003f;
						if (SCALE_TIME == 59){
							SCALE_TIME = 0;
							IMPACT_COUNT++;
						}
					}
				}
				//振動(爆破確定)
				if (IMPACT_COUNT == 3){
					SP += 0.005f;
					Position.X += cos(VIB_TIME*SP);
					Position.Z += sin(VIB_TIME*SP);
					VIB_TIME++;
					if (VIB_TIME >= 70){
						IMPACT_COUNT = 4;
						//自機がいるときだけ
						if (myship_death == myship_death_off){
							Big_bomb();//大爆発音
						}
					}
				}
				//爆破
				if (IMPACT_COUNT == 4){
					VIB_TIME = 0;
					Scale += 1.3f;
					SCALE_TIME++;
					if (SCALE_TIME >= 20){
						New<CEffect5>(CVector(Position.X, Position.Y, Position.Z));
						New<CEffect6>(CVector(Position.X, Position.Y, Position.Z));
						Life = 0;
						mekapen_number--;
					}
				}
				//＜中距離＞
				if (IMPACT_COUNT < 3 && Length(m->Position - Position) > 30.0f&& Length(m->Position - Position) < 500.0f){
					//色
					EmissiveColor = CColor(1.0f, 0.8f, 1.0f, 0.04f);
					//EmissiveColor_State = 2;
					//爆破リセット
					SCALE_TIME = 0;
					IMPACT_COUNT = 0;
					if (SCALE_COPY != Scale){
						Scale -= 0.004f;
					}
					if (Scale.X <= SCALE_COPY.X){
						Scale.X = SCALE_COPY.X;
					}
					if (Scale.Y <= SCALE_COPY.Y){
						Scale.Y = SCALE_COPY.Y;
					}
					if (Scale.Z <= SCALE_COPY.Z){
						Scale.Z = SCALE_COPY.Z;
					}
					//小爆弾発射
					Time++;
					if (Time % SHOT_TIME == 0){
						New<CBullet2>(Position + CVector(0.0f, 0.0f, 0.0f)*Rotation);
						New<CBullet3>(Position + CVector(0.0f, 0.0f, 0.0f)*Rotation);
						New<CBullet4>(Position + CVector(0.0f, 0.0f, 0.0f)*Rotation);
						New<CBullet6>(Position + CVector(0.0f, 0.0f, 0.0f)*Rotation);
					}
				}
			});
		}
	}
			if (enemy_startup == Enemy_startup_off){
				//--重力加算--
				Velocity.Y += -0.1f;
				Position += Velocity;//左右前後移動
				Position.Y += Velocity.Y;//上下移動
			}
			if (enemy_startup == Enemy_startupmovie_on&&enemy_start_state == enemy_start_on){
				if (COS_SIN_TIME < 90){
					Velocity.Y += VELO_Y_SP;
					Position.Y += Velocity.Y;//上下移動
				}
				if (COS_SIN_TIME >= 90 && COS_SIN_TIME <= 180){
					Velocity.Y -= VELO_Y_SP * 2;
					Position.Y += Velocity.Y;//上下移動
					if (COS_SIN_TIME >= 180){
						COS_SIN_TIME = 0;
					}
				}

				COS_SIN_TIME++;
				if (COS_SIN_TIME % 80 == 0)MOVE_CHANGE_COUNT = Random(0, 5);
				switch (MOVE_CHANGE_COUNT){
				case 0:
					Position.X += 0.4f*cos(COS_SIN_TIME*Random(0.02f, 0.02f));
					Position.Y += 0.1f*sin(COS_SIN_TIME*Random(0.02f, 0.02f));
					Position.Z += 0.4f*cos(COS_SIN_TIME*Random(0.02f, 0.02f));
					break;
				case 1:
					Position.X += 0.4f*sin(COS_SIN_TIME*Random(0.04f, 0.04f));
					Position.Z += 0.4f*cos(COS_SIN_TIME*Random(0.02f, 0.02f));
					break;
				case 2:
					Position.X += -0.4f*sin(COS_SIN_TIME*Random(0.02f, 0.02f));
					Position.Z += 0.4f*cos(COS_SIN_TIME*Random(0.06f, 0.06f));
					break;
				case 3:
					Position.Y += sin(COS_SIN_TIME*Random(0.2f, 0.2f));
					break;
				case 4:
					Position.Z += 0.4f*sin(COS_SIN_TIME*Random(0.06f, 0.06f));
					Position.Y += 0.4f*cos(COS_SIN_TIME*Random(0.06f, 0.06f));
					break;
				}
		}

	//-------------------------------------------------------------------------------------ステージ当たり判定-------------------------------------------------------------
		float Body_r = 5.0f;//壁用
		float Body_r2 = 2.5f;//敵用
		float Body_r3 = 4.0f;//中央ゲート
		CHit Fhit;
		//壁当たり判定
		Stage_02List.Apply([&](CMover*s2){
			if (Fhit.SphereAndModel(Position, Body_r, s2, s2->Model)){
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r;
			}
		});
		//床
		Stage_01List.Apply([&](CMover*s1){
			if (Fhit.SphereAndModel(Position, Body_r, s1, s1->Model)){
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r;
			}
		});
		//中央ゲート
		Stage_Centergate_LRList.Apply([&](CMover*sc){
			if (Fhit.SphereAndModel(Position, Body_r3, sc, sc->Model)){
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r3;
			}
		});
		//メカペン
		EnemyList.Apply([&](CMover* e){
			if (Fhit.SphereAndModel(Position, Body_r2, e, e->Model)){
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r2;
			}
		});
	}
	
}
// メカペンのモデル初期化
void CEnemy_obj::Reset() {
	Model = GetModel(L"ZAKO_PEN\\meka_pen3.x");
	Scale = CVector(1, 1.0f, 1)*1.0f;
	SpecularColor = CColor(1,1, 1, 2);//金属の様な反射(R,G,B,A)Aは数値が小さいと広く明るい、数値が小さいと鈍く鋭い感じ
	Color = CColor(1, 1, 1, 1.0f);
}

// メカペンのモデル初期化
void CEnemy_obj::Move() {
	if (enemy_startup == Enemy_startup_on){
		ANI_HABATAKI();
	}
	Position = Owner->Position;
	Rotation = Owner->Rotation;
	Scale = Owner->Scale*9.0f;
	if (Owner->Life<=0){
		Life = 0;
	}
	//------------------------------------色-----------------------------------
	EmissiveColor = Owner->EmissiveColor;
	if (Owner->BladeHitState_to == 1)Color = CColor(1, 1, 1, Random(0.2f, 0.6f));
	if (Owner->BladeHitState_to == 0)Color = CColor(1, 1, 1, 1);
		
}

//=====================================================================================================================================================================================

// 多脚ロボの初期化
void CEnemy_takyaku::Reset() {
	//Model = GetModel(L"PATIKOMA\\zako_canon.x");
	Model = GetModel(L"BEAM\\sphere.x");
	Scale = CVector(1, 1.0f, 1)*0.12f;//1.5
	Color = CColor(1, 1, 1, 0.0f);
	//SpecularColor = CColor(1, 1, 1, 5);//金属の様な反射(R,G,B,A)Aは数値が小さいと広く明るい、数値が小さいと鈍く鋭い感じ
	Life = 200;
	Rotation = RotationY(0.5f);
	New<CBlock>(Position)->Owner = this;
	HOMING_SP = Random(0.2f, 0.2f);
	//New<CLamp>(Position)->Owner = this;
	New<CEnemy_takyaku_obj>(Position)->Owner = this;
	New<CItem>(Position)->Owner = this;
	New<CItem2>(Position)->Owner = this;
	
}

// 多脚ロボの移動
void CEnemy_takyaku::Move() {
	if (all_combat_type == all_combat_on){
		//---------------------------------------------------------(共通基本処理)------------------------------------------------------------------------------------
		//重力
		GRAVITY_POWER = -1.0f;
		Velocity.Y += GRAVITY_POWER;
		Position += Velocity;
		if (Velocity.Y <= -1){
			Velocity.Y = -1;
		}
		//位置調整
		if (Position.Y <= 0.0f){
			Position.Y = 0.0f;
			Velocity.Y = 0;
		}
		//壁当たり判定
		float Body_r = 5.2f;//壁用
		float ETBody_r = 4.9f;//壁用
		CHit Fhit;
		Stage_02List.Apply([&](CMover*s2){
			if (Fhit.SphereAndModel(Position, Body_r, s2, s2->Model)){
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r;
			}
		});
		//床
		Stage_01List.Apply([&](CMover*s1){
			if (Fhit.SphereAndModel(Position, Body_r, s1, s1->Model)){
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r;
			}
		});
		//中央ゲート
		Stage_Centergate_LRList.Apply([&](CMover*sc){
			if (Fhit.SphereAndModel(Position, Body_r, sc, sc->Model)){
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r;
			}
		});
		//多脚ロボ
		Enemy_takyakuList.Apply([&](CMover*et){
			if (Type != et->Type){
				if (Fhit.SphereAndModel(Position, ETBody_r, et, et->Model)){
					Velocity.Y = 0;
					CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
					Position = Fhit.Position[1] + v*ETBody_r;
				}
			}
		});
	//（起動ムービー後）
		if (enemy_startup == Enemy_startup_on){
			ENEMY_ATTACK_STARTTIME++;
			if (ENEMY_ATTACK_STARTTIME >= 120)enemy_start_attack = enemy_start_attack_on;
			if (enemy_start_attack == enemy_start_attack_on){
				//回転補正
				MyShipList.Apply([&](CMover* m) {
					CVector p = m->Position;//最初に座標を保存しておくのがミソ
					if (patikoma_ani_state == patikoma_ani_walk){
						Rotation.Interpolate(CQuaternion(AXIS_Z, p - Position, AXIS_Y), 0.05f);
					}
				});
				//------------------------------------------------------------------------------------------------------------------------------------------
				//行動パターン変化
				ACTION_TIME++;
				if (ACTION_TIME % 160 == 0){
					MOVE_CHANGE_COUNT = Random(0, 3);
				}

				//ケンカしない処理
				CHit EThit;
				CMover* ET = NULL;
				CMover* ET2 = NULL;
				float ET_LEN = FLT_MAX;
				State = 0;
				Enemy_takyakuList.Apply([&](CMover* et){
					MyShipList.Apply([&](CMover* m) {
						//範囲内味方検索
						if (Length(et->Position - Position) < 15){
							ET_LEN2 = Length(et->Position - m->Position);
							if (ET_LEN2 < ET_LEN){
								ET_LEN = ET_LEN2;
								ET = et;
							}
						}
					});
				});
				//範囲内に味方なし
				if (!ET){

				}
				//範囲内に味方あり
				if (ET){
					//自分が一番近い
					if (ET->Type == Type){
						MyShipList.Apply([&](CMover* m) {
							//自機の近く
							if (Length(m->Position - Position) < 14){
								if (MOVE_CHANGE_COUNT == 0)MOVE(HOMING_SP);
								if (MOVE_CHANGE_COUNT == 1){
									BLADE_TIME++;
									if (BLADE_TIME == 1)New<CItem3>(Position)->Owner = this;
									ROTATION_ACTION();
								}
								if (MOVE_CHANGE_COUNT == 2){
									AttackState = 2;
								}
							}
							//自機の遠く
							if (Length(m->Position - Position) >= 14){
								if (MOVE_CHANGE_COUNT == 0)MOVE(HOMING_SP);
								if (MOVE_CHANGE_COUNT == 2)JUMP();
								if (MOVE_CHANGE_COUNT == 1){
									AttackState = 2;
								}
							}
						});
					}
					//自分以外が一番近い
					if (ET->Type != Type){
						MyShipList.Apply([&](CMover* m) {
							//自機の近く
							if (Length(m->Position - Position) < 13){
								//if (MOVE_CHANGE_COUNT == 0)MOVE(HOMING_SP);
								if (MOVE_CHANGE_COUNT == 1){
									BLADE_TIME++;
									if (BLADE_TIME == 1)New<CItem3>(Position)->Owner = this;
									ROTATION_ACTION();
								}
								if (MOVE_CHANGE_COUNT == 2){
									AttackState = 2;
								}
							}
							//自機の遠く
							if (Length(m->Position - Position) >= 13){
								if (MOVE_CHANGE_COUNT == 0)MOVE(HOMING_SP);
								if (MOVE_CHANGE_COUNT == 2)JUMP();
								if (MOVE_CHANGE_COUNT == 1){
									AttackState = 2;
								}
							}
						});
					}
				}
			}
				//当たり判定
				if (MOVE_CHANGE_COUNT != 2){
					MyShipList.Apply([&](CMover*m){
						Enemy_takyakuList.Apply([&](CMover*e){
							CHit Fhit;
							float Body_r = 4.0f;//4.0
							if (Fhit.SphereAndModel(m->Position, Body_r, e, e->Model)){
								Velocity.Y = 0;
								CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
								m->Position = Fhit.Position[1] + v*Body_r;
							}
						});
					});
				}

			//防衛機能ムービー
			if (enemy_startup == Enemy_startupmovie_on&&enemy_start_state == enemy_start_on){
				COS_SIN_TIME++;
				if (COS_SIN_TIME % 80 == 0)MOVE_CHANGE_COUNT = Random(0, 5);
				switch (MOVE_CHANGE_COUNT){
				case 0:
					Position.X += 0.4f*cos(COS_SIN_TIME*Random(0.02f, 0.02f));
					Position.Y += 0.1f*sin(COS_SIN_TIME*Random(0.02f, 0.02f));
					Position.Z += 0.4f*cos(COS_SIN_TIME*Random(0.02f, 0.02f));
					break;
				case 1:
					Position.X += 0.4f*sin(COS_SIN_TIME*Random(0.04f, 0.04f));
					Position.Z += 0.4f*cos(COS_SIN_TIME*Random(0.02f, 0.02f));
					break;
				case 2:
					Position.X += -0.4f*sin(COS_SIN_TIME*Random(0.02f, 0.02f));
					Position.Z += 0.4f*cos(COS_SIN_TIME*Random(0.06f, 0.06f));
					break;
				case 3:
					Position.Y += sin(COS_SIN_TIME*Random(0.2f, 0.2f));
					break;
				case 4:
					Position.Z += 0.4f*sin(COS_SIN_TIME*Random(0.06f, 0.06f));
					Position.Y += 0.4f*cos(COS_SIN_TIME*Random(0.06f, 0.06f));
					break;
				}

			}
		}
	}
}

// 多脚ロボモデルの初期化
void CEnemy_takyaku_obj::Reset() {
	Model = GetModel(L"PATIKOMA\\zako_canon00.x");
	Scale = CVector(1, 1.0f, 1)*1.5f;
	SpecularColor = CColor(1, 1, 1, 2);//金属の様な反射(R,G,B,A)Aは数値が小さいと広く明るい、数値が小さいと鈍く鋭い感じ
	Color = CColor(1, 1, 1, 1.0f);
}

// 多脚ロボモデルの移動
void CEnemy_takyaku_obj::Move() {
	if (enemy_startup == Enemy_startup_on){
		//歩き
		if (patikoma_ani_state == patikoma_ani_walk){
			ANI_WALK();
		}
		//ジャンプ
		if (patikoma_ani_state == patikoma_ani_jump){
			ANI_JUMP();
		}
	}
	Position = Owner->Position;
	Rotation = Owner->Rotation;
	if (Owner->Life <= 0){
		Life = 0;
	}
}

//======================================================(ボ ス)====================================================================
// ボスの初期化
void CEnemy_Boss::Reset() {
	Model = GetModel(L"BEAM\\sphere.x");
	Scale = CVector(1, 2.0f, 1)*0.15f;
	Color = CColor(1, 1, 1, 0.0f);
	New<CEnemy_Boss_model>(Position)->Owner = this;
	New<CBlock>(1,Position)->Owner = this;
	Life = 600;
}

// ボスの移動
void CEnemy_Boss::Move() {
	BossState = 1;//ビーム処理(Bulletで使っている)
	//重力数値加算
	Velocity.Y -= 1.0f;
	//--座標に加速度加算--
	Position += Velocity;
	//---重力加算上限---
	if (Velocity.Y <= -1){
		Velocity.Y = -1;
	}
	//位置調整
	if (Position.Y <= 0.0f){
		Position.Y = 0.0f;
		Velocity.Y = 0;
	}
	//ステージ壁当たり判定範囲
	CHit Fhit;
	float Body_r = 6.5f;//キャノン状態半径
	float Body_r2 = 11.5f;//通常状態半径
	//キャノン状態当たり判定
	Enemy_Boss_modelList.Apply([&](CMover*bm){
		if (bm->Model_State == Model_canon){
			//ステージ床
			Stage_01List.Apply([&](CMover*s){
				if (Fhit.SphereAndModel(Position, Body_r, s, s->Model)){
					Velocity.Y = 0;
					CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
					Position = Fhit.Position[1] + v*Body_r;
				}
			});
			//ステージ壁
			Stage_02List.Apply([&](CMover*s2){
				if (Fhit.SphereAndModel(Position, Body_r, s2, s2->Model)){
					Velocity.Y = 0;
					CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
					Position = Fhit.Position[1] + v*Body_r;
				}
			});
		}
	});
	//通常状態当たり判定
	Enemy_Boss_modelList.Apply([&](CMover*bm){
		if (bm->Model_State == Model_normal_walk || bm->Model_State == Model_normal_Wgun || Model_State == Model_normal_discovery){
			//ステージ床
			Stage_01List.Apply([&](CMover*s){
				if (Fhit.SphereAndModel(Position, Body_r2, s, s->Model)){
					Velocity.Y = 0;
					CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
					Position = Fhit.Position[1] + v*Body_r2;
				}
			});
			//ステージ壁
			Stage_02List.Apply([&](CMover*s2){
				if (Fhit.SphereAndModel(Position, Body_r2, s2, s2->Model)){
					Velocity.Y = 0;
					CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
					Position = Fhit.Position[1] + v*Body_r2;
				}
			});
		}
	});
	//ブレード＆ガン＆自機当たり判定モデルSCALE変更
	Enemy_Boss_modelList.Apply([&](CMover*bm){
		//通常状態
		if (bm->Model_State == Model_normal_walk){
			Scale = CVector(1, 2.0f, 1)*0.15f;
		}
		//キャノン状態
		if (bm->Model_State == Model_canon){
			Scale = CVector(1, 1.0f, 1)*0.15f;
		}
	});

//------------------------------------------------戦闘モード------------------------------------------------------------
	//BOSS起動
	if (boss_startup == boss_startup_on){
		MyShipList.Apply([&](CMover* m) {
			Enemy_Boss_modelList.Apply([&](CMover*bm){
				//通常モード歩き
				if (bm->Model_State == Model_normal_walk){
					if (Length(m->Position - Position)>5){
						Rotation.Interpolate(CQuaternion(AXIS_Z, Position - m->Position, -AXIS_Y), 0.05f);
						Position.Homing(m->Position, 0.3f);
						Rotation = CQuaternion(AXIS_X, AxisX(), AXIS_Y);
					}
				}
				//キャノンモードビーム発射
				if (bm->Model_State == Model_canon){
					BEAM_TIME++;
					if (BEAM_COUNT == 0){
						if (BEAM_TIME% 60 == 0){
							//自機がいるときだけ
							if (myship_death == myship_death_off){
								E_beam();//ビーム音
							}
							New<CBullet8>(Position + CVector(-0.5f, 0.0f, -11.0f)*Rotation)->Owner = this;
							BEAM_COUNT = 1;
							ROTA_TIME = 0;
						}
					}
					if (BEAM_COUNT == 1){
						ROTA_TIME++;
						if (ROTA_TIME > 120 && ROTA_TIME <= 240){
							Rotation.Interpolate(CQuaternion(AXIS_Z, Position -m->Position, -AXIS_Y), 0.05f);
						}
						if (ROTA_TIME >= 241){
							BEAM_COUNT = 0;
							BEAM_TIME = 0;
						}
					}
				}
				//Wガンモード
				if (bm->Model_State == Model_normal_Wgun){
					if (Length(m->Position - Position)>5){
						Rotation.Interpolate(CQuaternion(AXIS_Z, Position - m->Position, -AXIS_Y), 0.05f);
						Position.Homing(m->Position, 0.1f);
						Rotation = CQuaternion(AXIS_X, AxisX(), AXIS_Y);
					}
				}
			});
		});
	}
}

//-----------------------------------------------------------------------------------------------------------------------
// ボスモデルの初期化
void CEnemy_Boss_model::Reset() {
	Model = GetModel(L"BOSS\\BOSS_05.x");
	Scale = CVector(1, 1.0f, 1)*0.007f;
	SpecularColor = CColor(1, 1, 1, 6);//金属の様な反射(R,G,B,A)Aは数値が小さいと広く明るい、数値が小さいと鈍く鋭い感じ
	Color = CColor(1, 1, 1, 1.0f);
	New<CItem4>(2, Position)->Owner = this;//右手(銃)
	New<CItem4>(1, Position)->Owner = this;//左手(銃)

}

// ボスモデルの移動
void CEnemy_Boss_model::Move() {
	//---------------------------------------------------------------------------------------------------------------------
	//テスト用
	/*if (KeyState[0][DIK_P]){
		boss_moveimodel_change = boss_moveimodel_change_on;
		boss_startup = boss_startup_on;
		CANON_PAST_STATE = CANON_PAST_ON;
		Model_State = Model_normal_walk;
		MODEL_CHANGE_COUNT = 4;
	}*/
	//-------------------------------------------------色------------------------------------------------------------------
	//色
	EmissiveColor = CColor(1.0f, 0.8f, 1.0f, 0.2f);
	//----------------------------------------------ムービー中-------------------------------------------------------------
	//ムービー中の初期変形状態（キャノン状態）
	if (boss_moveimodel_change == boss_moveimodel_change_off){
		Position = Owner->Position + CVector(0, 5, 2);
		Animation = Model->GetAnimation(L"canon");
		AnimationTime = 60;
		Model_State = Model_canon;
	}
	//変形起動開始
	if (boss_moveimodel_change == boss_moveimodel_change_on){
		if (MODEL_CHANGE_COUNT == 0){
			Model_State = Model_normal_walk;
			Position = Owner->Position + CVector(0, 4, -1);
			Animation = Model->GetAnimation(L"canon");
			if (AnimationTime >= 0){
				AnimationTime -= 1.0f;
				if (AnimationTime <= 0){
					MODEL_CHANGE_COUNT = 1;
					AnimationTime = 0;
				}
			}
		}
		if (MODEL_CHANGE_COUNT == 1){
			Model_State = Model_normal_discovery;
			Animation = Model->GetAnimation(L"Discovery");
			if (AnimationTime <= 60){
				AnimationTime += 0.5f;
			}
			//起動後戦闘に移行するまでの間隔処理
			if (AnimationTime >= 59){
				MODEL_CHANGE_COUNT = 2;
				AnimationTime = 0;
			}
		}
		if (MODEL_CHANGE_COUNT == 2){
			MODEL_CHANGE_TIME++;
			if (MODEL_CHANGE_TIME == 30){
				MODEL_CHANGE_COUNT = 3;
			}
		}
		if (MODEL_CHANGE_COUNT == 3){
			MODEL_CHANGE_TIME = 0;
			State = 1;//Cameraで使っている(Cameraから戦闘モードに入る)
			MODEL_CHANGE_COUNT = 4;//とりあえず3にして処理を抜けてる
			Model_State = Model_normal_walk;//walkモードからstart

		}
		//--------------------------------------------戦闘モード-----------------------------------------------------------
		//BOSS起動
		if (boss_startup == boss_startup_on){
			//回転基礎モデルに同調
			Rotation = Owner->Rotation;
			//5秒置きに攻撃パターン変化
			MODEL_CHANGE_TIME++;
			if (MODEL_CHANGE_TIME ==300){
				MODEL_CHANGE_TIME = 0;
				//モデルstate
				Model_State = Random(0, 2.9f);
			}

			switch (Model_State){
				//通常モード歩行
			case Model_normal_walk:
				AttackState = 0;
				CANON_CHANGE_TIME = 0;
				Position = Owner->Position + CVector(0, 4, -1);
				if (CANON_PAST_STATE == CANON_PAST_OFF){
					ANI_WALK();
				}
				else if (CANON_PAST_STATE == CANON_PAST_ON){
					Animation = Model->GetAnimation(L"canon");
					if (AnimationTime >= 0){
						AnimationTime -= 1.0f;
					}
					if (AnimationTime <= 0){
						AnimationTime = 0;
						CANON_PAST_STATE = CANON_PAST_OFF;
					}
				}
				break;
				//キャノンモード
			case Model_canon:
				AttackState = 0;
				Animation = Model->GetAnimation(L"canon");
				Position = Owner->Position + CVector(0, 5, 2);
				CANON_PAST_STATE = CANON_PAST_ON;//キャノン変形をした
				CANON_CHANGE_TIME++;
				if (CANON_CHANGE_TIME == 1){
					AnimationTime = 0;
				}
				if (CANON_CHANGE_TIME > 0){
					if (AnimationTime <= 60){
						AnimationTime++;
					}
				}
				break;
				//Wガンモード
			case Model_normal_Wgun:
				Animation = Model->GetAnimation(L"w_gun");
				Position = Owner->Position + CVector(0, 4, -1);
				if (CANON_PAST_STATE == CANON_PAST_OFF){
					if (AnimationTime<40){
						AnimationTime += 0.5f;
					}
					if (AnimationTime>=40){
						AnimationTime = 40;
						AttackState = 1;//ガン発射
					}
				}
				else if (CANON_PAST_STATE == CANON_PAST_ON){
					AttackState = 0;
					Animation = Model->GetAnimation(L"canon");
					if (AnimationTime >= 0){
						AnimationTime -= 1.0f;
					}
					if (AnimationTime <= 0){
						AnimationTime = 0;
						CANON_PAST_STATE = CANON_PAST_OFF;
					}
				}
				break;
			}
		}
		//Ownerと消滅
		if (Owner->Life <= 0){
			Life = 0;
		}
	}
}