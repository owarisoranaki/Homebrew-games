#pragma once
#include "..\HigPen\HigPen.h"
using namespace higpen;

extern CMoverList
StageList, Stage2List, 
MyShipList, 
EnemyList, Enemy2List, Enemy3List, Enemy5List, Enemy6List, Enemy7List, Enemy8List, Enemy9List, Enemy10List,
WeaponList, Weapon2List, Weapon3List, Weapon4List, Weapon5List, Weapon6List, Weapon7List, Weapon8List, Weapon9List, Weapon10List, Weapon11List, Weapon12List,
BulletList, Bullet1List, Bullet2List,
EffectList, Effect1List, Effect2List, Effect3List, Effect4List, Effect5List, Effect6List, Effect7List, Effect8List, Effect9List, Effect10List,
Effect11List, Effect12List, Effect13List, Effect14List, Effect15List, Effect16List, Effect17List, Effect18List, Effect19List, Effect20List, Effect21List, Effect22List, Effect23List,
BlockList, Block1List, Block2List, Block3List, Block4List, Block5List, Block6List, Block7List, Block8List, Block9List, Block10List,Block11List, 
Block12List, Block13List, Block14List, Block15List, Block16List, Block17List, Block18List, Block19List, Block20List, Block21List, Block22List, 
Block23List, Block24List, Block25List, Block26List, Block27List, Block28List, Block29List, Block30List, Block31List,
ItemList, Item1List, Item2List, Item3List, Item4List, Item5List, Item6List, Item7List, Item8List, Item9List, Item10List, Item11List, Item12List, Item13List,
CameraList, LightList, OPList, OP1List, OP2List;

extern int game_over_count;
extern int Score,STP,CP,BSST,GOV1,OP2;
extern int BP,SI,WP,BRR,GOV,CLR,CLR1;
extern int BT,CS,RW,TIME,BOSSHP,BOSSC;

int Count=0;

#include "MyMover.h"
#include "Block.h"
#include "Bullet.h"
#include "Camera.h"
#include "Effect.h"
#include "Enemy.h"
#include "Item.h"
#include "Light.h"
#include "MyShip.h"
#include "Stage.h"
#include "Weapon.h"
#include "OP.h"


extern CCamera* Camera;

