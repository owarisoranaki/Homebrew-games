#include "..\Main\Main.h"

// �I�[�v�j���O��ʂ̏�����
void COP_Screen::Reset() {
	Texture = GetTexture(L"OP\\OP1.png");
	//Scale = CVector(1.34f, 1, 1)*0.75f;
	Scale = CVector(1.0f, 0.75f, 1.0f)*1.0f;
	CW = 1.0f;
}

// �I�[�v�j���O��ʂ̈ړ�
void COP_Screen::Move() {
	bgm_state = op_bgm_on;//BGM_ON
	if (KeyState[0][DIK_SPACE]){
		SCREEN_FADE_COUNT = 1;
	}
	if (SCREEN_FADE_COUNT == 1){
		BGM_CHANGE_INTERVAL_TIME++;
		if (BGM_CHANGE_INTERVAL_TIME == 1){
			GetWave(L"system\\op_space.wav")->Play(1);
			GetWave(L"system\\op_space.wav")->SetVolume(0.25f);
		}
		if (BGM_CHANGE_INTERVAL_TIME == 70){
			bgm_state = mission_bgm_on;//BGM_ON
		}
		CR -= 0.01f;
		CG -= 0.01f;
		CB -= 0.01f;
	}
	if (CR <= 0 && CG <= 0 && CB <= 0){
		SCREEN_FADE_COUNT = 0;
		screen_switch = screen_on;
		Life = 0;
	}
	Color = CColor(CR, CG, CB, CW);
}
//======================================================================================================================
// �I�[�v�j���O��ʕ����̏�����
void COP_Screen_Write::Reset() {
	Texture = GetTexture(L"OP\\OP_WARITE.png");
	Scale = CVector(2.3f, 0.5f, 0)*0.15f;
}

// �I�[�v�j���O��ʕ����̈ړ�
void COP_Screen_Write::Move() {
	Time++;
	if (Time%3==0){
		COLOR_TIME += 1;
		if (CW==1.5f){
			CW = 0.7f;
		}
		else if (CW == 0.7f){
			CW = 1.5f;
		}
	}
	if (Time%1==0){
		Color = CColor(Random(1, 0.7f), Random(1, 0.7f), Random(1, 0.7f), CW);
	}
	if (KeyState[0][DIK_SPACE]){
		Life = 0;
	}
}
//========================================================================================================================
// ��ʐ؂�ւ����C���̏�����0
void COP_RHINE0::Reset() {
	Texture = GetTexture(L"OP\\OP_RHINE0.png");
	Scale = CVector(1.34f, 1.0f, 1)*0.75f;
	Color = CColor(0, 0, 0, 0.0f);
}

// ��ʐ؂�ւ����C���̈ړ�0
void COP_RHINE0::Move() {
	if (screen_switch == screen_on){
		moviecamera_rotat_type = moviecamera_rotat_on;//���[�r�[�J�������[�e�[�V����ON
		Time++;
		if (Time == 120){
			Life = 0;
			//game_start_type = game_start_on;
			//score_display_switch = score_on;
			//combat_state_type = combat_state_on;
			message_frame_type = message_frame_on;//�A�C�R���\��
			message_frame_switch = message_frame_switch_on;//�A�C�R����ON
		}
		Position.X += 0.02f;
		Color = CColor(0, 0, 0, 1.0f);
	}
}
//========================================================================================================================
// ��ʐ؂�ւ����C���̏�����1
void COP_RHINE1::Reset() {
	Texture = GetTexture(L"OP\\OP_RHINE1.png");
	Scale = CVector(1.34f, 1.0f, 1)*0.75f;
	Color = CColor(0, 0, 0, 0.0f);
}

// ��ʐ؂�ւ����C���̈ړ�1
void COP_RHINE1::Move() {
	if (screen_switch == screen_on){
		Time++;
		if (Time == 120){
			Life = 0;
		}
		Position.X -= 0.02f;
		Color = CColor(0, 0, 0, 1.0f);
	}
}
//========================================================================================================================
// ���C�t�Q�[�W�y�䏉����
void COP_LIFEGAGE::Reset() {
	Texture = GetTexture(L"LIFEGAGE\\lifegage.png");
	Color = CColor(0, 0, 0, 0.0f);
}

// ���C�t�Q�[�W�y��ړ�
void COP_LIFEGAGE::Move() {
	//�Z���^�[�Q�[�g���[�r�[���͐F����
	if (icon0_type == icon0_movie_on || enemy_startup == Enemy_startupmovie_on){
		Color = CColor(0, 0, 0, 0.0f);
	}
	//�{�X���[�r�[������
	if (boss_movie_state == boss_movie_on){
		Color = CColor(0, 0, 0, 0.0f);
	}
	//�퓬���[�h���Z���^�[�Q�[�g���[�r�[�ł͂Ȃ�
	if (all_combat_type == all_combat_on&&icon0_type != icon0_movie_on&&enemy_startup != Enemy_startupmovie_on&&boss_movie_state != boss_movie_on){
		Color = CColor(0, 0, 0, 1.0f);
		LIFE = 3500;//MyShip���C�t
		LIFE *= 0.001f;

		Position = CVector(-0.5f, 0.66f, 0.0f);//-0.2f+X, 0.0f, 0.0f
		Scale = CVector(LIFE, 0.15f, 0.0f)*0.1f;
	}
}
//========================================================================================================================
// ���C�t�Q�[�W������
void COP_LIFEGAGE2::Reset() {
	
	Color = CColor(0.2f, 1, 0.2f, 1.0f);
}

// ���C�t�Q�[�W�ړ�
void COP_LIFEGAGE2::Move() {
	//�Z���^�[�Q�[�g���[�r�[���͐F����
	if (icon0_type == icon0_movie_on||enemy_startup == Enemy_startupmovie_on){
		Color = CColor(0.2f, 1, 0.2f, 0.0f);
	}
	//�{�X���[�r�[������
	if (boss_movie_state == boss_movie_on){
		Color = CColor(0, 0, 0, 0.0f);
	}
	//�퓬���[�h���Z���^�[�Q�[�g���[�r�[�ł͂Ȃ�
	if (all_combat_type == all_combat_on&&icon0_type != icon0_movie_on&&enemy_startup != Enemy_startupmovie_on&&boss_movie_state != boss_movie_on){
		Texture = GetTexture(L"LIFEGAGE\\lifegage.png");
		//���G���[�h�ɂȂ��Ă��Ȃ�
		MyShipList.Apply([&](CMover* m){
			m->Life -= my_damage;
			X -= my_damage*0.0001;

			LIFE = m->Life;
			LIFE *= 0.001f;

			Position = CVector(-0.5f + X, 0.662f, 0.0f);//-0.5f + X, 0.662f, 0.0f
			Scale = CVector(LIFE, 0.05f, 0.0f)*0.1f;//Y=0.06

			//�F����
			if (m->Life >= 2400 && m->Life <= 3500){
				Color = CColor(0.2f, 1, 0.2f, 1.0f);
				EmissiveColor = CColor(Random(0, 0.3f), Random(1.0, 1.0f), Random(0, 0), 0.25f);
			}
			else if (m->Life >= 1000 && m->Life < 2400){
				Color = CColor(1.0f, 1, 0.0f, 1.0f);
				EmissiveColor = CColor(Random(1.0f, 1.0f), Random(1.0, 1.0f), Random(0, 0), 0.25f);
			}
			else if (m->Life < 1000){
				Color = CColor(1.0f, 0, 0.0f, 1.0f);
				EmissiveColor = CColor(Random(1.0f, 1.0f), Random(0.0, 0.0f), Random(0, 0), 0.25f);
			}
		});

		//�Q�[���I�������ɂȂ��Ă��Ȃ�
		if (clear == clear_off){
			//���J�y���M���i���g���{���j
			Effect10List.Apply([&](CMover* B2) {
				MyShipList.Apply([&](CMover* m) {
					//���G��Ԃł͂Ȃ�
					if (myship_invincible_type == myship_invincible_off){
						//���g���{���Ǝ��@�Ƃ̋���
						if (Length(B2->Position - m->Position) <= 9.5f){
							my_damage = 100;
							New<CEffect_damage_position>(m->Position + CVector(0, 0.0f, 0));
							myship_invincible_type = myship_invincible_on;
						}
					}
				});
			});
			//���J�y���M���i�����j
			Effect5List.Apply([&](CMover* e5) {
				MyShipList.Apply([&](CMover* m) {
					//���G��Ԃł͂Ȃ�
					if (myship_invincible_type == myship_invincible_off){
						//���g���{���Ǝ��@�Ƃ̋���
						if (Length(e5->Position - m->Position) <= 50.0f){
							my_damage = 600;
							New<CEffect_damage_position>(m->Position + CVector(0, 0.0f, 0));
							myship_invincible_type = myship_invincible_on;
						}
					}
				});
			});
			//�p�`�R�}���[�U�[�u���[�h(Item.cpp���ɏ����������Ă���)
			Item3List.Apply([&](CMover* i3) {
				MyShip_Move_Model5List.Apply([&](CMover* m) {
					CHit Bhit;
					if (myship_invincible_type == myship_invincible_off){
						if (Bhit.SegmentAndModel(i3->Position, i3->Position - i3->AxisZ()*-13, m, m->Model)){//4
							my_damage = 100;
							New<CEffect_damage_position>(m->Position + CVector(0, 0.0f, 0));
							myship_invincible_type = myship_invincible_on;
						}
					}
				});
			});
			//�p�`�R�}�L���m��
			Bullet7List.Apply([&](CMover*B7){
				MyShipList.Apply([&](CMover* m) {
					CHit ETBhit;
					float ETBhit_r = 3;
					if (myship_invincible_type == myship_invincible_off){
						if (ETBhit.SphereAndModel(m->Position, ETBhit_r, B7, B7->Model)){
							my_damage = 100;
							New<CEffect_damage_position>(m->Position + CVector(0, 0.0f, 0));
							myship_invincible_type = myship_invincible_on;
						}
					}
				});
			});
			//�J�~�i��
			CHit Fhit;
			float Body_r = 6;
			//�X�e�[�W�Ǔ����蔻��
			Bullet5List.Apply([&](CMover*B5){
				MyShipList.Apply([&](CMover* m) {
					if (myship_invincible_type == myship_invincible_off){
						//�傫�ȉ~
						if (Fhit.SphereAndModel(m->Position, Body_r, B5, B5->Model)){
							my_damage = 500;
							New<CEffect_damage_position>(m->Position + CVector(0, 0.0f, 0));
							myship_invincible_type = myship_invincible_on;
						}
					}
				});
			});
		}
		//BOSS_GUN�e
		Bullet9List.Apply([&](CMover*B9){
			MyShipList.Apply([&](CMover* m) {
				CHit ETBhit;
				float ETBhit_r = 3;
				if (myship_invincible_type == myship_invincible_off){
					if (ETBhit.SphereAndModel(m->Position, ETBhit_r, B9, B9->Model)){
						my_damage = 50;
						New<CEffect_damage_position>(m->Position + CVector(0, 0.0f, 0));
						myship_invincible_type = myship_invincible_on;
					}
				}
			});
		});
		//-------------------���G����-------------------
		//���G���
		if (myship_invincible_type == myship_invincible_on){
			INVINCIBLE_COLOR_TIME++;
			if (INVINCIBLE_COLOR_TIME == 2){
				my_damage = 0;
			}
			if (INVINCIBLE_COLOR_TIME % 3 == 0){
				MyShipList.Apply([&](CMover* m) {
					m->Color = CColor(Random(1, 0.5f), Random(1, 0.5f), Random(1, 0.5f), Random(0.4f, 0.1f));
				});
			}
			if (INVINCIBLE_COLOR_TIME == 70){
				myship_invincible_type = myship_invincible_off;
				INVINCIBLE_COLOR_TIME = 0;
			}
		}
		//���G��Ԃł͂Ȃ�
		if (myship_invincible_type == myship_invincible_off){
			MyShipList.Apply([&](CMover* m) {
				m->Color = CColor(1, 1, 1, 1);
			});
		}
	}
}
//========================================================================================================================
// �u�[�X�g�Q�[�W�y�䏉����
void COP_BOOSTGAGE::Reset() {
	Texture = GetTexture(L"LIFEGAGE\\lifegage.png");
	Color = CColor(0.0f, 0.0f, 0.0f, 0.0f);//w=1
	Scale = CVector(1, 0.1f, 0.0f)*0.1f;
	Position = CVector(-0.447f, 0.6374f, 0.0f);
}

// �u�[�X�g�Q�[�W�y��ړ�
void COP_BOOSTGAGE::Move() {
	//�Z���^�[�Q�[�g���[�r�[���͐F����
	if (icon0_type == icon0_movie_on||enemy_startup == Enemy_startupmovie_on){
		Color = CColor(0, 0, 0, 0.0f);
	}
	//�{�X���[�r�[������
	if (boss_movie_state == boss_movie_on){
		Color = CColor(0, 0, 0, 0.0f);
	}
	//�퓬���[�h���Z���^�[�Q�[�g���[�r�[�ł͂Ȃ�
	if (all_combat_type == all_combat_on&&icon0_type != icon0_movie_on&&enemy_startup != Enemy_startupmovie_on&&boss_movie_state != boss_movie_on){
		Color = CColor(0.0f, 0.0f, 0.0f, 1.0f);
		BOOST_LIFE = 200 * 0.01f;//2
		Scale = CVector(BOOST_LIFE, 0.076f, 0.0f)*0.1f;
	}
}
//========================================================================================================================
// �u�[�X�g�Q�[�W������
void COP_BOOSTGAGE2::Reset() {
	Scale = CVector(1, 0.1f, 0.0f)*0.1f;
	boost_life = 200;
	Position = CVector(-0.447f, 0.6374f, 0.0f);
}

// �u�[�X�g�Q�[�W�ړ�
void COP_BOOSTGAGE2::Move() {
	//�Z���^�[�Q�[�g���[�r�[���͐F����
	if (icon0_type == icon0_movie_on || enemy_startup == Enemy_startupmovie_on){
		Color = CColor(0, 0, 0, 0.0f);
	}
	//�{�X���[�r�[������
	if (boss_movie_state == boss_movie_on){
		Color = CColor(0, 0, 0, 0.0f);
	}
	//�퓬���[�h���Z���^�[�Q�[�g���[�r�[�ł͂Ȃ�
	if (all_combat_type == all_combat_on&&icon0_type != icon0_movie_on&&enemy_startup != Enemy_startupmovie_on&&boss_movie_state != boss_movie_on){
		Texture = GetTexture(L"LIFEGAGE\\lifegage.png");
		float DASH_DAMAGE = 3.0f;
		float AIR_MOVE = 0.3f;
		float RECOVERY_LIFE = 0.8f;
		//�_�b�V�����Q�[�W����
		if (boost_gage_switch == boost_gage_on){
			boost_life -= DASH_DAMAGE;
			X -= DASH_DAMAGE*0.001;
			Position = CVector(-0.447f + X, 0.6374f, 0.0f);
		}
		if (boost_life <= 0){
			boost_life = 0;
			X = -0.2f;
		}
		if (boost_life >= 200){
			boost_life = 200;
			X = 0.0f;
		}

		//�󒆈ړ����Q�[�W����
		if (air_gage_switch == air_gage_on){

			boost_life -= AIR_MOVE;
			X -= AIR_MOVE*0.001;
			Position = CVector(-0.447f + X, 0.6374f, 0.0f);
		}

		//��(���n���Ă��違�_�b�V�����Ă��Ȃ�&�󒆈ړ��Q�[�W����OFF�i���R���n���Ă��邩��j)
		if (myship_landing_type == myship_landing_on&&dash_type == dash_off&&air_gage_switch == air_gage_off){
			boost_life += RECOVERY_LIFE;
			X += RECOVERY_LIFE*0.001;
			Position = CVector(-0.447f + X, 0.6374f, 0.0f);
		}

		//�X�P�[�����|�W�V�����ړ�
		BOOST_LIFE = boost_life*0.01f;//2
		Scale = CVector(BOOST_LIFE, 0.076f, 0.0f)*0.1f;

		//�Q�[�W�F�ω�
		if (boost_life >= 50 && boost_life <= 210){
			Color = CColor(0.0f, 0.6f, 1, 1.0f);
			EmissiveColor = CColor(Random(0.2f, 0.2f), Random(0.2f, 0.2f), Random(1, 1), 0.3f);
		}
		else if (boost_life < 50){
			Color = CColor(1.0f, 0, 0.0f, 1.0f);
			EmissiveColor = CColor(Random(1.0f, 1.0f), Random(0.0, 0.0f), Random(0, 0), 0.3f);
		}
		//���@���œ����Q�[�W����
		MyShipList.Apply([&](CMover* m){
			if (m->Life <= 0){
				Life = 0;
			}
		});
	}
}
//========================================================================================================================
// ���C�t�Q�[�W�g������
void COP_LIFEGAGE_FRAME::Reset() {
	Texture = GetTexture(L"LIFEGAGE\\lifegage_waku3.png");
	Color = CColor(1, 1, 1, 0.0f);
	Scale = CVector(1.33f, 0.42f, 0.0f)*0.36f;
	Position = CVector(-0.545f, 0.625f, 0.0f);
}

// ���C�t�Q�[�W�g�ړ�
void COP_LIFEGAGE_FRAME::Move() {
	//�Z���^�[�Q�[�g���[�r�[���͐F����
	if (icon0_type == icon0_movie_on || enemy_startup == Enemy_startupmovie_on){
		Color = CColor(0, 0, 0, 0.0f);
	}
	//�{�X���[�r�[������
	if (boss_movie_state == boss_movie_on){
		Color = CColor(0, 0, 0, 0.0f);
	}
	//�퓬���[�h���Z���^�[�Q�[�g���[�r�[�ł͂Ȃ�
	if (all_combat_type == all_combat_on&&icon0_type != icon0_movie_on&&enemy_startup != Enemy_startupmovie_on&&boss_movie_state != boss_movie_on){
		Color = CColor(1, 1, 1, 1.0f);
	}
}
//========================================================================================================================
// �^�C��������
void COP_TIME::Reset() {
	time_minute = 5;
	//time_second2 = 1;
}

// �^�C���ړ�
void COP_TIME::Move() {
	if (all_combat_type == all_combat_off){
		//==================�^�C������====================
		/*time_micro++;
		//�}�C�N���b
		if (time_micro==10){
		time_micro = 0;
		time_micro2++;
		}
		if (time_micro2==6){
		time_micro2 = 0;
		time_second++;
		}
		//�b
		if (time_second == 10){
		time_second2 ++;
		time_second = 0;
		}
		if (time_second2==6){
		time_second2 = 0;
		time_minute++;
		}
		//��
		if (time_minute==10){
		time_minute = 0;
		time_minute2++;
		}
		if (time_minute2==6){
		time_minute2 = 0;
		time_when++;
		}
		//��
		if (time_when2<=1&&time_when == 10){
		time_when = 0;
		time_when2++;
		}
		if (time_when2 == 2 && time_when == 5){
		time_when2 = 0;
		time_when == 0;
		}*/
	}
	//===================�^�C������======================
	//�퓬���[�h�����Z���^�[�Q�[�g���[�r�[���ł͂Ȃ�
	if (all_combat_type == all_combat_on&&TIME_COUNT == 0 && icon0_type != icon0_movie_on&&enemy_startup != Enemy_startupmovie_on&&boss_movie_state != boss_movie_on&&clear == clear_off){
		timeleft = timeleft_yes;//�c�莞�Ԃ���
		//�}�C�N��
			time_micro--;
			if (time_micro == -1){
				time_micro = 9;
				time_micro2--;
			}
			if (time_micro2 == -1){
				time_micro2 = 5;
				time_second--;
			}
			//�b
			if (time_second == -1){
				time_second = 9;
				time_second2--;
			}
			if (time_second2 == -1){
				time_second2 = 5;
				time_minute--;
			}
			//��
			if (time_minute == -1){
				time_minute = 9;
				time_minute2--;
			}
			if (time_minute2 == -1){
				time_minute2 = 5;
				time_when--;
			}
			//��
			if (time_when2 >= 0 && time_when == -1){
				time_when = 9;
				time_when2--;
			}
			if (time_when2 == -1){
				time_when2 = 0;
			}
		}

	if (time_minute == 0 && time_second2 > 0){
		last_one_minutes = last_one_minutes_on;
	}
	
	if (time_when2 == 0 && time_when2 == 0 && time_minute2 == 0 && time_minute == 0 && time_second2 == 0 && time_second == 0 && time_micro2 == 0 && time_micro == 0){
		TIME_COUNT = 1;
		clear = clear_bad_on;
		last_one_minutes = last_one_minutes_off;
		timeleft = timeleft_no;//�c�莞�ԂȂ�
	}
}
//========================================================================================================================
// ���b�Z�[�W�g������
void COP_MESSAGE_FRAME::Reset() {
	Texture = GetTexture(L"MESSAGE\\message1.png");
	Color = CColor(1, 1, 1, 0.2f);
	Scale = CVector(1.0f, 1.0f, 0.0f)*0.1f;
	Position = CVector(-0.9f, 0.3f, 0.0f);
}

// ���b�Z�[�W�g�ړ�
void COP_MESSAGE_FRAME::Move() {
	//�A�C�R���\��ON�������Q�[�g���[�r�[���ł͂Ȃ����x�񃀁[�r�[���ł͂Ȃ����{�X���[�r�[���ł͂Ȃ�
	if (message_frame_type == message_frame_on&&icon0_type != icon0_movie_on&&enemy_startup != Enemy_startupmovie_on&&boss_movie_state != boss_movie_on){
		//�A�C�R����ON
		if (message_frame_switch == message_frame_switch_on){
			if (MESSAGE_COUNT0 == 0){
				Time++;
				if (Time == 20){
					Time = 0;
					MESSAGE_COUNT0 = 1;
				}
			}
			if (MESSAGE_COUNT0 == 1){
				Color = CColor(1, 1, 1, 1.0f);
				EmissiveColor = CColor(Random(0.0f, 0.0f), Random(1.0, 0.5f), Random(0, 0.5f), 0.1f);
				Time++;
				if (Time == 17){
					message_switch = message_on;//message�\��
				}
			}
		}

		//�A�C�R����OFF
		if (message_frame_switch == message_frame_switch_off){
			Time = 0;
			MESSAGE_COUNT0 = 0;
			Color = CColor(1, 1, 1, 0.2f);
			EmissiveColor = CColor(Random(0.0f, 0.0f), Random(1.0, 0.5f), Random(0, 0.5f), 0.0f);
			}
		}
	else if (message_frame_type == message_frame_off||icon0_type == icon0_movie_on||enemy_startup == Enemy_startupmovie_on||boss_movie_state == boss_movie_on){
		Color = CColor(0, 0, 0, 0.0f);
	}
}
//========================================================================================================================
// �^�[�Q�b�g�g������
void COP_TARGET_FRAME::Reset() {
	
}

// �^�[�Q�b�g�g�ړ�
void COP_TARGET_FRAME::Move() {
		if (target_frame_type==target_frame_on){
			Texture = GetTexture(L"TAKYAKUROBO\\target.png");
			Color = CColor(1, 1, 1, 1.0f);
			Scale = CVector(1.0f, 1.0f, 0.0f)*0.25f;
			Position = CVector(-0.34f, 0.0f, 0.0f);
		}
		if (target_frame_type == target_frame_off){
			Color = CColor(1, 1, 1, 0.0f);
		}


}
//========================================================================================================================
// ���[�r�[�g������
void COP_MOVIE_FRAME::Reset() {

}

// ���[�r�[�g�ړ�
void COP_MOVIE_FRAME::Move() {
		Texture = GetTexture(L"MOVIE_FRAME\\MOVIE_FRAME.png");
		Scale = CVector(1.0f, 0.062f, 0.0f)*1.0f;
		if (all_combat_type == all_combat_on&&icon0_type != icon0_movie_on&&enemy_startup != Enemy_startupmovie_on&&boss_movie_state != boss_movie_on){
			Color = CColor(0, 0, 0, 0.0f);
		}
		if (all_combat_type == all_combat_off || icon0_type == icon0_movie_on || enemy_startup == Enemy_startupmovie_on || boss_movie_state == boss_movie_on){
			Color = CColor(0, 0, 0, 1.0f);
		}

}
//========================================================================================================================
// �K���Q�[�W�g������
void COP_GUN_FRAME::Reset() {
	Texture = GetTexture(L"GUN_GAGE\\GUN_GAGE_FRAME0.png");
	Color = CColor(1.0f, 1.0f, 1.0f, 0.0f);
	Scale = CVector(3.0f, 1.0f, 0.0f)*0.06f;
	Position = CVector(0.81f, -0.65f, 0.0f);
}

// �K���Q�[�W�g�ړ�
void COP_GUN_FRAME::Move() {
	//�Z���^�[�Q�[�g���[�r�[���͐F����
	if (icon0_type == icon0_movie_on || enemy_startup == Enemy_startupmovie_on || boss_movie_state == boss_movie_on){
		Color = CColor(0, 0, 0, 0.0f);
	}
	if (all_combat_type == all_combat_on&&icon0_type != icon0_movie_on&&enemy_startup != Enemy_startupmovie_on&&boss_movie_state != boss_movie_on){
		if (gun_gage_life >= 100)Color = CColor(1.0f, 1.0f, 1.0f, 1.0f);
		else if (gun_gage_life < 100)Color = CColor(1.0f, 0.0f, 0.0f, 1.0f);
	}
}
//========================================================================================================================
// �K���Q�[�W�g2������
void COP_GUN_FRAME2::Reset() {
	Texture = GetTexture(L"GUN_GAGE\\GUN_GAGE.png");
	Color = CColor(0.0f, 0.0f, 0.0f, 0.0f);
	Scale = CVector(1.8f, 0.1f, 0.0f)*0.06f;
	Position = CVector(0.831f, -0.65f, 0.0f);
}

// �K���Q�[�W�g2�ړ�
void COP_GUN_FRAME2::Move() {
	//�Z���^�[�Q�[�g���[�r�[���͐F����
	if (icon0_type == icon0_movie_on || enemy_startup == Enemy_startupmovie_on || boss_movie_state == boss_movie_on){
		Color = CColor(0, 0, 0, 0.0f);
	}
	if (all_combat_type == all_combat_on&&icon0_type != icon0_movie_on&&enemy_startup != Enemy_startupmovie_on&&boss_movie_state != boss_movie_on){
		Color = CColor(0.0f, 0.0f, 0.0f, 1.0f);
	}

}
//========================================================================================================================
// �K���Q�[�W������
void COP_GUN_GAGE::Reset() {
	Texture = GetTexture(L"GUN_GAGE\\GUN_GAGE.png");
	Color = CColor(0.2f, 0.4f, 1.0f, 0.0f);
	//Scale = CVector(1.742f, 0.1f, 0.0f)*0.06f;
	//Position = CVector(0.832f, -0.65f, 0.0f);
	gun_gage_life = 500;
	DAMAGE = 100;//50
	RECOVERY = 1;//5
	X = 0.83f;
}

// �K���Q�[�W�ړ�
void COP_GUN_GAGE::Move() {
	//�Z���^�[�Q�[�g���[�r�[���͐F����
	if (icon0_type == icon0_movie_on || enemy_startup == Enemy_startupmovie_on || boss_movie_state == boss_movie_on){
		Color = CColor(0, 0, 0, 0.0f);
	}
	if (all_combat_type == all_combat_on&&icon0_type != icon0_movie_on&&enemy_startup != Enemy_startupmovie_on&&boss_movie_state != boss_movie_on){
		if (gun_gage_life >= 100)Color = CColor(0.2f, 0.4f, 1.0f, 1.0f);
		else if (gun_gage_life < 100)Color = CColor(1.0f, 0.0f, 0.0f, 1.0f);


		if (gun_gage_consumption == gun_gage_consumption_on){
			Time = 0;
			if (gun_gage_life <= 0){
				MOVE_POSITION = 0;
				gun_gage_life = 0;
			}
			if (gun_gage_life >= 100){
				gun_gage_life -= DAMAGE;
				MOVE_POSITION = DAMAGE*0.000215f;
				X -= MOVE_POSITION;
			}
		}
		if (gun_gage_consumption == gun_gage_consumption_off){
			Time++;
			if (Time % 2 == 0){
				MOVE_POSITION = RECOVERY*0.000215f;
				if (gun_gage_life >= 500){
					MOVE_POSITION = 0;
					gun_gage_life = 500;
				}
				if (gun_gage_life < 500){
					gun_gage_life += RECOVERY;
					X += MOVE_POSITION;
				}
			}
		}
		GAGE_SCALE = gun_gage_life*0.000215f;
		Scale = CVector(GAGE_SCALE, 0.008f, 0);
		Position = CVector(X, -0.65f, 0);
	}
}

//================================�i�t�F�[�h�A�E�g����ʁj========================================================================================
// ����ʏ�����
void Cfade_black::Reset() {
	Texture = GetTexture(L"END\\black.png");
	//Scale = CVector(1.34f, 1, 1)*0.75f;
	Scale = CVector(1.0f, 0.75f, 1.0f)*1.0f;
	Color = CColor(CR, CG, CB, 0);
	CW = 0.0f;
}

// ����ʈړ�
void Cfade_black::Move() {
	if (fade_black_switch == fade_black_on){
		if (CW<0.99f){
			CW += 0.01f;
		}
		if (CW >= 0.99){
			end_screen_switch = end_screen_on;
		}
	}
	Color = CColor(CR, CG, CB, CW);
}
//================================�i�G���h�j========================================================================================
// END��ʏ�����
void CEND::Reset() {
	Texture = GetTexture(L"END\\END.png");
	//Scale = CVector(1.34f, 1, 1)*0.75f;
	Scale = CVector(1.0f, 0.75f, 1.0f)*1.0f;
	Color = CColor(CR, CG, CB, 0);
	CW = 0.0f;
}

// END��ʈړ�
void CEND::Move() {
	if (clear == clear_good_on){
		Texture = GetTexture(L"END\\good_end.png");//�N���A��ʂɍ����ւ�
		Color = CColor(CR, CG, CB, CW);
		if (end_screen_switch == end_screen_on){
			if (CW<0.99f){
				CW += 0.01f;
			}
		}
	}
	if (clear == clear_bad_on){
		Texture = GetTexture(L"END\\badend.png");
		Color = CColor(CR, CG, CB, CW);
		if (end_screen_switch == end_screen_on){
			if (CW<0.99f){
				CW += 0.01f;
			}
		}
	}
}

//================================�iEND_PUSH_C�j========================================================================================
// PUSH_C����������
void CPush_c::Reset() {
	Texture = GetTexture(L"END\\bad_push_c.png");
	//Scale = CVector(1.34f, 1, 1)*0.75f;
	Scale = CVector(1.4f, 0.5f, 1.0f)*0.25f;
	Color = CColor(CR, CG, CB, 0);
	CW = 0.0f;
}

// PUSH_C�����ړ�
void CPush_c::Move() {
	if (clear == clear_bad_on){
		Texture = GetTexture(L"END\\bad_push_c.png");
		Scale = CVector(1.4f, 0.5f, 1.0f)*0.25f;
	}
	if (clear == clear_good_on){
		Texture = GetTexture(L"END\\good_push_c.png");
		Scale = CVector(1.5f, 0.5f, 1.0f)*0.25f;
		Position = CVector(0.05f, -0.32f, 0);
	}
	Color = CColor(Random(1, 0.7f), Random(1, 0.7f), Random(1, 0.7f), CW);
	if (end_screen_switch == end_screen_on){
		if (CW<0.9f){
			CW += 0.01f;
		}
		if (KeyState[0][DIK_C] && !OldKeyState[0][DIK_C]){
			RESET_ON_COUNT = 1;
		}
		if (RESET_ON_COUNT == 1){
			RESET_ON_TIME++;
			if (RESET_ON_TIME==1){
				GetWave(L"system\\op_space.wav")->Play(1);
				GetWave(L"system\\op_space.wav")->SetVolume(0.25f);
			}
			if (RESET_ON_TIME>=40){
				Life = 0;
				reset_switch = reset_on;
			}
		}
	}
	if (end_screen_switch == end_screen_off){
		CW = 0.0f;
	}
}
//========================================================================================================================
// HELP0������
void CHELP0::Reset() {
	Texture = GetTexture(L"help\\HELP1.png");
	Scale = CVector(1.3f, 1.5f, 1.0f)*0.35f;
	Color = CColor(1, 1, 1, 0);
}

// HELP0�ړ�
void CHELP0::Move() {
	if (icon0_type == icon0_movie_on || enemy_startup == Enemy_startupmovie_on || boss_movie_state == boss_movie_on){
		Color = CColor(0, 0, 0, 0.0f);
	}
	if (all_combat_type == all_combat_on&&icon0_type != icon0_movie_on&&enemy_startup != Enemy_startupmovie_on&&boss_movie_state != boss_movie_on){
		if (COLOR_COUNT == 0){
			if (KeyState[0][DIK_Q] && !OldKeyState[0][DIK_Q]){
				Color = CColor(1, 1, 1, 1);
				COLOR_COUNT = 1;
			}
		}
		else if (COLOR_COUNT == 1){
			if (KeyState[0][DIK_Q] && !OldKeyState[0][DIK_Q]){
				Color = CColor(1, 1, 1, 0);
				COLOR_COUNT = 0;
			}
		}
	}
}
//========================================================================================================================
// HELP1������
void CHELP1::Reset() {

}

// HELP0�ړ�
void CHELP1::Move() {

}