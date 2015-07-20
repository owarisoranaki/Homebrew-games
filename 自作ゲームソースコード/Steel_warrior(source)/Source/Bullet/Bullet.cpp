#include "..\Main\Main.h"

// 弾の初期化（Myship）
void CBullet::Reset() {
	Model = GetModel(L"BEAM\\BEAM.x");
	Color = CColor(1,1,1,1);
	Scale = CVector(0.15f, 0.15f, 0.15f)*1.0f;
	SCALE_X = 0.15f;
	SCALE_Y = 0.15f;
	SCALE_Z = 0.15f;
	MyShipList.Apply([&](CMover* m){
		Rotation = m->Rotation;
	});
	
}

// 弾の移動（Myship）
void CBullet::Move() {
	//ビームスピード
	BEAM_MOVE = 0.5f;//4
	if (BEAM_COUNT == 0 && SCALE_Z <= 3){
		SCALE_Z += BEAM_MOVE;
		Position += ((AxisZ()*0.5f)*2.24f);//*4.15

		if (SCALE_Z >= 3){
			BEAM_COUNT = 1;
		}
	}
	if (BEAM_COUNT == 1){
		BEAM_TIME++;
		if (BEAM_TIME <= 120){
			Position += (AxisZ()*5.0f);//4
		}
		if (BEAM_TIME > 120){
			COLOR_W -= 0.03f;
			SCALE_X -= 0.003f;
			SCALE_Y -= 0.003f;
			Color = CColor(1, 1, 1, COLOR_W);
			if (COLOR_W <= 0){
				Life = 0;
			}
		}
	}
	
		Scale = CVector(SCALE_X, SCALE_Y, SCALE_Z);

		EmissiveColor = CColor(Random(1.0, 0.6f), Random(0.3, 0.2f), Random(0.2f, 0.3f), CW);
		//ToonInkColor = CColor(1, 1, 1, 1);
		//ToonInkEmissiveColor = CColor(1, 1, 1, 1);

		//クリア条件にになっていない
		if (clear == clear_off){
			EnemyList.Apply([&](CMover* e){
				if (ENEMY_HIT_COUNT <= 1 && Length(e->Position - Position) < 8.0f){
					ENEMY_HIT_COUNT++;
					if (ENEMY_HIT_COUNT == 1){
						enemy_shot_hit_type = enemy_shot_hit_on;
						Beam_hit_se();//ビームヒット音
						New<CEffect_shothit_position>(e->Position + CVector(0.0f, 0.0f, 0.0f), 0, RotationX(0.0f));
						e->Life -= 200;
						ENEMY_HIT_COUNT = 2;
					}
				}
			});
			Enemy_takyakuList.Apply([&](CMover* e){
				if (ENEMY_HIT_COUNT <= 1 && Length(e->Position - Position) < 8.0f){
					ENEMY_HIT_COUNT++;
					if (ENEMY_HIT_COUNT == 1){
						enemy_shot_hit_type = enemy_shot_hit_on;
						Beam_hit_se();//ビームヒット音
						New<CEffect_shothit_position>(e->Position + CVector(0.0f, 0.0f, 0.0f), 0, RotationX(0.0f));
						e->Life -= 200;
						ENEMY_HIT_COUNT = 2;
					}
				}
			});
			Enemy_BossList.Apply([&](CMover* e){
				if (ENEMY_HIT_COUNT <= 1 && Length(e->Position - Position) < 8.0f){
					ENEMY_HIT_COUNT++;
					if (ENEMY_HIT_COUNT == 1){
						enemy_shot_hit_type = enemy_shot_hit_on;
						Beam_hit_se();//ビームヒット音
						New<CEffect_shothit_position>(e->Position + CVector(0.0f, 0.0f, 0.0f), 0, RotationX(0.0f));
						e->Life -= 200;
						ENEMY_HIT_COUNT = 2;
					}
				}
			});
			if (ENEMY_HIT_COUNT == 2){
				Time++;
				if (Time % 8 == 0){
					enemy_shot_hit_type = enemy_shot_hit_off;
					Life = 0;
				}
			}
		}
}
//==================================================Enemy弾（右移動）====================================================================
void CBullet2::Reset() {
	//Model = GetModel(L"DEFAULT_SAMPLE\\sphere.x");
	Model = GetModel(L"LITTLE_BOOM\\litle_boom.x");
	Scale = CVector(1, 1, 1)*0.22f;//0.22
	Color = CColor(1, 0, 0, 1.0f);
	Rotation = RotationY(0.5f);
}
void CBullet2::Move() {
	//色
	Color = CColor(Random(1, 0), Random(1, 0), Random(1, 0), 1.0f);
	EmissiveColor = CColor(Random(1, 0.6f), Random(0.6, 0.6f), Random(0.9f, 0.9f), 1.0f);

			if (MOVE_COUNT == 0){
				Time++;
				if (Time <= 15){
					Rotation = CQuaternion(AXIS_Z, Position - MYSHIP_POSITION_COPY, -AXIS_Y);
					//Rotation.Interpolate(CQuaternion(MYSHIP_POSITION_COPY.Z + MYSHIP_POSITION_COPY.X*0.001f, Velocity), 0.10f);
					if (Time==1){
						MyShipList.Apply([&](CMover* m){
							MYSHIP_POSITION_COPY = m->Position + CVector(0, -6.5f, 0) + AXIS_X*Random(12, 12)*RotationY(Random(0, 1));
							New<CEffect9>(MYSHIP_POSITION_COPY);
						});
					}
				}
				if (Time>20 && Time <= 35){
					Velocity -= AxisX()*0.09f;
					Position += Velocity;
				}
				if (Time > 35 && Time <= 50){
					Velocity -= AxisX()*0.09f;
					Position += Velocity;
				}
				if (Time == 51){
					Velocity = 0;
					MOVE_COUNT = 1;
				}
			}
			if (MOVE_COUNT == 1){
				Time=0;
				//ホーミング
				Position.Homing(MYSHIP_POSITION_COPY, 3.0f);
				if (Length(MYSHIP_POSITION_COPY - Position) <= 1.0f){
					MOVE_COUNT = 2;
				}
			}
			if (MOVE_COUNT==2){
				Time++;
				Scale += 0.1f;
				if (Time>10){
					Life = 0;
				}
				if (Time==5){
					New<CEffect10>(MYSHIP_POSITION_COPY);
					//自機がいるときだけ
					if (myship_death == myship_death_off){
						Little_bomb_impact();//リトルボム爆発SE
					}
				}
			}
		
}
//==================================================Enemy弾（左移動）====================================================================
void CBullet3::Reset() {
	Model = GetModel(L"LITTLE_BOOM\\litle_boom.x");
	Scale = CVector(1, 1, 1)*0.22f;
	Color = CColor(1, 0, 0, 1.0f);
	Rotation = RotationY(0.5f);
}
void CBullet3::Move() {
	//色
	Color = CColor(Random(1, 0), Random(1, 0), Random(1, 0), 1.0f);
	EmissiveColor = CColor(Random(1, 0.6f), Random(0.6, 0.6f), Random(0.9f, 0.9f), 1.0f);

		
			if (MOVE_COUNT == 0){
				Time++;
				if (Time <= 15){
					Rotation = CQuaternion(AXIS_Z, Position - MYSHIP_POSITION_COPY, -AXIS_Y);
					//Rotation.Interpolate(CQuaternion(MYSHIP_POSITION_COPY.Z + MYSHIP_POSITION_COPY.X*0.001f, Velocity), 0.10f);
					if (Time == 1){
						MyShipList.Apply([&](CMover* m){
							MYSHIP_POSITION_COPY = m->Position + CVector(0, -6.5f, 0) + AXIS_X*Random(12, 12)*RotationY(Random(0, 1));
							New<CEffect9>(MYSHIP_POSITION_COPY);
						});
					}
				}
				if (Time>20 && Time <= 35){
					Velocity += AxisX()*0.09f;
					Position += Velocity;
				}
				if (Time > 35 && Time <= 50){
					Velocity -= AxisX()*0.09f;
					Position += Velocity;
				}
				if (Time == 51){
					Velocity = 0;
					MOVE_COUNT = 1;
				}
			}
			if (MOVE_COUNT == 1){
				Time = 0;
				Position.Homing(MYSHIP_POSITION_COPY, 3.0f);
				if (Length(MYSHIP_POSITION_COPY - Position) <= 1.0f){
					MOVE_COUNT = 2;
				}
			}
			if (MOVE_COUNT == 2){
				Time++;
				Scale += 0.1f;
				if (Time>10){
					Life = 0;
				}
				if (Time == 5){
					New<CEffect10>(MYSHIP_POSITION_COPY);
					//自機がいるときだけ
					if (myship_death == myship_death_off){
						Little_bomb_impact();//リトルボム爆発SE
					}
				}
			}
		
}
//==================================================Enemy弾（上移動）====================================================================
void CBullet4::Reset() {
	Model = GetModel(L"LITTLE_BOOM\\litle_boom.x");
	Scale = CVector(1, 1, 1)*0.22f;
	Color = CColor(1, 0, 0, 1.0f);
	Rotation = RotationY(0.5f);
}
void CBullet4::Move() {
	//色
	Color = CColor(Random(1, 0), Random(1, 0), Random(1, 0), 1.0f);
	EmissiveColor = CColor(Random(1, 0.6f), Random(0.6, 0.6f), Random(0.9f, 0.9f), 1.0f);

			if (MOVE_COUNT == 0){
				Time++;
				if (Time <= 15){
					Rotation = CQuaternion(AXIS_Z, Position - MYSHIP_POSITION_COPY, -AXIS_Y);
					//Rotation.Interpolate(CQuaternion(MYSHIP_POSITION_COPY.Z + MYSHIP_POSITION_COPY.X*0.001f, Velocity), 0.10f);
					if (Time == 1){
						MyShipList.Apply([&](CMover* m){
							MYSHIP_POSITION_COPY = m->Position + CVector(0, -6.5f, 0) + AXIS_X*Random(12, 12)*RotationY(Random(0, 1));
							New<CEffect9>(MYSHIP_POSITION_COPY);
						});
					}
				}
				if (Time>20 && Time <= 35){
					Velocity += AxisY()*0.09f;
					Position += Velocity;
				}
				if (Time > 35 && Time <= 50){
					Velocity += AxisY()*0.09f;
					Position += Velocity;
				}
				if (Time == 51){
					Velocity = 0;
					MOVE_COUNT = 1;
				}
			}
			if (MOVE_COUNT == 1){
				Time = 0;
				Position.Homing(MYSHIP_POSITION_COPY, 3.0f);
				if (Length(MYSHIP_POSITION_COPY - Position) <= 1.0f){
					MOVE_COUNT = 2;
				}
			}
			if (MOVE_COUNT == 2){
				Time++;
				Scale += 0.1f;
				if (Time>10){
					Life = 0;
				}
				if (Time == 5){
					New<CEffect10>(MYSHIP_POSITION_COPY);
					//自機がいるときだけ
					if (myship_death == myship_death_off){
						Little_bomb_impact();//リトルボム爆発SE
					}
				}
			}
		
}
//==================================================カミナリ====================================================================
void CBullet5::Reset() {
	Model = GetModel(L"VOLT\\volt.x");
	Scale = CVector(Random(1.3f, 1.0f), Random(1.5f, 1.2f), Random(1.3f, 1.0f))*0.1f;//7
	Color = CColor(1, 1, 1, 1.0f);
}
void CBullet5::Move() {
	Scale += 2.1f;
	Time++;
	if (Time>5){
		Life = 0;
	}
	Color = CColor(Random(1, 1), Random(0.9f, 0.7f), Random(1, 0.5f), 1.0f);
	EmissiveColor = CColor(Random(1, 1.0f), Random(0.6, 0.3f), Random(0.2f, 0.1f), Random(1,0));
}
//==================================================Enemy弾（下移動）====================================================================
void CBullet6::Reset() {
	Model = GetModel(L"LITTLE_BOOM\\litle_boom.x");
	Scale = CVector(1, 1, 1)*0.22f;
	Color = CColor(1, 0, 0, 1.0f);
	Rotation = RotationY(0.5f);
}
void CBullet6::Move() {
	//色
	Color = CColor(Random(1, 0), Random(1, 0), Random(1, 0), 1.0f);
	EmissiveColor = CColor(Random(1, 0.6f), Random(0.6, 0.6f), Random(0.9f, 0.9f), 1.0f);

	if (MOVE_COUNT == 0){
		Time++;
		if (Time <= 15){
			Rotation = CQuaternion(AXIS_Z, Position - MYSHIP_POSITION_COPY, -AXIS_Y);
			//Rotation.Interpolate(CQuaternion(MYSHIP_POSITION_COPY.Z + MYSHIP_POSITION_COPY.X*0.001f, Velocity), 0.10f);
			if (Time == 1){
				MyShipList.Apply([&](CMover* m){
					MYSHIP_POSITION_COPY = m->Position + CVector(0, -6.5f, 0) + AXIS_X*Random(0, 0)*RotationY(Random(0, 1));
					New<CEffect9>(MYSHIP_POSITION_COPY);
				});
			}
		}
		if (Time>20&&Time<=35){
			Velocity -= AxisY()*0.09f;
			Position += Velocity;
		}
		if (Time > 35 && Time <= 50){
			Velocity -= AxisY()*0.09f;
			Position += Velocity;
		}
		if (Time == 51){
			Velocity = 0;
			MOVE_COUNT = 1;
		}
	}
	if (MOVE_COUNT == 1){
		Time = 0;
		Position.Homing(MYSHIP_POSITION_COPY, 3.0f);
		if (Length(MYSHIP_POSITION_COPY - Position) <= 1.0f){
			MOVE_COUNT = 2;
		}
	}
	if (MOVE_COUNT == 2){
		Time++;
		Scale += 0.1f;
		if (Time>10){
			Life = 0;
		}
		if (Time == 5){
			New<CEffect10>(MYSHIP_POSITION_COPY);//自機がいるときだけ
			if (myship_death == myship_death_off){
				Little_bomb_impact();//リトルボム爆発SE
			}
		}
	}

}
//==================================================パチコマビーム====================================================================
void CBullet7::Reset() {
	Model = GetModel(L"BEAM\\pati_canon_beam00.x");
	Color = CColor(1, 1, 1, 1);
	Scale = CVector(0, 0, 0);
	S_X = 0.07f;
	S_Y = 0.07f;
	S_Z = 0;
}
void CBullet7::Move() {
	if (Owner){
		Rotation = Owner->Rotation;
		if (Owner->Type == 1 && S_Z <= 70){
			S_Z += 4.0f;
			Position += AxisZ()*9.316f;
			Scale = CVector(S_X, S_Y, S_Z);
			EmissiveColor = CColor(Random(0.1, 0.4f), Random(0.3, 0.3f), Random(0.2f, 0.4f), 1);
		}
		if (S_Z > 60){
			if (S_X >= 0)S_X -= 0.002f;
			if (S_X < 0)S_X = 0;
			if (S_Y >= 0)S_Y -= 0.002f;
			if (S_Y < 0)S_Y = 0;
		}
		
		if (S_X == 0 && S_Y == 0){
			Life = 0;
		}
	}
}
//==================================================パチコマビーム(球)====================================================================
void CBullet8::Reset() {
	Model = GetModel(L"BEAM\\sphere.x");
	Color = CColor(1, 1, 1, 1);
	Scale = CVector(0.0f, 0.0f, 0.0f);
	S_X = 0.07f;
	S_Y = 0.07f;
	S_Z = 0;
	New<CBullet7>(Position*Rotation)->Owner = this;
}
void CBullet8::Move() {
	if (Owner){
		if (Owner->BossState == 0){
			Rotation = Owner->Rotation;
		}
		if (Owner->BossState == 1){
			Rotation = Owner->Rotation*RotationY(0.5f);
		}
		EmissiveColor = CColor(Random(0.1, 0.4f), Random(0.3, 0.3f), Random(0.2f, 0.4f), 1);
		if (S_COUNT == 0 && Scale.X < 0.05f){
			Scale += 0.002f;
			if (Scale.X >= 0.05f){
				TIME_COUNT++;
				if (TIME_COUNT==1){
					Type = 1;
					TIME_COUNT = 0;
				}
			}
		}
		if (S_COUNT == 0 && Scale.X >= 0.05f){
			S_COUNT = 1;
		}
		if (S_COUNT==1){
			TIME_COUNT++;
		}
		if (S_COUNT == 1 && TIME_COUNT>40){
			Scale.X -= 0.006f;
			Scale.Y -= 0.006f;
			if (Scale.X <= 0){
				Life = 0;
			}
		}
	}
	
}
//=========s=========================================Boss_gun弾====================================================================
void CBullet9::Reset() {
	Model = GetModel(L"BEAM\\sphere.x");
	Scale = CVector(1, 1, 1)*0.02f;//7
	Color = CColor(1, 1, 1, 0.3f);
}
void CBullet9::Move() {
	if (Owner){
		if (Owner->Type==1){
			Position += (Owner->AxisZ()*-5.0f);
			HOMING_TIME++;
			MyShipList.Apply([&](CMover* m){
				if (HOMING_TIME >= 5 && HOMING_TIME <= 30){
					Position.Homing(m->Position, 1.9f);
				}
				if (Length(m->Position - Position) <= 3.0f){
					//m->Life -= 20;
					Life = 0;
				}
			});
			Item4List.Apply([&](CMover* i4){
				if (Length(i4->Position - Position) >= 500.0f){
					Life = 0;
				}
			});
			EmissiveColor = CColor(Random(0.3, 0.1f), Random(0.1, 0.2f), Random(0.6f, 0.2f), 1);
		}
		if (Owner->Type == 2){
			Position += (Owner->AxisZ()*-5.0f);
			HOMING_TIME++;
			MyShipList.Apply([&](CMover* m){
				if (HOMING_TIME >= 5 && HOMING_TIME <= 30){
					Position.Homing(m->Position, 1.9f);
				}
				if (Length(m->Position - Position) <= 3.0f){
					//m->Life -= 20;
					Life = 0;
				}
			});
			Item4List.Apply([&](CMover* i4){
				if (Length(i4->Position - Position) >= 500.0f){
					Life = 0;
				}
			});
			EmissiveColor = CColor(Random(0.3, 0.1f), Random(0.1, 0.2f), Random(0.6f, 0.2f), 1);
		}
		
	}
}