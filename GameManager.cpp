#include "GameManager.h"

using namespace std;

// 몬스터 소환 // 동적 할당
Monster* GameManager::generateMonster(int level) // level = Character->getLevel()
{
    if (level <= 3)
    {
        if (rand() % 2 == 0) { return new Student1; }
        else { return new Student2(); }

    }
    else if (level > 3 && level <= 6)
    {
        if (rand() % 2 == 0) { return new Student3; }
        else { return new Student4; }
    }
    else if (level > 6 && level <= 9)
    {
        if (rand() % 2 == 0) { return new Student5; }
        else { return new Student6; }
    }
    else // 보스 전투
    {
        bossAppears();
        return new Boss;
    }
}

//--- 전투
void GameManager::battle(Character* player)
{
    system("color 0e");
    // 몬스터 동적 할당
    Monster* monster = generateMonster(player->getLevel());
    // 몬스터 출현 대사
    cout << "!!!!! 튜터실에 " << monster->getName();
    cout << "이 나타났다 !!!!!\n" << endl;
    monster->displayStatus();

    while (true) // 몬스터나 캐릭터 사망 전까지 반복
    {
        //Sleep(3000); // 3초마다 자동 전투
        system("pause"); // 계속하려면 아무 키

        system("color 07"); // 배경색 검, 글자색 흰
        system("cls");

        cout << player->getName() << "의 공격!" << endl;
        player->skillCharacter(); // 플레이어의 공격!
        cout << "\n";
        
        // 몬스터 피격 // 몬스터 사망 시 조건문 실행
        if (monster->takeDamage(player->getAttack()))
        {
            int r = rand();
            if ((r % 100) < 30) // 30퍼센트 확률로 아이템 획득
            {
                if (r % 2 == 0) // 의 절반의 확률
                {
                    Item* h = new HealthPotion;
                    player->getItem(h);
                }
                else // 나머지 절반
                {
                    Item* a = new AttackBoost;
                    player->getItem(a);
                }
            }

            // 경험치 획득
            player->setExp(player->getExp() + 50);
            // 골드 획득
            player->setGold(player->getGold() + 10 * (r % 2 + 1));
            // 처치한 몬스터 수 증가
            player->setKillCount(player->getKillCount() + 1);
            // 처치한 몬스터 기록
            player->insertKillLog(monster->getName());
            // 조건에 따라 레벨 증가
            player->levelUp();

            // 보스 몬스터일 경우 엔딩, 게임 종료
            if (monster->getName() == "실험체 '멍청멍청'") { end = true; }

            delete monster; // 몬스터 동적 할당 해제
            monster = nullptr; // nullptr로 댕글링 포인터 방지
            break; // 몬스터가 사망했으니 전투 종료
        }
        
        monster->skillMonster(); // 몬스터의 공격!
        cout << "\n";
        if (player->takeDamage(monster->getAttack()))
        {
            player->resetStatus(); // 사망 시 리셋
            delete monster;
            monster = nullptr;
            break;
        }

        cout << "\"도핑이 필요해...\"" << endl;
        player->useItem(0);
    }
}

//--- 캐릭터 인벤토리 출력
void GameManager::displayInventory(Character* player)
{
    if (!player->getInventory().empty()) // 인벤토리가 비었는지 확인
    {
        cout << " = Inventory = " << endl;
        for (int i = 0; i < player->getInventory().size(); i++)
        {
            if (player->getInventory()[i] != nullptr) // nullptr 방지
            {
                cout << i << ". ";
                cout << player->getInventory()[i]->getName() << endl;
            }
        }
        cout << "---------------" << endl;
    }
    else // 비었을 경우, 보험
    {
        cout << " = Inventory = " << endl;
        cout << "---------------" << endl;
    }
}

//--- 게임 메뉴
void GameManager::menu(Character* player)
{
    int choice; // Enum, switch-case 변경 가능

    while (true)
    {
        system("pause"); // 다른 행동이 끝날 때의 퍼즈를 대체

        if (end) // 보스몬스터 처치 확인
        { 
            ending();
            break; 
        }

        // 메뉴 화면, 캐릭터 능력치, 인벤토리 출력
        system("cls");
        cout << "1.전투  2.상점  3.로그  4.종료\n\n"; // 변경 요망
        player->displayStatus();
        cout << "\n";
        displayInventory(player);
        cout << "\n선택 : ";
 
        cin >> choice;
        if (choice == 1) // 전투
        {
            system("cls");
            battle(player);
        }
        else if (choice == 2) // 상점
        {
            system("cls");
            Shop shop;
            while (true)
            {
                // 상점 화면 출력, 캐릭터 소지금, 인벤토리 출력
                system("pause");
                system("cls");
                cout << "소지 골드 : " << player->getGold() << endl;
                displayInventory(player);
                shop.displayItems();
                cout << "1.구매 2.판매 3.떠나기" << endl;

                cin >> choice;
                if (choice == 1) // 구매
                {
                    cout << "구매할 아이템 : ";
                    cin >> choice;
                    shop.buyItem(choice, player);
                    continue;
                }
                else if (choice == 2) // 판매
                {
                    cout << "판매할 아이템 : ";
                    cin >> choice;
                    shop.sellItem(choice, player);
                    continue;
                }
                else if (choice == 3) // 떠나기
                {
                    break;
                }
                else
                {
                    // cin.fail 해결
                    cin.clear();
                    string dummy;
                    getline(cin, dummy);
                    //while (cin.get() == '\n') continue;
                    cout << "잘못된 입력입니다." << endl;
                    continue;
                }
            }
        }
        else if (choice == 3) // 몬스터 처치 로그 출력
        {
            displayLog(player);
            continue;
        }
        else if (choice == 4) // 게임 종료
        {
            system("cls");
            cout << "게임을 종료합니다." << endl;
            break;
        }
        else // cin.fail
        {
            system("cls");
            cin.clear();
            string dummy;
            getline(cin, dummy);
            cout << "잘못된 입력입니다." << endl;
            continue;
        }
    }
}

//--- 처치한 몬스터 출력
void GameManager::displayLog(Character* player)
{
    cout << "\n    내준 과제\n";
    cout << "-----------------\n\n";
    for (auto it : player->getKillLog())
    {
        cout << it.first << " : " << it.second << "개\n";
    }
    cout << "\n-----------------\n" << endl;
}

//--- 닉네임 생성
void GameManager::ifnVoidName(Character* player, string name)
{
    cout << "이름을 정해주세요." << endl;
    getline(cin, name);
    player->setName(name);

    if (player->getName() == "")
    {
        cout << "이름은 공백이 될 수 없습니다." << endl;
        cout << "다시 입력해주세요." << endl;
        system("pause");
        system("cls");
        return ifnVoidName(player, name);
    }

    return;
}

//--- 인트로
void GameManager::intro()
{
    int r = rand() % 7;
    if (r == 0) { system("color 09"); }
    else if (r == 1) { system("color 0A"); }
    else if (r == 2) { system("color 0B"); }
    else if (r == 3) { system("color 0C"); }
    else if (r == 4) { system("color 0D"); }
    else if (r == 5) { system("color 0E"); }
    else { system("color 0F"); }

    cout << "\n      _      ______      ____       ______      _____       ______      __     " << endl;
    cout << "    /' \\    /\\__  _\\    /\\  _`\\    /\\__  _\\    /\\  __`\\    /\\__  _\\   /'__`\\ " << endl;
    cout << "   /\\_, \\   \\/_/\\ \\/    \\ \\ \\/\\ \\  \\/_/\\ \\/    \\ \\ \\/\\ \\   \\/_/\\ \\/  /\\_\\L\\ \\ " << endl;
    cout << "   \\/_/\\ \\     \\ \\ \\     \\ \\ \\ \\ \\    \\ \\ \\     \\ \\ \\ \\ \\     \\ \\ \\  \\/_/_\\_<_" << endl;
    cout << "      \\ \\ \\     \\_\\ \\__   \\ \\ \\_\\ \\    \\_\\ \\__   \\ \\ \\_\\ \\     \\ \\ \\   /\\ \\L\\ \\ " << endl;
    cout << "       \\ \\_\\    /\\_____\\   \\ \\____/    /\\_____\\   \\ \\_____\\     \\ \\_\\  \\ \\____/" << endl;
    cout << "        \\/_/    \\/_____/    \\/___/     \\/_____/    \\/_____/      \\/_/   \\/___/" << endl;
    cout << "\n                           튜터의 모험 : 야근 방어전 \n" << endl;
    system("pause");
    system("color 07");
    system("cls");
}

//--- 보스 출현 대사
void GameManager::bossAppears()
{
    system("color 0c");
    std::cout << " ____                               __      __     " << std::endl;
    std::cout << "/\\  _`\\                            /\\ \\    /\\ \\    " << std::endl;
    std::cout << "\\ \\ \\L\\ \\    ___     ____    ____  \\ \\ \\   \\ \\ \\   " << std::endl;
    std::cout << " \\ \\  _ <'  / __`\\  /',__\\  /',__\\  \\ \\ \\   \\ \\ \\  " << std::endl;
    std::cout << "  \\ \\ \\L\\ \\/\\ \\L\\ \\/\\__, `\\/\\__, `\\  \\ \\_\\   \\ \\_\\ " << std::endl;
    std::cout << "   \\ \\____/\\ \\____/\\/\\____/\\/\\____/   \\/\\_\\   \\/\\_\\" << std::endl;
    std::cout << "    \\/___/  \\/___/  \\/___/  \\/___/     \\/_/    \\/_/" << std::endl;
    std::cout << "                                                   " << std::endl;
    std::cout << "                                                   " << std::endl;
    Sleep(1500); // 1500ms // 1.5초
}

//--- 엔딩 // 수정 요망
void GameManager::ending()
{
    system("cls");
    std::cout << " ____                 __      __      __      " << std::endl;
    std::cout << "/\\  _`\\              /\\ \\    /\\ \\    /\\ \\    " << std::endl;
    std::cout << "\\ \\ \\L       ___     \\_\\ \\   \\ \\ \\   \\ \\ \\   " << std::endl;
    std::cout << " \\ \\  _\\   /' _ `\\   /'_` \\   \\ \\ \\   \\ \\ \\  " << std::endl;
    std::cout << "  \\ \\ \\__  /\\ \\/\\ \\ /\\ \\L\\ \\   \\ \\_\\   \\ \\_\\ " << std::endl;
    std::cout << "   \\ \\____/\\ \\_\\ \\_\\\\ \\___,_\\   \\/\\_\\   \\/\\_\\" << std::endl;
    std::cout << "    \\/___/  \\/_/\\/_/ \\/__,_ /    \\/_/    \\/_/" << std::endl;
    Sleep(3000);
    system("cls");
    cout << "- special thanks -\n" << endl;
    Sleep(1000);
    cout << " 김어진 매니저님" << endl;
    Sleep(500);
    cout << " 양주영 매니저님" << endl;
    Sleep(500);
    cout << " 손주연 매니저님" << endl;
    Sleep(500);
    cout << " 이지원 매니저님" << endl;
    Sleep(500);
    cout << "\n";
    cout << " 강창민 튜터님" << endl;
    Sleep(500);
    cout << " 서화성 튜터님" << endl;
    Sleep(500);
    cout << " 최민성 튜터님" << endl;
    Sleep(500);
    cout << " 조호영 튜터님" << endl;
    Sleep(500);
    cout << " 박정식 튜터님" << endl;
    Sleep(500);
    cout << " 박경호 튜터님" << endl;
    Sleep(500);
    cout << " 정영훈 튜터님" << endl;
    Sleep(500);
    cout << " 한창욱 튜터님" << endl;
    Sleep(500);
    cout << " 이  삭 튜터님" << endl;
    Sleep(4000);
    system("cls");
    system("color 0e");
    cout << "게임을 플레이 해 주셔서 감사합니다!\n" << endl;
    cout << "\n- 내배캠 Unreal 13조 -\n" << endl;
    cout << "   김지원   전형준\n" << endl;
    cout << "   김성빈   성준모\n" << endl;
    cout << "   장재근   최선호\n" << endl;
    cout << "\n\n\n\n\n\n\n\n" << endl;
    
}