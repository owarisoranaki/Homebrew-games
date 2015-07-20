#include "Main.h"

//ステージ作成
static char* stage0[] = {

	"P                                                                                                                                                                ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	0
};


static char* stage1[] = {
	
	"121342134121342134121342134121342134121342134121342134121342134121342134121342134121342134121342134121342134121342134121342134121342134121342134121342134121342121",
	"1                                                                                           l      Y                                                              1",
	"1                   y             y                        y                       k      y l      Y                                                              1",
	"1                                                                                           l      Y                                                              1",
	"1Dw                         t                 k                    t                        l      Y                                                              1",
	"1213                                                 u                      k                      Y                                                              1",
	"1             Y                     k                 Y                        n                   Y                                                              1",
	"1                        I                   t                     Y   L     L        L            Y                                                              1",
	"1                        Y                               t         Y                        l      Y                                                              1",
	"1      23142            Y Y                L                       Y                        l      Y                                                              1",
	"1     2                Y   Y  %    e &    l        L              u                         l     GY                                                              1",
	"1M   1cccccc23142          I    %      &  lcccccccccl  %   e   &&         3421ccccccc2134          Y                                                            G 1",
	"123142134121342134121342134121342134121342134121342134121342134121342134121342134121342134121342134121342134121342134121342134121342134121342134121342134121342121",
	"ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc                                                               ",
	"                                                                                                                                                                  ",
	"                                                                                                                                                                  ",
	"                                                                                                                                                                  ",
	"                                                                                                                                                                  ",
	"                                                                                                                                                                  ",
	"                                                                                                                                                                  ",
	"                                                                                                                                                                  ",
	"                                                                                                                                                                  ",
	"                                                                                                                                                                  ",
	"                                                                                                                                                                  ",
	"                                                                                                                                                                  ",
	"                                                                                                                                                                  ",//横0～162
    0
}; 

static char* stage2[] = {

	"565656565656565656565656565656565656565656565656565                                                                                                               ",
	"5             6 o6    565656 65 5    o            5                                                                                                               ",
	"6        O6   I  5      O     o 6                 6                                                                                                               ",
	"5        65      6      O       5           x     5                                                                                                               ",
	"656565    6      5              6                 6                                                                                                               ",
	"5cccc5    5      6        6     5                 5                                                                                                               ",
	"6         6   5655   x    5     6   656           6                             s                                                                                 ",
	"5         5               6         5             5                             s                                                                                 ",
	"6a   56566                5         66~~~~~~~~6   6                                                                                                               ",
	"55    j9i56~~~~~~~~~5     6         5 56565655    5                                                                                                               ",
	"6     #9j6 6566565656     5    x    6             6                                                                                                               ",
	"5M   56565F              i6         5             5                                                                                                               ",
	"556565    65            565       i 6o       5~~~~6                                                                                                               ",
	"787878787878878~~~~~~~87878787878787878dddd78787887                                                                                                               ",
	"7             878787878           7               7                                                                                                               ",
	"8787878878                        8               8                                                                                                               ",
	"7            ccccccc              7               7                                                                                                               ",
	"8           7   78         x      8  ccc          8                                                                                                               ",
	"77878787    o                     778             7                             S                                                                                 ",
	"8                                 8         8~~~~~8                             S                                                                                 ",
	"78                          8               7878787                                                                                                               ",
	"8  F           x       m          7       x       8                                                                                                               ",
	"77878             i   87878       8               7                                                                                                               ",
	"8                          8      O               8                                                                                                               ",
	"7D 7887    7~~~~~~~~8       7     #j      i       7                                                                                                               ",
	"787878787878787878787878787878787878787878787878787                                                                                                               ",
	0
};

static char* stage3[] = {

	"78787878787878787878787878787878                                                                                                                                  ",
	"7    X     X   X      X        7                                                                                                                                  ",
	"87X                          X88                                                                                                                                  ",
	"7        I      787    m      D7                                                                                                                                  ",
	"8      8787           787   7878                                                                                                                                  ",
	"7                              7                                                                                                                                  ",
	"8w 8                           8                                                S                                                                                 ",
	"77                             7                                                S                                                                                 ",
	"8                              8                                                                                                                                  ",
	"7                              7                                                                                                                                  ",
	"J                          Q   z                                                                                                                                  ",
	"7     M                        7                                                                                                                                  ",
	"7~~87878787878787878787878787~~8                                                                                                                                  ",
	" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                                                                                                                                  ",
	" ccccccccccccccccccccccccccccccc                                                                                                                                  ",
	"                                                                                                                                                                  ",
	"                                                                                                                                                                  ",
	"                                                                                                                                                                  ",
	"                                                                                                                                                                  ",
	"                                                                                                                                                                  ",
	"                                                                                                                                                                  ",
	"                                                                                                                                                                  ",
	"                                                                                                                                                                  ",
	"                                                                                                                                                                  ",
	"                                                                                                                                                                  ",
	"                                                                                                                                                                  ", 
	0
};

//ステージ作成
static char* stage4[] = {

	"       p                                                                                                                                                         ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	0
};

//ステージ作成
static char* stage5[] = {

	"       Z                                                                                                                                                         ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	"                                                                                                                                                                 ",
	0
};

// ステージの初期化
void CStage::Reset() {

		BlockList.Kill();
		Block1List.Kill();
		Block2List.Kill();
		Block3List.Kill();
		Block4List.Kill();
		Block5List.Kill();
		Block6List.Kill();
		Block7List.Kill();
		Block8List.Kill();
		Block9List.Kill();
		Block10List.Kill();
		Block11List.Kill();
		Block12List.Kill();
		Block13List.Kill();
		Block14List.Kill();
		Block15List.Kill();
		Block16List.Kill();
		Block17List.Kill();
		Block18List.Kill();
		Block19List.Kill();
		Block20List.Kill();
		Block21List.Kill();
		Block22List.Kill();
		Block23List.Kill();
		Block24List.Kill();
		Block25List.Kill();
		Block26List.Kill();
		Block27List.Kill();
		Block28List.Kill();
		Block29List.Kill();
		Block30List.Kill();
		Block31List.Kill();
		MyShipList.Kill();
		ItemList.Kill();
		Item1List.Kill();
		Item2List.Kill();
		Item3List.Kill();
		Item4List.Kill();
		Item5List.Kill();
		Item6List.Kill();
		Item7List.Kill();
		Item8List.Kill();
		Item9List.Kill();
		Item10List.Kill();
		Item11List.Kill();
		Item12List.Kill();
		Item13List.Kill();
		Effect1List.Kill();
		Effect2List.Kill();
		Effect5List.Kill();
		Effect8List.Kill();
		Effect9List.Kill();
		Effect10List.Kill();
		Effect11List.Kill();
		EnemyList.Kill();
		Enemy2List.Kill();
		Enemy3List.Kill();
		Enemy5List.Kill();
		//Enemy2List.Kill();
		Weapon3List.Kill();
		Weapon4List.Kill();
		Weapon5List.Kill();
		Weapon6List.Kill();
		Weapon8List.Kill();
		Weapon9List.Kill();
		OPList.Kill();
		//OP1List.Kill();
		//OP2List.Kill();
		
	//枠武器表示-------------------------------------------------------------------------------
		New<CEffect13>();	
		New<CEffect14>();
		New<CEffect12>();
		New<CEffect17>();
   //チェンジ画面
		char** stage;
		if (Type == 0) stage = stage0;//OP
		if (Type == 1) stage = stage1;//1面
		if (Type == 2) stage = stage2;//2面
		if(Type == 3) stage = stage3;//3面
		if (Type == 4) stage = stage4;//GAMEOVER画面
		if (Type == 5) stage = stage5;//CLEAR画面

    //ステージBGM
		//OP
		if (Type == 0 && Type != 4 && Type != 5){ GetWave(L"game_maoudamashii_5_village05.wav")->Play(-1); GetWave(L"game_maoudamashii_5_village05.wav")->SetVolume(0.07f); }
		if (Type == 1 || Type == 2 || Type == 3 || Type == 4 || Type == 5){ GetWave(L"game_maoudamashii_5_village05.wav")->Stop(); }
		//1面
		if (Type == 1 && Type != 4 && Type != 5){ GetWave(L"bgm_maoudamashii_acoustic01b.wav")->Play(-1); GetWave(L"bgm_maoudamashii_acoustic01b.wav")->SetVolume(0.07f); }
		if (Type == 0 || Type == 2 || Type == 3 || Type == 4 || Type == 5){ GetWave(L"bgm_maoudamashii_acoustic01b.wav")->Stop(); }
		//2面
		if (Type == 2 && Type != 4 && Type != 5){ GetWave(L"bgm_maoudamashii_healing05.wav")->Play(-1); GetWave(L"bgm_maoudamashii_healing05.wav")->SetVolume(0.07f); }
		if (Type == 0 || Type == 1 || Type == 3 || Type == 4 || Type == 5){ GetWave(L"bgm_maoudamashii_healing05.wav")->Stop(); }
		//BOSS面
		if (Type == 3 && Type != 4 && Type != 5){ GetWave(L"game_maoudamashii_1_battle19.wav")->Play(-1); GetWave(L"game_maoudamashii_1_battle19.wav")->SetVolume(0.07f); }
		if (Type == 0 || Type == 1 || Type == 2 || Type == 4 || Type == 5){ GetWave(L"game_maoudamashii_1_battle19.wav")->Stop(); }
		
		
		for (int y = 0; stage1[y]; y++) {
			for (int x = 0; stage1[y][x]; x++) {
				float a = x*0.2f, b = -y*0.2f;
				switch (stage[y][x]) {
				//case 'H': New<CEffect2>(a, b, 0, 0, 0, 0); break;//背景＿氷
				case 'n': New<CEffect8>(a, b, 0, 0, 0, 0); break;//背景＿お菓子世界（表）
				case 's': New<CEffect9>(a, b, 0, 0, 0, 0); break;//背景＿水晶世界（青）
				case 'T': New<CEffect11>(a, b, 0, 0, 0, 0); break;//背景＿お菓子世界（裏）
				case 'S': New<CEffect10>(a, b, 0, 0, 0, 0); break;//背景＿水晶世界（緑）
				//case '#': New<CBlock>(a, b, 0, 0, 0, 0); break;//氷世界フィールドブロック
				case 'B': New<CBlock1>(a, b, 0, 0, 0, 0); break;//壊せる氷ブロック大
				case 'C': New<CBlock2>(a, b, 0, 0, 0, 0); break;//召喚ブロック（下）
				case '&': New<CBlock3>(a, b, 0, 0, 0, 0); break;//赤ブロック
				case '~': New<CBlock4>(a, b, 0, 0, 0, 0); break;//トゲ
				case '%': New<CBlock5>(a, b, 0, 0, 0, 0); break;//黒ブロック
				case '1': New<CBlock8>(a, b, 0, 0, 0, 0); break;//bulock_kasi1
				case '2': New<CBlock9>(a, b, 0, 0, 0, 0); break;//bulock_kasi2
				case '3': New<CBlock10>(a, b, 0, 0, 0, 0); break;//bulock_kasi3
				case '4': New<CBlock11>(a, b, 0, 0, 0, 0); break;//bulock_kasi4
				case '5': New<CBlock12>(a, b, 0, 0, 0, 0); break;//bulock_sui1
				case '6': New<CBlock13>(a, b, 0, 0, 0, 0); break;//bulock_sui2
				case '7': New<CBlock14>(a, b, 0, 0, 0, 0); break;//bulock_sui3_1
				case '8': New<CBlock15>(a, b, 0, 0, 0, 0); break;//bulock_sui3_2
				case 'q': New<CBlock16>(a, b, 0, 0, 0, 0); break;//bulock_kasi1_1
				case 'W': New<CBlock17>(a, b, 0, 0, 0, 0); break;//bulock_kasi1_2
				case 'r': New<CBlock18>(a, b, 0, 0, 0, 0); break;//bulock_kasi1_3
				case 'R': New<CBlock19>(a, b, 0, 0, 0, 0); break;//bulock_kasi1_4
				case 'Y': New<CBlock20>(a, b, 0, 0, 0, 0); break;//ケーキブロック
				case 'l': New<CBlock22>(a, b, 0, 0, 0, 0); break;//キャンディーケーン（縦）
				case 'L': New<CBlock23>(a, b, 0, 0, 0, 0); break;//キャンディーケーン（横）
				case 'u': New<CBlock24>(a, b, 0, 0, 0, 0); break;//大砲
				case '#': New<CBlock25>(a, b, 0, 0, 0, 0); break;//赤氷ブロック（右）
				case '9': New<CBlock26>(a, b, 0, 0, 0, 0); break;//赤氷ブロック（左）
				case 'j': New<CBlock27>(a, b, 0, 0, 0, 0); break;//赤氷ブロック（下）
				case 'O': New<CBlock28>(a, b, 0, 0, 0, 0); break;//鉄ブロック
				case 'a': New<CBlock29>(a, b, 0, 0, 0, 0); break;//鉄ブロック
				case 'J': New<CBlock30>(a, b, 0, 0, 0, 0); break;//BOSS方向転換
				case 'z': New<CBlock31>(a, b, 0, 0, 0, 0); break;//BOSS方向転換
				case 'I': New<CItem>(a, b, 0, 0, 0, 0); break;//ハート
				case 'K': New<CItem1>(a, b, 0, 0, 0, 0); break;//暗闇アイテム
				case 'A': New<CItem2>(a, b, 0, 0, 0, 0); break;//明るくスイッチ
				case 'D': New<CItem3>(a, b, 0, 0, 0, 0); break;//毒キノコ
				case 'E': New<CItem4>(a, b, 0, 0, 0, 0); break;//敵出現ゲート
				case 'G': New<CItem5>(a, b, 0, 0, 0, 0); break;//ゲート（1～2）
				case 'w': New<CItem6>(a, b, 0, 0, 0, 0); break;//爆弾アイテム
				case 'h': New<CItem7>(a, b, 0, 0, 0, 0); break;//氷手裏剣アイテム
				case 'F': New<CItem8>(a, b, 0, 0, 0, 0); break;//ゲート（2～3）
				case 'f': New<CItem9>(a, b, 0, 0, 0, 0); break;//ゲート（3～4）
				case 'm': New<CItem10>(a, b, 0, 0, 0, 0); break;//桃ブーメランアイテム
				case 'd': New<CItem11>(a, b, 0, 0, 0, 0); break;//カメラ移動アイテム(寿司)
				case 'i': New<CItem12>(a, b, 0, 0, 0, 0); break;//カメラ移動アイテム(緑上)
				case 'o': New<CItem13>(a, b, 0, 0, 0, 0); break;//カメラ移動アイテム(青上)
				case 'e': New<CEnemy>(a, b, 0, 0, 0, 0); break;//クマ
				case 'Q': New<CEnemy2>(a, b, 0, 0, 0, 0); break;//BOSS
				case 't': New<CEnemy3>(a, b, 0, 0, 0, 0); break;//タイ焼き
				case 'x': New<CEnemy5>(a, b, 0, 0, 0, 0); break;//爆弾野郎
				case 'M': New<CMyShip>(a, b, 0, 0, 0, 0); break;//自機
				case 'y': New<CWeapon3>(a, b, 0, 0, 0, 0); break;//フォーク先端
				case 'k': New<CWeapon4>(a, b, 0, 0, 0, 0); break;//星クッキー
				case 'c': New<CWeapon5>(a, b, 0, 0, 0, 0); break;//金平糖
				case 'P': New<COP>(a, b, 0, 0, 0, 0); break;//OP画面
				case 'p': New<COP1>(a, b, 0, 0, 0, 0); break;//GOV画面
				case 'Z': New<COP2>(a, b, 0, 0, 0, 0); break;//CLEAR画面
				case 'X': New<CBullet2>(a, b, 0, 0, 0, 0); break;//岩召喚陣

				}

			}
		}
	
}


void CStage2::Reset() {
	//ステージ2
	
}

// ステージの移動
void CStage::Move() {
	//自機消滅エフェクト
	MyShipList.Apply([&](CMover* m) {
		if (m->Life <= 0){
			game_over_count = 1;
			MYSHIP_DELETE_TYPE = 1;
			New<CEffect7>(m->Position);
			//GBGM = 1;//ゲームオーバーBGM再生変数
			GOV1 = 1;//ゲームオーバー画面表示変数
			OP2 = 0;
		}
	});
	//GAMEOVER画面表示処理
	if (GOV1 == 1){
		if (Time == 60)GOV = 1;
		if (Time == 60){
			//ゲームオーバー
			GetWave(L"GAMEOVER.wav")->Play(1);
			GetWave(L"GAMEOVER.wav")->SetVolume(0.07f);
		}
		Time++;
	}
	if (GOV == 1){
		Type = 4; 
			Reset();
		
	}

	EnemyList.Apply([&](CMover* e) {
		if (e->Life <= 0){
			if (MYSHIP_DELETE_TYPE == 0){
				New<CEffect1>(e->Position);
			}
			//GetWave(L"b_062.wav")->Play(1);
			//GetWave(L"b_062.wav")->SetVolume(0.07f);
		}
	});
	//BOSS消滅エフェクト
	Enemy2List.Apply([&](CMover* e) {
		Enemy7List.Apply([&](CMover* m) {
			if (m->Life == 0){
				e->Life = 0;
				if (e->Life == 0){
					//GetWave(L"b_062.wav")->Play(1);
					//GetWave(L"b_062.wav")->SetVolume(0.07f);
					New<CEffect7>(e->Position);
					New<CEffect7>(m->Position);
					CLR1 = 1;//クリアー画面表示
				}
			}
		});
	});
	//CLEAR画面表示処理
	if (CLR1 == 1){
		if (Time == 60)CLR = 1;
		if (Time == 60){
			//クリア
			GetWave(L"j_19.wav")->Play(1);
			GetWave(L"j_19.wav")->SetVolume(0.07f);
		}
		Time++;
	}
	if (CLR == 1){
		Type = 5;
		Reset();
	}

	Enemy3List.Apply([&](CMover* e) {
		if (e->Life == 0){
			//GetWave(L"b_062.wav")->Play(1);
			//GetWave(L"b_062.wav")->SetVolume(0.07f);
			if (MYSHIP_DELETE_TYPE == 0){
				New<CEffect1>(e->Position);
			}
		}
	});

	Enemy5List.Apply([&](CMover* e) {
		if (e->Life == 0){
			//GetWave(L"b_062.wav")->Play(1);
			//GetWave(L"b_062.wav")->SetVolume(0.07f);
			New<CEffect7>(e->Position);
		}
	});
	Enemy6List.Apply([&](CMover* e) {
		Enemy7List.Apply([&](CMover* m) {
			if (m->Life == 0){
				e->Life = 0;
			}
		});
	});

	Enemy8List.Apply([&](CMover* e) {
		Enemy7List.Apply([&](CMover* m) {
			if (m->Life == 0){
				e->Life = 0;
				/*if (e->Life == 0){
					New<CEffect7>(e->Position);
				}*/
			}
		});
	});

}