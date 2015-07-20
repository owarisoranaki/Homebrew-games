#pragma once
#include "..\..\..\HigPen\HigPen.h"
using namespace higpen;

extern enum Blade_hold{ blade_hold_normal, blade_hold_reverse };//�u���[�h������؂�ւ��萔
extern enum Blade{blade_off,blade_on};//�u���[�h�o��ON,OFF
extern enum Gun{ gun_off, gun_on };//�K���o��ON,OFF
extern enum weapon_chang{ chang_blade, chang_gun };//����`�F���W�萔
extern enum Blade_hand_chang{left_hand,right_hand};//�u���[�h������ύX
extern enum screen_switch{screen_off,screen_on};//�X�N���[��ON_OFF
extern enum Dash_type{ dash_off, dash_w_on, dash_s_on, dash_a_on, dash_d_on, dash_aw_on, dash_dw_on, dash_as_on, dash_ds_on };
extern enum Rota_attack_type{ rota_attack_off, rota_attack_on};
extern enum Beam_launch{beam_off,beam_on};//�r�[�����˒萔
extern enum Gun_hande_angle{normal_on,air_on};//�K���p�x�萔
extern enum Boost_main1_switch{ boost_main1_off, boost_main1_on};//�u�[�X�g��i�K�萔
extern enum Boost_main2_switch{ boost_main2_off, boost_main2_on };//�u�[�X�g��i�K�萔
extern enum Boost_sub_switch{ boost_sub_off, boost_sub_on };
extern enum Boost_subup_switch{ boost_subup_off, boost_subup_on };
extern enum Boost_gage_switch{boost_gage_off,boost_gage_on};
extern enum Boost_recovery_switch{ boost_recovery_off, boost_recovery_on};
extern enum Myship_landing_type{ myship_landing_off, myship_landing_on }; //���n�萔
extern enum Air_gage_switch{air_gage_off,air_gage_on};
extern enum Time_type{time_type_off,time_type_on};
extern enum Enemy_shot_hit_type{ enemy_shot_hit_off, enemy_shot_hit_on };
extern enum Enemy_slash_hit_tyape{ enemy_slash_hit_off, enemy_slash_hit_on };
extern enum Myship_invincible_type{ myship_invincible_off, myship_invincible_on};//���G����ON_OFF
extern enum Message_frame_type{ message_frame_off, message_frame_on};
extern enum Message_frame_switch{ message_frame_switch_off, message_frame_switch_on};
extern enum Camera_combat_state_type{ camera_combat_state_off, camera_combat_state_on };
extern enum Message_switch{ message_off, message_on };
extern enum Moviecamera_rotat_type{ moviecamera_rotat_off, moviecamera_rotat_on};
extern enum All_combat_type{ all_combat_off, all_combat_on};
extern enum Target_frame_type{ target_frame_off, target_frame_on};
extern enum{ Movie_cancel_off, Movie_cancel_on};
extern enum Gunshot_camera_type{ gunshot_camera_off, gunshot_camera_on };
extern enum Gun_gage_consumption{ gun_gage_consumption_off, gun_gage_consumption_on };
extern enum Patikoma_ani_state{ patikoma_ani_walk, patikoma_ani_jump };
extern enum Targetselection{ targetselection_off, targetselection_on };
extern enum Targetenemy_truefalse{ targetenemy_truefalse_off, targetenemy_truefalse_on };
extern enum Selection_camera_reset{ selection_camera_reset_off, selection_camera_reset_on };
extern enum Icon0_type{ icon0_off, icon0_on, icon0_movie_on};
extern enum Centergate_movietype{ centergate_movie_off, centergate_movie_on};
extern enum Enemy_startup{ Enemy_startup_off, Enemy_startup_on, Enemy_startupmovie_on };
extern enum Enemy_start_state{ enemy_start_off, enemy_start_on};
extern enum Enemy_start_attack{ enemy_start_attack_off, enemy_start_attack_on};
extern enum Boss_movie_state{ boss_movie_off, boss_movie_on,  boss_combat_on };
extern enum Boss_startup{ boss_startup_off, boss_startup_on };
extern enum Boss_moveimodel_change{ boss_moveimodel_change_off, boss_moveimodel_change_on };
extern enum Clear{ clear_off, clear_good_on, clear_bad_on };
extern enum Clear_reset{ clear_reset_off, clear_reset_on};
//extern enum Bgm_state{ combat_bgm_off, combat_bgm_on, clear_bgm_on };
extern enum Bgm_state{ op_bgm_on, mission_bgm_on, defence_combat_bgm_on, boss_combat_bgm_on, defence_combatrelease_on, normal_bgm_on, mission_complete_bgm_on, mission_failure_bgm_on, clearend_bgm_on, failureend_bgm_on };
extern enum Stop_count{stop_count_off,stop_count_on};
extern enum Timeleft{ timeleft_yes, timeleft_no };
extern enum Last_one_minutes{ last_one_minutes_off, last_one_minutes_on};
extern enum Fade_black_switch{ fade_black_off, fade_black_on};
extern enum End_screen_switch{ end_screen_off, end_screen_on};
extern enum Reset_switch{ reset_off, reset_on};
extern enum Myship_death{ myship_death_off, myship_death_on };

extern CMoverList 
StageList, Stage_01List, Stage_02List, Stage_gateList, Stage_gate2List, Stage_gate3List, Stage_gate4List, Stage_Centergate_LList, Stage_Centergate_RList, Stage_Centergate_LRList, MonitorList, MyShipList, MyShip_Move_ModelList, MyShip_Move_Model2List, MyShip_Move_Model3List, MyShip_Move_Model4List, MyShip_Move_Model5List,
EnemyList, Enemy_BossList, Enemy_Boss_modelList, Enemy_objList, Enemy_takyakuList, Enemy_takyaku_objList, WeaponList, Weapon_GunList, BulletList, Bullet2List, Bullet3List, Bullet4List, Bullet5List, Bullet6List, Bullet7List, Bullet8List, Bullet9List, EffectList, Effect2List, Effect3List, Effect4List, Effect5List,
Effect6List, Effect7List, Effect8List, Effect9List, Effect10List, Effect11List, Effect12List, Effect13List, Effect14List, Effect15List, Effect16List, Effect17List, 
Effect18List, Effect19List, Effect20List, Effect21List, Effect22List, Icon0List, Effect_positionList, Effect_position2List, Effect_sub_positionList, Effect_sub_position2List, Effect_zan_positionList, Effect_shothit_positionList,
Effect_volt_positionList, Effect_thunder_machineryList, Effect_damage_positionList, BlockList, LampList, ItemList, Item2List, Item3List, Item4List, CameraList, LightList, OP_ScreenList, OP_Screen_WriteList,
OP_RHINE0List, OP_RHINE1List, OP_LIFEGAGEList, OP_BOOSTGAGEList, OP_BOOSTGAGE2List, OP_LIFEGAGE2List, OP_LIFEGAGE_FRAMEList, OP_GUN_FRAMEList, OP_GUN_FRAME2List, OP_GUN_GAGEList, OP_TIMEList, OP_MESSAGE_FRAMEList, OP_TARGET_FRAMEList, OP_MOVIE_FRAMEList, ENDList, fade_blackList, Push_cList, HELP0List, HELP1List;

extern int myship_death;//���@���Ŕ���
extern int clear_bgm_change_time;//�N���A�[��ʎ���BGM�ɕω������鏈���p
extern int good_end_bgm_time;//�O�b�h�G���hBGM�_�u��h�~����
extern int reset_switch;//C�L�[�ɂ��resetON,OFF
extern int end_screen_switch;//�ŏI�G���h��ʕ\��ON,OFF
extern int fade_black_switch;//�t�F�[�h�A�E�g���C��black���ON,OFF
extern int bad_end_bgm_time;//�Q�[���I�[�o�[BGM�^�C��
extern int bad_end_message_time;//�Q�[���I�[�o�[message�^�C��
extern int last_one_minutessound_time;//�_�u�萶������
extern int last_one_minutes;//�c��ꕪ�؂�������
extern int timeleft;//�c�莞�Ԕ���
extern int movie_cancel_type;//���[�r�[cancel���s���������_�u�萧��
extern int movie_stop_count;//���[�r�[�r��stop
extern int bgm_state;//�퓬���yON_OFF
extern int clear_reset;//clear��ʂ���ăQ�[��
extern int clear;//�Q�[���N���A
extern int boss_moveimodel_change;//�{�X���[�r�[���ό`�A�N�V����ON
extern int boss_startup;//�{�X�N��
extern int boss_movie_state;//�{�X�타�[�r�[�J�n
extern int enemy_start_attack ;
extern int enemy_start_state;//�G�l�~�[�N��
extern int enemy_startup;//�G�l�~�[�N�����[�r�[ON

extern float my_damage;
extern int centergate_movietype;
extern int icon0_type;
extern float ftest;
extern int mekapen_number;
extern int patikoma_number;

extern float test_floatx;
extern float test_floaty;
extern float test_floatz;
extern float test_float2x;
extern float test_float2y;
extern float test_float2z;

extern int selection_camera_reset;//�I��G���Ȃ���΃J�������Z�b�g
extern int targetmarker_red;
extern int targetenemy_truefalse;//�͈͓��̓G�����邢�Ȃ�
extern int targetselection;//�^�[�Q�b�g�I��ON_OFF
extern int enemy_count;//�G����
extern int test_no;//�e�X�g
extern int Score;
extern int blade_hold;//�u���[�h������؂�ւ��ϐ�
extern int blade;//�u���[�h�o���؂�ւ��ϐ�
extern int gun;//�K���o���؂�ւ��ϐ�
extern int weapon_chang;//����`�F���W�؂�ւ��ϐ��i�����j
extern int weapon_chang_name;//����`�F���W�؂�ւ��ϐ��i���O�j
extern int blade_hand_chang;//�u���[�h������ύX
extern int screen_switch;//�X�N���[���؂�ւ�
extern int dash_type;//�_�b�V��ON_OFF
extern int rota_attack_type;//��]�U��ON_OFF
extern int beam_launch;//�r�[������ON_OFF
extern int gun_hande_Angle;//�K���p�x�ύX
extern int myship_landing_type;//���n�ϐ�
extern int enemy_shot_hit_type;//�r�[�������蔻��
extern int enemy_slash_hit_tyape;//�u���[�h�����蔻��
extern int myship_invincible_type;//���@�F�����G����
extern float myship_damage;//���@�_���[�W
extern int message_frame_type;//message�g�\��
extern int message_frame_switch;//message�g��ON_OFF
extern int camera_combat_state_type;//�J�����퓬�J�nON_OFF
extern int all_combat_type;//�S�ẴI�u�W�F�N�g�퓬���
extern int message_switch;//���b�Z�[�WON_OFF
extern int moviecamera_rotat_type;//���[�r�[�J�������[�e�[�V����ON_OFF
extern int target_frame_type;//�^�[�Q�b�g�t���[��OFF
extern int movie_cancel;//���[�r�[�L�����Z��
extern int gunshot_camera_type;//�K���V���b�gON���̃J�������[�e�[�V����
extern int gun_gage_life;
extern int gun_gage_consumption;
extern int patikoma_ani_state;//�p�`�R�}���f���A�j���[�V�����ω�

//�u�[�X�gON_OFF�X�C�b�`(�u�[�X�g��i�K,�u�[�X�g��i�K,�_�b�V�����T�u�u�[�X�g,UP���T�u�u�[�X�g)
extern int boost_main1_switch;
extern int boost_main2_switch;
extern int boost_sub_switch;
extern int boost_subup_switch;

//�u�[�X�g���C�t
extern float boost_life;
extern int boost_gage_switch;
extern int boost_recovery_switch;
extern int air_gage_switch;

//�^�C��
extern int time_type;
extern int time_micro;//�}�C�N���b�i��̈ʁj
extern int time_micro2;//�}�C�N���b�i�\�̈ʁj
extern int time_second;//�b�i��̈ʁj
extern int time_second2;//�b�i�\�̈ʁj
extern int time_minute;//���i��̈ʁj
extern int time_minute2;//���i�\�̈ʁj
extern int time_when;//���i��̈ʁj
extern int time_when2;//���i�\�̈ʁj

//���b�Z�[�W�ϐ�(���[�J��)
extern int MESSAGE_TIME;
extern int MESSAGE_COUNT;
extern float MESSAGE_VOL;
extern float MESSAGE_BGM_VOL;

//BGM
extern int op_bgm_time;
extern int mission_bgm_time;
extern int defence_combat_bgm_time;
extern int normal_bgm_time;
extern int mission_complete_bgm_time;
extern int mission_failure_bgm_time;
extern int clearend_bgm_time;
extern int failureend_bgm_time;
extern int defence_combatrelease_time;
extern int boss_combat_bgm_time;

#include "MyMover.h"
#include "..\Effect\Block.h"
#include "..\Bullet\Bullet.h"
#include "..\Camera\Camera.h"
#include "..\Effect\Effect.h"
#include "..\Effect\Effect_position.h"
#include "..\Character\Enemy.h"
#include "..\Weapon\Item.h"
#include "..\Stage\Light.h"
#include "..\Character\MyShip.h"
#include "..\Stage\Stage.h"
#include "..\Weapon\Weapon.h"
#include "..\Screen_2D\OP_Screen.h"

extern CCamera* Camera;

