#include "..\Main\Main.h"

// �����@�̏�������
void CMyShip::Reset() {
	Model = GetModel(L"ROBO\\Robo_Yo10.x");//�@�̃��f��::Yo09
	SpecularColor = CColor(1, 1, 1, 9);//�����̗l�Ȕ���(R,G,B,A)A�͐��l���������ƍL�����邢�A���l���������Ɠ݂��s������
	Scale = CVector(1, 1, 1)*0.6f;//�@�̃T�C�Y
	Rotation = RotationY(0.0f);
	New<CWeapon>()->Owner = this;//����I�[�i�[
	New<CWeapon_Gun>()->Owner = this;//����I�[�i�[
	New<CEffect_position>()->Owner = this;//�G�t�F�N�gposition�E
	New<CEffect_position2>()->Owner = this;//�G�t�F�N�gposition��
	New<CEffect_sub_position>()->Owner = this;//�G�t�F�N�gsub_position�E
	New<CEffect_sub_position2>()->Owner = this;//�G�t�F�N�gsub_position��
	Life = 3500;//3500
	ENEMY_COUNT = enemy_count;
	TARGETSELECTION_TIMECONSTANT = 30;
	
}

// �����@�̈ړ���
void CMyShip::Move() {
	//=========================================================�d��=================================================================
	//--�W�����v���[�h�ɂȂ��Ă��Ȃ�
	if (JAMP_TYPE == up_off){
		GRAVITY_POWER = -1.01f;
	}
	//--�d�͉��Z--
	AxisY_Velocity.Y += GRAVITY_POWER;
	//--���W�ɉ����x���Z--
	Position += Velocity;//���E�O��ړ�
	Position.Y += AxisY_Velocity.Y;//�㉺�ړ�
	//---�d�͉��Z���---
	if (Velocity.Y <= -1){
		Velocity.Y = -1;
	}
	if (AxisY_Velocity.Y <= -0.1f){
		AxisY_Velocity.Y = -0.1f;
	}
	//========================================================�ʒu����==============================================================
	if (Position.Y <= 0.0f){
		Position.Y = 0.0f;
		Velocity.Y = 0;
		myship_landing_type = myship_landing_on;//���n
		
	}
	if (myship_landing_type == myship_landing_on){
		boost_recovery_switch = boost_recovery_on;//��
		UP_COUNT = 0;//�W�����v�J�E���g������
		//�󒆃_�b�V���ړ���ړ��\
		AIR_DASHAFTER_MOVECOUNT = 0;
		//�󒆃u���[�h�U�������n�����ꍇ������
		AIR_BLADE_ATTACK = 0;
		AIR_BLADE_TIME = 0;
		AIR_BLADE_ATTACK_TYPE = air_blade_attack_off;
		air_gage_switch = air_gage_off;
	}
	//===================================================�ړ�&�A�j���[�V����========================================================
	//�����[�r�[�I���ɂ�葀��\��ԁ�
	if (all_combat_type == all_combat_on && (enemy_startup == Enemy_startup_on || enemy_startup == Enemy_startup_off) && boss_movie_state != boss_movie_on&&end_screen_switch == end_screen_off){
	//�X�s�[�h������
	Velocity.X = 0.0f;
	Velocity.Z = 0.0f;
		//�u���[�h�^�C�v�ƃK���^�C�v��������
		if (weapon_chang == chang_blade || weapon_chang == chang_gun){
			//���n���Ă��ăW�����v���Ă��Ȃ�
			if (myship_landing_type == myship_landing_on){
				//�Î~���ʏ�ړ����[�h
				if (ACTION_TYPE == normal || ACTION_TYPE == dash || ACTION_TYPE == attack){
					//�J�����������f��2
					MyShip_Move_Model4List.Apply([&](CMover*Mm){
						//�ʏ�ړ��X�s�[�h
						LAN_SP = 0.53f;//0.4f
						//�O�i
						if (KeyState[0][DIK_W]){
							boost_main1_switch = boost_main1_on;//�u�[�X�g��i�KON_OFF
							if (ACTION_TYPE != attack){
								Velocity += Mm->AxisZ()*LAN_SP;
							}
							if (ACTION_TYPE == attack){
								Velocity += Mm->AxisZ()*0.0001f;
							}
							if (ACTION_TYPE == normal&&ACTION_TYPE != attack){
								ANI_TYPE = lan;
							}
							NORMAL_MOVE_TIME = 0;
						}
						//��i
						if (KeyState[0][DIK_S]){
							boost_main1_switch = boost_main1_on;//�u�[�X�g��i�KON_OFF
							if (ACTION_TYPE != attack){
								Velocity -= Mm->AxisZ()*LAN_SP;
							}
							if (ACTION_TYPE == attack){
								Velocity -= Mm->AxisZ()*0.0001f;
							}
							if (ACTION_TYPE == normal&&ACTION_TYPE != attack){
								ANI_TYPE = lan;
							}
							NORMAL_MOVE_TIME = 0;
						}
						//�E�i
						if (KeyState[0][DIK_D]){
							boost_main1_switch = boost_main1_on;//�u�[�X�g��i�KON_OFF
							if (ACTION_TYPE != attack){
								Velocity += Mm->AxisX()*LAN_SP;
							}
							if (ACTION_TYPE == attack){
								Velocity += Mm->AxisX()*0.0001f;
							}
							if (ACTION_TYPE == normal&&ACTION_TYPE != attack){
								ANI_TYPE = lan;
							}
							NORMAL_MOVE_TIME = 0;
						}
						//���i
						if (KeyState[0][DIK_A]){
							boost_main1_switch = boost_main1_on;//�u�[�X�g��i�KON_OFF
							if (ACTION_TYPE != attack){
								Velocity -= Mm->AxisX()*LAN_SP;
							}
							if (ACTION_TYPE == attack){
								Velocity -= Mm->AxisX()*0.0001f;
							}
							if (ACTION_TYPE == normal&&ACTION_TYPE != attack){
								ANI_TYPE = lan;
							}
							NORMAL_MOVE_TIME = 0;
						}
						//�L�[��������Ă��Ȃ���΃A�C�h�����O�萔���
						if (!KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_D] && !KeyState[0][DIK_A] && ACTION_TYPE != attack){
							if (ACTION_TYPE == normal){
								NORMAL_MOVE_TIME++;
							}
							if (NORMAL_MOVE_TIME == 1){
								AnimationTime = 0;
							}
							if (NORMAL_MOVE_TIME > 1){
								if (ACTION_TYPE == normal){
									ANI_TYPE = idl;
									boost_main1_switch = boost_main1_off;//�u�[�X�g��i�KON_OFF
								}
							}

						}
						//�A�j���[�V�����֐�
						if (ANI_TYPE == lan){
							if (ACTION_TYPE == normal){
								Robo_ani_lan();
							}
						}
						if (ANI_TYPE == idl){
							if (ACTION_TYPE == normal){
								Robo_ani_idl();
							}
						}
					});
				}
			}
		}
	//====================================================�U���A�j���[�V����========================================================
	//�u���[�h�^�C�v�ɂȂ��Ă��違�I�������ɂȂ��Ă��Ȃ�
	if (weapon_chang == chang_blade){
		//�㏸���Ă���Ƃ��͔������Ȃ�
		if (JAMP_TYPE == up_off){
			//�_�b�V�����Ă��Ȃ�
			if (ACTION_TYPE != dash){
				//���ڍU������
				if (ATTACK_COUNT == 0 && myship_landing_type == myship_landing_on){
					if (MouseState[0].Button[0] && !OldMouseState[0].Button[0]){
						ATTACK_ANI_SP = 2.4f;//�A�j���[�V�����X�s�[�h
						ACTION_TYPE = attack;
						blade = blade_on;
						blade_hold = blade_hold_normal;//���莝��
						ATTACK_ANITIME_RESET = 0;
						ATTACK_COUNT = 1;
						blade_hand_chang = left_hand;
					}
				}
				if (ATTACK_COUNT == 1){
					ATTACK_ANITIME_RESET++;
					if (ATTACK_ANITIME_RESET == 1){
						AnimationTime = 0;
					}
					if (ATTACK_ANITIME_RESET > 1){
						Animation = Model->GetAnimation(L"zan_ren3");
						if (AnimationTime_Copy >= 0 && AnimationTime_Copy <= 49){
							AnimationTime += ATTACK_ANI_SP;
							if (AnimationTime >= 2 && AnimationTime < 3)Blade_motion_se();//���U��SE
							Velocity += AxisZ()*0.03f;
							if (AnimationTime >= 30){
								AnimationTime = 30;
							}
							AnimationTime_Copy += ATTACK_ANI_SP;
							//2��ڂ̍U������
							if (MouseState[0].Button[0] && !OldMouseState[0].Button[0]){
								ATTACK_MOUSE_COUNT = 1;
								ATTACK_ANI_SP = 2.6f;//�A�j���[�V�����X�s�[�h
							}
						}
						if (ATTACK_MOUSE_COUNT == 1 && AnimationTime_Copy >= 49){
							AnimationTime_Copy = 49;
							ATTACK_COUNT = 2;
						}
						if (AnimationTime_Copy > 49){
							ATTACK_COUNT = 0;
							ATTACK_ANITIME_RESET = 0;
							AnimationTime = 0;
							AnimationTime_Copy = 0;
							ATTACK_MOUSE_COUNT = 0;
							blade = blade_off;
							ACTION_TYPE = normal;
							Velocity = 0;
						}
					}
				}
				if (ATTACK_COUNT == 2){
					if (AnimationTime_Copy >= 49 && AnimationTime_Copy <= 105){
						if (AnimationTime_Copy >= 49 && AnimationTime_Copy < 50)Blade_motion_se();//���U��SE
						AnimationTime += ATTACK_ANI_SP;
						if (AnimationTime >= 65){
							AnimationTime = 65;
						}
						AnimationTime_Copy += ATTACK_ANI_SP;
						//3��ڂ̍U������
						if (MouseState[0].Button[0] && !OldMouseState[0].Button[0]){
							ATTACK_MOUSE_COUNT = 2;
							ATTACK_ANI_SP = 2.9f;//�A�j���[�V�����X�s�[�h
						}
					}
					if (ATTACK_MOUSE_COUNT == 2 && AnimationTime_Copy >= 105){
						AnimationTime_Copy = 105;
						ATTACK_COUNT = 3;
					}
					if (AnimationTime_Copy > 105){
						ATTACK_COUNT = 0;
						ATTACK_ANITIME_RESET = 0;
						AnimationTime = 0;
						AnimationTime_Copy = 0;
						ATTACK_MOUSE_COUNT = 0;
						blade = blade_off;
						ACTION_TYPE = normal;
					}
				}
				if (ATTACK_COUNT == 3){
					if (AnimationTime_Copy >= 105 && AnimationTime_Copy <= 186){
						if (AnimationTime_Copy >= 105 && AnimationTime_Copy < 106)Blade_motion_se();//���U��SE
						AnimationTime += ATTACK_ANI_SP;
						Velocity += AxisZ()*0.15f;
						if (AnimationTime >= 124){
							AnimationTime = 124;
						}
						AnimationTime_Copy += ATTACK_ANI_SP;
						//4��ڂ̍U������
						if (MouseState[0].Button[0] && !OldMouseState[0].Button[0]){
							ATTACK_MOUSE_COUNT = 3;
						}
					}
					if (ATTACK_MOUSE_COUNT == 3 && AnimationTime_Copy >= 186){
						AnimationTime_Copy = 186;
						ATTACK_COUNT = 4;
					}
					if (AnimationTime_Copy > 186){
						ATTACK_COUNT = 0;
						ATTACK_ANITIME_RESET = 0;
						AnimationTime = 0;
						AnimationTime_Copy = 0;
						ATTACK_MOUSE_COUNT = 0;
						blade = blade_off;
						ACTION_TYPE = normal;
						Velocity = 0;
					}
				}
				if (ATTACK_COUNT == 4){
					if (AnimationTime_Copy >= 186 && AnimationTime_Copy <= 270){
						if (AnimationTime_Copy >= 186 && AnimationTime_Copy < 187)Blade_motion_se();//���U��SE
						AnimationTime += ATTACK_ANI_SP;
						Velocity += AxisZ()*0.28f;
						if (AnimationTime >= 184){
							AnimationTime = 184;
						}
						AnimationTime_Copy += ATTACK_ANI_SP;
						//5��ڂ̍U������
						if (MouseState[0].Button[0] && !OldMouseState[0].Button[0]){
							ATTACK_MOUSE_COUNT = 5;
							ATTACK_ANI_SP = 2.4f;//�A�j���[�V�����X�s�[�h
						}
					}
					if (ATTACK_MOUSE_COUNT == 5 && AnimationTime_Copy >= 270){
						AnimationTime_Copy = 270;
						ATTACK_COUNT = 5;
					}
					if (AnimationTime_Copy > 270){
						ATTACK_COUNT = 0;
						ATTACK_ANITIME_RESET = 0;
						AnimationTime = 0;
						AnimationTime_Copy = 0;
						ATTACK_MOUSE_COUNT = 0;
						blade = blade_off;
						ACTION_TYPE = normal;
						Velocity = 0;
					}
				}
				if (ATTACK_COUNT == 5){
					if (AnimationTime_Copy >= 270 && AnimationTime_Copy <= 300){
						if (AnimationTime_Copy >= 270 && AnimationTime_Copy < 271)Blade_motion_se();//���U��SE
						AnimationTime += ATTACK_ANI_SP;
						AnimationTime_Copy += ATTACK_ANI_SP;
						if (AnimationTime >= 223){
							AnimationTime = 223;
						}
					}
					if (AnimationTime_Copy > 300){
						AnimationTime_Copy = 300;
						ATTACK_COUNT = 6;
						rota_attack_type = rota_attack_on;
					}
				}
				if (ATTACK_COUNT == 6){
					//��]�U��
					MyShip_Move_Model3List.Apply([&](CMover*Mm2){
						if (AnimationTime_Copy >= 233 && JUMP_ROTATION_ATTACK_TIME <= 48){
							AnimationTime = 223;
							JUMP_ROTATION_ATTACK_SP = 1.12f;
							JUMP_ROTATION_ATTACK_TIME++;
							if (JUMP_ROTATION_ATTACK_TIME <= 23){
								AxisY_Velocity.Y += JUMP_ROTATION_ATTACK_SP;
								myship_landing_type = myship_landing_off;
								if (JUMP_ROTATION_ATTACK_TIME == 5){
									Rote_VeloZ = Mm2->AxisZ();
								}
								if (JUMP_ROTATION_ATTACK_TIME >= 6){
									Rotation *= CQuaternion(AxisX(), -0.022f);
									Position -= Rote_VeloZ * 0.1f;
								}
							}
						}
						if (JUMP_ROTATION_ATTACK_TIME >= 14 && JUMP_ROTATION_ATTACK_TIME <= 40){
							Rotation *= CQuaternion(AxisX(), -0.022f);
						}
						if (JUMP_ROTATION_ATTACK_TIME >= 14 && JUMP_ROTATION_ATTACK_TIME <= 48){
							Position -= Rote_VeloZ * 0.8f;
						}
						if (JUMP_ROTATION_ATTACK_TIME > 48){
							AnimationTime += ATTACK_ANI_SP - 0.3f;
							if (JUMP_ROTATION_ATTACK_TIME<80){
								Position -= Rote_VeloZ * 0.8f;
							}
						}
						if (AnimationTime > 253){
							AnimationTime = 0;
							AnimationTime_Copy = 0;
							JUMP_ROTATION_ATTACK_TIME = 0;
							Rotation = CQuaternion(AXIS_X, AxisX(), AXIS_Y);
							ATTACK_COUNT = 0;
							ATTACK_ANITIME_RESET = 0;
							ATTACK_MOUSE_COUNT = 0;
							blade = blade_off;
							ACTION_TYPE = normal;
							rota_attack_type = rota_attack_off;
						}
					});
				}
			}
			//�_�b�V�����^�̎�
			if (ACTION_TYPE == dash){
				//�U�������Ȃ��̕ϐ�������
				ATTACK_COUNT = 0;
				ATTACK_ANITIME_RESET = 0;
				AnimationTime_Copy = 0;
				ATTACK_MOUSE_COUNT = 0;
				JUMP_ROTATION_ATTACK_TIME = 0;
			}
		}
	}
	//======================================================�_�b�V���ړ�============================================================
	//�u���[�h�^�C�v�ƃK���^�C�v��������
	if (weapon_chang == chang_blade || weapon_chang == chang_gun){
		//�K���V���b�g���Ă��Ȃ�
		if (ACTION_TYPE != shot_attack){
			//(�O�_�b�V��)
			//�Î~��Ԃ܂��͒ʏ�U�����Ă���Ƃ�
			if (ACTION_TYPE == normal || ACTION_TYPE == attack){
				//�_�b�V���U���s��(�_�b�V���X�^�[�g�܂ł����Ă��Ȃ�)
				if (DASH_ZANANI_TYPE == 0){
					//�_�b�V�����͏�Ԃ�0
					if (DASH_COUNT == 0){
						//1��ڂ�w������
						if (KeyState[0][DIK_W] && !OldKeyState[0][DIK_W] && boost_life >= 50){
							//�_�b�V�����͊��o�^�C�}�[�n��
							DASH_IRREGULAR_COUNT = 1;
						}
						if (DASH_IRREGULAR_COUNT == 1){
							DASH_TIME++;
						}
						if (DASH_TIME >= 1 && DASH_TIME <= 15){
							if (!KeyState[0][DIK_W]){
								DASH_COUNT = 1;
								DASH_TIME = 0;
								DASH_IRREGULAR_COUNT = 0;
							}
							if (KeyState[0][DIK_A] || KeyState[0][DIK_S] || KeyState[0][DIK_D]){
								DASH_COUNT = 0;
								DASH_TIME = 0;
								DASH_IRREGULAR_COUNT = 0;
							}
						}
						if (DASH_TIME > 15){
							if (!KeyState[0][DIK_W]){
								DASH_TIME = 0;
								DASH_IRREGULAR_COUNT = 0;//
							}
							if (KeyState[0][DIK_A] || KeyState[0][DIK_S] || KeyState[0][DIK_D]){
								DASH_COUNT = 0;
								DASH_TIME = 0;
							}
						}
					}

					if (DASH_COUNT == 1){
						DASH_TIME++;
						if (DASH_TIME >= 1 && DASH_TIME <= 15){
							//2��ڂ�w������
							if (KeyState[0][DIK_W] && !OldKeyState[0][DIK_W]){
								DASH_COUNT = 2;
								DASH_TIME = 0;
							}
						}
						if (DASH_TIME > 15){
							DASH_TIME = 0;
							DASH_COUNT = 0;
						}
					}
					//�_�b�V���X�^�[�g
					//�_�b�V�����͏��2
					if (DASH_COUNT == 2){
						Jet_se();//dash��
						DASH_SP = 4.0f;
						//�A�N�V�����^�C�v(�_�b�V��)
						ACTION_TYPE = dash;
						dash_type = dash_w_on;
						if (weapon_chang == chang_blade){
							//�_�b�V���U������
							DASH_ZANANI_TYPE = 1;
						}
					}
				}
			}
			//�A�N�V�����^�C�v(�_�b�V��)����
			if (ACTION_TYPE == dash&&DASH_COUNT == 2){
				//�_�b�V���U���ɐ؂�ւ���Ă��Ȃ����̂݃A�j���[�V��������
				if (DASH_ZAN_CHANGE == dash_zan_off&&ACTION_TYPE != shot_attack&&AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
					Robo_ani_boost();
					AnimationTime = 0;
				}
				//�_�b�V���U�����ł���������
				MyShip_Move_Model4List.Apply([&](CMover*Mm){
					DASH_TIME++;
					if (DASH_TIME <= 2){
						Velocity += Mm->AxisZ()*DASH_SP;
						boost_main2_switch = boost_main2_on;//�u�[�X�g��i�KON_OFF
						boost_sub_switch = boost_sub_on;//�T�u�u�[�X�gON_OFF
					}
					if (DASH_TIME >= 3 && DASH_TIME <= 36){
						DASH_SP *= 0.9f;
						Velocity += Mm->AxisZ()*DASH_SP;
						if (DASH_TIME == 3){
							AIR_DASHAFTER_MOVE = 1;//�󒆃_�b�V����ړ��\
						}
						//�u�[�X�g�Q�[�W�����
						if (DASH_TIME >= 3 && DASH_TIME <= 12){
							boost_gage_switch = boost_gage_on;
							boost_recovery_switch = boost_recovery_off;
						}
						if (DASH_TIME > 12){
							boost_gage_switch = boost_gage_off;
						}
					}
					//�_�b�V���U�����Ă��Ȃ�
					if (DASH_ATTACK_COUNT == dash_attack_off && AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
						//�_�b�V���I��
						if (DASH_TIME >= 37){
							boost_recovery_switch = boost_recovery_on;//�u�[�X�g�Q�[�W��ON
							AIR_DASHAFTER_MOVE = 0;
							DASH_COUNT = 0;//�_�b�V�����͏�ԏ�����
							DASH_TIME = 0;//�_�b�V�����͊��o�^�C�}�[������
							AnimationTime = 0;
							Velocity = 0;//�����x������
							DASH_ZANANI_TYPE = 0;//�_�b�V���U�����ϐ�������
							DASH_ATTACK_TIME = 0;//�_�b�V���U�����͊��o�^�C�}�[������
							blade = blade_off;//�u���[�h����
							blade = gun_off;//�K������
							ACTION_TYPE = normal;//�A�N�V�����^�C�v��Î~��Ԃɏ�����
							dash_type = dash_off;
							DASH_ZAN_CHANGE = dash_zan_off;//�_�b�V���U���ɐ؂�ւ���Ă��Ȃ����̂݃A�j���[�V���������ϐ�������
							boost_main2_switch = boost_main2_off;//�u�[�X�g��i�KON_OFF
							boost_sub_switch = boost_sub_off;
						}
					}
					if (AIR_GUNSHOT_ONOFF == 1){
						boost_gage_switch = boost_gage_off;//�u�[�X�g����OFF
						boost_recovery_switch = boost_recovery_on;//�u�[�X�g�Q�[�W��ON
						AIR_DASHAFTER_MOVE = 0;
						DASH_COUNT = 0;//�_�b�V�����͏�ԏ�����
						DASH_TIME = 0;//�_�b�V�����͊��o�^�C�}�[������
						AnimationTime = 0;
						Velocity = 0;//�����x������
						DASH_ZANANI_TYPE = 0;//�_�b�V���U�����ϐ�������
						DASH_ATTACK_TIME = 0;//�_�b�V���U�����͊��o�^�C�}�[������
						blade = blade_off;//�u���[�h����
						blade = gun_off;//�K������
						ACTION_TYPE = normal;//�A�N�V�����^�C�v��Î~��Ԃɏ�����
						dash_type = dash_off;
						DASH_ZAN_CHANGE = dash_zan_off;//�_�b�V���U���ɐ؂�ւ���Ă��Ȃ����̂݃A�j���[�V���������ϐ�������
						boost_main2_switch = boost_main2_off;//�u�[�X�g��i�KON_OFF
						boost_sub_switch = boost_sub_off;
					}
				});
			}
			//(��_�b�V��)
			//�Î~��Ԃ܂��͒ʏ�U�����Ă���Ƃ� 
			if (ACTION_TYPE == normal || ACTION_TYPE == attack){
				//�_�b�V���U���s��
				if (DASH_ZANANI_TYPE == 0){
					//�_�b�V�����͏�Ԃ�0
					if (DASH_COUNT2 == 0){
						//1��ڂ�s������
						if (KeyState[0][DIK_S] && !OldKeyState[0][DIK_S] && boost_life >= 50){
							//�_�b�V�����͊��o�^�C�}�[�n��
							DASH_IRREGULAR_COUNT2 = 1;
						}
						if (DASH_IRREGULAR_COUNT2 == 1){
							DASH_TIME2++;
						}
						if (DASH_TIME2 >= 1 && DASH_TIME2 <= 15){
							if (!KeyState[0][DIK_S] ){
								DASH_COUNT2 = 1;
								DASH_TIME2 = 0;
								DASH_IRREGULAR_COUNT2 = 0;
							}
							if (KeyState[0][DIK_A] || KeyState[0][DIK_W] || KeyState[0][DIK_D]){
								DASH_COUNT2 = 0;
								DASH_TIME2 = 0;
								DASH_IRREGULAR_COUNT2=0;
							}
						}
						if (DASH_TIME2 > 15){
							if (!KeyState[0][DIK_S] ){
								DASH_TIME2 = 0;
								DASH_IRREGULAR_COUNT2 = 0;
							}
							if (KeyState[0][DIK_A] || KeyState[0][DIK_W] || KeyState[0][DIK_D]){
								DASH_COUNT2 = 0;
								DASH_TIME2 = 0;
							}
						}
					}

					if (DASH_COUNT2 == 1){
						DASH_TIME2++;
						if (DASH_TIME2 >= 1 && DASH_TIME2 <= 15){
							//2��ڂ�s������
							if (KeyState[0][DIK_S] && !OldKeyState[0][DIK_S]){
								DASH_COUNT2 = 2;
								DASH_TIME2 = 0;
							}
						}
						if (DASH_TIME2 > 15){
							DASH_TIME2 = 0;
							DASH_COUNT2 = 0;
						}
					}
					//�_�b�V���X�^�[�g
					//�_�b�V�����͏��2
					if (DASH_COUNT2 == 2){
						Jet_se();//dash��
						DASH_SP2 = 4.0f;
						//�A�N�V�����^�C�v(�_�b�V��)
						ACTION_TYPE = dash;
						dash_type = dash_s_on;
						if (weapon_chang == chang_blade){
							//�_�b�V���U������
							DASH_ZANANI_TYPE = 1;
						}
					}
				}
			}
			//�A�N�V�����^�C�v(�_�b�V��)����
			if (ACTION_TYPE == dash&&DASH_COUNT2 == 2){
				//�_�b�V���U���ɐ؂�ւ���Ă��Ȃ����̂݃A�j���[�V��������
				if (DASH_ZAN_CHANGE == dash_zan_off&&ACTION_TYPE != shot_attack&&AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
					Robo_ani_boost();
					AnimationTime = 0;
				}
				//�_�b�V���U�����ł���������
				MyShip_Move_Model4List.Apply([&](CMover*Mm){
					DASH_TIME2++;
					if (DASH_TIME2 <= 2){
						Velocity -= Mm->AxisZ()*DASH_SP2;
						boost_main2_switch = boost_main2_on;//�u�[�X�g��i�KON_OFF
						boost_sub_switch = boost_sub_on;//�T�u�u�[�X�gON_OFF
					}
					if (DASH_TIME2 >= 3 && DASH_TIME2 <= 36){
						DASH_SP2 *= 0.9f;
						Velocity -= Mm->AxisZ()*DASH_SP2;
						if (DASH_TIME2 == 3){
							AIR_DASHAFTER_MOVE = 1;
						}
						//�u�[�X�g�Q�[�W�����
						if (DASH_TIME2 >= 3 && DASH_TIME2 <= 12){
							boost_gage_switch = boost_gage_on;
							boost_recovery_switch = boost_recovery_off;
						}
						if (DASH_TIME2 > 12){
							boost_gage_switch = boost_gage_off;
						}
					}
					//�_�b�V���U�����Ă��Ȃ�
					if (DASH_ATTACK_COUNT == dash_attack_off && AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
						//�_�b�V���I��
						if (DASH_TIME2 >= 37){
							boost_recovery_switch = boost_recovery_on;//�u�[�X�g�Q�[�W��ON
							AIR_DASHAFTER_MOVE = 0;
							DASH_COUNT2 = 0;//�_�b�V�����͏�ԏ�����
							DASH_TIME2 = 0;//�_�b�V�����͊��o�^�C�}�[������
							AnimationTime = 0;
							Velocity = 0;//�����x������
							DASH_ZANANI_TYPE = 0;//�_�b�V���U�����ϐ�������
							DASH_ATTACK_TIME = 0;//�_�b�V���U�����͊��o�^�C�}�[������
							blade = blade_off;//�u���[�h����
							blade = gun_off;//�K������
							ACTION_TYPE = normal;//�A�N�V�����^�C�v��Î~��Ԃɏ�����
							dash_type = dash_off;
							DASH_ZAN_CHANGE = dash_zan_off;//�_�b�V���U���ɐ؂�ւ���Ă��Ȃ����̂݃A�j���[�V���������ϐ�������
							boost_main2_switch = boost_main2_off;//�u�[�X�g��i�KON_OFF
							boost_sub_switch = boost_sub_off;//�T�u�u�[�X�gON_OFF
						}
					}
					if (AIR_GUNSHOT_ONOFF == 1){
						boost_gage_switch = boost_gage_off;//�u�[�X�g����OFF
						boost_recovery_switch = boost_recovery_on;//�u�[�X�g�Q�[�W��ON
						AIR_DASHAFTER_MOVE = 0;
						DASH_COUNT2 = 0;//�_�b�V�����͏�ԏ�����
						DASH_TIME2 = 0;//�_�b�V�����͊��o�^�C�}�[������
						AnimationTime = 0;
						Velocity = 0;//�����x������
						DASH_ZANANI_TYPE = 0;//�_�b�V���U�����ϐ�������
						DASH_ATTACK_TIME = 0;//�_�b�V���U�����͊��o�^�C�}�[������
						blade = blade_off;//�u���[�h����
						blade = gun_off;//�K������
						ACTION_TYPE = normal;//�A�N�V�����^�C�v��Î~��Ԃɏ�����
						dash_type = dash_off;
						DASH_ZAN_CHANGE = dash_zan_off;//�_�b�V���U���ɐ؂�ւ���Ă��Ȃ����̂݃A�j���[�V���������ϐ�������
						boost_main2_switch = boost_main2_off;//�u�[�X�g��i�KON_OFF
						boost_sub_switch = boost_sub_off;//�T�u�u�[�X�gON_OFF
					}
				});
			}
			//(�E�_�b�V��)		
			//�Î~��Ԃ܂��͒ʏ�U�����Ă���Ƃ�
			if (ACTION_TYPE == normal || ACTION_TYPE == attack){
				//�_�b�V���U���s��
				if (DASH_ZANANI_TYPE == 0){
					//�_�b�V�����͏�Ԃ�0
					if (DASH_COUNT3 == 0){
						//1��ڂ�d������
						if (KeyState[0][DIK_D] && !OldKeyState[0][DIK_D] && boost_life >= 50){
							//�_�b�V�����͊��o�^�C�}�[�n��
							DASH_IRREGULAR_COUNT3 = 1;
						}
						if (DASH_IRREGULAR_COUNT3 == 1){
							DASH_TIME3++;
						}
						if (DASH_TIME3 >= 1 && DASH_TIME3 <= 15){
							if (!KeyState[0][DIK_D]){
								DASH_COUNT3 = 1;
								DASH_TIME3 = 0;
								DASH_IRREGULAR_COUNT3 = 0;
							}
							if (KeyState[0][DIK_S] || KeyState[0][DIK_W] || KeyState[0][DIK_A]){
								DASH_COUNT3 = 0;
								DASH_TIME3 = 0;
								DASH_IRREGULAR_COUNT3 = 0;
							}
						}
						if (DASH_TIME3 > 15){
							if (!KeyState[0][DIK_D]){
								DASH_TIME3 = 0;
								DASH_IRREGULAR_COUNT3 = 0;
							}
							if (KeyState[0][DIK_S] || KeyState[0][DIK_W] || KeyState[0][DIK_A]){
								DASH_COUNT3 = 0;
								DASH_TIME3 = 0;
							}
						}
					}

					if (DASH_COUNT3 == 1){
						DASH_TIME3++;
						if (DASH_TIME3 >= 1 && DASH_TIME3 <= 15){
							//2��ڂ�d������
							if (KeyState[0][DIK_D] && !OldKeyState[0][DIK_D]){
								DASH_COUNT3= 2;
								DASH_TIME3 = 0;
							}
						}
						if (DASH_TIME3 > 15){
							DASH_TIME3 = 0;
							DASH_COUNT3 = 0;
						}
					}
					//�_�b�V���X�^�[�g
					//�_�b�V�����͏��2
					if (DASH_COUNT3 == 2){
						Jet_se();//dash��
						DASH_SP3 = 4.0f;
						//�A�N�V�����^�C�v(�_�b�V��)
						ACTION_TYPE = dash;
						dash_type = dash_d_on;
						if (weapon_chang == chang_blade){
							//�_�b�V���U������
							DASH_ZANANI_TYPE = 1;
						}
					}
				}
			}
			//�A�N�V�����^�C�v(�_�b�V��)����
			if (ACTION_TYPE == dash&&DASH_COUNT3 == 2){
				//�_�b�V���U���ɐ؂�ւ���Ă��Ȃ����̂݃A�j���[�V��������
				if (DASH_ZAN_CHANGE == dash_zan_off&&ACTION_TYPE != shot_attack&&AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
					Robo_ani_boost();
					AnimationTime = 0;
				}
				//�_�b�V���U�����ł���������
				MyShip_Move_Model4List.Apply([&](CMover*Mm){
					DASH_TIME3++;
					if (DASH_TIME3 <= 2){
						boost_sub_switch = boost_sub_on;//�T�u�u�[�X�gON_OFF
						boost_main2_switch = boost_main2_on;//�u�[�X�g��i�KON_OFF
						Velocity += Mm->AxisX()*DASH_SP3;
					}
					if (DASH_TIME3 >= 3 && DASH_TIME3 <= 36){
						DASH_SP3 *= 0.9f;
						Velocity += Mm->AxisX()*DASH_SP3;
						if (DASH_TIME3 == 3){
							AIR_DASHAFTER_MOVE = 1;
						}
						//�u�[�X�g�Q�[�W�����
						if (DASH_TIME3 >= 3 && DASH_TIME3 <= 12){
							boost_gage_switch = boost_gage_on;
							boost_recovery_switch = boost_recovery_off;
						}
						if (DASH_TIME3 > 12){
							boost_gage_switch = boost_gage_off;
						}
					}
					//�_�b�V���U�����Ă��Ȃ�
					if (DASH_ATTACK_COUNT == dash_attack_off && AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
						//�_�b�V���I��
						if (DASH_TIME3 >= 37){
							boost_recovery_switch = boost_recovery_on;//�u�[�X�g�Q�[�W��ON
							AIR_DASHAFTER_MOVE = 0;
							DASH_COUNT3 = 0;//�_�b�V�����͏�ԏ�����
							DASH_TIME3 = 0;//�_�b�V�����͊��o�^�C�}�[������
							AnimationTime = 0;
							Velocity = 0;//�����x������
							DASH_ZANANI_TYPE = 0;//�_�b�V���U�����ϐ�������
							DASH_ATTACK_TIME = 0;//�_�b�V���U�����͊��o�^�C�}�[������
							blade = blade_off;//�u���[�h����
							blade = gun_off;//�K������
							ACTION_TYPE = normal;//�A�N�V�����^�C�v��Î~��Ԃɏ�����
							dash_type = dash_off;
							DASH_ZAN_CHANGE = dash_zan_off;//�_�b�V���U���ɐ؂�ւ���Ă��Ȃ����̂݃A�j���[�V���������ϐ�������
							boost_main2_switch = boost_main2_off;//�u�[�X�g��i�KON_OFF
							boost_sub_switch = boost_sub_off;//�T�u�u�[�X�gON_OFF
						
						}
					}
					if (AIR_GUNSHOT_ONOFF == 1){
						boost_gage_switch = boost_gage_off;//�u�[�X�g����OFF
						boost_recovery_switch = boost_recovery_on;//�u�[�X�g�Q�[�W��ON
						AIR_DASHAFTER_MOVE = 0;
						DASH_COUNT3 = 0;//�_�b�V�����͏�ԏ�����
						DASH_TIME3 = 0;//�_�b�V�����͊��o�^�C�}�[������
						AnimationTime = 0;
						Velocity = 0;//�����x������
						DASH_ZANANI_TYPE = 0;//�_�b�V���U�����ϐ�������
						DASH_ATTACK_TIME = 0;//�_�b�V���U�����͊��o�^�C�}�[������
						blade = blade_off;//�u���[�h����
						blade = gun_off;//�K������
						ACTION_TYPE = normal;//�A�N�V�����^�C�v��Î~��Ԃɏ�����
						dash_type = dash_off;
						DASH_ZAN_CHANGE = dash_zan_off;//�_�b�V���U���ɐ؂�ւ���Ă��Ȃ����̂݃A�j���[�V���������ϐ�������
						boost_main2_switch = boost_main2_off;//�u�[�X�g��i�KON_OFF
						boost_sub_switch = boost_sub_off;//�T�u�u�[�X�gON_OFF
					}
				});
			}
			//(���_�b�V��)
			//�Î~��Ԃ܂��͒ʏ�U�����Ă���Ƃ�
			if (ACTION_TYPE == normal || ACTION_TYPE == attack){
				//�_�b�V���U���s��
				if (DASH_ZANANI_TYPE == 0){
					//�_�b�V�����͏�Ԃ�0
					if (DASH_COUNT4 == 0){
						//1��ڂ�a������
						if (KeyState[0][DIK_A] && !OldKeyState[0][DIK_A] && boost_life >= 50){
							//�_�b�V�����͊��o�^�C�}�[�n��
							DASH_IRREGULAR_COUNT4 = 1;
						}
						if (DASH_IRREGULAR_COUNT4 == 1){
							DASH_TIME4++;
						}
						if (DASH_TIME4 >= 1 && DASH_TIME4 <= 15){
							if (!KeyState[0][DIK_A]){
								DASH_COUNT4 = 1;
								DASH_TIME4= 0;
								DASH_IRREGULAR_COUNT4 = 0;
							}
							if (KeyState[0][DIK_D] || KeyState[0][DIK_W] || KeyState[0][DIK_S]){
								DASH_COUNT4 = 0;
								DASH_TIME4 = 0;
								DASH_IRREGULAR_COUNT4 = 0;
							}
						}
						if (DASH_TIME4 > 15){
							if (!KeyState[0][DIK_A]){
								DASH_TIME4 = 0;
								DASH_IRREGULAR_COUNT4 = 0;
							}
							if (KeyState[0][DIK_D] || KeyState[0][DIK_W] || KeyState[0][DIK_S]){
								DASH_COUNT4 = 0;
								DASH_TIME4 = 0;
							}
						}
					}

					if (DASH_COUNT4 == 1){
						DASH_TIME4++;
						if (DASH_TIME4 >= 1 && DASH_TIME4 <= 15){
							//2��ڂ�a������
							if (KeyState[0][DIK_A] && !OldKeyState[0][DIK_A]){
								DASH_COUNT4 = 2;
								DASH_TIME4 = 0;
							}
						}
						if (DASH_TIME4 > 15){
							DASH_TIME4 = 0;
							DASH_COUNT4 = 0;
						}
					}
					//�_�b�V���X�^�[�g
					//�_�b�V�����͏��2
					if (DASH_COUNT4 == 2){
						DASH_SP4 = 4.0f;
						Jet_se();//dash��
						//�A�N�V�����^�C�v(�_�b�V��)
						ACTION_TYPE = dash;
						dash_type = dash_a_on;
						//�u���[�h�������̂ݏ���
						if (weapon_chang == chang_blade){
							//�_�b�V���U������
							DASH_ZANANI_TYPE = 1;
						}
					}
				}
			}
			//�A�N�V�����^�C�v(�_�b�V��)����
			if (ACTION_TYPE == dash&&DASH_COUNT4 == 2){
				//�_�b�V���U���ɐ؂�ւ���Ă��Ȃ����̂݃A�j���[�V��������
				if (DASH_ZAN_CHANGE == dash_zan_off&&ACTION_TYPE != shot_attack&&AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
					Robo_ani_boost();
					AnimationTime = 0;
				}
				//�_�b�V���U�����ł���������
				MyShip_Move_Model4List.Apply([&](CMover*Mm){
					DASH_TIME4++;
					if (DASH_TIME4 <= 2){
						boost_sub_switch = boost_sub_on;//�T�u�u�[�X�gON_OFF
						Velocity -= Mm->AxisX()*DASH_SP4;
						boost_main2_switch = boost_main2_on;//�u�[�X�g��i�KON_OFF
					}
					if (DASH_TIME4 >= 3 && DASH_TIME4 <= 36){
						DASH_SP4 *= 0.9f;
						Velocity -= Mm->AxisX()*DASH_SP4;
						if (DASH_TIME4 == 3){
							AIR_DASHAFTER_MOVE = 1;
						}
						//�u�[�X�g�Q�[�W�����
						if (DASH_TIME4 >= 3 && DASH_TIME4 <= 12){
							boost_gage_switch = boost_gage_on;
							boost_recovery_switch = boost_recovery_off;
						}
						if (DASH_TIME4 > 12){
							boost_gage_switch = boost_gage_off;
						}
					}
					//�_�b�V���U�����Ă��Ȃ�
					if (DASH_ATTACK_COUNT == dash_attack_off && AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
						if (DASH_TIME4 >= 37){
							boost_recovery_switch = boost_recovery_on;//�u�[�X�g�Q�[�W��ON
							AIR_DASHAFTER_MOVE = 0;
							DASH_COUNT4 = 0;//�_�b�V�����͏�ԏ�����
							DASH_TIME4 = 0;//�_�b�V�����͊��o�^�C�}�[������
							AnimationTime = 0;
							Velocity = 0;//�����x������
							DASH_ZANANI_TYPE = 0;//�_�b�V���U�����ϐ�������
							DASH_ATTACK_TIME = 0;//�_�b�V���U�����͊��o�^�C�}�[������
							blade = blade_off;//�u���[�h����
							blade = gun_off;//�K������
							DASH_ZAN_CHANGE = dash_zan_off;//�_�b�V���U���ɐ؂�ւ���Ă��Ȃ����̂݃A�j���[�V���������ϐ�������
							ACTION_TYPE = normal;//�A�N�V�����^�C�v��Î~��Ԃɏ�����
							dash_type = dash_off;
							boost_main2_switch = boost_main2_off;//�u�[�X�g��i�KON_OFF
							boost_sub_switch = boost_sub_off;//�T�u�u�[�X�gON_OFF
						}
					}
					if (AIR_GUNSHOT_ONOFF == 1){
						boost_gage_switch = boost_gage_off;//�u�[�X�g����OFF
						boost_recovery_switch = boost_recovery_on;//�u�[�X�g�Q�[�W��ON
						AIR_DASHAFTER_MOVE = 0;
						DASH_COUNT4 = 0;//�_�b�V�����͏�ԏ�����
						DASH_TIME4 = 0;//�_�b�V�����͊��o�^�C�}�[������
						AnimationTime = 0;
						Velocity = 0;//�����x������
						DASH_ZANANI_TYPE = 0;//�_�b�V���U�����ϐ�������
						DASH_ATTACK_TIME = 0;//�_�b�V���U�����͊��o�^�C�}�[������
						blade = blade_off;//�u���[�h����
						blade = gun_off;//�K������
						DASH_ZAN_CHANGE = dash_zan_off;//�_�b�V���U���ɐ؂�ւ���Ă��Ȃ����̂݃A�j���[�V���������ϐ�������
						ACTION_TYPE = normal;//�A�N�V�����^�C�v��Î~��Ԃɏ�����
						dash_type = dash_off;
						boost_main2_switch = boost_main2_off;//�u�[�X�g��i�KON_OFF
						boost_sub_switch = boost_sub_off;//�T�u�u�[�X�gON_OFF
					}
				});
			}
			//(���O�_�b�V��)
			//�Î~��Ԃ܂��͒ʏ�U�����Ă���Ƃ�
			if (ACTION_TYPE == normal || ACTION_TYPE == attack){
				//�_�b�V���U���s��
				if (DASH_ZANANI_TYPE == 0){
					//�_�b�V�����͏�Ԃ�0
					if (DASH_COUNT5 == 0){
						//1��ڂ�a������
						if (KeyState[0][DIK_A] && KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_D] && boost_life >= 50){
							//�_�b�V�����͊��o�^�C�}�[�n��
							DASH_TIME5++;
						}
						if (DASH_TIME5 >= 1 && DASH_TIME5 <= 15){//20
							if (!KeyState[0][DIK_A] && !KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_D]){
								DASH_COUNT5 = 1;
								DASH_TIME5 = 0;
							}
						}
						if (DASH_TIME5 > 15){
							if (!KeyState[0][DIK_A] && !KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_D]){
								DASH_TIME5 = 0;
							}
						}
					}
					if (DASH_COUNT5 == 1){
						DASH_TIME5++;
						if (DASH_TIME5 >= 1 && DASH_TIME5 <= 15){
							//2��ڂ�a������
							if (KeyState[0][DIK_A] && KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_D]){
								DASH_COUNT5 = 2;
								DASH_TIME5 = 0;
							}
						}
						if (DASH_TIME5 > 15){
							DASH_TIME5 = 0;
							DASH_COUNT5 = 0;
						}
					}
					//�_�b�V���X�^�[�g
					//�_�b�V�����͏��2
					if (DASH_COUNT5 == 2){
						DASH_SP5 = 2.0f;
						Jet_se();//dash��
						//�A�N�V�����^�C�v(�_�b�V��)
						ACTION_TYPE = dash;
						dash_type = dash_aw_on;
						//�u���[�h�������̂ݏ���
						if (weapon_chang == chang_blade){
							//�_�b�V���U������
							DASH_ZANANI_TYPE = 1;
						}
					}
				}
			}
			//�A�N�V�����^�C�v(�_�b�V��)����
			if (ACTION_TYPE == dash&&DASH_COUNT5 == 2){
				//�_�b�V���U���ɐ؂�ւ���Ă��Ȃ����̂݃A�j���[�V��������
				if (DASH_ZAN_CHANGE == dash_zan_off&&ACTION_TYPE != shot_attack&&AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
					Robo_ani_boost();
					AnimationTime = 0;
				}
				//�_�b�V���U�����ł���������
				MyShip_Move_Model4List.Apply([&](CMover*Mm){
					DASH_TIME5++;
					if (DASH_TIME5 <= 2){
						boost_main2_switch = boost_main2_on;//�u�[�X�g��i�KON_OFF
						boost_sub_switch = boost_sub_on;//�T�u�u�[�X�gON_OFF
						Velocity -= Mm->AxisX()*DASH_SP5;
						Velocity += Mm->AxisZ()*DASH_SP5;
					}
					if (DASH_TIME5 >= 3 && DASH_TIME5 <= 36){
						DASH_SP5 *= 0.9f;
						Velocity -= Mm->AxisX()*DASH_SP5;
						Velocity += Mm->AxisZ()*DASH_SP5;
						if (DASH_TIME5 == 3){
							AIR_DASHAFTER_MOVE = 1;
						}
						//�u�[�X�g�Q�[�W�����
						if (DASH_TIME5 >= 3 && DASH_TIME5 <= 12){
							boost_gage_switch = boost_gage_on;
							boost_recovery_switch = boost_recovery_off;
						}
						if (DASH_TIME5 > 12){
							boost_gage_switch = boost_gage_off;
						}
					}
					//�_�b�V���U�����Ă��Ȃ�
					if (DASH_ATTACK_COUNT == dash_attack_off && AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
						if (DASH_TIME5 >= 37){
							boost_recovery_switch = boost_recovery_on;//�u�[�X�g�Q�[�W��ON
							AIR_DASHAFTER_MOVE = 0;
							DASH_COUNT5 = 0;//�_�b�V�����͏�ԏ�����
							DASH_TIME5 = 0;//�_�b�V�����͊��o�^�C�}�[������
							AnimationTime = 0;
							Velocity = 0;//�����x������
							DASH_ZANANI_TYPE = 0;//�_�b�V���U�����ϐ�������
							DASH_ATTACK_TIME = 0;//�_�b�V���U�����͊��o�^�C�}�[������
							blade = blade_off;//�u���[�h����
							blade = gun_off;//�K������
							DASH_ZAN_CHANGE = dash_zan_off;//�_�b�V���U���ɐ؂�ւ���Ă��Ȃ����̂݃A�j���[�V���������ϐ�������
							ACTION_TYPE = normal;//�A�N�V�����^�C�v��Î~��Ԃɏ�����
							dash_type = dash_off;
							boost_main2_switch = boost_main2_off;//�u�[�X�g��i�KON_OFF
							boost_sub_switch = boost_sub_off;//�T�u�u�[�X�gON_OFF
						}
					}
					if (AIR_GUNSHOT_ONOFF == 1){
						boost_gage_switch = boost_gage_off;//�u�[�X�g����OFF
						boost_recovery_switch = boost_recovery_on;//�u�[�X�g�Q�[�W��ON
						AIR_DASHAFTER_MOVE = 0;
						DASH_COUNT5 = 0;//�_�b�V�����͏�ԏ�����
						DASH_TIME5 = 0;//�_�b�V�����͊��o�^�C�}�[������
						AnimationTime = 0;
						Velocity = 0;//�����x������
						DASH_ZANANI_TYPE = 0;//�_�b�V���U�����ϐ�������
						DASH_ATTACK_TIME = 0;//�_�b�V���U�����͊��o�^�C�}�[������
						blade = blade_off;//�u���[�h����
						blade = gun_off;//�K������
						DASH_ZAN_CHANGE = dash_zan_off;//�_�b�V���U���ɐ؂�ւ���Ă��Ȃ����̂݃A�j���[�V���������ϐ�������
						ACTION_TYPE = normal;//�A�N�V�����^�C�v��Î~��Ԃɏ�����
						dash_type = dash_off;
						boost_main2_switch = boost_main2_off;//�u�[�X�g��i�KON_OFF
						boost_sub_switch = boost_sub_off;//�T�u�u�[�X�gON_OFF
					}
				});
			}
			//(�E�O�_�b�V��)
			//�Î~��Ԃ܂��͒ʏ�U�����Ă���Ƃ�
			if (ACTION_TYPE == normal || ACTION_TYPE == attack){
				//�_�b�V���U���s��
				if (DASH_ZANANI_TYPE == 0){
					//�_�b�V�����͏�Ԃ�0
					if (DASH_COUNT6 == 0){
						//1��ڂ�a������
						if (KeyState[0][DIK_D] && KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_A] && boost_life >= 50){
							//�_�b�V�����͊��o�^�C�}�[�n��
							DASH_TIME6++;
						}
						if (DASH_TIME6 >= 1 && DASH_TIME6 <= 15){
							if (!KeyState[0][DIK_D] && !KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_A]){
								DASH_COUNT6 = 1;
								DASH_TIME6 = 0;
							}
						}
						if (DASH_TIME6 > 15){
							if (!KeyState[0][DIK_D] && !KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_A]){
								DASH_TIME6 = 0;
							}
						}
					}
					if (DASH_COUNT6 == 1){
						DASH_TIME6++;
						if (DASH_TIME6 >= 1 && DASH_TIME6 <= 15){
							//2��ڂ�a������
							if (KeyState[0][DIK_D] && KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_A]){
								DASH_COUNT6 = 2;
								DASH_TIME6 = 0;
							}
						}
						if (DASH_TIME6 > 15){
							DASH_TIME6 = 0;
							DASH_COUNT6 = 0;
						}
					}
					//�_�b�V���X�^�[�g
					//�_�b�V�����͏��2
					if (DASH_COUNT6 == 2){
						Jet_se();//dash��
						DASH_SP6 = 2.0f;
						//�A�N�V�����^�C�v(�_�b�V��)
						ACTION_TYPE = dash;
						dash_type = dash_dw_on;
						//�u���[�h�������̂ݏ���
						if (weapon_chang == chang_blade){
							//�_�b�V���U������
							DASH_ZANANI_TYPE = 1;
						}
					}
				}
			}
			//�A�N�V�����^�C�v(�_�b�V��)����
			if (ACTION_TYPE == dash&&DASH_COUNT6 == 2){
				//�_�b�V���U���ɐ؂�ւ���Ă��Ȃ����̂݃A�j���[�V��������
				if (DASH_ZAN_CHANGE == dash_zan_off&&ACTION_TYPE != shot_attack&&AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
					Robo_ani_boost();
					AnimationTime = 0;
				}
				//�_�b�V���U�����ł���������
				MyShip_Move_Model4List.Apply([&](CMover*Mm){
					DASH_TIME6++;
					if (DASH_TIME6 <= 2){
						boost_main2_switch = boost_main2_on;//�u�[�X�g��i�KON_OFF
						boost_sub_switch = boost_sub_on;//�T�u�u�[�X�gON_OFF
						Velocity += Mm->AxisX()*DASH_SP6;
						Velocity += Mm->AxisZ()*DASH_SP6;
					}
					if (DASH_TIME6 >= 3 && DASH_TIME6 <= 36){
						DASH_SP6 *= 0.9f;
						Velocity += Mm->AxisX()*DASH_SP6;
						Velocity += Mm->AxisZ()*DASH_SP6;
						if (DASH_TIME6 == 3){
							AIR_DASHAFTER_MOVE = 1;
						}
						//�u�[�X�g�Q�[�W�����
						if (DASH_TIME6 >= 3 && DASH_TIME6 <= 12){
							boost_gage_switch = boost_gage_on;
							boost_recovery_switch = boost_recovery_off;
						}
						if (DASH_TIME6 > 12){
							boost_gage_switch = boost_gage_off;
						}
					}
					//�_�b�V���U�����Ă��Ȃ�
					if (DASH_ATTACK_COUNT == dash_attack_off && AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
						if (DASH_TIME6 >= 37){
							boost_recovery_switch = boost_recovery_on;//�u�[�X�g�Q�[�W��ON
							AIR_DASHAFTER_MOVE = 0;
							DASH_COUNT6 = 0;//�_�b�V�����͏�ԏ�����
							DASH_TIME6 = 0;//�_�b�V�����͊��o�^�C�}�[������
							AnimationTime = 0;
							Velocity = 0;//�����x������
							DASH_ZANANI_TYPE = 0;//�_�b�V���U�����ϐ�������
							DASH_ATTACK_TIME = 0;//�_�b�V���U�����͊��o�^�C�}�[������
							blade = blade_off;//�u���[�h����
							blade = gun_off;//�K������
							DASH_ZAN_CHANGE = dash_zan_off;//�_�b�V���U���ɐ؂�ւ���Ă��Ȃ����̂݃A�j���[�V���������ϐ�������
							ACTION_TYPE = normal;//�A�N�V�����^�C�v��Î~��Ԃɏ�����
							dash_type = dash_off;
							boost_main2_switch = boost_main2_off;//�u�[�X�g��i�KON_OFF
							boost_sub_switch = boost_sub_off;//�T�u�u�[�X�gON_OFF
						}
					}
					if (AIR_GUNSHOT_ONOFF == 1){
						boost_gage_switch = boost_gage_off;//�u�[�X�g����OFF
						boost_recovery_switch = boost_recovery_on;//�u�[�X�g�Q�[�W��ON
						AIR_DASHAFTER_MOVE = 0;
						DASH_COUNT6 = 0;//�_�b�V�����͏�ԏ�����
						DASH_TIME6 = 0;//�_�b�V�����͊��o�^�C�}�[������
						AnimationTime = 0;
						Velocity = 0;//�����x������
						DASH_ZANANI_TYPE = 0;//�_�b�V���U�����ϐ�������
						DASH_ATTACK_TIME = 0;//�_�b�V���U�����͊��o�^�C�}�[������
						blade = blade_off;//�u���[�h����
						blade = gun_off;//�K������
						DASH_ZAN_CHANGE = dash_zan_off;//�_�b�V���U���ɐ؂�ւ���Ă��Ȃ����̂݃A�j���[�V���������ϐ�������
						ACTION_TYPE = normal;//�A�N�V�����^�C�v��Î~��Ԃɏ�����
						dash_type = dash_off;
						boost_main2_switch = boost_main2_off;//�u�[�X�g��i�KON_OFF
						boost_sub_switch = boost_sub_off;//�T�u�u�[�X�gON_OFF
					}
				});
			}
			//(����_�b�V��)
			//�Î~��Ԃ܂��͒ʏ�U�����Ă���Ƃ�
			if (ACTION_TYPE == normal || ACTION_TYPE == attack){
				//�_�b�V���U���s��
				if (DASH_ZANANI_TYPE == 0){
					//�_�b�V�����͏�Ԃ�0
					if (DASH_COUNT7 == 0){
						//1��ڂ�a������
						if (KeyState[0][DIK_A] && KeyState[0][DIK_S] && !KeyState[0][DIK_W] && !KeyState[0][DIK_D] && boost_life >= 50){
							//�_�b�V�����͊��o�^�C�}�[�n��
							DASH_TIME7++;
						}
						if (DASH_TIME7 >= 1 && DASH_TIME7 <= 15){
							if (!KeyState[0][DIK_A] && !KeyState[0][DIK_S] && !KeyState[0][DIK_W] && !KeyState[0][DIK_D]){
								DASH_COUNT7 = 1;
								DASH_TIME7 = 0;
							}
						}
						if (DASH_TIME7 > 15){
							if (!KeyState[0][DIK_A] && !KeyState[0][DIK_S] && !KeyState[0][DIK_W] && !KeyState[0][DIK_D]){
								DASH_TIME7 = 0;
							}
						}
					}
					if (DASH_COUNT7 == 1){
						DASH_TIME7++;
						if (DASH_TIME7 >= 1 && DASH_TIME7 <= 15){
							//2��ڂ�a������
							if (KeyState[0][DIK_A] && KeyState[0][DIK_S] && !KeyState[0][DIK_W] && !KeyState[0][DIK_D]){
								DASH_COUNT7 = 2;
								DASH_TIME7 = 0;
							}
						}
						if (DASH_TIME7 > 15){
							DASH_TIME7 = 0;
							DASH_COUNT7 = 0;
						}
					}
					//�_�b�V���X�^�[�g
					//�_�b�V�����͏��2
					if (DASH_COUNT7 == 2){
						Jet_se();//dash��
						DASH_SP7 = 2.0f;
						//�A�N�V�����^�C�v(�_�b�V��)
						ACTION_TYPE = dash;
						dash_type = dash_as_on;
						//�u���[�h�������̂ݏ���
						if (weapon_chang == chang_blade){
							//�_�b�V���U������
							DASH_ZANANI_TYPE = 1;
						}
					}
				}
			}
			//�A�N�V�����^�C�v(�_�b�V��)����
			if (ACTION_TYPE == dash&&DASH_COUNT7 == 2){
				//�_�b�V���U���ɐ؂�ւ���Ă��Ȃ����̂݃A�j���[�V��������
				if (DASH_ZAN_CHANGE == dash_zan_off&&ACTION_TYPE != shot_attack&&AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
					Robo_ani_boost();
					AnimationTime = 0;
				}
				//�_�b�V���U�����ł���������
				MyShip_Move_Model4List.Apply([&](CMover*Mm){
					DASH_TIME7++;
					if (DASH_TIME7 <= 2){
						boost_main2_switch = boost_main2_on;//�u�[�X�g��i�KON_OFF
						boost_sub_switch = boost_sub_on;//�T�u�u�[�X�gON_OFF
						Velocity -= Mm->AxisX()*DASH_SP7;
						Velocity -= Mm->AxisZ()*DASH_SP7;
					}
					if (DASH_TIME7 >= 3 && DASH_TIME7 <= 36){
						DASH_SP7 *= 0.9f;
						Velocity -= Mm->AxisX()*DASH_SP7;
						Velocity -= Mm->AxisZ()*DASH_SP7;
						if (DASH_TIME7 == 3){
							AIR_DASHAFTER_MOVE = 1;
						}
						//�u�[�X�g�Q�[�W�����
						if (DASH_TIME7 >= 3 && DASH_TIME7 <= 12){
							boost_gage_switch = boost_gage_on;
							boost_recovery_switch = boost_recovery_off;
						}
						if (DASH_TIME7 > 12){
							boost_gage_switch = boost_gage_off;
						}
					}
					//�_�b�V���U�����Ă��Ȃ�
					if (DASH_ATTACK_COUNT == dash_attack_off && AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
						if (DASH_TIME7 >= 37){
							boost_recovery_switch = boost_recovery_on;//�u�[�X�g�Q�[�W��ON
							AIR_DASHAFTER_MOVE = 0;
							DASH_COUNT7 = 0;//�_�b�V�����͏�ԏ�����
							DASH_TIME7 = 0;//�_�b�V�����͊��o�^�C�}�[������
							AnimationTime = 0;
							Velocity = 0;//�����x������
							DASH_ZANANI_TYPE = 0;//�_�b�V���U�����ϐ�������
							DASH_ATTACK_TIME = 0;//�_�b�V���U�����͊��o�^�C�}�[������
							blade = blade_off;//�u���[�h����
							blade = gun_off;//�K������
							DASH_ZAN_CHANGE = dash_zan_off;//�_�b�V���U���ɐ؂�ւ���Ă��Ȃ����̂݃A�j���[�V���������ϐ�������
							ACTION_TYPE = normal;//�A�N�V�����^�C�v��Î~��Ԃɏ�����
							dash_type = dash_off;
							boost_main2_switch = boost_main2_off;//�u�[�X�g��i�KON_OFF
							boost_sub_switch = boost_sub_off;//�T�u�u�[�X�gON_OFF
						}
					}
					if (AIR_GUNSHOT_ONOFF == 1){
						boost_gage_switch = boost_gage_off;//�u�[�X�g����OFF
						boost_recovery_switch = boost_recovery_on;//�u�[�X�g�Q�[�W��ON
						AIR_DASHAFTER_MOVE = 0;
						DASH_COUNT7 = 0;//�_�b�V�����͏�ԏ�����
						DASH_TIME7 = 0;//�_�b�V�����͊��o�^�C�}�[������
						AnimationTime = 0;
						Velocity = 0;//�����x������
						DASH_ZANANI_TYPE = 0;//�_�b�V���U�����ϐ�������
						DASH_ATTACK_TIME = 0;//�_�b�V���U�����͊��o�^�C�}�[������
						blade = blade_off;//�u���[�h����
						blade = gun_off;//�K������
						DASH_ZAN_CHANGE = dash_zan_off;//�_�b�V���U���ɐ؂�ւ���Ă��Ȃ����̂݃A�j���[�V���������ϐ�������
						ACTION_TYPE = normal;//�A�N�V�����^�C�v��Î~��Ԃɏ�����
						dash_type = dash_off;
						boost_main2_switch = boost_main2_off;//�u�[�X�g��i�KON_OFF
						boost_sub_switch = boost_sub_off;//�T�u�u�[�X�gON_OFF
					}
				});
			}
			//(�E��_�b�V��)
			//�Î~��Ԃ܂��͒ʏ�U�����Ă���Ƃ�
			if (ACTION_TYPE == normal || ACTION_TYPE == attack){
				//�_�b�V���U���s��
				if (DASH_ZANANI_TYPE == 0){
					//�_�b�V�����͏�Ԃ�0
					if (DASH_COUNT8 == 0){
						//1��ڂ�a������
						if (KeyState[0][DIK_D] && KeyState[0][DIK_S] && !KeyState[0][DIK_W] && !KeyState[0][DIK_A] && boost_life >= 50){
							//�_�b�V�����͊��o�^�C�}�[�n��
							DASH_TIME8++;
						}
						if (DASH_TIME8 >= 1 && DASH_TIME8 <= 15){
							if (!KeyState[0][DIK_D] && !KeyState[0][DIK_S] && !KeyState[0][DIK_W] && !KeyState[0][DIK_A]){
								DASH_COUNT8 = 1;
								DASH_TIME8 = 0;
							}
						}
						if (DASH_TIME8 > 15){
							if (!KeyState[0][DIK_D] && !KeyState[0][DIK_S] && !KeyState[0][DIK_W] && !KeyState[0][DIK_A]){
								DASH_TIME8 = 0;
							}
						}
					}
					if (DASH_COUNT8 == 1){
						DASH_TIME8++;
						if (DASH_TIME8 >= 1 && DASH_TIME8 <= 15){
							//2��ڂ�a������
							if (KeyState[0][DIK_D] && KeyState[0][DIK_S] && !KeyState[0][DIK_W] && !KeyState[0][DIK_A]){
								DASH_COUNT8 = 2;
								DASH_TIME8 = 0;
							}
						}
						if (DASH_TIME8 > 15){
							DASH_TIME8 = 0;
							DASH_COUNT8 = 0;
						}
					}
					//�_�b�V���X�^�[�g
					//�_�b�V�����͏��2
					if (DASH_COUNT8 == 2){
						Jet_se();//dash��
						DASH_SP8 = 2.0f;
						//�A�N�V�����^�C�v(�_�b�V��)
						ACTION_TYPE = dash;
						dash_type = dash_ds_on;
						//�u���[�h�������̂ݏ���
						if (weapon_chang == chang_blade){
							//�_�b�V���U������
							DASH_ZANANI_TYPE = 1;
						}
					}
				}
			}
			//�A�N�V�����^�C�v(�_�b�V��)����
			if (ACTION_TYPE == dash&&DASH_COUNT8 == 2){
				//�_�b�V���U���ɐ؂�ւ���Ă��Ȃ����̂݃A�j���[�V��������
				if (DASH_ZAN_CHANGE == dash_zan_off&&ACTION_TYPE != shot_attack&&AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
					Robo_ani_boost();
					AnimationTime = 0;
				}
				//�_�b�V���U�����ł���������
				MyShip_Move_Model4List.Apply([&](CMover*Mm){
					DASH_TIME8++;
					if (DASH_TIME8 <= 2){
						boost_main2_switch = boost_main2_on;//�u�[�X�g��i�KON_OFF
						boost_sub_switch = boost_sub_on;//�T�u�u�[�X�gON_OFF
						Velocity += Mm->AxisX()*DASH_SP8;
						Velocity -= Mm->AxisZ()*DASH_SP8;
					}
					if (DASH_TIME8 >= 3 && DASH_TIME8 <= 36){
						DASH_SP8 *= 0.9f;
						Velocity += Mm->AxisX()*DASH_SP8;
						Velocity -= Mm->AxisZ()*DASH_SP8;
						if (DASH_TIME8 == 3){
							AIR_DASHAFTER_MOVE = 1;
						}
						//�u�[�X�g�Q�[�W�����
						if (DASH_TIME8 >= 3 && DASH_TIME8 <= 12){
							boost_gage_switch = boost_gage_on;
							boost_recovery_switch = boost_recovery_off;
						}
						if (DASH_TIME8 > 12){
							boost_gage_switch = boost_gage_off;
						}
					}
					//�_�b�V���U�����Ă��Ȃ�
					if (DASH_ATTACK_COUNT == dash_attack_off && AIR_BLADE_ATTACK_TYPE == air_blade_attack_off){
						if (DASH_TIME8 >= 37){
							boost_recovery_switch = boost_recovery_on;//�u�[�X�g�Q�[�W��ON
							AIR_DASHAFTER_MOVE = 0;
							DASH_COUNT8 = 0;//�_�b�V�����͏�ԏ�����
							DASH_TIME8 = 0;//�_�b�V�����͊��o�^�C�}�[������
							AnimationTime = 0;
							Velocity = 0;//�����x������
							DASH_ZANANI_TYPE = 0;//�_�b�V���U�����ϐ�������
							DASH_ATTACK_TIME = 0;//�_�b�V���U�����͊��o�^�C�}�[������
							blade = blade_off;//�u���[�h����
							blade = gun_off;//�K������
							DASH_ZAN_CHANGE = dash_zan_off;//�_�b�V���U���ɐ؂�ւ���Ă��Ȃ����̂݃A�j���[�V���������ϐ�������
							ACTION_TYPE = normal;//�A�N�V�����^�C�v��Î~��Ԃɏ�����
							dash_type = dash_off;
							boost_main2_switch = boost_main2_off;//�u�[�X�g��i�KON_OFF
							boost_sub_switch = boost_sub_off;//�T�u�u�[�X�gON_OFF
						}
					}
					if (AIR_GUNSHOT_ONOFF == 1){
						boost_gage_switch = boost_gage_off;//�u�[�X�g����OFF
						boost_recovery_switch = boost_recovery_on;//�u�[�X�g�Q�[�W��ON
						AIR_DASHAFTER_MOVE = 0;
						DASH_COUNT8 = 0;//�_�b�V�����͏�ԏ�����
						DASH_TIME8 = 0;//�_�b�V�����͊��o�^�C�}�[������
						AnimationTime = 0;
						Velocity = 0;//�����x������
						DASH_ZANANI_TYPE = 0;//�_�b�V���U�����ϐ�������
						DASH_ATTACK_TIME = 0;//�_�b�V���U�����͊��o�^�C�}�[������
						blade = blade_off;//�u���[�h����
						blade = gun_off;//�K������
						DASH_ZAN_CHANGE = dash_zan_off;//�_�b�V���U���ɐ؂�ւ���Ă��Ȃ����̂݃A�j���[�V���������ϐ�������
						ACTION_TYPE = normal;//�A�N�V�����^�C�v��Î~��Ԃɏ�����
						dash_type = dash_off;
						boost_main2_switch = boost_main2_off;//�u�[�X�g��i�KON_OFF
						boost_sub_switch = boost_sub_off;//�T�u�u�[�X�gON_OFF
					}
				});
			}
		}
	}
	//===========================================================�_�b�V���U��=======================================================
	//���n���Ă���
	if (myship_landing_type == myship_landing_on){
		//�_�b�V���U������(�_�b�V����)
		if (DASH_ZANANI_TYPE == 1){
			if (myship_landing_type == myship_landing_off){
				DASH_ATTACK_COUNT = dash_attack_off;
				DASH_ATTACK_TIME = 0;
				AnimationTime = 0;
				blade = blade_off;
			}
			//�_�b�V�����ɍ��N���b�N�������ꂽ
			if (MouseState[0].Button[0] && !OldMouseState[0].Button[0]){
				blade = blade_on;//�o��
				blade_hold = blade_hold_reverse;//�t�莝��
				DASH_ZAN_CHANGE = dash_zan_on;//�_�b�V���A�j���[�V�����ɕύX
				Animation = Model->GetAnimation(L"boost_zan");
				DASH_ATTACK_COUNT = dash_attack_on;//�_�b�V���U���n��
				blade_hand_chang = left_hand;//���莝��
			}
		}
		//�_�b�V���U���n������
		if (DASH_ATTACK_COUNT == dash_attack_on){
			DASH_ATTACK_TIME++;
			if (DASH_ATTACK_TIME == 1){
				AnimationTime = 0;
			}//2�A����
			if (DASH_ATTACK_TIME < 38){
				if (DASH_ATTACK_TIME == 1)Blade_motion2_se();//���U�艹
				AnimationTime += 2.2f;
				if (AnimationTime > 80){
					AnimationTime = 80;
				}
			}
			if (DASH_ATTACK_TIME > 38){
				DASH_ATTACK_COUNT = dash_attack_off;
			}
		}
	}
	//�󒆂ɂ�������
	if (myship_landing_type == myship_landing_off || AIR_BLADE_ATTACK_TYPE == air_blade_attack_on){
		DASH_ATTACK_COUNT = dash_attack_off;
		DASH_ATTACK_TIME = 0;
		DASH_ZANANI_TYPE = 0;
		blade_hold = blade_hold_normal;
		DASH_ZAN_CHANGE = dash_zan_off;
	}
	//=============================================================�U�����@�`�F���W=========================================================
	//�u���[�h������	
	if (weapon_chang == chang_blade){
			if (MouseState[0].Button[2] && !OldMouseState[0].Button[2]){
				WEAPON_CHANGE_COUNT = 1;
				weapon_chang_name = chang_gun;
			}
			if (WEAPON_CHANGE_COUNT==1){
				//�ړ���
				if (ACTION_TYPE == normal){
					weapon_chang = chang_gun;
					WEAPON_CHANGE_COUNT = 0;
				}
				//�ʏ�U����
				if (ACTION_TYPE == attack){
					if (AnimationTime_Copy > 49 && AnimationTime_Copy <= 50){
						BLADEWEAPON_CHANGE_NORMAL_TYPE = 1;
					}
					if (AnimationTime_Copy > 105 && AnimationTime_Copy <= 106){
						BLADEWEAPON_CHANGE_NORMAL_TYPE = 1;
					}
					if (AnimationTime_Copy > 186 && AnimationTime_Copy <= 187){
						BLADEWEAPON_CHANGE_NORMAL_TYPE = 1;
					}
					if (AnimationTime_Copy > 270 && AnimationTime_Copy <= 271){
						BLADEWEAPON_CHANGE_NORMAL_TYPE = 1;
					}
					if (AnimationTime_Copy > 300 && AnimationTime_Copy <= 301){
						BLADEWEAPON_CHANGE_NORMAL_TYPE = 1;
					}
					if (AnimationTime > 253){
						BLADEWEAPON_CHANGE_NORMAL_TYPE = 1;
					}
					if (BLADEWEAPON_CHANGE_NORMAL_TYPE == 1){
						weapon_chang = chang_gun;
						blade = blade_off;//�u���[�h����
						WEAPON_CHANGE_COUNT = 0;
						ATTACK_COUNT = 0;
						ATTACK_ANITIME_RESET = 0;
						AnimationTime_Copy = 0;
						ATTACK_MOUSE_COUNT = 0;
						ACTION_TYPE = normal;
						Velocity = 0;
						BLADEWEAPON_CHANGE_NORMAL_TYPE = 0;
					}
				}
				//�_�b�V���ړ���
				if (ACTION_TYPE == dash){
					weapon_chang = chang_gun;
					WEAPON_CHANGE_COUNT = 0;
				}
				//�_�b�V���U����
				if (DASH_ATTACK_TIME > 38){
					weapon_chang = chang_gun;
					WEAPON_CHANGE_COUNT = 0;
				}
			}
		}
	//�K��������
		else if (weapon_chang == chang_gun){
			if (MouseState[0].Button[2] && !OldMouseState[0].Button[2]){
				GUN_WEAPON_CHANGE_COUNT = 1;
				weapon_chang_name = chang_blade;
			}
			if (GUN_WEAPON_CHANGE_COUNT == 1){
				if (GUN_ATTACK_COUNT == 0){
					GUN_WEAPON_CHANGE_NORMAL_TYPE = 1;
				}


				if (GUN_WEAPON_CHANGE_NORMAL_TYPE == 1){
					weapon_chang = chang_blade;
					GUN_ATTACK_COUNT = 0;
					gun = gun_off;
					GUN_ATTACK_TIME = 0;
					ANI_TYPE = idl;
					GUN_WEAPON_CHANGE_NORMAL_TYPE = 0;
					GUN_WEAPON_CHANGE_COUNT = 0;

					AIR_GUNSHOT_COUNT = 0;
					AIR_GUNSHOT_TIME = 0;
					AIR_GUNSHOT_ONOFF = 0;
				}
			}
			
		}
		
	//==============================================================�K���U��==================================================================
		//�K��������
		if (weapon_chang == chang_gun){
			//�㏸���͔������Ȃ�(�󒆂ɂ��Ȃ�)
			if (JAMP_TYPE == up_off&&myship_landing_type == myship_landing_on){
				if (GUN_ATTACK_COUNT == 0 && MouseState[0].Button[0] && !OldMouseState[0].Button[0] && gun_gage_life >= 100){
					gun = gun_on;//�K���o��
					ACTION_TYPE = shot_attack;//�A�N�V�����^�C�v���V���b�g�ɕύX
					blade = blade_off;//�u���[�h����
					GUN_ATTACK_TIME = 0;
					//������
					DASH_COUNT = 0;//�_�b�V�����͏�ԏ�����
					DASH_TIME = 0;//�_�b�V�����͊��o�^�C�}�[������
					DASH_COUNT2 = 0;//�_�b�V�����͏�ԏ�����
					DASH_TIME2 = 0;//�_�b�V�����͊��o�^�C�}�[������
					DASH_COUNT3 = 0;//�_�b�V�����͏�ԏ�����
					DASH_TIME3 = 0;//�_�b�V�����͊��o�^�C�}�[������
					DASH_COUNT4 = 0;//�_�b�V�����͏�ԏ�����
					DASH_TIME4 = 0;//�_�b�V�����͊��o�^�C�}�[������
					DASH_COUNT5 = 0;//�_�b�V�����͏�ԏ�����
					DASH_TIME5 = 0;//�_�b�V�����͊��o�^�C�}�[������
					DASH_COUNT6 = 0;//�_�b�V�����͏�ԏ�����
					DASH_TIME6 = 0;//�_�b�V�����͊��o�^�C�}�[������
					DASH_COUNT7 = 0;//�_�b�V�����͏�ԏ�����
					DASH_TIME7 = 0;//�_�b�V�����͊��o�^�C�}�[������
					DASH_COUNT8 = 0;//�_�b�V�����͏�ԏ�����
					DASH_TIME8 = 0;//�_�b�V�����͊��o�^�C�}�[������
					DASH_ZANANI_TYPE = 0;//�_�b�V���U�����ϐ�������
					DASH_ATTACK_TIME = 0;//�_�b�V���U�����͊��o�^�C�}�[������
					DASH_ZAN_CHANGE = dash_zan_off;//�_�b�V���U���ɐ؂�ւ���Ă��Ȃ����̂݃A�j���[�V���������ϐ�������
					GUN_ATTACK_COUNT = 1;
					gun_hande_Angle = normal_on;
					boost_main2_switch = boost_main2_off;//�u�[�X�g��i�KON_OFF
					dash_type = dash_off;
					boost_sub_switch = boost_sub_off;//�T�u�u�[�X�g������
					boost_recovery_switch = boost_recovery_on;//�u�[�X�g�Q�[�W��ON
					boost_gage_switch = boost_gage_off;//�u�[�X�g����off
				}
				if (GUN_ATTACK_COUNT == 1){
					GUN_ATTACK_TIME++;
					if (GUN_ATTACK_TIME == 1){
						Animation = Model->GetAnimation(L"shot");
						AnimationTime = 0;
					}
					if (GUN_ATTACK_TIME > 1){
						Animation = Model->GetAnimation(L"shot");
						AnimationTime += 3.2f;
						if (AnimationTime > 30.0){
							AnimationTime = 30;
						}
						//�r�[������
						if (GUN_ATTACK_TIME == 21){
							Beam_se();//�r�[�����ˉ�
							beam_launch = beam_on;//�r�[������
							gun_gage_consumption = gun_gage_consumption_on;
						}
						if (GUN_ATTACK_TIME > 21){
							beam_launch = beam_off;
							gun_gage_consumption = gun_gage_consumption_off;
						}
						if (GUN_ATTACK_TIME > 33){
							GUN_ATTACK_COUNT = 2;
						}
					}
				}
				if (GUN_ATTACK_COUNT == 2){
					Animation = Model->GetAnimation(L"shot");
					AnimationTime -= 3.2f;
					if (AnimationTime <= 0){
						AnimationTime = 0;
						gun = gun_off;
						GUN_ATTACK_COUNT = 0;
						ACTION_TYPE = normal;
						ANI_TYPE = idl;
						GUN_ATTACK_TIME = 0;
					}
				}
			}
		}
//=================================================================�W�����v====================================================
		//�u���[�h�^�C�v�ƃK���^�C�v��������
		if (weapon_chang == chang_blade || weapon_chang == chang_gun){
			//�����n�����U�����Ă��Ȃ���
			if (myship_landing_type == myship_landing_on&&ACTION_TYPE != attack&&boost_life >= 1 && GUN_ATTACK_COUNT == 0 && icon0_type == icon0_off){
				if (UP_COUNT == 0){
					UP_TIME = 0;
					UP_SP = 2.2f;
					AxisY_Velocity.Y = 0;
					if (KeyState[0][DIK_SPACE]){
						UP_COUNT = 1;
						myship_landing_type = myship_landing_off;
						JAMP_TYPE = up_on;//�W�����vON
						boost_subup_switch = boost_subup_on;//UP�u�[�X�gON
						GRAVITY_POWER = 0;
						AnimationTime = 0;

					}
					if (!KeyState[0][DIK_SPACE]){
						JAMP_TYPE = up_off;//�W�����vOFF
						boost_subup_switch = boost_subup_off;//UP�u�[�X�gOFF
					}
					
				}
			}
			//���u�[�X�g�Q�[�W0�̏ꍇ��
			if (boost_life <= 0){
				JAMP_TYPE = up_off;//�W�����vOFF
				boost_subup_switch = boost_subup_off;//UP�u�[�X�gOFF
				UP_TIME = 0;
				UP_COUNT = 0;
				GRAVITY_POWER = -1.0;
				air_gage_switch = air_gage_off;
			}
			//���󒆒��X�y�[�X�L�[��������Ă���i�㏸���Ă��違�u�[�X�g���C�t0���_�b�V�����Ă��Ȃ���
			if (myship_landing_type == myship_landing_off&&JAMP_TYPE == up_on&&boost_life >= 1 && icon0_type == icon0_off){//&& dash_type == dash_off
				//----------------------------�W�����v--------------------
				if (UP_COUNT == 1){//�W�����vON��
					Velocity.Y = 0;
					if (ACTION_TYPE != dash&&!KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_D] && !KeyState[0][DIK_A] && AIR_BLADE_ATTACK_TYPE == 0 && AIR_GUNSHOT_ONOFF == 0){//�_�b�V�����Ă��Ȃ�
						Animation = Model->GetAnimation(L"up");
						AnimationTime += 2.5f;
						if (AnimationTime >= 30){
							AnimationTime = 30;
						}
					}
					UP_TIME++;
					//���i�㏸
					if (UP_TIME <= 2){
						AxisY_Velocity.Y += UP_SP;
					}
					if (UP_TIME > 3 && UP_TIME <= 3){//���i����
						UP_SP *= 0.3f;
						AxisY_Velocity.Y += UP_SP;
					}
					if (UP_TIME > 3){
						AxisY_Velocity.Y = 0.0f;
						UP_SP *= 0.88f;
						AxisY_Velocity.Y += UP_SP;
						boost_subup_switch = boost_subup_off;//UP�u�[�X�gON
					}

					//-------------------------�㏸�p��-----------------------
					if (UP_TIME > 20){
						if (KeyState[0][DIK_SPACE]){
							air_gage_switch = air_gage_on;
							boost_subup_switch = boost_subup_on;//UP�u�[�X�gON
							UP_SP = 0.3f;
							AxisY_Velocity.Y += UP_SP;
							if (AxisY_Velocity.Y >= 0.3f){
								AxisY_Velocity.Y = 0.3f;
							}
						}
						//------------�㏸���i�󒆂ɂ���ԂɃ}�E�X�{�^���𗣂��j-------------
						if (!KeyState[0][DIK_SPACE]){
							air_gage_switch = air_gage_off;
							boost_subup_switch = boost_subup_off;//UP�u�[�X�gON
							UP_COUNT = 2;
							UP_TIME = 0;
							GRAVITY_POWER = -1.0;
						}
					}
				}
				if (UP_COUNT == 2){
					if (DASH_COUNT != 3 && DASH_COUNT2 != 3 && DASH_COUNT3 != 3 && DASH_COUNT4 != 3){//�_�b�V�����ĂȂ�
						if (!KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_D] && !KeyState[0][DIK_A] && AIR_BLADE_ATTACK_TYPE == 0 && AIR_GUNSHOT_ONOFF == 0){
							Animation = Model->GetAnimation(L"up");
						}
					}
					//-------------------���~���ď㏸---------------------
					if (KeyState[0][DIK_SPACE]){
						AIR_MOVE_CHANGE = 1;
						air_gage_switch = air_gage_on;
						boost_subup_switch = boost_subup_on;//UP�u�[�X�gON
						if (!KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_D] && !KeyState[0][DIK_A] && AIR_BLADE_ATTACK_TYPE == 0 && AIR_GUNSHOT_ONOFF == 0){
							Animation = Model->GetAnimation(L"up");
							if (AnimationTime <= 30){
								AnimationTime += 2.5f;
							}
							if (AnimationTime > 30){
								AnimationTime = 30;
							}
						}

						UP_TIME++;
						GRAVITY_POWER = 0.0;
						if (UP_TIME >30){
							UP_SP = 0.3f;
							AxisY_Velocity.Y += UP_SP;
							if (AxisY_Velocity.Y >= 0.3f){
								AxisY_Velocity.Y = 0.3f;
							}
						}
					}
					else if (!KeyState[0][DIK_SPACE] || boost_life <= 0){
						AIR_MOVE_CHANGE = 0;
						air_gage_switch = air_gage_off;
						boost_subup_switch = boost_subup_off;//UP�u�[�X�gON
						UP_TIME = 0;
						AxisY_Velocity.Y = 0.0f;
						GRAVITY_POWER = -1.0;
					}
				}
			}
			//�����n���Ă��Ȃ����W�����v���Ă��Ȃ����_�b�V�����Ă��Ȃ���
			if (myship_landing_type == myship_landing_off&&UP_COUNT == 0 && dash_type == dash_off){
				if (KeyState[0][DIK_SPACE] && !KeyState[0][DIK_A] && !KeyState[0][DIK_D] && !KeyState[0][DIK_S] && !KeyState[0][DIK_W]&&boost_life>0){
					UP_COUNT = 2;
					JAMP_TYPE = up_on;//�W�����vON
					boost_subup_switch = boost_subup_on;//UP�u�[�X�gON
					GRAVITY_POWER = -0.1f;
					AnimationTime = 0;
				}
			}
			//�󒆂ɂ��違�ړ����Ă��Ȃ����U�����Ă��Ȃ�(�󒆍U���A�ʏ�U��)
			if (myship_landing_type == myship_landing_off&&!KeyState[0][DIK_A] && !KeyState[0][DIK_D] && !KeyState[0][DIK_S] && !KeyState[0][DIK_W] && !KeyState[0][DIK_SPACE]
				       && ACTION_TYPE != attack && GUN_ATTACK_COUNT == 0 && AIR_BLADE_ATTACK == 0 && AIR_GUNSHOT_ONOFF == 0 && AIR_MOVE_CHANGE == 0){
				air_gage_switch = air_gage_off;
				boost_subup_switch = boost_subup_off;
				Animation = Model->GetAnimation(L"up");
				AnimationTime = 30;
			}
		}
		
//=====================================================================�󒆈ړ�================================================
		//�󒆂ɂ��čU�����Ă��Ȃ��B���_�b�V�����Ă��Ȃ�
		if (myship_landing_type == myship_landing_off&&ACTION_TYPE != attack&&ACTION_TYPE != dash){
			AIR_MOVE = 0.4f;
			//�ʏ�ړ�
			MyShip_Move_Model4List.Apply([&](CMover*Mm){
				//�O�i
				if (KeyState[0][DIK_W]){
					air_gage_switch = air_gage_on;
					boost_main1_switch = boost_main1_on;//�u�[�X�g��i�KON_OFF
					boost_subup_switch = boost_subup_on;//UP�T�u�u�[�X�gON
					Velocity += Mm->AxisZ()*AIR_MOVE;
					AIR_DASHAFTER_MOVECOUNT = 1;
					AIR_AFTER_ANI = 1;
					AIR_RL_MOVEANI = air_rl_moveani_go;//�ǉ�2015/5/24
				}
				//��i
				if (KeyState[0][DIK_S]){
					air_gage_switch = air_gage_on;
					boost_main1_switch = boost_main1_on;//�u�[�X�g��i�KON_OFF
					boost_subup_switch = boost_subup_on;//UP�T�u�u�[�X�gON
					Velocity -= Mm->AxisZ()*AIR_MOVE;
					AIR_DASHAFTER_MOVECOUNT = 1;
					AIR_AFTER_ANI = 1;
					AIR_RL_MOVEANI = air_rl_moveani_go;//�ǉ�2015/5/24
				}
				//�E�i
				if (KeyState[0][DIK_D]){
					air_gage_switch = air_gage_on;
					boost_main1_switch = boost_main1_on;//�u�[�X�g��i�KON_OFF
					boost_subup_switch = boost_subup_on;//UP�T�u�u�[�X�gON
					Velocity += Mm->AxisX()*AIR_MOVE;
					AIR_DASHAFTER_MOVECOUNT = 1;
					AIR_AFTER_ANI = 1;
					AIR_RL_MOVEANI = air_rl_moveani_right;//�ǉ�2015/5/24
				}
				//���i
				if (KeyState[0][DIK_A]){
					air_gage_switch = air_gage_on;
					boost_main1_switch = boost_main1_on;//�u�[�X�g��i�KON_OFF
					boost_subup_switch = boost_subup_on;//UP�T�u�u�[�X�gON
					Velocity -= Mm->AxisX()*AIR_MOVE;
					AIR_DASHAFTER_MOVECOUNT = 1;
					AIR_AFTER_ANI = 1;
					AIR_RL_MOVEANI = air_rl_moveani_left;//�ǉ�2015/5/24
				}
				//�L�[��������Ă��Ȃ���΃A�C�h�����O�萔���
				if (!KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_D] && !KeyState[0][DIK_A]){
					AIR_DASHAFTER_MOVECOUNT = 0;
					boost_main1_switch = boost_main1_off;//�u�[�X�g��i�KON_OFF
					AIR_AFTER_ANI = 0;
					AIR_RL_MOVEANI = air_rl_moveani_go;//�ǉ�2015/5/24
				}
				//�u�[�X�g�Q�[�W0
				if (boost_life <= 0){
					boost_main1_switch = boost_main1_off;//�u�[�X�g��i�KON_OFF
					AIR_DASHAFTER_MOVECOUNT = 0;
					GRAVITY_POWER = -1.0;
				}
			});
			//�u�[�X�g���C�t0�A�󒆍U�����Ă��Ȃ��i�u���[�h&�K���j
			if (boost_life <= 0 && AIR_BLADE_ATTACK_TYPE == air_blade_attack_off&&AIR_GUNSHOT_COUNT == 0){//boost_life <= 0 &&
				if (KeyState[0][DIK_W] || KeyState[0][DIK_S] || KeyState[0][DIK_D] || KeyState[0][DIK_A]){
					Robo_ani_afteamove();
				}
				if (!KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_D] && !KeyState[0][DIK_A]){
					Animation = Model->GetAnimation(L"up");
					if (AnimationTime <= 30){
						AnimationTime += 2.5f;
					}
					if (AnimationTime > 30){
						AnimationTime = 30;
					}
				}
			}
		}
		//�󒆂ɂ��ă_�b�V�����Ă���Ƃ��̏d�͐���
		if (myship_landing_type == myship_landing_off&&ACTION_TYPE == dash){
			GRAVITY_POWER = -0.1;
		}
		//�󒆂ɂ��ă_�b�V����ړ����Ă���Ƃ��̏d�́�����
		if (myship_landing_type == myship_landing_off&&AIR_DASHAFTER_MOVE == 1){
				//�O�i
				if (KeyState[0][DIK_W]){
					AIR_DASHAFTER_MOVECOUNT = 1;
					AIR_RL_MOVEANI = air_rl_moveani_go;//�ǉ�2015/5/24
				}
				//��i
				if (KeyState[0][DIK_S]){
					AIR_DASHAFTER_MOVECOUNT = 1;
					AIR_RL_MOVEANI = air_rl_moveani_go;//�ǉ�2015/5/24
				}
				//�E�i
				if (KeyState[0][DIK_D]){
					AIR_DASHAFTER_MOVECOUNT = 1;
					AIR_RL_MOVEANI = air_rl_moveani_right;//�ǉ�2015/5/24
				}
				//���i
				if (KeyState[0][DIK_A]){
					AIR_DASHAFTER_MOVECOUNT = 1;
					AIR_RL_MOVEANI = air_rl_moveani_left;//�ǉ�2015/5/24
				}
		}
		//�󒆃_�b�V����ړ�
		if (myship_landing_type == myship_landing_off&&AIR_DASHAFTER_MOVECOUNT == 1){
			AIR_MOVE = 0.5f;
			//�ʏ�ړ�
			MyShip_Move_Model4List.Apply([&](CMover*Mm){
				//�O�i
				if (KeyState[0][DIK_W]){
					boost_main1_switch = boost_main1_on;//�u�[�X�g��i�KON_OFF
					AIR_AFTER_ANI = 1;
					Velocity += Mm->AxisZ()*AIR_MOVE;
					GRAVITY_POWER = -0.05;
				}
				//��i
				if (KeyState[0][DIK_S]){
					boost_main1_switch = boost_main1_on;//�u�[�X�g��i�KON_OFF
					AIR_AFTER_ANI = 1;
					Velocity -= Mm->AxisZ()*AIR_MOVE;
					GRAVITY_POWER = -0.05;
				}
				//�E�i
				if (KeyState[0][DIK_D]){
					boost_main1_switch = boost_main1_on;//�u�[�X�g��i�KON_OFF
					AIR_AFTER_ANI = 1;
					Velocity += Mm->AxisX()*AIR_MOVE;
					GRAVITY_POWER = -0.05;
				}
				//���i
				if (KeyState[0][DIK_A]){
					boost_main1_switch = boost_main1_on;//�u�[�X�g��i�KON_OFF
					AIR_AFTER_ANI = 1;
					Velocity -= Mm->AxisX()*AIR_MOVE;
					GRAVITY_POWER = -0.05;
				}
				//�L�[��������Ă��Ȃ���΃A�C�h�����O�萔���
				if (!KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_D] && !KeyState[0][DIK_A] ){
					AIR_DASHAFTER_MOVECOUNT = 0;
					GRAVITY_POWER = -0.1;
					AIR_AFTER_ANI = 0;
					boost_main1_switch = boost_main1_off;//�u�[�X�g��i�KON_OFF
				}
			});
		}
		//�󒆍U�����Ă��Ȃ�
		if (myship_landing_type == myship_landing_off&&AIR_BLADE_ATTACK_TYPE == air_blade_attack_off&&AIR_GUNSHOT_COUNT == 0 && ACTION_TYPE != attack){
			if (AIR_AFTER_ANI == 1 || dash_type == dash_a_on || dash_type == dash_d_on || dash_type == dash_w_on || dash_type == dash_s_on || dash_type == dash_aw_on || dash_type == dash_dw_on || dash_type == dash_as_on || dash_type == dash_ds_on){
				//���b�N�I��OFF
				if (targetselection == targetselection_off)Robo_ani_afteamove();
				//���b�N�I��ON
				if (targetselection == targetselection_on){
					if (AIR_RL_MOVEANI == air_rl_moveani_go)Robo_ani_afteamove();
					if (AIR_RL_MOVEANI == air_rl_moveani_right)Robo_ani_afteamove_r();
					if (AIR_RL_MOVEANI == air_rl_moveani_left)Robo_ani_afteamove_l();
				}
			}
		}
//====================================================================�󒆍U��=======================================================
		//�u���[�h������
		if (weapon_chang == chang_blade){
			//�󒆂ɂ���
			if (myship_landing_type == myship_landing_off&&ACTION_TYPE != attack){
				if (AIR_BLADE_ATTACK == 0){
					if (MouseState[0].Button[0] && !OldMouseState[0].Button[0]){
						AIR_BLADE_ATTACK = 1;
						AIR_BLADE_ATTACK_TYPE = air_blade_attack_on;
						blade_hand_chang = right_hand;//�E�莝��
					}
				}
				//�P����
				if (AIR_BLADE_ATTACK == 1){
					AIR_BLADE_TIME++;
					if (AIR_BLADE_TIME == 1){
						Blade_motion_se();//���U��SE
						AnimationTime = 0;
						blade = blade_on;
					}
					if (AIR_BLADE_TIME >= 2 && AIR_BLADE_TIME <= 34){
						if (MouseState[0].Button[0] && !OldMouseState[0].Button[0]){
							AIR_BLADE_ATTACK_COUNT = 1;
						}
						Animation = Model->GetAnimation(L"aftea_attack");
						AnimationTime += 2.9f;
						if (AnimationTime >= 60){
							AnimationTime = 60;
						}
						//�Q�A���ڂ֌p��
						if (AIR_BLADE_ATTACK_COUNT == 1 && AIR_BLADE_TIME == 32){
							AIR_BLADE_ATTACK = 2;
							Blade_motion_se();//���U��SE
							AIR_BLADE_ATTACK_COUNT = 0;
						}
						else if (AIR_BLADE_ATTACK_COUNT == 0 && AIR_BLADE_TIME == 32){
							AIR_BLADE_ATTACK = 0;
							AnimationTime = 0;
							AIR_BLADE_TIME = 0;
							AIR_BLADE_ATTACK_TYPE = air_blade_attack_off;
							blade = blade_off;
						}
					}
				}
				//�Q����
				if (AIR_BLADE_ATTACK == 2){
					AIR_BLADE_TIME++;
					if (AIR_BLADE_TIME >= 32 && AIR_BLADE_TIME <= 61){
						if (MouseState[0].Button[0] && !OldMouseState[0].Button[0]){
							AIR_BLADE_ATTACK_COUNT = 1;
						}
						Animation = Model->GetAnimation(L"aftea_attack");
						AnimationTime += 2.8f;
						if (AnimationTime >= 100){
							AnimationTime = 100;
						}
						//3�A���ڂ֌p��
						if (AIR_BLADE_ATTACK_COUNT == 1 && AIR_BLADE_TIME == 61){
							AIR_BLADE_ATTACK = 3;
							Blade_motion_se();//���U��SE
							AIR_BLADE_ATTACK_COUNT = 0;
						}
						else if (AIR_BLADE_ATTACK_COUNT == 0 && AIR_BLADE_TIME == 61){
							AIR_BLADE_ATTACK = 0;
							AnimationTime = 0;
							AIR_BLADE_TIME = 0;
							AIR_BLADE_ATTACK_TYPE = air_blade_attack_off;
							blade = blade_off;
						}
					}
				}
				//3����
				if (AIR_BLADE_ATTACK == 3){
					AIR_BLADE_TIME++;
					if (AIR_BLADE_TIME >= 61 && AIR_BLADE_TIME <= 96){
						Animation = Model->GetAnimation(L"aftea_attack");
						AnimationTime += 3.2f;
						if (AnimationTime >= 145){
							AnimationTime = 145;
						}
						if (AIR_BLADE_TIME == 96){
							AIR_BLADE_ATTACK = 4;
						}
					}
				}
				//�����\��
				if (AIR_BLADE_ATTACK == 4){
					AIR_BLADE_TIME++;
					if (AIR_BLADE_TIME >= 96 && AIR_BLADE_TIME <= 113){
						Animation = Model->GetAnimation(L"aftea_attack");
						AnimationTime += 2.0f;
						if (AnimationTime >= 165){
							AnimationTime = 165;
						}
						if (AIR_BLADE_TIME == 113){
							AIR_BLADE_ATTACK = 0;
							AnimationTime = 0;
							AIR_BLADE_TIME = 0;
							AIR_BLADE_ATTACK_TYPE = air_blade_attack_off;
							blade = blade_off;
						}
					}
				}
			}

			//���n���������F���n���Ă���&�ʏ�U�����Ă��Ȃ����_�b�V���U�����Ă��Ȃ�
			if (myship_landing_type == myship_landing_on&&ATTACK_COUNT == 0 && DASH_ATTACK_COUNT == dash_attack_off){
				AIR_BLADE_ATTACK = 0;
				AIR_BLADE_TIME = 0;
				AIR_BLADE_ATTACK_TYPE = air_blade_attack_off;
				blade = blade_off;
			}
		}

		//�K��������
		if (weapon_chang == chang_gun){
			AIR_BLADE_ATTACK = 0;
			AIR_BLADE_TIME = 0;
			AIR_BLADE_ATTACK_TYPE = air_blade_attack_off;
			blade = blade_off;
		}
//====================================================================�󒆃K���U��=======================================================
		//�K��������
		if (weapon_chang == chang_gun){
			//�󒆂ɂ���
			if (myship_landing_type == myship_landing_off){
				if (AIR_GUNSHOT_COUNT == 0 && gun_gage_life >= 100){
					if (MouseState[0].Button[0] && !OldMouseState[0].Button[0]){
						AIR_GUNSHOT_ONOFF = 1;
						AIR_GUNSHOT_COUNT = 1;
						gun = gun_on;
						gun_hande_Angle = air_on;//�K���p�x�ύX
					}
				}
				if (AIR_GUNSHOT_COUNT == 1){
					Animation = Model->GetAnimation(L"aftea_shot1");
					AIR_GUNSHOT_TIME++;
					if (AIR_GUNSHOT_TIME==1){
						AnimationTime = 0;
					}
					if (AIR_GUNSHOT_TIME>1 && AIR_GUNSHOT_TIME<=23){
						AnimationTime += 2.5f;
						if (AnimationTime >= 30){
							AnimationTime = 30;
						}
					}
					if (AIR_GUNSHOT_TIME == 23){
						beam_launch = beam_on;
						Beam_se();//�r�[�����ˉ�
						gun_gage_consumption = gun_gage_consumption_on;
					}
					if (AIR_GUNSHOT_TIME > 23){
						gun_gage_consumption = gun_gage_consumption_off;
						beam_launch = beam_off;
						AnimationTime -= 2.5f;
						if (AnimationTime <= 0){
							AnimationTime = 0;
							AIR_GUNSHOT_COUNT = 0;
							AIR_GUNSHOT_TIME = 0;
							AIR_GUNSHOT_ONOFF = 0;
							gun = gun_off;
							gun_hande_Angle = normal_on;//�K���p�x�ύX
						}
					}
				}
			}
			//���n���Ă��違�󒆃K���U���ǂ̏�Ԃł����ʏ�K���U�����Ă��Ȃ�
			if (myship_landing_type == myship_landing_on&&AIR_GUNSHOT_COUNT >= 0 && GUN_ATTACK_COUNT == 0){
				AIR_GUNSHOT_COUNT = 0;
				AIR_GUNSHOT_TIME = 0;
				AIR_GUNSHOT_ONOFF = 0;
				gun = gun_off;
				gun_hande_Angle = normal_on;//�K���p�x�ύX
				beam_launch = beam_off;
			}
		}
	}//�i�����܂�all_combat��ON��ԂɂȂ��Ă���O��j
//==================================================================�����蔻��================================================================
		float Body_r = 7.0f;//�E�H�[�N�p
		float Body_r2 = 7.1f;//�_�b�V���W�����v�p
		float Body_r3 = 5.0f;//�Ǘp
		float Monitor_r = 3.0f;//���j�^�[�p
		CHit Fhit;
		//�X�e�[�W�������蔻��
		Stage_01List.Apply([&](CMover*s1){
			//�傫�ȉ~
			if (Fhit.SphereAndModel(Position, Body_r, s1, s1->Model)){
				myship_landing_type = myship_landing_on;
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r;
				if (Fhit.SphereAndModel(Position, Body_r, s1, s1->Model)){
					myship_landing_type = myship_landing_on;
					Velocity.Y = 0;
					Color = CColor(1, 1, 1, 1.0f);
					CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
					Position = Fhit.Position[1] + v*Body_r;
				}
			}
			//�������ĂȂ�
			if (!Fhit.SphereAndModel(Position, Body_r2, s1, s1->Model) && Position.Y>0){
				myship_landing_type = myship_landing_off;
			}
		});
		//�X�e�[�W�Ǔ����蔻��
		Stage_02List.Apply([&](CMover*s2){
			//�傫�ȉ~
			if (Fhit.SphereAndModel(Position, Body_r3, s2, s2->Model)){
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r3;
			}
		});
		//�X�e�[�W�Q�[�g�����蔻��
		Stage_gateList.Apply([&](CMover*s){
			//�傫�ȉ~
			if (Fhit.SphereAndModel(Position, Body_r3, s, s->Model)){
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r3;
			}
		});
		//�X�e�[�W�����Q�[�g�����蔻��
		Stage_Centergate_LList.Apply([&](CMover*ts){
			//�傫�ȉ~
			if (Fhit.SphereAndModel(Position, Body_r, ts, ts->Model)){
				myship_landing_type = myship_landing_on;
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r;
				if (Fhit.SphereAndModel(Position, Body_r, ts, ts->Model)){
					myship_landing_type = myship_landing_on;
					Velocity.Y = 0;
					Color = CColor(1, 1, 1, 1.0f);
					CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
					Position = Fhit.Position[1] + v*Body_r;
				}
			}
		});
		Stage_Centergate_RList.Apply([&](CMover*ts){
			//�傫�ȉ~
			if (Fhit.SphereAndModel(Position, Body_r, ts, ts->Model)){
				myship_landing_type = myship_landing_on;
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r;
				if (Fhit.SphereAndModel(Position, Body_r, ts, ts->Model)){
					myship_landing_type = myship_landing_on;
					Velocity.Y = 0;
					Color = CColor(1, 1, 1, 1.0f);
					CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
					Position = Fhit.Position[1] + v*Body_r;
				}
			}
		});
		Stage_Centergate_LRList.Apply([&](CMover*ts){
			//�傫�ȉ~
			if (Fhit.SphereAndModel(Position, Body_r, ts, ts->Model)){
				myship_landing_type = myship_landing_on;
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r;
				if (Fhit.SphereAndModel(Position, Body_r, ts, ts->Model)){
					myship_landing_type = myship_landing_on;
					Velocity.Y = 0;
					Color = CColor(1, 1, 1, 1.0f);
					CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
					Position = Fhit.Position[1] + v*Body_r;
				}
			}
		});
		//���j�^�[�����蔻��
		MonitorList.Apply([&](CMover*mn){
			//�傫�ȉ~
			if (Fhit.SphereAndModel(Position, Monitor_r, mn, mn->Model)){
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Monitor_r;
			}
		});
		//�G�����蔻��(���J�y��)
		EnemyList.Apply([&](CMover*e){
			CHit Fhit;
			float Body_r = 2.0f;
		
			if (Fhit.SphereAndModel(Position, Body_r, e, e->Model)){
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r;
			}
		});
		//�G�����蔻��(�p�`�R�})Enemy.Cpp��CEnemy_takyaku�N���X�ɏ����Ă���

		//�Q�[�g3����i�p�`�R�}�N���j
		Stage_gate3List.Apply([&](CMover*s3){
			//�傫�ȉ~
			if (Fhit.SphereAndModel(Position, Monitor_r, s3, s3->Model)){
				enemy_startup = Enemy_startupmovie_on;
				s3->Life = 0;
			}
		});

		//�Q�[�g4����i�{�X���[�r�[�n���j
		Stage_gate4List.Apply([&](CMover*s4){
			//�傫�ȉ~
			if (Fhit.SphereAndModel(Position, Monitor_r, s4, s4->Model)){
				//�{�X���[�r�[�J�n
				boss_movie_state = boss_movie_on;
				s4->Life = 0;
				//BOSS_BGM
				bgm_state = boss_combat_bgm_on;
			}
		});

		//�{�X
		float Body_r4 = 1.3f;
		Enemy_BossList.Apply([&](CMover*eb){
			if (Fhit.SphereAndModel(Position, Body_r4, eb, eb->Model)){
				Velocity.Y = 0;
				CVector v = Normalize(Fhit.Position[0] - Fhit.Position[1]);
				Position = Fhit.Position[1] + v*Body_r4;
			}
		});
//==================================================================��]�␳==================================================================
			//�K���V���b�g���Ă��Ȃ�
			if (GUN_ATTACK_COUNT != 1){
				if (Velocity.X != 0) {
					MyShip_Move_ModelList.Apply([&](CMover*Mm){
						Velocity.Y = 0;
						Rotation.Interpolate(CQuaternion(Mm->AxisZ() + Mm->AxisX()*0.001f, Velocity), 0.10f);
					});
				}
				if (Velocity.Z != 0) {
					MyShip_Move_ModelList.Apply([&](CMover*Mm){
						Velocity.Y = 0;
						Rotation.Interpolate(CQuaternion(Mm->AxisZ() + Mm->AxisX()*0.001f, Velocity), 0.10f);
					});
				}
			}
//==========================================================�u���[�h�U���_���[�W�m��Enemy======================================================
		//���J�y���M��
		if (weapon_chang == chang_blade){
			//�u���[�h�̓�����͈͂ɂ���G������
			EnemyList.Apply([&](CMover* e) {
				e->BladeHitState = Length(e->Position - Position) < 16.0f ? max(e->BladeHitState, 1) : 0;
			});
			Enemy_takyakuList.Apply([&](CMover* et) {
				et->BladeHitState = Length(et->Position - Position) < 16.0f ? max(et->BladeHitState, 1) : 0;
			});
			Enemy_BossList.Apply([&](CMover* eb) {
				eb->BladeHitState = Length(eb->Position - Position) < 16.0f ? max(eb->BladeHitState, 1) : 0;
			});
		}
//========================================================�K���V���b�g�ڕW&���[�e�[�V����========================================================
		//���n��or�󒆂ǂ���ł�����
		if (myship_landing_type == myship_landing_off || myship_landing_type == myship_landing_on){
			if (weapon_chang == chang_gun){

		//----------------�^�[�Q�b�g�I��OFF(�I�[�g�}�[�J�[)----------------------------------------------------------------------------------------------
				if (targetselection == targetselection_off){
					float el = FLT_MAX;//Enemy�����O�X
					float etl = FLT_MAX;//Enemy_takyaku�����O�X
					float ebl = FLT_MAX;//Enemy_takyaku�����O�X
					//�͈͓��i���J�y���j
					float f = FLT_MAX;
					CMover* n = 0;
					EnemyList.Apply([&](CMover* e) {
						//����&���E�͈͓��̓G����
						if (e->Position.Y - Position.Y <= 30 && Length(e->Position - Position) <= 200.0f&&Length(e->Position - Position) >= 30.0f)e->State = 1;
						if (e->Position.Y - Position.Y > 30 || Length(e->Position - Position) > 200.0f || Length(e->Position - Position) < 30.0f)e->State = 0;
						if (e->State == 1){
							float g = Length(e->Position - Position);
							if (g < f){
								f = g;
								n = e;
								n->State = 2;
								el = Length(n->Position - Position);
							}
						}
					});

					//�͈͓��i���r���{�j
					float ft = FLT_MAX;
					CMover* nt = 0;
					Enemy_takyakuList.Apply([&](CMover* et) {
						//����&���E�͈͓��̓G����
						if (et->Position.Y - Position.Y <= 20 && Length(et->Position - Position) <= 200.0f&&Length(et->Position - Position) >= 30.0f)et->State = 1;
						if (et->Position.Y - Position.Y > 20 || Length(et->Position - Position) > 200.0f || Length(et->Position - Position) < 30.0f)et->State = 0;
						if (et->State == 1){
							float gt = Length(et->Position - Position);
							if (gt < ft){
								ft = gt;
								nt = et;
								nt->State = 2;
								etl = Length(nt->Position - Position);
							}
						}
					});


					//�ł��߂��G����(���J�y��������Ƃ�)
					EnemyList.Apply([&](CMover* e) {
						if (el<etl){
							n->State = 3;
							if (n->State == 3 && GUN_ATTACK_COUNT == 1 || AIR_GUNSHOT_COUNT == 1){//�ǉ��FAIR_GUNSHOT_COUNT == 1
								CVector p = Position;//�ŏ��ɍ��W��ۑ����Ă����̂��~�\
								Position.Homing(n->Position, 0.0001f);
								Rotation = CQuaternion(AXIS_Z, n->Position - p, -AXIS_Y);
								gunshot_camera_type = gunshot_camera_on;
							}
						}
						else if (el>etl){
							nt->State = 3;
							if (nt->State == 3 && GUN_ATTACK_COUNT == 1 || AIR_GUNSHOT_COUNT == 1){//�ǉ��FAIR_GUNSHOT_COUNT == 1
								CVector p = Position;//�ŏ��ɍ��W��ۑ����Ă����̂��~�\
								Position.Homing(nt->Position, 0.0001f);
								Rotation = CQuaternion(AXIS_Z, nt->Position - p, -AXIS_Y);
								gunshot_camera_type = gunshot_camera_on;
							}
						}
					});
					//�ł��߂��G����(���r���{������Ƃ�)
					Enemy_takyakuList.Apply([&](CMover* et) {
						if (el<etl){
							n->State = 3;
							if (n->State == 3 && GUN_ATTACK_COUNT == 1 || AIR_GUNSHOT_COUNT == 1){//�ǉ��FAIR_GUNSHOT_COUNT == 1
								CVector p = Position;//�ŏ��ɍ��W��ۑ����Ă����̂��~�\
								Position.Homing(n->Position, 0.0001f);
								Rotation = CQuaternion(AXIS_Z, n->Position - p, -AXIS_Y);
								gunshot_camera_type = gunshot_camera_on;
							}
						}
						else if (el>etl){
							nt->State = 3;
							if (nt->State == 3 && GUN_ATTACK_COUNT == 1 || AIR_GUNSHOT_COUNT == 1){//�ǉ��FAIR_GUNSHOT_COUNT == 1
								CVector p = Position;//�ŏ��ɍ��W��ۑ����Ă����̂��~�\
								Position.Homing(nt->Position, 0.0001f);
								Rotation = CQuaternion(AXIS_Z, nt->Position - p, -AXIS_Y);
								gunshot_camera_type = gunshot_camera_on;
							}
						}
					});

					//�G���L���������Ȃ�BOSS�̂�
					if (enemy_count == 0){
						//�͈͓��iBOSS�j
						float fb = FLT_MAX;
						CMover* nb = 0;
						Enemy_BossList.Apply([&](CMover* eb) {
							//����&���E�͈͓��̓G����
							if (eb->Position.Y - Position.Y <= 30 && Length(eb->Position - Position) <= 200.0f&&Length(eb->Position - Position) >= 30.0f)eb->State = 1;
							if (eb->Position.Y - Position.Y > 30 || Length(eb->Position - Position) > 200.0f || Length(eb->Position - Position) < 30.0f)eb->State = 0;
							if (eb->State == 1){
								float gb = Length(eb->Position - Position);
								if (gb < fb){
									fb = gb;
									nb = eb;
									nb->State = 2;
									ebl = Length(nb->Position - Position);
								}
							}
						});
						Enemy_BossList.Apply([&](CMover* eb) {
							if (nb){
								nb->State = 3;
								if (nb->State == 3 && GUN_ATTACK_COUNT == 1 || AIR_GUNSHOT_COUNT == 1){//�ǉ��FAIR_GUNSHOT_COUNT == 1
									CVector pb = Position;//�ŏ��ɍ��W��ۑ����Ă����̂��~�\
									Position.Homing(nb->Position, 0.0001f);
									Rotation = CQuaternion(AXIS_Z, nb->Position - pb, -AXIS_Y);
									gunshot_camera_type = gunshot_camera_on;
								}
							}
						});
					}
					
					//�V���b�g�I���ʒu������
					if (myship_landing_type == myship_landing_on){
						if (GUN_ATTACK_COUNT == 2){
							Rotation = CQuaternion(AXIS_X, AxisX(), AXIS_Y);
							gunshot_camera_type = gunshot_camera_off;
						}
					}
					if (myship_landing_type == myship_landing_off){
						if (AIR_GUNSHOT_COUNT == 0){
							Rotation = CQuaternion(AXIS_X, AxisX(), AXIS_Y);
							gunshot_camera_type = gunshot_camera_off;
						}
					}
				}
			}
		}
//========================================================�u���[�h�ڕW&���[�e�[�V����========================================================
		//���n��or�󒆂ǂ���ł�����
		if (myship_landing_type == myship_landing_off || myship_landing_type == myship_landing_on){
			if (weapon_chang == chang_blade || weapon_chang == chang_gun){
				//�^�[�Q�b�g�I��OFF����ON�؂�ւ�
				if (targetselection == targetselection_off){
					if (TARGETSELECTION_COUNT == 0){
						if (KeyState[0][DIK_F] && !OldKeyState[0][DIK_F]){
							TARGETSELECTION_COUNT = 1;
						}
					}
					if (TARGETSELECTION_COUNT == 1){
						if (KeyState[0][DIK_F]){
							TARGETSELECTION_TIME++;
							if (TARGETSELECTION_TIME >= TARGETSELECTION_TIMECONSTANT){
								TARGETSELECTION_COUNT = 2;
								TARGETSELECTION_TIME = 0;
							}
						}
					}
					if (TARGETSELECTION_COUNT <= 1 && !KeyState[0][DIK_F] && TARGETSELECTION_TIME < TARGETSELECTION_TIMECONSTANT){
						TARGETSELECTION_TIME = 0;
						TARGETSELECTION_COUNT = 0;
					}
					if (TARGETSELECTION_COUNT == 2){
						TARGETSELECTION_TIME = 0;
						TARGETSELECTION_COUNT = 0;
						targetselection = targetselection_on;
					}
				}
				//�^�[�Q�b�g�I��ON����OFF�؂�ւ�
				if (targetselection == targetselection_on){
					if (TARGETSELECTION_COUNT == 0){
						if (KeyState[0][DIK_F] && !OldKeyState[0][DIK_F]){
							TARGETSELECTION_COUNT = 1;
						}
					}
					if (TARGETSELECTION_COUNT == 1){
						if (KeyState[0][DIK_F]){
							TARGETSELECTION_TIME++;
							if (TARGETSELECTION_TIME >= TARGETSELECTION_TIMECONSTANT){
								TARGETSELECTION_COUNT = 2;
								TARGETSELECTION_TIME = 0;
							}
						}
					}
					if (TARGETSELECTION_COUNT <= 1 && !KeyState[0][DIK_F] && TARGETSELECTION_TIME < TARGETSELECTION_TIMECONSTANT){
						TARGETSELECTION_TIME = 0;
						TARGETSELECTION_COUNT = 0;
					}
					if (TARGETSELECTION_COUNT == 2){
						TARGETSELECTION_TIME = 0;
						TARGETSELECTION_COUNT = 0;
						targetselection = targetselection_off;
					}
				}
				//(�^�[�Q�b�g�I��OFF)
				if (targetselection == targetselection_off){
					EnemyList.Apply([&](CMover* e) {
						e->TargetState = 0;
					});
					Enemy_takyakuList.Apply([&](CMover* et) {
						et->TargetState = 0;
					});
					Enemy_BossList.Apply([&](CMover* eb) {
						eb->TargetState = 0;
					});
					EP_COUNT = 0;
				}
				//(�^�[�Q�b�g�I��ON)
				if (targetselection == targetselection_on){
					if (EP_COUNT == 0){
						MEKAPEN = NULL;
						PATIKOMA = NULL;
						BOSS = NULL;
						//�͈͓��G����
						EnemyList.Apply([&](CMover* e) {
							if (e->TargetState != 3){
								e->TargetState = Length(e->Position - Position) <= 1000.0f ? 1 : 0;
								MEKAPEN = e;
							}
						});
						Enemy_takyakuList.Apply([&](CMover* et) {
							if (et->TargetState != 3){
								et->TargetState = Length(et->Position - Position) <= 1000.0f ? 1 : 0;
								PATIKOMA = et;
							}
						});
						Enemy_BossList.Apply([&](CMover* eb) {
							if (eb->TargetState != 3){
								eb->TargetState = Length(eb->Position - Position) <= 1000.0f ? 1 : 0;
								BOSS = eb;
							}
						});
					}

					//---------���J�y����������-------------
					if (MEKAPEN != NULL&&PATIKOMA == NULL){
						if (EP_COUNT == 0){
							EP_P = NULL;//�ŏ��̃^�[�Q�b�g����
							E_LEN = FLT_MAX;
							COLSE_E = NULL;
							EnemyList.Apply([&](CMover* e) {
								//��ԋ߂����J�y������
								if (e->TargetState == 1){
									E_LEN_S = Length(e->Position - Position);
									if (E_LEN_S < E_LEN){
										E_LEN = E_LEN_S;
										COLSE_E = e;
									}
								}
							});
							if (COLSE_E){
								EP_P = COLSE_E;
								EP_COUNT = 1;
							}
							//�W�I�m��
							if (EP_P){
								EP_P->TargetState = 2;
							}
						}
						if (EP_COUNT == 1){
							if (EP_P){
								if (KeyState[0][DIK_F] && !OldKeyState[0][DIK_F]){
									EP_P->TargetState = 3;
									EP_COUNT = 0;
								}
								if (EP_P->Life <= 0){
									EP_COUNT = 0;
								}
							}
						}
					}

					//---------�p�`�R�}��������-------------
					if (MEKAPEN == NULL&&PATIKOMA != NULL){
						if (EP_COUNT == 0){
							EP_P = NULL;//�ŏ��̃^�[�Q�b�g����
							E_LEN = FLT_MAX;
							COLSE_E = NULL;
							Enemy_takyakuList.Apply([&](CMover* et) {
								//��ԋ߂����J�y������
								if (et->TargetState == 1){
									E_LEN_S = Length(et->Position - Position);
									if (E_LEN_S < E_LEN){
										E_LEN = E_LEN_S;
										COLSE_E = et;
									}
								}
							});
							if (COLSE_E){
								EP_P = COLSE_E;
								EP_COUNT = 1;
							}
							//�W�I�m��
							if (EP_P){
								EP_P->TargetState = 2;
							}
						}
						if (EP_COUNT == 1){
							if (EP_P){
								if (KeyState[0][DIK_F] && !OldKeyState[0][DIK_F]){
									EP_P->TargetState = 3;
									EP_COUNT = 0;
								}
								if (EP_P->Life <= 0){
									EP_COUNT = 0;
								}
							}
						}
					}

					if (enemy_count == 0){
						//---------BOSS��������-------------
						if (MEKAPEN == NULL&&PATIKOMA == NULL&&BOSS != NULL){
							if (EP_COUNT == 0){
								EP_P = NULL;//�ŏ��̃^�[�Q�b�g����
								E_LEN = FLT_MAX;
								COLSE_E = NULL;
								Enemy_BossList.Apply([&](CMover* eb) {
									//��ԋ߂�BOSS����
									if (eb->TargetState == 1){
										E_LEN_S = Length(eb->Position - Position);
										if (E_LEN_S < E_LEN){
											E_LEN = E_LEN_S;
											COLSE_E = eb;
										}
									}
								});
								if (COLSE_E){
									EP_P = COLSE_E;
									EP_COUNT = 1;
								}
								//�W�I�m��
								if (EP_P){
									EP_P->TargetState = 2;
								}
							}
							if (EP_COUNT == 1){
								if (EP_P){
									if (KeyState[0][DIK_F] && !OldKeyState[0][DIK_F]){
										EP_P->TargetState = 3;
										EP_COUNT = 0;
									}
									if (EP_P->Life <= 0){
										EP_COUNT = 0;
									}
								}
							}
						}
					}

					//---------���J�y�����p�`�R�}��������-------------
					if (MEKAPEN != NULL&&PATIKOMA != NULL){
						if (EP_COUNT == 0){
							EP_P = NULL;//�ŏ��̃^�[�Q�b�g����
							E_LEN = FLT_MAX;
							COLSE_E = NULL;
							EnemyList.Apply([&](CMover* e) {
								//��ԋ߂����J�y������
								if (e->TargetState == 1){
									E_LEN_S = Length(e->Position - Position);
									if (E_LEN_S < E_LEN){
										E_LEN = E_LEN_S;
										COLSE_E = e;
									}
								}
							});
							EP_P2 = NULL;//�ŏ��̃^�[�Q�b�g����
							E_LEN2 = FLT_MAX;
							COLSE_E2 = NULL;
							Enemy_takyakuList.Apply([&](CMover* et) {
								//��ԋ߂����r����
								if (et->TargetState == 1){
									E_LEN_S2 = Length(et->Position - Position);
									if (E_LEN_S2 < E_LEN2){
										E_LEN2 = E_LEN_S2;
										COLSE_E2 = et;
									}
								}
							});
							//���J�y���ƃp�`�R�}�߂�������
							if (COLSE_E&&COLSE_E2){
								EP_P = Length(COLSE_E->Position - Position) < Length(COLSE_E2->Position - Position) ? COLSE_E : COLSE_E2;
							}
							//�W�I�m��
							if (EP_P){
								EP_P->TargetState = 2;
								EP_COUNT = 1;
							}
						}
						if (EP_COUNT == 1){
							if (EP_P){
								if (KeyState[0][DIK_F] && !OldKeyState[0][DIK_F]){
									EP_P->TargetState = 3;
									EP_COUNT = 0;
								}
								if (EP_P->Life <= 0){
									EP_COUNT = 0;
								}
							}
						}
					}

					RANG_E_COUNT = 0;
					EnemyList.Apply([&](CMover* e) {
						if (e->TargetState != 0){
							RANG_E_COUNT = 1;
						}
					});
					Enemy_takyakuList.Apply([&](CMover* et) {
						if (et->TargetState != 0){
							RANG_E_COUNT = 1;
						}
					});
					if (enemy_count == 0){
						Enemy_BossList.Apply([&](CMover* eb) {
							if (eb->TargetState != 0){
								RANG_E_COUNT = 1;
							}
						});
					}
					if (RANG_E_COUNT == 0){
						EP_COUNT = 0;
						targetselection = targetselection_off;
					}
				}


				//�W�I�����J�y����������
				EnemyList.Apply([&](CMover* e) {
					//���@��]
					if (weapon_chang == chang_blade){
						if (e->TargetState == 2 && Length(e->Position - Position) <= 20.0f){
							targetmarker_red = 1;
						}
					}
					if (weapon_chang == chang_gun){
						if (e->TargetState == 2 && e->Position.Y - Position.Y <= 30 && e->Position.X - Position.X <= 500 && e->Position.X - Position.X >= -500 && e->Position.Z - Position.Z <= 500 && e->Position.Z - Position.Z >= -500){
							targetmarker_red = 1;
							if (GUN_ATTACK_COUNT == 1 || myship_landing_type == myship_landing_off){
								Velocity.Y = 0;
								CVector PP = Position;
								Rotation = CQuaternion(AXIS_Z, e->Position - PP, -AXIS_Y);
							}
						}
					}
					//�U���}�[�J�[�O���[��
					if (weapon_chang == chang_blade){
						if (e->TargetState == 2 && Length(e->Position - Position) > 20.0f){
							targetmarker_red = 0;
						}
					}
					if (weapon_chang == chang_gun){
						if (e->TargetState == 2 && ((e->Position.Y - Position.Y > 30) || (e->Position.X - Position.X > 500 && e->Position.X - Position.X < -500 && e->Position.Z - Position.Z > 500 && e->Position.Z - Position.Z < -500))){
							targetmarker_red = 0;
							if (GUN_ATTACK_COUNT == 1 || myship_landing_type == myship_landing_off){
								//Velocity.Y = 0;
								//CVector PP = Position;
								//Rotation = CQuaternion(AXIS_Z, e->Position - PP, -AXIS_Y);
							}
						}
					}
					//�J����BOX��]
					if (e->TargetState == 2){
						MyShip_Move_Model2List.Apply([&](CMover* mm2) {//
							Velocity.Y = 0;
							CVector PP3 = Position;
							mm2->Rotation = CQuaternion(AXIS_Z, e->Position - PP3, -AXIS_Y);
							targetenemy_truefalse = targetenemy_truefalse_on;
							selection_camera_reset = selection_camera_reset_on;
						});
					}
				});
				//�W�I���p�`�R�}��������
				Enemy_takyakuList.Apply([&](CMover* et) {
					//���@��]
					if (weapon_chang == chang_blade){
						if (et->TargetState == 2 && Length(et->Position - Position) <= 20.0f){
							targetmarker_red = 1;
						}
					}
					if (weapon_chang == chang_gun){
						if (et->TargetState == 2 && et->Position.Y - Position.Y <= 30 && et->Position.X - Position.X <= 500 && et->Position.X - Position.X >= -500 && et->Position.Z - Position.Z <= 500 && et->Position.Z - Position.Z >= -500){
							targetmarker_red = 1;
							if (GUN_ATTACK_COUNT == 1 || myship_landing_type == myship_landing_off){
								Velocity.Y = 0;
								CVector PP = Position;
								Rotation = CQuaternion(AXIS_Z, et->Position - PP, -AXIS_Y);
							}
						}
					}
					//�U���}�[�J�[�O���[��
					//���@��]
					if (weapon_chang == chang_blade){
						if (et->TargetState == 2 && Length(et->Position - Position) > 20.0f){
							targetmarker_red = 0;
						}
					}
					if (weapon_chang == chang_gun){
						if (et->TargetState == 2 && ((et->Position.Y - Position.Y > 30) || (et->Position.X - Position.X > 500 && et->Position.X - Position.X < -500 && et->Position.Z - Position.Z > 500 && et->Position.Z - Position.Z < -500))){
							targetmarker_red = 0;
							if (GUN_ATTACK_COUNT == 1 || myship_landing_type == myship_landing_off){
								//Velocity.Y = 0;
								//CVector PP = Position;
								//Rotation = CQuaternion(AXIS_Z, et->Position - PP, -AXIS_Y);
							}
						}
					}
					//�J����BOX��]
					if (et->TargetState == 2){
						MyShip_Move_Model2List.Apply([&](CMover* mm2) {//
							Velocity.Y = 0;
							CVector PP3 = Position;
							mm2->Rotation = CQuaternion(AXIS_Z, et->Position - PP3, -AXIS_Y);
							targetenemy_truefalse = targetenemy_truefalse_on;
							selection_camera_reset = selection_camera_reset_on;
						});
					}
				});

				//�W�I��BOSS��������
				Enemy_BossList.Apply([&](CMover* eb) {
					//���@��]
					if (weapon_chang == chang_blade){
						if (eb->TargetState == 2 && Length(eb->Position - Position) <= 20.0f){
							targetmarker_red = 1;
						}
					}
					if (weapon_chang == chang_gun){
						if (eb->TargetState == 2 && eb->Position.Y - Position.Y <= 30 && eb->Position.X - Position.X <= 500 && eb->Position.X - Position.X >= -500 && eb->Position.Z - Position.Z <= 500 && eb->Position.Z - Position.Z >= -500){
							targetmarker_red = 1;
							if (GUN_ATTACK_COUNT == 1 || myship_landing_type == myship_landing_off){
								Velocity.Y = 0;
								CVector PP = Position;
								Rotation = CQuaternion(AXIS_Z, eb->Position - PP, -AXIS_Y);
							}
						}
					}
					//�U���}�[�J�[�O���[��
					if (weapon_chang == chang_blade){
						if (eb->TargetState == 2 && Length(eb->Position - Position) > 20.0f){
							targetmarker_red = 0;
						}
					}
					if (weapon_chang == chang_gun){
						if (eb->TargetState == 2 && ((eb->Position.Y - Position.Y > 30) || (eb->Position.X - Position.X > 500 && eb->Position.X - Position.X < -500 && eb->Position.Z - Position.Z > 500 && eb->Position.Z - Position.Z < -500))){
							targetmarker_red = 0;
							if (GUN_ATTACK_COUNT == 1 || myship_landing_type == myship_landing_off){
								//Velocity.Y = 0;
								//CVector PP = Position;
								//Rotation = CQuaternion(AXIS_Z, e->Position - PP, -AXIS_Y);
							}
						}
					}
					//�J����BOX��]
					if (eb->TargetState == 2){
						MyShip_Move_Model2List.Apply([&](CMover* mm2) {//
							Velocity.Y = 0;
							CVector PP3 = Position;
							mm2->Rotation = CQuaternion(AXIS_Z, eb->Position - PP3, -AXIS_Y);
							targetenemy_truefalse = targetenemy_truefalse_on;
							selection_camera_reset = selection_camera_reset_on;
						});
					}
				});



				EnemyList.Apply([&](CMover* e) {
					if (e->TargetState != 0){
						RANG_E_COUNT = 1;
					}
					else if (e->TargetState == 0){
						RANG_E_COUNT = 0;
					}
				});
				Enemy_takyakuList.Apply([&](CMover* et) {
					if (et->TargetState != 0){
						RANG_ET_COUNT = 1;
					}
					else if (et->TargetState == 0){
						RANG_E_COUNT = 0;
					}
				});
				if (enemy_count == 0){
					Enemy_BossList.Apply([&](CMover* eb) {
						if (eb->TargetState != 0){
							RANG_ET_COUNT = 1;
						}
						else if (eb->TargetState == 0){
							RANG_E_COUNT = 0;
						}
					});
				}

				ENEMY_All3 = 0;
				EnemyList.Apply([&](CMover* e) {
					if (e->TargetState == 1 || e->TargetState == 2){
						ENEMY_All3 = 1;
					}
				});
				Enemy_takyakuList.Apply([&](CMover* et) {
					if (et->TargetState == 1 || et->TargetState == 2){
						ENEMY_All3 = 1;
					}
				});
				if (enemy_count == 0){
					Enemy_BossList.Apply([&](CMover* eb) {
						if (eb->TargetState == 1 || eb->TargetState == 2){
							ENEMY_All3 = 1;
						}
					});
				}

				if (ENEMY_All3 == 0){
					EnemyList.Apply([&](CMover* e) {
						e->TargetState = 0;
					});
					Enemy_takyakuList.Apply([&](CMover* et) {
						et->TargetState = 0;
					});
					if (enemy_count == 0){
						Enemy_BossList.Apply([&](CMover* eb) {
							eb->TargetState = 0;
						});
					}
				}

				//���@�p������
				if (myship_landing_type == myship_landing_on){
					if (GUN_ATTACK_COUNT == 2 || GUN_ATTACK_COUNT == 0){
						Rotation = CQuaternion(AXIS_X, AxisX(), AXIS_Y);
					}
				}
			}
		}

			//�h�q�@�\���[�r�[��
		if (enemy_startup == Enemy_startupmovie_on || boss_movie_state == boss_movie_on){
				Velocity = 0;
				Robo_ani_idl();
			}

		//�v���[���p�V�X�e���i�u�Ԉړ��j
		if (DELETE_ENEMY_COUNT == 1&&WARP_COUNT == 0){
			if (KeyState[0][DIK_RETURN] && !OldKeyState[0][DIK_RETURN]){
				Position = CVector(2, 317, 1243);
				WARP_COUNT = 1;
			}
		}
		else if (DELETE_ENEMY_COUNT == 1 && WARP_COUNT == 1){
			 if (KeyState[0][DIK_RETURN] && !OldKeyState[0][DIK_RETURN]){
				 Position = CVector(0, 317, 431);
				 WARP_COUNT = 2;
			 }
		 }

		 if (DELETE_ENEMY_COUNT==0&&KeyState[0][DIK_RETURN] && !OldKeyState[0][DIK_RETURN]){
			 Enemy_takyakuList.Apply([&](CMover* et) {
				 et->Life = 0;
			 });
			 EnemyList.Apply([&](CMover* e) {
				 e->Life = 0;
			 });
			 DELETE_ENEMY_COUNT = 1;
			 patikoma_number = 0;
			 mekapen_number = 0;
		 }
}


// �����@�ړ��p���f����������
void CMyShip_Move_Model::Reset() {
	Model = GetModel(L"POSITION_NAME_BOX\\POSITIONNAME_BOX.x");
	Scale = CVector(1, 1, 1)*100;
	Color = CColor(1, 1, 1, 0.0f);
}
// �����@�ړ��p���f���ړ���
void CMyShip_Move_Model::Move() {
	MyShipList.Apply([&](CMover*m){
	Position = m->Position + CVector(0, -2.3f, 0)*m->Rotation;
	//Rotation.y = m->Rotation.y;
	//Rotation.z = m->Rotation.z;
	//Rotation.w = m->Rotation.w;
	});
}

// �����@�ړ��p���f��2������(�J��������)��
void CMyShip_Move_Model2::Reset() {
	Model = GetModel(L"POSITION_NAME_BOX\\POSITIONNAME_BOX.x");
	Scale = CVector(1, 1, 1)*100.0f;
	Color = CColor(1, 0, 1, 0.0f);
}
// �����@�ړ��p���f��2�ړ�(�J��������)��
void CMyShip_Move_Model2::Move() {
	MyShipList.Apply([&](CMover*m){
		Position = m->Position + CVector(0, 0, 0);
	});
}

// �����@�ړ��p���f��������3��
void CMyShip_Move_Model3::Reset() {
	Model = GetModel(L"POSITION_NAME_BOX\\POSITIONNAME_BOX.x");
	Scale = CVector(1, 1, 1)*100.0f;
	Color = CColor(0, 1, 1, 0.0f);
}
// �����@�ړ��p���f���ړ�3��
void CMyShip_Move_Model3::Move() {
	MyShipList.Apply([&](CMover*m){
		Position = m->Position + CVector(0, 0, 0);
		Rotation.y = m->Rotation.y;
		Rotation.w = m->Rotation.w;
	});
}

// �����@�ړ��p���f��������4��
void CMyShip_Move_Model4::Reset() {
	Model = GetModel(L"POSITION_NAME_BOX\\POSITIONNAME_BOX.x");
	Scale = CVector(1, 1, 1)*100.0f;
	Color = CColor(0, 1, 0, 0.0f);
}
// �����@�ړ��p���f���ړ�4��
void CMyShip_Move_Model4::Move() {
	if (dash_type == dash_off){
		CameraList.Apply([&](CMover*c){
			Rotation.y = c->Rotation.y;
			Rotation.w = c->Rotation.w;
		});
	}
	MyShipList.Apply([&](CMover*m){
		Position = m->Position + CVector(0, 3, 0);
	});
}

// �����@�ړ��p���f��������5��
void CMyShip_Move_Model5::Reset() {
	Model = GetModel(L"BEAM\\sphere.x");
	Scale = CVector(0.7f, 1, 0.4f)*0.1f;
	Color = CColor(1, 1, 1, 0.0f);
}
// �����@�ړ��p���f���ړ�5��
void CMyShip_Move_Model5::Move() {
	MyShipList.Apply([&](CMover*m){
		Position = m->Position + CVector(0, -2.3f, 0)*m->Rotation;
		Rotation = m->Rotation;
	});
}