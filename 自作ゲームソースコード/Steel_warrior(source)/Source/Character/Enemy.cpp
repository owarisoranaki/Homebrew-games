#include "..\Main\Main.h"

// ���J�y���̏�����
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

// ���J�y���̈ړ�
void CEnemy::Move() {
	if (all_combat_type == all_combat_on){
		if (enemy_startup == Enemy_startup_on){
			//��]�␳
			MyShipList.Apply([&](CMover* m) {
				CVector p = Position;//�ŏ��ɍ��W��ۑ����Ă����̂��~�\
				//Position.Homing(m->Position, 0.001f);
				Position.Homing(m->Position + CVector(POSITION, POSITION, POSITION), HOMING_SP);
				Rotation.Interpolate(CQuaternion(m->AxisZ() + m->AxisX()*0.001f, Velocity), 0.10f);
				Rotation = CQuaternion(AXIS_Z, Position - p, -AXIS_Y);
			});

			//�ړ��`�F���W
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

			//�ŏ��̐������i�h�q�@�\�쓮�O�j
			ENEMY_ATTACK_STARTTIME++;
			if (ENEMY_ATTACK_STARTTIME >= 120)enemy_start_attack = enemy_start_attack_on;
			//�U���J�n�iEneMy�N�����[�r�[�I����j
			if (enemy_start_attack == enemy_start_attack_on){
			//�������U��
			MyShipList.Apply([&](CMover* m) {
				//���ߋ�����
				if (Length(m->Position - Position) <= 30.0f){
					//�F
					EmissiveColor = CColor(Random(0.5f, 0.8f), Random(0.5f, 0.8f), Random(0.5f, 0.8f), Random(0.3f, 0.4f));
					//EmissiveColor_State = 3;
					//�g��
					SCALE_TIME++;
					if (IMPACT_COUNT < 3 && SCALE_TIME < 30){
						Scale += 0.004f;
					}
					//�k��
					if (IMPACT_COUNT < 3 && SCALE_TIME >= 30){
						Scale -= 0.003f;
						if (SCALE_TIME == 59){
							SCALE_TIME = 0;
							IMPACT_COUNT++;
						}
					}
				}
				//�U��(���j�m��)
				if (IMPACT_COUNT == 3){
					SP += 0.005f;
					Position.X += cos(VIB_TIME*SP);
					Position.Z += sin(VIB_TIME*SP);
					VIB_TIME++;
					if (VIB_TIME >= 70){
						IMPACT_COUNT = 4;
						//���@������Ƃ�����
						if (myship_death == myship_death_off){
							Big_bomb();//�唚����
						}
					}
				}
				//���j
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
				//����������
				if (IMPACT_COUNT < 3 && Length(m->Position - Position) > 30.0f&& Length(m->Position - Position) < 500.0f){
					//�F
					EmissiveColor = CColor(1.0f, 0.8f, 1.0f, 0.04f);
					//EmissiveColor_State = 2;
					//���j���Z�b�g
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
					//�����e����
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
				//--�d�͉��Z--
				Velocity.Y += -0.1f;
				Position += Velocity;//���E�O��ړ�
				Position.Y += Velocity.Y;//�㉺�ړ�
			}
			if (enemy_startup == Enemy_startupmovie_on&&enemy_start_state == enemy_start_on){
				if (COS_SIN_TIME < 90){
					Velocity.Y += VELO_Y_SP;
					Position.Y += Velocity.Y;//�㉺�ړ�
				}
				if (COS_SIN_TIME >= 90 && COS_SIN_TIME <= 180){
					Velocity.Y -= VELO_Y_SP * 2;
					Position.Y += Velocity.Y;//�㉺�ړ�
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

	//-------------------------------------------------------------------------------------�X�e�[�W�����蔻��-------------------------------------------------------------
		float Body_r = 5.0f;//�Ǘp
		float Body_r2 = 2.5f;//�G�p
		float Body_r3 = 4.0f;//�����Q�[�g
		CHit Fhit;
		//�Ǔ����蔻��
		Stage_02List.Apply([&](CMover*s2){
			if (Fhit.SphereAndModel(Position, Body_r, s2, s2->Model)){
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r;
			}
		});
		//��
		Stage_01List.Apply([&](CMover*s1){
			if (Fhit.SphereAndModel(Position, Body_r, s1, s1->Model)){
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r;
			}
		});
		//�����Q�[�g
		Stage_Centergate_LRList.Apply([&](CMover*sc){
			if (Fhit.SphereAndModel(Position, Body_r3, sc, sc->Model)){
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r3;
			}
		});
		//���J�y��
		EnemyList.Apply([&](CMover* e){
			if (Fhit.SphereAndModel(Position, Body_r2, e, e->Model)){
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r2;
			}
		});
	}
	
}
// ���J�y���̃��f��������
void CEnemy_obj::Reset() {
	Model = GetModel(L"ZAKO_PEN\\meka_pen3.x");
	Scale = CVector(1, 1.0f, 1)*1.0f;
	SpecularColor = CColor(1,1, 1, 2);//�����̗l�Ȕ���(R,G,B,A)A�͐��l���������ƍL�����邢�A���l���������Ɠ݂��s������
	Color = CColor(1, 1, 1, 1.0f);
}

// ���J�y���̃��f��������
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
	//------------------------------------�F-----------------------------------
	EmissiveColor = Owner->EmissiveColor;
	if (Owner->BladeHitState_to == 1)Color = CColor(1, 1, 1, Random(0.2f, 0.6f));
	if (Owner->BladeHitState_to == 0)Color = CColor(1, 1, 1, 1);
		
}

//=====================================================================================================================================================================================

// ���r���{�̏�����
void CEnemy_takyaku::Reset() {
	//Model = GetModel(L"PATIKOMA\\zako_canon.x");
	Model = GetModel(L"BEAM\\sphere.x");
	Scale = CVector(1, 1.0f, 1)*0.12f;//1.5
	Color = CColor(1, 1, 1, 0.0f);
	//SpecularColor = CColor(1, 1, 1, 5);//�����̗l�Ȕ���(R,G,B,A)A�͐��l���������ƍL�����邢�A���l���������Ɠ݂��s������
	Life = 200;
	Rotation = RotationY(0.5f);
	New<CBlock>(Position)->Owner = this;
	HOMING_SP = Random(0.2f, 0.2f);
	//New<CLamp>(Position)->Owner = this;
	New<CEnemy_takyaku_obj>(Position)->Owner = this;
	New<CItem>(Position)->Owner = this;
	New<CItem2>(Position)->Owner = this;
	
}

// ���r���{�̈ړ�
void CEnemy_takyaku::Move() {
	if (all_combat_type == all_combat_on){
		//---------------------------------------------------------(���ʊ�{����)------------------------------------------------------------------------------------
		//�d��
		GRAVITY_POWER = -1.0f;
		Velocity.Y += GRAVITY_POWER;
		Position += Velocity;
		if (Velocity.Y <= -1){
			Velocity.Y = -1;
		}
		//�ʒu����
		if (Position.Y <= 0.0f){
			Position.Y = 0.0f;
			Velocity.Y = 0;
		}
		//�Ǔ����蔻��
		float Body_r = 5.2f;//�Ǘp
		float ETBody_r = 4.9f;//�Ǘp
		CHit Fhit;
		Stage_02List.Apply([&](CMover*s2){
			if (Fhit.SphereAndModel(Position, Body_r, s2, s2->Model)){
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r;
			}
		});
		//��
		Stage_01List.Apply([&](CMover*s1){
			if (Fhit.SphereAndModel(Position, Body_r, s1, s1->Model)){
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r;
			}
		});
		//�����Q�[�g
		Stage_Centergate_LRList.Apply([&](CMover*sc){
			if (Fhit.SphereAndModel(Position, Body_r, sc, sc->Model)){
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r;
			}
		});
		//���r���{
		Enemy_takyakuList.Apply([&](CMover*et){
			if (Type != et->Type){
				if (Fhit.SphereAndModel(Position, ETBody_r, et, et->Model)){
					Velocity.Y = 0;
					CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
					Position = Fhit.Position[1] + v*ETBody_r;
				}
			}
		});
	//�i�N�����[�r�[��j
		if (enemy_startup == Enemy_startup_on){
			ENEMY_ATTACK_STARTTIME++;
			if (ENEMY_ATTACK_STARTTIME >= 120)enemy_start_attack = enemy_start_attack_on;
			if (enemy_start_attack == enemy_start_attack_on){
				//��]�␳
				MyShipList.Apply([&](CMover* m) {
					CVector p = m->Position;//�ŏ��ɍ��W��ۑ����Ă����̂��~�\
					if (patikoma_ani_state == patikoma_ani_walk){
						Rotation.Interpolate(CQuaternion(AXIS_Z, p - Position, AXIS_Y), 0.05f);
					}
				});
				//------------------------------------------------------------------------------------------------------------------------------------------
				//�s���p�^�[���ω�
				ACTION_TIME++;
				if (ACTION_TIME % 160 == 0){
					MOVE_CHANGE_COUNT = Random(0, 3);
				}

				//�P���J���Ȃ�����
				CHit EThit;
				CMover* ET = NULL;
				CMover* ET2 = NULL;
				float ET_LEN = FLT_MAX;
				State = 0;
				Enemy_takyakuList.Apply([&](CMover* et){
					MyShipList.Apply([&](CMover* m) {
						//�͈͓���������
						if (Length(et->Position - Position) < 15){
							ET_LEN2 = Length(et->Position - m->Position);
							if (ET_LEN2 < ET_LEN){
								ET_LEN = ET_LEN2;
								ET = et;
							}
						}
					});
				});
				//�͈͓��ɖ����Ȃ�
				if (!ET){

				}
				//�͈͓��ɖ�������
				if (ET){
					//��������ԋ߂�
					if (ET->Type == Type){
						MyShipList.Apply([&](CMover* m) {
							//���@�̋߂�
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
							//���@�̉���
							if (Length(m->Position - Position) >= 14){
								if (MOVE_CHANGE_COUNT == 0)MOVE(HOMING_SP);
								if (MOVE_CHANGE_COUNT == 2)JUMP();
								if (MOVE_CHANGE_COUNT == 1){
									AttackState = 2;
								}
							}
						});
					}
					//�����ȊO����ԋ߂�
					if (ET->Type != Type){
						MyShipList.Apply([&](CMover* m) {
							//���@�̋߂�
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
							//���@�̉���
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
				//�����蔻��
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

			//�h�q�@�\���[�r�[
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

// ���r���{���f���̏�����
void CEnemy_takyaku_obj::Reset() {
	Model = GetModel(L"PATIKOMA\\zako_canon00.x");
	Scale = CVector(1, 1.0f, 1)*1.5f;
	SpecularColor = CColor(1, 1, 1, 2);//�����̗l�Ȕ���(R,G,B,A)A�͐��l���������ƍL�����邢�A���l���������Ɠ݂��s������
	Color = CColor(1, 1, 1, 1.0f);
}

// ���r���{���f���̈ړ�
void CEnemy_takyaku_obj::Move() {
	if (enemy_startup == Enemy_startup_on){
		//����
		if (patikoma_ani_state == patikoma_ani_walk){
			ANI_WALK();
		}
		//�W�����v
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

//======================================================(�{ �X)====================================================================
// �{�X�̏�����
void CEnemy_Boss::Reset() {
	Model = GetModel(L"BEAM\\sphere.x");
	Scale = CVector(1, 2.0f, 1)*0.15f;
	Color = CColor(1, 1, 1, 0.0f);
	New<CEnemy_Boss_model>(Position)->Owner = this;
	New<CBlock>(1,Position)->Owner = this;
	Life = 600;
}

// �{�X�̈ړ�
void CEnemy_Boss::Move() {
	BossState = 1;//�r�[������(Bullet�Ŏg���Ă���)
	//�d�͐��l���Z
	Velocity.Y -= 1.0f;
	//--���W�ɉ����x���Z--
	Position += Velocity;
	//---�d�͉��Z���---
	if (Velocity.Y <= -1){
		Velocity.Y = -1;
	}
	//�ʒu����
	if (Position.Y <= 0.0f){
		Position.Y = 0.0f;
		Velocity.Y = 0;
	}
	//�X�e�[�W�Ǔ����蔻��͈�
	CHit Fhit;
	float Body_r = 6.5f;//�L���m����Ԕ��a
	float Body_r2 = 11.5f;//�ʏ��Ԕ��a
	//�L���m����ԓ����蔻��
	Enemy_Boss_modelList.Apply([&](CMover*bm){
		if (bm->Model_State == Model_canon){
			//�X�e�[�W��
			Stage_01List.Apply([&](CMover*s){
				if (Fhit.SphereAndModel(Position, Body_r, s, s->Model)){
					Velocity.Y = 0;
					CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
					Position = Fhit.Position[1] + v*Body_r;
				}
			});
			//�X�e�[�W��
			Stage_02List.Apply([&](CMover*s2){
				if (Fhit.SphereAndModel(Position, Body_r, s2, s2->Model)){
					Velocity.Y = 0;
					CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
					Position = Fhit.Position[1] + v*Body_r;
				}
			});
		}
	});
	//�ʏ��ԓ����蔻��
	Enemy_Boss_modelList.Apply([&](CMover*bm){
		if (bm->Model_State == Model_normal_walk || bm->Model_State == Model_normal_Wgun || Model_State == Model_normal_discovery){
			//�X�e�[�W��
			Stage_01List.Apply([&](CMover*s){
				if (Fhit.SphereAndModel(Position, Body_r2, s, s->Model)){
					Velocity.Y = 0;
					CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
					Position = Fhit.Position[1] + v*Body_r2;
				}
			});
			//�X�e�[�W��
			Stage_02List.Apply([&](CMover*s2){
				if (Fhit.SphereAndModel(Position, Body_r2, s2, s2->Model)){
					Velocity.Y = 0;
					CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
					Position = Fhit.Position[1] + v*Body_r2;
				}
			});
		}
	});
	//�u���[�h���K�������@�����蔻�胂�f��SCALE�ύX
	Enemy_Boss_modelList.Apply([&](CMover*bm){
		//�ʏ���
		if (bm->Model_State == Model_normal_walk){
			Scale = CVector(1, 2.0f, 1)*0.15f;
		}
		//�L���m�����
		if (bm->Model_State == Model_canon){
			Scale = CVector(1, 1.0f, 1)*0.15f;
		}
	});

//------------------------------------------------�퓬���[�h------------------------------------------------------------
	//BOSS�N��
	if (boss_startup == boss_startup_on){
		MyShipList.Apply([&](CMover* m) {
			Enemy_Boss_modelList.Apply([&](CMover*bm){
				//�ʏ탂�[�h����
				if (bm->Model_State == Model_normal_walk){
					if (Length(m->Position - Position)>5){
						Rotation.Interpolate(CQuaternion(AXIS_Z, Position - m->Position, -AXIS_Y), 0.05f);
						Position.Homing(m->Position, 0.3f);
						Rotation = CQuaternion(AXIS_X, AxisX(), AXIS_Y);
					}
				}
				//�L���m�����[�h�r�[������
				if (bm->Model_State == Model_canon){
					BEAM_TIME++;
					if (BEAM_COUNT == 0){
						if (BEAM_TIME% 60 == 0){
							//���@������Ƃ�����
							if (myship_death == myship_death_off){
								E_beam();//�r�[����
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
				//W�K�����[�h
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
// �{�X���f���̏�����
void CEnemy_Boss_model::Reset() {
	Model = GetModel(L"BOSS\\BOSS_05.x");
	Scale = CVector(1, 1.0f, 1)*0.007f;
	SpecularColor = CColor(1, 1, 1, 6);//�����̗l�Ȕ���(R,G,B,A)A�͐��l���������ƍL�����邢�A���l���������Ɠ݂��s������
	Color = CColor(1, 1, 1, 1.0f);
	New<CItem4>(2, Position)->Owner = this;//�E��(�e)
	New<CItem4>(1, Position)->Owner = this;//����(�e)

}

// �{�X���f���̈ړ�
void CEnemy_Boss_model::Move() {
	//---------------------------------------------------------------------------------------------------------------------
	//�e�X�g�p
	/*if (KeyState[0][DIK_P]){
		boss_moveimodel_change = boss_moveimodel_change_on;
		boss_startup = boss_startup_on;
		CANON_PAST_STATE = CANON_PAST_ON;
		Model_State = Model_normal_walk;
		MODEL_CHANGE_COUNT = 4;
	}*/
	//-------------------------------------------------�F------------------------------------------------------------------
	//�F
	EmissiveColor = CColor(1.0f, 0.8f, 1.0f, 0.2f);
	//----------------------------------------------���[�r�[��-------------------------------------------------------------
	//���[�r�[���̏����ό`��ԁi�L���m����ԁj
	if (boss_moveimodel_change == boss_moveimodel_change_off){
		Position = Owner->Position + CVector(0, 5, 2);
		Animation = Model->GetAnimation(L"canon");
		AnimationTime = 60;
		Model_State = Model_canon;
	}
	//�ό`�N���J�n
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
			//�N����퓬�Ɉڍs����܂ł̊Ԋu����
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
			State = 1;//Camera�Ŏg���Ă���(Camera����퓬���[�h�ɓ���)
			MODEL_CHANGE_COUNT = 4;//�Ƃ肠����3�ɂ��ď����𔲂��Ă�
			Model_State = Model_normal_walk;//walk���[�h����start

		}
		//--------------------------------------------�퓬���[�h-----------------------------------------------------------
		//BOSS�N��
		if (boss_startup == boss_startup_on){
			//��]��b���f���ɓ���
			Rotation = Owner->Rotation;
			//5�b�u���ɍU���p�^�[���ω�
			MODEL_CHANGE_TIME++;
			if (MODEL_CHANGE_TIME ==300){
				MODEL_CHANGE_TIME = 0;
				//���f��state
				Model_State = Random(0, 2.9f);
			}

			switch (Model_State){
				//�ʏ탂�[�h���s
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
				//�L���m�����[�h
			case Model_canon:
				AttackState = 0;
				Animation = Model->GetAnimation(L"canon");
				Position = Owner->Position + CVector(0, 5, 2);
				CANON_PAST_STATE = CANON_PAST_ON;//�L���m���ό`������
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
				//W�K�����[�h
			case Model_normal_Wgun:
				Animation = Model->GetAnimation(L"w_gun");
				Position = Owner->Position + CVector(0, 4, -1);
				if (CANON_PAST_STATE == CANON_PAST_OFF){
					if (AnimationTime<40){
						AnimationTime += 0.5f;
					}
					if (AnimationTime>=40){
						AnimationTime = 40;
						AttackState = 1;//�K������
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
		//Owner�Ə���
		if (Owner->Life <= 0){
			Life = 0;
		}
	}
}