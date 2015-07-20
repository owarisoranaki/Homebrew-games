#include "..\Main\Main.h"

// �J�����̏�����
void CCamera::Reset() {
	//�΂ߏォ�猩�邽�߂�������]
	Rotation = RotationX(0.05f)*Rotation;
	Rotation *= CQuaternion(AXIS_Y, 2.35f);
	AUTO_ROTATION_CHANGE = AUTO_ROTATION_BACKWARD;
	HOMING_SP = 1.2f;
}

// �J�����̈ړ�
void CCamera::Move() {
	//�i�퓬���[�h�j
	if (camera_combat_state_type == camera_combat_state_on&&enemy_startup != Enemy_startupmovie_on&&boss_movie_state != boss_movie_on){
		
		//���[�r�[�I������퓬��ԂɃJ�����ړ�
		if (COMBAT_CAMERA == 0){
			MyShipList.Apply([&](CMover*m){
				COMBAT_CHANGE_TIME++;
				if (MOVIE_END_COUNT==0){
					Rotation.Interpolate(m->Rotation, 0.05f);//0.05
					if (COMBAT_CHANGE_TIME == 145){//140
						all_combat_type = all_combat_on;//���@���삪�ł���
						bgm_state = normal_bgm_on;//BGM
						COMBAT_CAMERA = 1;
						COMBAT_CHANGE_TIME = 0;
						Time = 0;
					}
				}
				if (MOVIE_END_COUNT == 1){
					Rotation=m->Rotation;//0.05
					COMBAT_CAMERA = 1;
					COMBAT_CHANGE_TIME = 0;
					Time = 0;
				}
				Position = m->Position + CVector(0, 4, -52)*Camera->Rotation;
			});
		}
		//-----------------------------------------------------------------�����S�퓬���[�h��---------------------------------------------------------------------------------------------------------
		//����Gate���[�r�[��ON�ł͂Ȃ�
		if (COMBAT_CAMERA == 1 && icon0_type != icon0_movie_on){
			MyShipList.Apply([&](CMover*m){
				//�Y�[���z�[�����E�ݒ�
				if (MOUSE_WHEEL_COPY1 != MouseState[0].Wheel){
					if (MOUSE_WHEEL_COPY1 > MouseState[0].Wheel)ZOOM_WHEEL -= 4;
					else if (MOUSE_WHEEL_COPY1 < MouseState[0].Wheel)ZOOM_WHEEL += 4;
					MOUSE_WHEEL_COPY1 = MouseState[0].Wheel;
				}
				if (ZOOM_WHEEL <= -20)ZOOM_WHEEL = -20;
				if (ZOOM_WHEEL >= 20)ZOOM_WHEEL = 20;//48

				//�I�����b�N�I�����[�hOFF
				if (targetselection == targetselection_off || targetenemy_truefalse == targetenemy_truefalse_off){
					//�E�_�u���N���b�N
					if (CAMERA_COUNT == 0){
						if (MouseState[0].Button[1] && !OldMouseState[0].Button[1]){
							CAMERA_COUNT = 1;
						}
					}
					if (CAMERA_COUNT == 1){
						CAMERA_TIME++;
						if (CAMERA_TIME >= 1 && CAMERA_TIME <= 18){
							if (!MouseState[0].Button[1]){
								CAMERA_COUNT = 2;
								CAMERA_TIME = 0;
							}
						}
						if (CAMERA_TIME > 18){
							CAMERA_COUNT = 0;
							CAMERA_TIME = 0;
						}
					}
					if (CAMERA_COUNT == 2){
						CAMERA_TIME++;
						if (CAMERA_TIME >= 1 && CAMERA_TIME <= 18){
							if (MouseState[0].Button[1]){
								CAMERA_COUNT = 3;
								CAMERA_TIME = 0;
							}
						}
						if (CAMERA_TIME > 18){
							CAMERA_COUNT = 0;
							CAMERA_TIME = 0;
						}
					}
				}
				//�L�[����NO
				if (KeyState[0][DIK_W])KEY_NO = W;
				else if (KeyState[0][DIK_S])KEY_NO = S;
				else if (KeyState[0][DIK_A])KEY_NO = A;
				else if (KeyState[0][DIK_D])KEY_NO = D;
				else if (!KeyState[0][DIK_W] && !KeyState[0][DIK_S] && !KeyState[0][DIK_A] && !KeyState[0][DIK_D])KEY_NO = F;
				if (dash_type != dash_off)DASH_NO = 1;
			
			//---------------------------------------------------------------------------------------------------------------------------------------
				//�J�����������Z�b�g����Ă��Ȃ����I�[�g�K���V���b�gOFF���I�����b�N�I�����[�hOFF
				if (gunshot_camera_type == gunshot_camera_off && (targetselection == targetselection_off || targetenemy_truefalse == targetenemy_truefalse_off)){
					//�������[�e�[�V����OFF
					if (CAMERA_COUNT != 3){
						//--------------�E�N���b�NON&OFF---------------
						if (MouseState[0].Button[1]){
							MOUSE_MOVE_COUNT = 1;
						}
						if (!MouseState[0].Button[1]){
							MOUSE_MOVE_COUNT = 0;
							MOUSE_ROTATION_TIME = 0;
						}
						//---------(�E�N���b�N������Ă�)--------------
						if (MOUSE_MOVE_COUNT == 1){
							//�E�N���b�N�����ꂽ�u�Ԃ̃��[�e�[�V�����ۊ�
							MOUSE_ROTATION_TIME++;
							if (MOUSE_ROTATION_TIME == 1){
								ROTATION_COPY2 = Rotation;
							}
							//�E�N���b�N�A���h�h���b�O�}�E�X�������Ă��Ȃ��i�ŏ��ɃN���b�N�����Ƃ��Ɠ������[�e�[�V�����j
							if (ROTATION_COPY2 == Rotation){
								CAMERA_MOVE_COUNT2 = 0;
								Rotation *= CQuaternion(AXIS_Y, MouseState[0].Movement.X*0.0005f);
								Rotation *= CQuaternion(AxisX(), -MouseState[0].Movement.Y*0.0005f);
							}
							//�E�N���b�N�A���h�h���b�O�}�E�X��������
							else if (ROTATION_COPY2 != Rotation){
								MOUSE_ROTATION_CHANGETYPE = MOUSE_ROTATION_ON;
								CAMERA_MOVE_COUNT = 1;
								CAMERA_MOVE_COUNT2 = 1;
								HOMING_SP = 2.0f;//2.5
								Rotation *= CQuaternion(AXIS_Y, MouseState[0].Movement.X*0.0005f);
								Rotation *= CQuaternion(AxisX(), -MouseState[0].Movement.Y*0.0005f);
							}
						}
						//--------(�E�N���b�N������Ă��Ȃ�)----------
						if (MOUSE_MOVE_COUNT == 0){
							//�߂��Ă���X�s�[�h�ω�
							//��x�ł��}�E�X���E�N���b�N���ړ������Ƃ�
							if (!MouseState[0].Button[1] && CAMERA_MOVE_COUNT == 1){
								HOMING_SP = 6.0f;//3.0
							}
						}
					}
					//�������[�e�[�V����ON
					else if (CAMERA_COUNT == 3){
						ROTA_DIFFERENCE_X = Rotation.x;
						ROTA_DIFFERENCE_Y = Rotation.y;
						ROTA_DIFFERENCE_Z = Rotation.z;

						ROTA_DIFFERENCE2_X = m->Rotation.x;
						ROTA_DIFFERENCE2_Y = m->Rotation.y;
						ROTA_DIFFERENCE2_Z = m->Rotation.z;

						if (ROTA_DIFFERENCE_X < 0)ROTA_DIFFERENCE_X *= -1;
						if (ROTA_DIFFERENCE_Y < 0)ROTA_DIFFERENCE_Y *= -1;
						if (ROTA_DIFFERENCE_Z < 0)ROTA_DIFFERENCE_Z *= -1;

						if (ROTA_DIFFERENCE2_X < 0)ROTA_DIFFERENCE2_X *= -1;
						if (ROTA_DIFFERENCE2_Y < 0)ROTA_DIFFERENCE2_Y *= -1;
						if (ROTA_DIFFERENCE2_Z < 0)ROTA_DIFFERENCE2_Z *= -1;

						ROTA_DIFFERENCE3_X = ROTA_DIFFERENCE2_X - ROTA_DIFFERENCE_X;
						ROTA_DIFFERENCE3_Y = ROTA_DIFFERENCE2_Y - ROTA_DIFFERENCE_Y;
						ROTA_DIFFERENCE3_Z = ROTA_DIFFERENCE2_Z - ROTA_DIFFERENCE_Z;

						if (ROTA_DIFFERENCE3_X < 0)ROTA_DIFFERENCE3_X *= -1;
						if (ROTA_DIFFERENCE3_Y < 0)ROTA_DIFFERENCE3_Y *= -1;
						if (ROTA_DIFFERENCE3_Z < 0)ROTA_DIFFERENCE3_Z *= -1;

						DIFFERENCE_XYZ = 0.0003f;

						//���̏������甲����
						if (ROTA_DIFFERENCE_X <= DIFFERENCE_XYZ && ROTA_DIFFERENCE_Z <= DIFFERENCE_XYZ){
							if (KeyState[0][DIK_A] || KeyState[0][DIK_D] || KeyState[0][DIK_S]){
								CAMERA_COUNT = 0;
							}
						}
						if (ROTA_DIFFERENCE_X <= DIFFERENCE_XYZ && ROTA_DIFFERENCE_Z <= DIFFERENCE_XYZ && ROTA_DIFFERENCE3_Y <= DIFFERENCE_XYZ){
							CAMERA_COUNT = 0;
						}

						//�ړ�����
						HOMING_SP2 = 1.25f*5;
						Position.Homing(m->Position + CVector(0, 4, -52 + ZOOM_WHEEL)*Rotation, HOMING_SP2);//15
						Rotation.Interpolate(m->Rotation, 0.1f);

					}
				}
			//--------------------------------------------------------------------------------------------------------------------------------
				//�J���������ʒu�ɂ���
				if (CAMERA_HOMEPOSITION_TYPE == CAMERA_HOMEPOSITIONTYPE_YES){
					if (dash_type == dash_off){
						Position = m->Position + CVector(0, 4, -52 + ZOOM_WHEEL)*Rotation;
					}
					else if (dash_type != dash_off){
						HOMING_SP = 1.2f;
						Position.Homing(m->Position + CVector(0, 4, -52 + ZOOM_WHEEL)*Rotation, HOMING_SP);
					}
					MOUSE_ROTATION_CHANGETYPE = MOUSE_ROTATION_OFF;
					CAMERA_MOVE_COUNT = 0;
				}

				//�J���������ʒu�ɂ��Ȃ�
				if (CAMERA_HOMEPOSITION_TYPE == CAMERA_HOMEPOSITIONTYPE_NO){
					Position.Homing(m->Position + CVector(0, 4, -52 + ZOOM_WHEEL)*Rotation, HOMING_SP);
				}

				//��{�ʒu�ɃJ���������Ă��邩
				if (Position != m->Position + CVector(0, 4, -52 + ZOOM_WHEEL)*Rotation){
					CAMERA_HOMEPOSITION_TYPE = CAMERA_HOMEPOSITIONTYPE_NO;
				}
				if (Position == m->Position + CVector(0, 4, -52 + ZOOM_WHEEL)*Rotation){
					CAMERA_HOMEPOSITION_TYPE = CAMERA_HOMEPOSITIONTYPE_YES;
				}

			//--------------------------------------------------------------------------------------------------------------------------------
				//�I�[�g�K���V���b�g�����[�e�[�V����
				if (gunshot_camera_type == gunshot_camera_on){
					MyShipList.Apply([&](CMover*m){
						Rotation.Interpolate(m->Rotation, 0.13f);
						Position = m->Position + CVector(0, 4, -52 + ZOOM_WHEEL)*Camera->Rotation;
					});
				}
				//�^�[�Q�b�g�I��ON���̉E�N���b�N�h���b�O
				if (targetselection == targetselection_on){
					MyShip_Move_Model2List.Apply([&](CMover*mm2){
						if (MouseState[0].Button[1]){
							CAMERA_ROTATION_TIME++;
							if (CAMERA_ROTATION_TIME == 1)CAMERA_ROTATION_COPY = Rotation;
							if (CAMERA_ROTATION_COPY != Rotation){
								Rotation *= CQuaternion(AXIS_Y, MouseState[0].Movement.X*0.0005f);
								Rotation *= CQuaternion(AxisX(), -MouseState[0].Movement.Y*0.0005f);
								CAMERA_AUTOROTATION_STOP = 1;
							}
						}
						if (!MouseState[0].Button[1]){
							CAMERA_ROTATION_TIME = 0;
							CAMERA_AUTOROTATION_STOP = 0;
						}
					});
				}
				//�͈͓��ɓG�����邩�^�[�Q�b�g�I��ON���E�N���b�N�h���b�O���Ă��Ȃ�
				if (targetenemy_truefalse == targetenemy_truefalse_on&&targetselection == targetselection_on){
					MyShip_Move_Model2List.Apply([&](CMover*mm2){
						if (CAMERA_AUTOROTATION_STOP == 0){
							Rotation.Interpolate(mm2->Rotation * CQuaternion(mm2->AxisX(), 0.02f), 0.13f);
						}
						if (Position == mm2->Position + CVector(0, 4, -52 + ZOOM_WHEEL)*Camera->Rotation){
							CAMERA_AUTOROTATION_STOP2 = 1;
						}
						if (Position != mm2->Position + CVector(0, 4, -52 + ZOOM_WHEEL)*Camera->Rotation){
							CAMERA_AUTOROTATION_STOP2 = 0;
						}

						if (CAMERA_AUTOROTATION_STOP == 0 && CAMERA_AUTOROTATION_STOP2 == 0){
							//Position.Homing(mm2->Position + CVector(0, 4, -52 + ZOOM_WHEEL)*Rotation, 2.2f);
							Position = mm2->Position + CVector(0, 4, -52 + ZOOM_WHEEL)*Camera->Rotation;
						}
						if (CAMERA_AUTOROTATION_STOP == 0 && CAMERA_AUTOROTATION_STOP2 == 1){
							Position = mm2->Position + CVector(0, 4, -52 + ZOOM_WHEEL)*Camera->Rotation;
						}
						if (CAMERA_AUTOROTATION_STOP == 1){
							Position = mm2->Position + CVector(0, 4, -52 + ZOOM_WHEEL)*Camera->Rotation;
						}

					});
				}
			});
		}
	}

//----------------------------------------------------------------------------�i�J�n���[�r�[��ԁj----------------------------------------------------------------------------------------------
	else if (camera_combat_state_type == camera_combat_state_off&&enemy_startup != Enemy_startupmovie_on){
		MyShipList.Apply([&](CMover*m){
			if (moviecamera_rotat_type == moviecamera_rotat_on){
				Rotation *= CQuaternion(AXIS_Y, 0.0002f);
			}
			Position = m->Position + CVector(-2.5f, 0, -10)*Camera->Rotation;//-2.5f, 0, -10
		});
		//���[�r�[�L�����Z��
		MOVIE_CANCEL_TIME++;
		if (moviecamera_rotat_type == moviecamera_rotat_on&&MOVIE_CANCEL_TIME >= 0 && KeyState[0][DIK_SPACE] && !OldKeyState[0][DIK_SPACE]){
			movie_cancel = Movie_cancel_on;
			moviecamera_rotat_type = moviecamera_rotat_off;
			message_frame_switch = message_frame_switch_off;
			message_switch = message_off;
			target_frame_type = target_frame_off;
			MOVIE_CANCEL_TIME = 0;
			camera_combat_state_type = camera_combat_state_on;
			OP_RHINE0List.Apply([&](CMover*op0){
				op0->Life = 0;
			});
			OP_RHINE0List.Apply([&](CMover*op0){
				op0->Life = 0;
			});
			OP_RHINE1List.Apply([&](CMover*op1){
				op1->Life = 0;
			});
			
		}
	}

//--------------------------------------------------------------------------�i�Z���^�[�Q�[�g���[�r�[�j------------------------------------------------------------------------------------------
	if (icon0_type == icon0_movie_on&&enemy_startup != Enemy_startupmovie_on){
		CENTER_MOVIE_TIME++;
		if (CENTER_MOVIE_TIME==1){
			Rotation = CQuaternion(-AXIS_X, AXIS_Z, AXIS_Y);
			Position.X = -9.0;//1.93
			Position.Y = 316;
			Position.Z = 1270;
		}
		if (CENTER_MOVIE_TIME>2){
			if (CENTER_MOVIE_TIME<=54)Rotation.Interpolate(CQuaternion(AXIS_Y, 0.5), 0.1f);
			if (CENTER_MOVIE_TIME > 54 && CENTER_MOVIE_TIME < 161){
				Velocity += AxisZ()*0.1516f;
				Velocity += AxisY()*0.004f;
				Position += Velocity;
			}
			if (CENTER_MOVIE_TIME == 162){
				Velocity = 0;
			}
			if (CENTER_MOVIE_TIME > 162 && CENTER_MOVIE_TIME <= 238){
				Velocity.Y += 0.08f;
				Position += Velocity;
				Rotation.Interpolate(CQuaternion(AXIS_X,AxisX(), AXIS_Z)*0.25f, 0.024f);
			}
			if (CENTER_MOVIE_TIME > 241){
				centergate_movietype = centergate_movie_on;
			}
		}
	}
//-------------------------------------------------------------------------------�i�h�q�@�\�쓮���j----------------------------------------------------------------------------------------------
	if (enemy_startup == Enemy_startupmovie_on){
		ETMOVIE_CAMERA_TIME++;
		if (ETMOVIE_CAMERA_TIME==1){
			Rotation = RotationY(-0.5f);
			Position.X = 0;
			Position.Y = 377;
			Position.Z = -10;
		}
		if (ETMOVIE_CAMERA_TIME >= 1 && ETMOVIE_CAMERA_TIME <= 136){
			Position.Z += 0.52f;
			Position.Y -= 0.14f;
		}
		if (ETMOVIE_CAMERA_TIME > 126 && ETMOVIE_CAMERA_TIME < 189){
			Rotation *= RotationY(0.008f);
		}
		if (ETMOVIE_CAMERA_TIME >= 189 && ETMOVIE_CAMERA_TIME <= 258){
			Position.Z += 5.0f;
			Position.Y -= 0.14f;
		}
		if (ETMOVIE_CAMERA_TIME == 262){
			bgm_state = defence_combat_bgm_on;//BGM
		}
		if (ETMOVIE_CAMERA_TIME == 268){
			StageList.Apply([&](CMover* s){
				s->MovieState = 1;
			});
		}
		if (ETMOVIE_CAMERA_TIME == 295){
			Stage_gateList.Apply([&](CMover*st){
				st->State = 1;
			});
			Stage_gate2List.Apply([&](CMover*st2){
				st2->State = 1;
			});
		}
		if (ETMOVIE_CAMERA_TIME > 408 && ETMOVIE_CAMERA_TIME < 790){
			enemy_start_state = enemy_start_on;
			Rotation *= RotationY(-0.0017f);
			Position.Z += 0.07f;
			Position.Y -= 0.07f;
		}
		if (ETMOVIE_CAMERA_TIME == 790){
			COMBAT_CAMERA = 0;
			MOVIE_END_COUNT = 1;
			enemy_startup = Enemy_startup_on;
		}
		
	}
//---------------------------------------------------------------------------------�{�X�타�[�r�[-----------------------------------------------------------------------------------------------------------------
	if (boss_movie_state == boss_movie_on){
		BOSS_MOVIE_TIME++;
		if (BOSS_MOVIE_TIME == 1){
			BOSS_MOVIE_TIME2++;
			Position.X = 100;
			Position.Y = 131;
			Position.Z = 550;
			Rotation = 0;
		}
		if (BOSS_MOVIE_TIME > 1 && BOSS_MOVIE_TIME <= 300){
			BOSS_MOVIE_TIME2++;
			Velocity = 0;
			Velocity += ((AxisX()*BOSS_MOVIE_TIME*0.009f) + (AxisZ()*BOSS_MOVIE_TIME*0.009f))+AxisY()*-0.2f;
			Rotation *= RotationY(BOSS_MOVIE_TIME*-0.000013f);
		}
		if (BOSS_MOVIE_TIME >300 && BOSS_MOVIE_TIME <= 605){
			BOSS_MOVIE_TIME2--;
			Velocity = 0;
			Velocity += ((AxisX()*BOSS_MOVIE_TIME2*0.01f) + (AxisZ()*BOSS_MOVIE_TIME2*0.01f)) + AxisY()*-0.2f;
			Rotation *= RotationY(BOSS_MOVIE_TIME2*-0.000013f);
		}
		if (BOSS_MOVIE_TIME > 605){
			Velocity = 0;
			BOSS_MOVIE_TIME3++;
			if (BOSS_MOVIE_TIME3==42){
				boss_moveimodel_change = boss_moveimodel_change_on;
			}
		}
		Position += Velocity;
	}

	Enemy_Boss_modelList.Apply([&](CMover*eb){
		if (eb->State == 1 && boss_startup == boss_startup_off){
			COMBAT_CAMERA = 0;
			MOVIE_END_COUNT = 1;
			boss_movie_state = boss_combat_on;
			boss_startup = boss_startup_on;
		}
	});
}
