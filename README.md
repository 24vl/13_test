![header](https://capsule-render.vercel.app/api?type=wave&color=auto&height=300&section=header&text=1IDIOT3&fontSize=100) 




< T U T O R : 야근 방어전>


<br/>

<div align=left>



-  이 프로젝트는 텍스트 기반의 RPG 게임입니다.


- 주인공(튜터님)은 몬스터(학생들)와 전투를 하거나 상점을 이용하실 수 있습니다. 최종적으로 플레이어의 레벨이 10에 도달하여 보스 몬스터를 처치하면 
정시 퇴근에 성공하면서 게임이 클리어 됩니다. 
반대로 플레이어의 체력이 0이 되면 야근 방어에 실패하여 게임 오버가 됩니다.

<br/>

>###  <p>$\bf{\large{\color{#DD6565}주요 기능 가이드 🎮}}$</p>




#### 1. 캐릭터 생성 및 관리
- 원하는 이름으로 캐릭터 생성이 가능합니다.
- 초기 능력치는 고정돼있으며, 캐릭터 능력치 확인이 가능합니다.
 - 레벨 업 시 능력치가 증가하며 최대 레벨은 10레벨입니다.


#### 2. 전투 시스템
  - 몬스터는 랜덤하게 등장합니다.
  - 몬스터 처치 시 경험치 50 획득합니다.
  - 몬스터에 따라 골드 획득량이 달라집니다.

#### 3. 상점 시스템
  - 골드로 아이템 구매 및 판매가 가능합니다.

 #### 4. 일반 몬스터 설명
 - 일반 몬스터는 총 6명이며, 각자 다른 이름, 체력, 공격력을 가집니다.
  - 주인공의 레벨 1 ~ 3 / 4 ~ 6 / 7 ~ 9

    3구간마다 등장하는 몬스터의 종류가 달라집니다. (각 구간마다 몬스터는 2명씩 배정되어 랜덤으로 등장합니다.)

#### 5. 보스 몬스터(키메라)
  - 레벨 10에 도달 시 등장합니다.
  - 처치 시 게임이 클리어 되고 실패 시 게임 오버 됩니다.

#### 6. 아이템 설명
 - 전투에서 이기면 골드를 얻고, 가끔(30% 확률) 아이템이 떨어집니다.
  - 아이템은 **체력 +50** 또는 **공격력 +5**을 해줍니다.
  - 아이템은 사용 순간 사라지고, 효과는 바로 캐릭터에게 반영됩니다.

#### 7. 게임 로그 확인
  - 로그를 통해 오늘 어떤 몬스터를 몇 마리 잡았는지 확인이 가능합니다.
  

<br/>

---

  

 



      


 ### - 개발 언어 및 도구 🔧
- Visual Studio 2022
- C++ 17 지원
- 빌드 시스템: MSVC (Debug / Release)
      
 ### - 실행 방법 ⚙
- main.cpp에서 프로그램 시작
- Visual Studio 기준: Ctrl + F5 또는 디버깅 없이 시작



<br/>


---
### -팀 소개 및 역할 👥
<br/>


|이름|역할|담당|
|:---:|:---:|:---:|
|김지원|팀장|Monster, README 작성, UI 디자인|
|전형준|부팀장|Item, GameManager, Ending|
|장재근|팀원|Item, GameManager, Shop, 오류 해결|
|성준모|팀원|Monster, Monster 컨셉 및 대사, PPT|
|최선호|팀원|Character, 여러 기능 추가, QA 게임 테스트|
|김성빈|팀원|Character, Character 대사, 밸런스 구상, 발표|



   <br/>

---

### -기술 스택 💻



<img src="https://img.shields.io/badge/cplusplus-00599C?style=for-the-badge&logo=cplusplus&logoColor=white">
<img src="https://img.shields.io/badge/git-F05032?style=for-the-badge&logo=git&logoColor=white">
<img src="https://img.shields.io/badge/github-181717?style=for-the-badge&logo=github&logoColor=white">
<img src="https://img.shields.io/badge/VISUALSTUDIO-6929C4?style=for-the-badge&logo=VISUALSTUDIO&logoColor=white">

<br/>

---

### -협업 공간 🤝
<img src="https://img.shields.io/badge/ZEP-4E5EE4?style=for-the-badge&logo=ZEP&logoColor=white">

<br/>

---

### -폴더 구조 🔍
<br/>


```
1IDIOT3_PROJECT
┣ source
┃ ┣ Main.cpp // 메인 함수 구현
┃ ┣ GameManager.cpp // 전반적인 프로그램 관리
┃ ┣ Character.cpp // 캐릭터 시스템
┃ ┣ Item.cpp // 캐릭터 인벤토리 아이템 클래스
┃ ┣ Shop.cpp // 상점 시스템
┃ ┗ Monster.cpp // 몬스터 시스템
┃
┗ resource
    ┣ GameManager.h // GameManager  멤버 선언
    ┣ Character.h // Character 멤버 선언
    ┣ Item.h // Item 멤버 선언
    ┣ Shop.h // Shop 멤버 선언
    ┗ Monster.h // Monster 멤버 선언
```


<br/>


--- 

### -추가 구현 사항 📚

- 킬로그 구현
- Ui 디자인(아스키 아트)
- 스토리, 대사 기획
- 인트로, 엔딩 제작
- 몬스터 레벨 디자인 및 밸런스 구현


