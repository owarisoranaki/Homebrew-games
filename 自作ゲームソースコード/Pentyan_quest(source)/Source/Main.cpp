#include "Main.h"

// �ϐ�
CMoverList MyShipList(sizeof(CMyShip), 100);
CMoverList StageList(sizeof(CStage), 1000);
CMoverList Stage2List(sizeof(CStage2), 1000);
CMoverList EnemyList(sizeof(CEnemy), 1000);
CMoverList Enemy2List(sizeof(CEnemy2), 1000);
CMoverList Enemy3List(sizeof(CEnemy3), 1000);
CMoverList Enemy5List(sizeof(CEnemy5), 1000);
CMoverList Enemy6List(sizeof(CEnemy6), 1000);
CMoverList Enemy7List(sizeof(CEnemy7), 1000);
CMoverList Enemy8List(sizeof(CEnemy8), 1000);
CMoverList Enemy9List(sizeof(CEnemy9), 1000);
CMoverList Enemy10List(sizeof(CEnemy10), 1000);
CMoverList WeaponList(sizeof(CWeapon), 10000);
CMoverList Weapon2List(sizeof(CWeapon2), 10000);
CMoverList Weapon3List(sizeof(CWeapon3), 10000);
CMoverList Weapon4List(sizeof(CWeapon4), 10000);
CMoverList Weapon5List(sizeof(CWeapon5), 10000);
CMoverList Weapon6List(sizeof(CWeapon6), 10000);
CMoverList Weapon7List(sizeof(CWeapon7), 10000);
CMoverList Weapon8List(sizeof(CWeapon8), 10000);
CMoverList Weapon9List(sizeof(CWeapon9), 10000);
CMoverList Weapon10List(sizeof(CWeapon10), 10000);
CMoverList Weapon11List(sizeof(CWeapon11), 10000);
CMoverList Weapon12List(sizeof(CWeapon12), 10000);
CMoverList BulletList(sizeof(CBullet), 10000);
CMoverList Bullet1List(sizeof(CBullet1), 10000);
CMoverList Bullet2List(sizeof(CBullet2), 10000);
CMoverList EffectList(sizeof(CEffect), 10000);
CMoverList Effect1List(sizeof(CEffect1), 10000);
CMoverList Effect2List(sizeof(CEffect2), 10000);
CMoverList Effect3List(sizeof(CEffect3), 10000);
CMoverList Effect4List(sizeof(CEffect4), 10000);
CMoverList Effect5List(sizeof(CEffect5), 10000);
CMoverList Effect6List(sizeof(CEffect6), 10000);
CMoverList Effect7List(sizeof(CEffect7), 10000);
CMoverList Effect8List(sizeof(CEffect8), 100000);
CMoverList Effect9List(sizeof(CEffect9), 100000);
CMoverList Effect10List(sizeof(CEffect10), 100000);
CMoverList Effect11List(sizeof(CEffect11), 100000);
CMoverList Effect12List(sizeof(CEffect12), 100000);
CMoverList Effect13List(sizeof(CEffect13), 100000);
CMoverList Effect14List(sizeof(CEffect14), 100000);
CMoverList Effect15List(sizeof(CEffect15), 100000);
CMoverList Effect16List(sizeof(CEffect16), 100000);
CMoverList Effect17List(sizeof(CEffect17), 100000);
CMoverList Effect18List(sizeof(CEffect18), 100000);
CMoverList Effect19List(sizeof(CEffect19), 100000);
CMoverList Effect20List(sizeof(CEffect20), 100000);
CMoverList Effect21List(sizeof(CEffect21), 100000);
CMoverList Effect22List(sizeof(CEffect22), 100000);
CMoverList Effect23List(sizeof(CEffect23), 100000);
CMoverList BlockList(sizeof(CBlock), 10000);
CMoverList Block1List(sizeof(CBlock1), 10000);//�ǉ�
CMoverList Block2List(sizeof(CBlock2), 10000);//�ǉ�
CMoverList Block3List(sizeof(CBlock3), 10000);//�ǉ�
CMoverList Block4List(sizeof(CBlock4), 10000);//�ǉ�
CMoverList Block5List(sizeof(CBlock5), 10000);//�ǉ�
CMoverList Block6List(sizeof(CBlock6), 10000);//�ǉ�
CMoverList Block7List(sizeof(CBlock7), 10000);//�ǉ�
CMoverList Block8List(sizeof(CBlock8), 10000);//�ǉ�
CMoverList Block9List(sizeof(CBlock9), 10000);//�ǉ�
CMoverList Block10List(sizeof(CBlock10), 10000);//�ǉ�
CMoverList Block11List(sizeof(CBlock11), 10000);//�ǉ�
CMoverList Block12List(sizeof(CBlock12), 10000);//�ǉ�
CMoverList Block13List(sizeof(CBlock13), 10000);//�ǉ�
CMoverList Block14List(sizeof(CBlock14), 10000);//�ǉ�
CMoverList Block15List(sizeof(CBlock15), 10000);//�ǉ�
CMoverList Block16List(sizeof(CBlock16), 10000);//�ǉ�
CMoverList Block17List(sizeof(CBlock17), 10000);//�ǉ�
CMoverList Block18List(sizeof(CBlock18), 10000);//�ǉ�
CMoverList Block19List(sizeof(CBlock19), 10000);//�ǉ�
CMoverList Block20List(sizeof(CBlock20), 10000);//�ǉ�
CMoverList Block21List(sizeof(CBlock21), 10000);//�ǉ�
CMoverList Block22List(sizeof(CBlock22), 10000);//�ǉ�
CMoverList Block23List(sizeof(CBlock23), 10000);//�ǉ�
CMoverList Block24List(sizeof(CBlock24), 10000);//�ǉ�
CMoverList Block25List(sizeof(CBlock25), 10000);//�ǉ�
CMoverList Block26List(sizeof(CBlock26), 10000);//�ǉ�
CMoverList Block27List(sizeof(CBlock27), 10000);//�ǉ�
CMoverList Block28List(sizeof(CBlock28), 10000);//�ǉ�
CMoverList Block29List(sizeof(CBlock29), 10000);//�ǉ�
CMoverList Block30List(sizeof(CBlock30), 10000);//�ǉ�
CMoverList Block31List(sizeof(CBlock31), 10000);//�ǉ�
CMoverList ItemList(sizeof(CItem), 1000);
CMoverList Item1List(sizeof(CItem1), 1000);//�ǉ�
CMoverList Item2List(sizeof(CItem2), 1000);//�ǉ�
CMoverList Item3List(sizeof(CItem3), 1000);//�ǉ�
CMoverList Item4List(sizeof(CItem4), 1000);//�ǉ�
CMoverList Item5List(sizeof(CItem5), 1000);//�ǉ�
CMoverList Item6List(sizeof(CItem6), 1000);//�ǉ�
CMoverList Item7List(sizeof(CItem7), 1000);//�ǉ�
CMoverList Item8List(sizeof(CItem8), 1000);//�ǉ�
CMoverList Item9List(sizeof(CItem9), 1000);//�ǉ�
CMoverList Item10List(sizeof(CItem10), 1000);//�ǉ�
CMoverList Item11List(sizeof(CItem11), 1000);//�ǉ�
CMoverList Item12List(sizeof(CItem12), 1000);//�ǉ�
CMoverList Item13List(sizeof(CItem13), 1000);//�ǉ�
CMoverList CameraList(sizeof(CCamera), 100);
CMoverList LightList(sizeof(CLight), 100);
CMoverList OPList(sizeof(COP), 100);
CMoverList OP1List(sizeof(COP1), 100);
CMoverList OP2List(sizeof(COP2), 100);
CCamera* Camera;
int game_over_count = 0;
float test_X, test_Y;
int Score,STP=0,GOV=0,GOV1=0,CLR=0,CLR1=0;
int BP, WP = 0, BSST = 0,OP2=0;
int BT,RW=0,TIME=0,BOSSC=0;
int SI=0,CS,CP=0,BRR=0,BOSSHP=0;

// �Q�[���{��
class CMyGame : public CGame {
public:
	int Time;
	bool Pause, PrevPause;
	CFont* Font;

	// ������
	CMyGame::CMyGame() : CGame(L"My Game") {
		const wchar_t fontchar[]=
			L"~|0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ,.(){}<>!?+-x*/='\\\"#$%&@[]";
		Font=new CFont(Graphics->GetDevice(), 
			ExePath+L"..\\Font\\Font.png", 0, fontchar, 
			16.0f/256, 32.0f/256, 16, 32, 2, 2);
		//NetworkInput.Open(Config.GetValue(L"Server"), Config.GetIntValue(L"Port"));
		Reset();
	}

	// ���Z�b�g
	void Reset() {
		Sound->Stop();

		StageList.Clear();
		Stage2List.Clear();
		MyShipList.Clear();
		EnemyList.Clear();
		Enemy2List.Clear();
		Enemy3List.Clear();
		Enemy5List.Clear();
		Enemy6List.Clear();
		Enemy7List.Clear();
		Enemy8List.Clear();
		Enemy9List.Clear();
		Enemy10List.Clear();
		WeaponList.Clear();
		Weapon2List.Clear();//�ǉ�
		Weapon3List.Clear();//�ǉ�
		Weapon4List.Clear();//�ǉ�
		Weapon5List.Clear();//�ǉ�
		Weapon6List.Clear();//�ǉ�
		Weapon7List.Clear();//�ǉ�
		Weapon8List.Clear();//�ǉ�
		Weapon9List.Clear();//�ǉ�
		Weapon10List.Clear();//�ǉ�
		Weapon11List.Clear();//�ǉ�
		Weapon12List.Clear();//�ǉ�
		BulletList.Clear();
		Bullet1List.Clear();
		Bullet2List.Clear();
		EffectList.Clear();
		Effect1List.Clear();//�ǉ�
		Effect2List.Clear();//�ǉ�
		Effect3List.Clear();//�ǉ�
		Effect4List.Clear();//�ǉ�
		Effect5List.Clear();//�ǉ�
		Effect6List.Clear();//�ǉ�
		Effect7List.Clear();//�ǉ�
		Effect8List.Clear();//�ǉ�
		Effect9List.Clear();//�ǉ�
		Effect10List.Clear();//�ǉ�
		Effect11List.Clear();//�ǉ�
		Effect12List.Clear();//�ǉ�
		Effect13List.Clear();//�ǉ�
		Effect14List.Clear();//�ǉ�
		Effect15List.Clear();//�ǉ�
		Effect16List.Clear();//�ǉ�
		Effect17List.Clear();//�ǉ�
		Effect18List.Clear();//�ǉ�
		Effect19List.Clear();//�ǉ�
		Effect20List.Clear();//�ǉ�
		Effect21List.Clear();//�ǉ�
		Effect22List.Clear();//�ǉ�
		Effect23List.Clear();//�ǉ�
		BlockList.Clear();
		Block1List.Clear();//�ǉ�
		Block2List.Clear();//�ǉ�
		Block3List.Clear();//�ǉ�
		Block4List.Clear();//�ǉ�
		Block5List.Clear();//�ǉ�
		Block6List.Clear();//�ǉ�
		Block7List.Clear();//�ǉ�
		Block8List.Clear();//�ǉ�
		Block9List.Clear();//�ǉ�
		Block10List.Clear();//�ǉ�
		Block11List.Clear();//�ǉ�
		Block12List.Clear();//�ǉ�
		Block13List.Clear();//�ǉ�
		Block14List.Clear();//�ǉ�
		Block15List.Clear();//�ǉ�
		Block16List.Clear();//�ǉ�
		Block17List.Clear();//�ǉ�
		Block18List.Clear();//�ǉ�
		Block19List.Clear();//�ǉ�
		Block20List.Clear();//�ǉ�
		Block21List.Clear();//�ǉ�
		Block22List.Clear();//�ǉ�
		Block23List.Clear();//�ǉ�
		Block24List.Clear();//�ǉ�
		Block25List.Clear();//�ǉ�
		Block26List.Clear();//�ǉ�
		Block27List.Clear();//�ǉ�
		Block28List.Clear();//�ǉ�
		Block29List.Clear();//�ǉ�
		Block30List.Clear();//�ǉ�
		Block31List.Clear();//�ǉ�
		ItemList.Clear();
		Item1List.Clear();//�ǉ�
		Item2List.Clear();//�ǉ�
		Item3List.Clear();//�ǉ�
		Item4List.Clear();//�ǉ�
		Item5List.Clear();//�ǉ�
		Item6List.Clear();//�ǉ�
		Item7List.Clear();//�ǉ�
		Item8List.Clear();//�ǉ�
		Item9List.Clear();//�ǉ�
		Item10List.Clear();//�ǉ�
		Item11List.Clear();//�ǉ�
		Item12List.Clear();//�ǉ�
		Item13List.Clear();//�ǉ�
		CameraList.Clear();
		LightList.Clear();
		OPList.Clear();//�ǉ�
		OP1List.Clear();//�ǉ�
		OP2List.Clear();//�ǉ�

		Score=Time=0;
		//�ǉ��ϐ����Z�b�g
		game_over_count = 0;
		test_X = test_Y = 0;
		 Score= STP =GOV = GOV1 = CLR = CLR1 = 0;
		 BP= WP = BSST =  OP2 = 0;
		 BT= RW = TIME = BOSSC = 0;
		 SI = CS=CP = BRR =  BOSSHP = 0;
		Pause=PrevPause=false;

		Camera=New<CCamera>();
		New<CStage>();
	}

	// �ړ�
	void Move() {
		if (KeyState[0][DIK_C]) {
			Reset();
		}
		if (!PrevPause && KeyState[0][DIK_V]) Pause=!Pause;
		PrevPause=KeyState[0][DIK_V];
		if (!Pause) {
			StageList.Move();
			Stage2List.Move();
			MyShipList.Move();
			EnemyList.Move();
			Enemy2List.Move();
			Enemy3List.Move();
			Enemy5List.Move();
			Enemy6List.Move();
			Enemy7List.Move();
			Enemy8List.Move();
			Enemy9List.Move();
			Enemy10List.Move();
			WeaponList.Move();
			Weapon2List.Move();//�ǉ�
			Weapon3List.Move();//�ǉ�
			Weapon4List.Move();//�ǉ�
			Weapon5List.Move();//�ǉ�
			Weapon6List.Move();//�ǉ�
			Weapon7List.Move();//�ǉ�
			Weapon8List.Move();//�ǉ�
			Weapon9List.Move();//�ǉ�
			Weapon10List.Move();//�ǉ�
			Weapon11List.Move();//�ǉ�
			Weapon12List.Move();//�ǉ�
			BulletList.Move();
			Bullet1List.Move();
			Bullet2List.Move();
			EffectList.Move();
			Effect1List.Move();//�ǉ�
			Effect2List.Move();//�ǉ�
			Effect3List.Move();//�ǉ�
			Effect4List.Move();//�ǉ�
			Effect5List.Move();//�ǉ�
			Effect6List.Move();//�ǉ�
			Effect7List.Move();//�ǉ�
			Effect8List.Move();//�ǉ�
			Effect9List.Move();//�ǉ�
			Effect10List.Move();//�ǉ�
			Effect11List.Move();//�ǉ�
			BlockList.Move();
			Block1List.Move();//�ǉ�
			Block2List.Move();//�ǉ�
			Block3List.Move();//�ǉ�
			Block4List.Move();//�ǉ�
			Block5List.Move();//�ǉ�
			Block6List.Move();//�ǉ�
			Block7List.Move();//�ǉ�
			Block8List.Move();//�ǉ�
			Block9List.Move();//�ǉ�
			Block10List.Move();//�ǉ�
			Block11List.Move();//�ǉ�
			Block12List.Move();//�ǉ�
			Block13List.Move();//�ǉ�
			Block14List.Move();//�ǉ�
			Block15List.Move();//�ǉ�
			Block16List.Move();//�ǉ�
			Block17List.Move();//�ǉ�
			Block18List.Move();//�ǉ�
			Block19List.Move();//�ǉ�
			Block20List.Move();//�ǉ�
			Block21List.Move();//�ǉ�
			Block22List.Move();//�ǉ�
			Block23List.Move();//�ǉ�
			Block24List.Move();//�ǉ�
			Block25List.Move();//�ǉ�
			Block26List.Move();//�ǉ�
			Block27List.Move();//�ǉ�
			Block28List.Move();//�ǉ�
			Block29List.Move();//�ǉ�
			Block30List.Move();//�ǉ�
			Block31List.Move();//�ǉ�
			LightList.Move();
			ItemList.Move();
			Item1List.Move();//�ǉ�
			Item2List.Move();//�ǉ�
			Item3List.Move();//�ǉ�
			Item4List.Move();//�ǉ�
			Item5List.Move();//�ǉ�
			Item6List.Move();//�ǉ�
			Item7List.Move();//�ǉ�
			Item8List.Move();//�ǉ�
			Item9List.Move();//�ǉ�
			Item10List.Move();//�ǉ�
			Item11List.Move();//�ǉ�
			Item12List.Move();//�ǉ�
			Item13List.Move();//�ǉ�
			CameraList.Move();
			Effect13List.Move();//�ǉ�
			Effect14List.Move();//�ǉ�
			Effect15List.Move();//�ǉ�
			Effect12List.Move();//�ǉ�
			Effect16List.Move();//�ǉ�
			Effect17List.Move();//�ǉ�
			Effect18List.Move();//�ǉ�
			Effect19List.Move();//�ǉ�
			Effect20List.Move();//�ǉ�
			Effect21List.Move();//�ǉ�
			Effect22List.Move();//�ǉ�
			Effect23List.Move();//�ǉ�
			OPList.Move();//�ǉ�
			OP1List.Move();//�ǉ�
			OP2List.Move();//�ǉ�
			Time++;
			if (Time % 60 == 0){		//1�b�̊��Z���@
				Count--;
			}
		}
	}

	// �`��
	void Draw() {
		
		CBasicRenderer& r=*Renderer;
		r.ClearRenderTarget=true;
		r.Color=CColor(1, 1, 1, 1);
		r.Camera=Camera;
		r.LightList=&LightList;
		r.Perspective=r.ZBuffer=r.Sort=r.Billboard=false;
		//r.Perspective = r.ZBuffer = r.Sort = r.Billboard = true;
		r.ClearRenderTarget = r.ClearDepthStencil = r.ZBuffer = true;// �X�e�[�W�S�ʂ�`�悷��
		r.Remove();
		r.Add(Effect2List);//�w�i
		r.Add(Effect8List);//�w�i2
		r.Add(Effect9List);//�w�i3
		r.Add(Effect10List);//�w�i4
		r.Add(Effect11List);//�w�i5
		r.Add(EffectList);//�X�|�b�g���C�g
		r.Add(StageList);//�X�e�[�W1
		r.Add(Stage2List);//�X�e�[�W2
		r.Add(Block20List);//���َq�u���b�N9(�P�[�L)
		r.Add(Item5List);//���[�v�Q�[�g�i1�ʂ�2�ʁj
		r.Add(Item8List);//���[�v�Q�[�g�i2�ʂ���3�ʁj
		r.Add(Item9List);//���[�v�Q�[�g�i3�ʂ���4�ʁj
		r.Add(Item12List);//�X�e�[�W�J�����ړ�
		r.Add(Item13List);//�X�e�[�W�J�����ړ�
		r.Add(Block22List);//���َq�L�����f�B�[�P�[���i�c�j
		r.Add(Block23List);//���َq�L�����f�B�[�P�[���i��)
		r.Add(BulletList);//�G�L�����Q�[�g
		r.Add(EnemyList);//�F
		r.Add(Enemy3List);//�^�C�Ă�
		r.Add(Enemy2List);//BOSS
		r.Add(WeaponList);//�X�藠��
		r.Add(Effect18List);//�c��
		r.Add(Effect19List);//�c��
		r.Add(Effect20List);//BOSS�c��
		r.Add(MyShipList);//���L����
		r.Add(Effect22List);//�u���b�N�\��
		r.Add(Effect21List);//�aୃN���}�^�N�g
		r.Add(Bullet1List);//�����U��
		r.Add(Bullet2List);//�⏢���U��
		r.Add(Weapon11List);//�N���}�^�N�g
		r.Add(Effect23List);//�N���}�^�N�g����
		r.Add(Weapon2List);//���e
		r.Add(Weapon3List);//�t�H�[�N��[
		r.Add(Weapon8List);//�S�g�Q
		r.Add(Weapon9List);//�S�g�Q1
		r.Add(Weapon4List);//��]���N�b�L�[
		r.Add(Weapon5List);//������
		r.Add(Weapon6List);//�C�e
		r.Add(Weapon7List);//�C�e
		r.Add(Block5List);//���u���b�N
		r.Add(Block8List);//���َq�u���b�N1
		r.Add(Block9List);//���َq�u���b�N2
		r.Add(Block10List);//���َq�u���b�N3
		r.Add(Block11List);//���َq�u���b�N4
		r.Add(Block12List);//�����u���b�N1
		r.Add(Block13List);//�����u���b�N2
		r.Add(Block14List);//�����u���b�N3
		r.Add(Block15List);//�����u���b�N4
		r.Add(Block16List);//���َq�u���b�N5
		r.Add(Block17List);//���َq�u���b�N6
		r.Add(Block18List);//���َq�u���b�N7
		r.Add(Block19List);//���َq�u���b�N8
		r.Add(Block21List);//�t�H�[�N��
		r.Add(Block24List);//��C
		r.Add(Item6List);//�{��
		r.Add(Item7List);//�X�藠��
		r.Add(Item10List);//���u�[������
		r.Add(Block25List);//�ԕX�u���b�N�i�E�j
		r.Add(Block26List);//�ԕX�u���b�N�i���j
		r.Add(Block27List);//�ԕX�u���b�N�i���j
		r.Add(Block28List);//�S�u���b�N
		r.Add(Block29List);//�S�u���b�N1
		r.Add(Block30List);//BOSS�����]��
		r.Add(Block31List);//BOSS�����]��1
		r.Add(BlockList);//�u���b�N
		r.Add(Block3List);//�ԃu���b�N
		r.Add(Block4List);//�j�u���b�N
		r.Add(Block1List);//�t�B�[���h�X�u���b�N��
		r.Add(ItemList);//�n�[�g
		r.Add(Item1List);//�È�
		r.Add(Item2List);//���邳����
		r.Add(Item3List);//�ŃL�m�R
		r.Add(Item4List);//�G�o���Q�[�g
		r.Add(Item11List);//�X�e�[�W�J�����ړ�
		r.Add(Effect1List);//���@���G���Ŕ��j
		r.Add(Effect4List);//�X�u���b�N�劄��
		r.Add(Enemy8List);//BOSS��
		r.Add(Enemy10List);//BOSS�炠���蔻��
		r.Add(Weapon10List);//BOSS��(�U���j
		r.Add(Enemy6List);//BOSS������
		r.Add(Enemy7List);//BOSS�画��
		r.Add(Enemy9List);//BOSS�画��2
		r.Add(Effect5List);//���픚�e���j
		r.Add(Block2List);//�����XDOWN
		r.Add(Block6List);//�����u���b�NRIGHT
		r.Add(Block7List);//�����u���b�NLEFT
		r.Add(Effect3List);//�����X����
		r.Add(Effect6List);//�����X����
		r.Add(Effect15List);//�����X����i�ԁj
		r.Add(Effect7List);//BOSS���Ŕ��j
		r.Add(Effect13List);//�A�C�e���\���i�X�藠���j
		r.Add(Effect14List);//�A�C�e���\��2�i���e�j
		r.Add(Effect16List);//�A�C�e���\��3�i���u�[�������j
		r.Add(Effect12List);//�A�C�e���\���g
		r.Add(Effect17List);//�u���b�N�\��
		r.Add(Enemy5List);//���e��Y
		r.Add(Weapon12List);//�⏢���w
		r.Add(OPList);//OP���
		r.Add(OP1List);//GAMEOVER���
		r.Add(OP2List);//CLEAR���
		r.Render();
		
		// �X�|�b�g���C�g��`�悷��
		r.ClearRenderTarget = false;
		r.Remove();
		r.Add(EffectList);
		r.Render();

		// �Èł�`�悷��
		r.ClearDepthStencil = false;
		r.Remove();
		r.Add(BulletList);
		r.Render();

//---------------------------------------------------------------------------------------------------------------------------------------------------------

		StageList.Apply([&](CMover* s) {
			if (s->Type != 0){


				//Time(�o�ߎ���)
				if (GOV == 0 && CLR == 0){
					if (Time % 60 == 0){		//1�b�̊��Z���@
						TIME++;
					}
				}
				//�e�X�g
			
				if (game_over_count==0){
					Font->DrawText(wstring(L"TIME:") + ToStr(TIME), 600, 0, CColor(1, 1, 1, 1), CColor(2, 0, 0, 1));
					//�X�R�A�\��
					Font->DrawText(wstring(L"SCORE:") + ToStr(Score), 600, 32, CColor(1, 1, 1, 1), CColor(1, 2, 0, 1));
				}
				if (GOV == 0 && CLR==0){//
					//�X�R�A�\��
					//Font->DrawText(wstring(L"SCORE:") + ToStr(Score), 600, 32, CColor(1, 1, 1, 1), CColor(1, 2, 0, 1));
					//�X�R�A�\��
					//Font->DrawText(wstring(L"GOV:") + ToStr(GOV), 600, 64, CColor(1, 1, 1, 1), CColor(1, 2, 0, 1));
					//���C�t�\���ǉ�
					MyShipList.Apply([&](CMover* a) {
						Font->DrawText(wstring(L"LIFE:") + ToStr(a->Life), 0, 0, CColor(1, 1, 1, 1), CColor(1, 0, 1, 1));
					});
					//�X�c��\���ǉ�
					Font->DrawText(wstring(L"BP:") + ToStr(BP), 0, 32, CColor(1, 1, 1, 1), CColor(0, 0, 1, 1));
					if (BP == 5){
						Font->DrawText(wstring(L"MAX"), 64, 32, CColor(1, 1, 1, 1), CColor(2, 0, 0, 1));
					}

					//�u���b�N�^�C�v�\��
					if (RW == 0 && BT == 0){
						Font->DrawText(wstring(L"DOWN"), 0, 64, CColor(1, 1, 1, 2), CColor(0, 0, 1, 1));
					}
					if (RW == 0 && BT == 1){
						Font->DrawText(wstring(L"RIGHT"), 0, 64, CColor(1, 1, 1, 2), CColor(0, 0, 1, 1));
					}
					if (RW == 0 && BT == 2){
						Font->DrawText(wstring(L"LEFT"), 0, 64, CColor(1, 1, 1, 2), CColor(0, 0, 1, 1));
					}
					//----------------------------------------------------------------------------------------------------------------------
					if (RW == 1 && BT == 0){
						Font->DrawText(wstring(L"DOWN"), 0, 64, CColor(1, 1, 1, 2), CColor(0, 0, 1, 1));
					}
					if (RW == 1 && BT == 2){
						Font->DrawText(wstring(L"RIGHT"), 0, 64, CColor(1, 1, 1, 2), CColor(0, 0, 1, 1));
					}
					if (RW == 1 && BT == 1){
						Font->DrawText(wstring(L"LEFT"), 0, 64, CColor(1, 1, 1, 2), CColor(0, 0, 1, 1));
					}
				}
			}//
		});
	}
};

// �A�v���P�[�V�����̋N��
CMyGame* Game;
INT WINAPI WinMain(HINSTANCE hinst, HINSTANCE, LPSTR, INT) {
	Game=new CMyGame();
	Game->Run();
	delete Game;
	return 0;
}

