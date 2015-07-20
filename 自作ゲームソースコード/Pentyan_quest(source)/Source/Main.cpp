#include "Main.h"

// 変数
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
CMoverList Block1List(sizeof(CBlock1), 10000);//追加
CMoverList Block2List(sizeof(CBlock2), 10000);//追加
CMoverList Block3List(sizeof(CBlock3), 10000);//追加
CMoverList Block4List(sizeof(CBlock4), 10000);//追加
CMoverList Block5List(sizeof(CBlock5), 10000);//追加
CMoverList Block6List(sizeof(CBlock6), 10000);//追加
CMoverList Block7List(sizeof(CBlock7), 10000);//追加
CMoverList Block8List(sizeof(CBlock8), 10000);//追加
CMoverList Block9List(sizeof(CBlock9), 10000);//追加
CMoverList Block10List(sizeof(CBlock10), 10000);//追加
CMoverList Block11List(sizeof(CBlock11), 10000);//追加
CMoverList Block12List(sizeof(CBlock12), 10000);//追加
CMoverList Block13List(sizeof(CBlock13), 10000);//追加
CMoverList Block14List(sizeof(CBlock14), 10000);//追加
CMoverList Block15List(sizeof(CBlock15), 10000);//追加
CMoverList Block16List(sizeof(CBlock16), 10000);//追加
CMoverList Block17List(sizeof(CBlock17), 10000);//追加
CMoverList Block18List(sizeof(CBlock18), 10000);//追加
CMoverList Block19List(sizeof(CBlock19), 10000);//追加
CMoverList Block20List(sizeof(CBlock20), 10000);//追加
CMoverList Block21List(sizeof(CBlock21), 10000);//追加
CMoverList Block22List(sizeof(CBlock22), 10000);//追加
CMoverList Block23List(sizeof(CBlock23), 10000);//追加
CMoverList Block24List(sizeof(CBlock24), 10000);//追加
CMoverList Block25List(sizeof(CBlock25), 10000);//追加
CMoverList Block26List(sizeof(CBlock26), 10000);//追加
CMoverList Block27List(sizeof(CBlock27), 10000);//追加
CMoverList Block28List(sizeof(CBlock28), 10000);//追加
CMoverList Block29List(sizeof(CBlock29), 10000);//追加
CMoverList Block30List(sizeof(CBlock30), 10000);//追加
CMoverList Block31List(sizeof(CBlock31), 10000);//追加
CMoverList ItemList(sizeof(CItem), 1000);
CMoverList Item1List(sizeof(CItem1), 1000);//追加
CMoverList Item2List(sizeof(CItem2), 1000);//追加
CMoverList Item3List(sizeof(CItem3), 1000);//追加
CMoverList Item4List(sizeof(CItem4), 1000);//追加
CMoverList Item5List(sizeof(CItem5), 1000);//追加
CMoverList Item6List(sizeof(CItem6), 1000);//追加
CMoverList Item7List(sizeof(CItem7), 1000);//追加
CMoverList Item8List(sizeof(CItem8), 1000);//追加
CMoverList Item9List(sizeof(CItem9), 1000);//追加
CMoverList Item10List(sizeof(CItem10), 1000);//追加
CMoverList Item11List(sizeof(CItem11), 1000);//追加
CMoverList Item12List(sizeof(CItem12), 1000);//追加
CMoverList Item13List(sizeof(CItem13), 1000);//追加
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

// ゲーム本体
class CMyGame : public CGame {
public:
	int Time;
	bool Pause, PrevPause;
	CFont* Font;

	// 初期化
	CMyGame::CMyGame() : CGame(L"My Game") {
		const wchar_t fontchar[]=
			L"~|0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ,.(){}<>!?+-x*/='\\\"#$%&@[]";
		Font=new CFont(Graphics->GetDevice(), 
			ExePath+L"..\\Font\\Font.png", 0, fontchar, 
			16.0f/256, 32.0f/256, 16, 32, 2, 2);
		//NetworkInput.Open(Config.GetValue(L"Server"), Config.GetIntValue(L"Port"));
		Reset();
	}

	// リセット
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
		Weapon2List.Clear();//追加
		Weapon3List.Clear();//追加
		Weapon4List.Clear();//追加
		Weapon5List.Clear();//追加
		Weapon6List.Clear();//追加
		Weapon7List.Clear();//追加
		Weapon8List.Clear();//追加
		Weapon9List.Clear();//追加
		Weapon10List.Clear();//追加
		Weapon11List.Clear();//追加
		Weapon12List.Clear();//追加
		BulletList.Clear();
		Bullet1List.Clear();
		Bullet2List.Clear();
		EffectList.Clear();
		Effect1List.Clear();//追加
		Effect2List.Clear();//追加
		Effect3List.Clear();//追加
		Effect4List.Clear();//追加
		Effect5List.Clear();//追加
		Effect6List.Clear();//追加
		Effect7List.Clear();//追加
		Effect8List.Clear();//追加
		Effect9List.Clear();//追加
		Effect10List.Clear();//追加
		Effect11List.Clear();//追加
		Effect12List.Clear();//追加
		Effect13List.Clear();//追加
		Effect14List.Clear();//追加
		Effect15List.Clear();//追加
		Effect16List.Clear();//追加
		Effect17List.Clear();//追加
		Effect18List.Clear();//追加
		Effect19List.Clear();//追加
		Effect20List.Clear();//追加
		Effect21List.Clear();//追加
		Effect22List.Clear();//追加
		Effect23List.Clear();//追加
		BlockList.Clear();
		Block1List.Clear();//追加
		Block2List.Clear();//追加
		Block3List.Clear();//追加
		Block4List.Clear();//追加
		Block5List.Clear();//追加
		Block6List.Clear();//追加
		Block7List.Clear();//追加
		Block8List.Clear();//追加
		Block9List.Clear();//追加
		Block10List.Clear();//追加
		Block11List.Clear();//追加
		Block12List.Clear();//追加
		Block13List.Clear();//追加
		Block14List.Clear();//追加
		Block15List.Clear();//追加
		Block16List.Clear();//追加
		Block17List.Clear();//追加
		Block18List.Clear();//追加
		Block19List.Clear();//追加
		Block20List.Clear();//追加
		Block21List.Clear();//追加
		Block22List.Clear();//追加
		Block23List.Clear();//追加
		Block24List.Clear();//追加
		Block25List.Clear();//追加
		Block26List.Clear();//追加
		Block27List.Clear();//追加
		Block28List.Clear();//追加
		Block29List.Clear();//追加
		Block30List.Clear();//追加
		Block31List.Clear();//追加
		ItemList.Clear();
		Item1List.Clear();//追加
		Item2List.Clear();//追加
		Item3List.Clear();//追加
		Item4List.Clear();//追加
		Item5List.Clear();//追加
		Item6List.Clear();//追加
		Item7List.Clear();//追加
		Item8List.Clear();//追加
		Item9List.Clear();//追加
		Item10List.Clear();//追加
		Item11List.Clear();//追加
		Item12List.Clear();//追加
		Item13List.Clear();//追加
		CameraList.Clear();
		LightList.Clear();
		OPList.Clear();//追加
		OP1List.Clear();//追加
		OP2List.Clear();//追加

		Score=Time=0;
		//追加変数リセット
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

	// 移動
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
			Weapon2List.Move();//追加
			Weapon3List.Move();//追加
			Weapon4List.Move();//追加
			Weapon5List.Move();//追加
			Weapon6List.Move();//追加
			Weapon7List.Move();//追加
			Weapon8List.Move();//追加
			Weapon9List.Move();//追加
			Weapon10List.Move();//追加
			Weapon11List.Move();//追加
			Weapon12List.Move();//追加
			BulletList.Move();
			Bullet1List.Move();
			Bullet2List.Move();
			EffectList.Move();
			Effect1List.Move();//追加
			Effect2List.Move();//追加
			Effect3List.Move();//追加
			Effect4List.Move();//追加
			Effect5List.Move();//追加
			Effect6List.Move();//追加
			Effect7List.Move();//追加
			Effect8List.Move();//追加
			Effect9List.Move();//追加
			Effect10List.Move();//追加
			Effect11List.Move();//追加
			BlockList.Move();
			Block1List.Move();//追加
			Block2List.Move();//追加
			Block3List.Move();//追加
			Block4List.Move();//追加
			Block5List.Move();//追加
			Block6List.Move();//追加
			Block7List.Move();//追加
			Block8List.Move();//追加
			Block9List.Move();//追加
			Block10List.Move();//追加
			Block11List.Move();//追加
			Block12List.Move();//追加
			Block13List.Move();//追加
			Block14List.Move();//追加
			Block15List.Move();//追加
			Block16List.Move();//追加
			Block17List.Move();//追加
			Block18List.Move();//追加
			Block19List.Move();//追加
			Block20List.Move();//追加
			Block21List.Move();//追加
			Block22List.Move();//追加
			Block23List.Move();//追加
			Block24List.Move();//追加
			Block25List.Move();//追加
			Block26List.Move();//追加
			Block27List.Move();//追加
			Block28List.Move();//追加
			Block29List.Move();//追加
			Block30List.Move();//追加
			Block31List.Move();//追加
			LightList.Move();
			ItemList.Move();
			Item1List.Move();//追加
			Item2List.Move();//追加
			Item3List.Move();//追加
			Item4List.Move();//追加
			Item5List.Move();//追加
			Item6List.Move();//追加
			Item7List.Move();//追加
			Item8List.Move();//追加
			Item9List.Move();//追加
			Item10List.Move();//追加
			Item11List.Move();//追加
			Item12List.Move();//追加
			Item13List.Move();//追加
			CameraList.Move();
			Effect13List.Move();//追加
			Effect14List.Move();//追加
			Effect15List.Move();//追加
			Effect12List.Move();//追加
			Effect16List.Move();//追加
			Effect17List.Move();//追加
			Effect18List.Move();//追加
			Effect19List.Move();//追加
			Effect20List.Move();//追加
			Effect21List.Move();//追加
			Effect22List.Move();//追加
			Effect23List.Move();//追加
			OPList.Move();//追加
			OP1List.Move();//追加
			OP2List.Move();//追加
			Time++;
			if (Time % 60 == 0){		//1秒の換算方法
				Count--;
			}
		}
	}

	// 描画
	void Draw() {
		
		CBasicRenderer& r=*Renderer;
		r.ClearRenderTarget=true;
		r.Color=CColor(1, 1, 1, 1);
		r.Camera=Camera;
		r.LightList=&LightList;
		r.Perspective=r.ZBuffer=r.Sort=r.Billboard=false;
		//r.Perspective = r.ZBuffer = r.Sort = r.Billboard = true;
		r.ClearRenderTarget = r.ClearDepthStencil = r.ZBuffer = true;// ステージ全般を描画する
		r.Remove();
		r.Add(Effect2List);//背景
		r.Add(Effect8List);//背景2
		r.Add(Effect9List);//背景3
		r.Add(Effect10List);//背景4
		r.Add(Effect11List);//背景5
		r.Add(EffectList);//スポットライト
		r.Add(StageList);//ステージ1
		r.Add(Stage2List);//ステージ2
		r.Add(Block20List);//お菓子ブロック9(ケーキ)
		r.Add(Item5List);//ワープゲート（1面ら2面）
		r.Add(Item8List);//ワープゲート（2面から3面）
		r.Add(Item9List);//ワープゲート（3面から4面）
		r.Add(Item12List);//ステージカメラ移動
		r.Add(Item13List);//ステージカメラ移動
		r.Add(Block22List);//お菓子キャンディーケーン（縦）
		r.Add(Block23List);//お菓子キャンディーケーン（横)
		r.Add(BulletList);//敵キャラゲート
		r.Add(EnemyList);//熊
		r.Add(Enemy3List);//タイ焼き
		r.Add(Enemy2List);//BOSS
		r.Add(WeaponList);//氷手裏剣
		r.Add(Effect18List);//残像
		r.Add(Effect19List);//残像
		r.Add(Effect20List);//BOSS残像
		r.Add(MyShipList);//自キャラ
		r.Add(Effect22List);//ブロック表示
		r.Add(Effect21List);//斬牆クリマタクト
		r.Add(Bullet1List);//召喚攻撃
		r.Add(Bullet2List);//岩召喚攻撃
		r.Add(Weapon11List);//クリマタクト
		r.Add(Effect23List);//クリマタクト発射
		r.Add(Weapon2List);//爆弾
		r.Add(Weapon3List);//フォーク先端
		r.Add(Weapon8List);//鉄トゲ
		r.Add(Weapon9List);//鉄トゲ1
		r.Add(Weapon4List);//回転星クッキー
		r.Add(Weapon5List);//金平糖
		r.Add(Weapon6List);//砲弾
		r.Add(Weapon7List);//砲弾
		r.Add(Block5List);//黒ブロック
		r.Add(Block8List);//お菓子ブロック1
		r.Add(Block9List);//お菓子ブロック2
		r.Add(Block10List);//お菓子ブロック3
		r.Add(Block11List);//お菓子ブロック4
		r.Add(Block12List);//水晶ブロック1
		r.Add(Block13List);//水晶ブロック2
		r.Add(Block14List);//水晶ブロック3
		r.Add(Block15List);//水晶ブロック4
		r.Add(Block16List);//お菓子ブロック5
		r.Add(Block17List);//お菓子ブロック6
		r.Add(Block18List);//お菓子ブロック7
		r.Add(Block19List);//お菓子ブロック8
		r.Add(Block21List);//フォーク柄
		r.Add(Block24List);//大砲
		r.Add(Item6List);//ボム
		r.Add(Item7List);//氷手裏剣
		r.Add(Item10List);//桃ブーメラン
		r.Add(Block25List);//赤氷ブロック（右）
		r.Add(Block26List);//赤氷ブロック（左）
		r.Add(Block27List);//赤氷ブロック（下）
		r.Add(Block28List);//鉄ブロック
		r.Add(Block29List);//鉄ブロック1
		r.Add(Block30List);//BOSS方向転換
		r.Add(Block31List);//BOSS方向転換1
		r.Add(BlockList);//青ブロック
		r.Add(Block3List);//赤ブロック
		r.Add(Block4List);//針ブロック
		r.Add(Block1List);//フィールド氷ブロック大
		r.Add(ItemList);//ハート
		r.Add(Item1List);//暗闇
		r.Add(Item2List);//明るさ復活
		r.Add(Item3List);//毒キノコ
		r.Add(Item4List);//敵出現ゲート
		r.Add(Item11List);//ステージカメラ移動
		r.Add(Effect1List);//自機＆敵消滅爆破
		r.Add(Effect4List);//氷ブロック大割れ
		r.Add(Enemy8List);//BOSS顔
		r.Add(Enemy10List);//BOSS顔あたり判定
		r.Add(Weapon10List);//BOSS顔(攻撃）
		r.Add(Enemy6List);//BOSS足判定
		r.Add(Enemy7List);//BOSS顔判定
		r.Add(Enemy9List);//BOSS顔判定2
		r.Add(Effect5List);//武器爆弾爆破
		r.Add(Block2List);//召喚氷DOWN
		r.Add(Block6List);//召喚ブロックRIGHT
		r.Add(Block7List);//召喚ブロックLEFT
		r.Add(Effect3List);//召喚氷割れ
		r.Add(Effect6List);//召喚氷割れ
		r.Add(Effect15List);//召喚氷割れ（赤）
		r.Add(Effect7List);//BOSS消滅爆破
		r.Add(Effect13List);//アイテム表示（氷手裏剣）
		r.Add(Effect14List);//アイテム表示2（爆弾）
		r.Add(Effect16List);//アイテム表示3（桃ブーメラン）
		r.Add(Effect12List);//アイテム表示枠
		r.Add(Effect17List);//ブロック表示
		r.Add(Enemy5List);//爆弾野郎
		r.Add(Weapon12List);//岩召喚陣
		r.Add(OPList);//OP画面
		r.Add(OP1List);//GAMEOVER画面
		r.Add(OP2List);//CLEAR画面
		r.Render();
		
		// スポットライトを描画する
		r.ClearRenderTarget = false;
		r.Remove();
		r.Add(EffectList);
		r.Render();

		// 暗闇を描画する
		r.ClearDepthStencil = false;
		r.Remove();
		r.Add(BulletList);
		r.Render();

//---------------------------------------------------------------------------------------------------------------------------------------------------------

		StageList.Apply([&](CMover* s) {
			if (s->Type != 0){


				//Time(経過時間)
				if (GOV == 0 && CLR == 0){
					if (Time % 60 == 0){		//1秒の換算方法
						TIME++;
					}
				}
				//テスト
			
				if (game_over_count==0){
					Font->DrawText(wstring(L"TIME:") + ToStr(TIME), 600, 0, CColor(1, 1, 1, 1), CColor(2, 0, 0, 1));
					//スコア表示
					Font->DrawText(wstring(L"SCORE:") + ToStr(Score), 600, 32, CColor(1, 1, 1, 1), CColor(1, 2, 0, 1));
				}
				if (GOV == 0 && CLR==0){//
					//スコア表示
					//Font->DrawText(wstring(L"SCORE:") + ToStr(Score), 600, 32, CColor(1, 1, 1, 1), CColor(1, 2, 0, 1));
					//スコア表示
					//Font->DrawText(wstring(L"GOV:") + ToStr(GOV), 600, 64, CColor(1, 1, 1, 1), CColor(1, 2, 0, 1));
					//ライフ表示追加
					MyShipList.Apply([&](CMover* a) {
						Font->DrawText(wstring(L"LIFE:") + ToStr(a->Life), 0, 0, CColor(1, 1, 1, 1), CColor(1, 0, 1, 1));
					});
					//氷残り表示追加
					Font->DrawText(wstring(L"BP:") + ToStr(BP), 0, 32, CColor(1, 1, 1, 1), CColor(0, 0, 1, 1));
					if (BP == 5){
						Font->DrawText(wstring(L"MAX"), 64, 32, CColor(1, 1, 1, 1), CColor(2, 0, 0, 1));
					}

					//ブロックタイプ表示
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

// アプリケーションの起動
CMyGame* Game;
INT WINAPI WinMain(HINSTANCE hinst, HINSTANCE, LPSTR, INT) {
	Game=new CMyGame();
	Game->Run();
	delete Game;
	return 0;
}

