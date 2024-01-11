#include <iostream>

#define SIZE 5

#define EMPTY_FIELD '-'
#define DANGER_FIELD 'D'
#define WELL_FIELD 'W'
#define RELICT_FIELD 'R'

#define ERRORMESSAGE_WRONGMOVE "Invalid input, try again!\n"

//struct
typedef struct heroStats
{
    int heroX;
    int heroY;
    int healthPoints;
    int relictPoints;
} heroStats;

typedef struct gameBoard
{
    char world[SIZE][SIZE];
} gameBoard;

typedef struct enemyStats
{
    int enemyX;
    int enemyY;
} enemyStats;

typedef struct gameStats
{
    int hpLost;
    int hpRecovered;
    int tilesTravelled;
} gameStats;

//forward declarations
void printWorld(gameBoard* pMap, heroStats hero, enemyStats enemy);
void fillWorld(gameBoard* pMap, int* pRelictFields);
void startScreen();
void printStats(heroStats hero, int relictFields);
void checkField(gameBoard* pMap, heroStats* pHero, gameStats* pStats);
void enemyMovement(enemyStats* pEnemy);

//main
int main()
{
    srand((unsigned int)time(NULL));

    heroStats hero;
    gameBoard map;
    enemyStats enemy;
    gameStats stats;

    char dirInput;
    hero.heroX = 0;
    hero.heroY = 0;
    hero.healthPoints = 5;
    hero.relictPoints = 0;

    enemy.enemyX = 4;
    enemy.enemyY = 4;

    stats.hpLost = 0;
    stats.hpRecovered = 0;
    stats.tilesTravelled = 0;

    int relictFields = 0;
    int* pRelictFields = &relictFields;

    heroStats* pHero = &hero;
    gameBoard* pMap = &map;
    enemyStats* pEnemy = &enemy;
    gameStats* pStats = &stats;

    fillWorld(pMap, pRelictFields);
    startScreen();

    while (true) {
        system("CLS");
        printStats(hero, relictFields);
        printWorld(pMap, hero, enemy);

        char tempInput;

        std::cin >> dirInput;

        switch (dirInput)
        {
            case 'w':
            case 'W': 
                if (hero.heroY > 0) {
                    hero.heroY--;
                    stats.tilesTravelled++;
                }
                else {
                    std::cout << ERRORMESSAGE_WRONGMOVE;
                    std::cin >> tempInput;
                }
                    break;

            case 'a':
            case 'A': 
                if (hero.heroX > 0) {
                    hero.heroX--;
                    stats.tilesTravelled++;
                }
                else {
                    std::cout << ERRORMESSAGE_WRONGMOVE;
                    std::cin >> tempInput;
                }
                    break;

            case 's':
            case 'S': 
                if (hero.heroY < SIZE - 1) {
                    hero.heroY++;
                    stats.tilesTravelled++;
                }
                else {
                    std::cout << ERRORMESSAGE_WRONGMOVE;
                    std::cin >> tempInput;
                }
                    break;

            case 'd':
            case 'D': 
                if (hero.heroX < SIZE - 1) {
                    hero.heroX++;
                    stats.tilesTravelled++;
                }
                else {
                    std::cout << ERRORMESSAGE_WRONGMOVE;
                    std::cin >> tempInput;
                }
                    break;
        }

        checkField(pMap, pHero, pStats);

        map.world[hero.heroY][hero.heroX] = EMPTY_FIELD;

        if (hero.healthPoints <= 0) {
            std::cout << "Oh no, you died :(\n";

            break;
        }

        if (hero.relictPoints == relictFields) {
            std::cout << "You found all the relicts! :D\n";

            break;
        }

        enemyMovement(pEnemy);

        if (enemy.enemyY == hero.heroY && enemy.enemyX == hero.heroX)
        {
            std::cout << "The enemy killed you before you could collect all the relicts. :(\n Better luck next time!\n";
            std::cin >> tempInput;

            break;
        }
    }

    std::cout << "You lost " << stats.hpLost << " and recovered " << stats.hpRecovered << " HP while travelling " << stats.tilesTravelled << " tiles.\n";
    std::cout << "You also found " << hero.relictPoints << " out of the " << relictFields << " relicts scattered around the oasis!\n";
    std::cout << "Well done! :D\n";

    return 0;
}

//functions
void printStats(heroStats hero, int relictFields)
{
    std::cout << "HP: " << hero.healthPoints << "\n";
    std::cout << "Relicts found: " << hero.relictPoints << "/" << relictFields << "\n\n";
}

void printWorld(gameBoard* pMap, heroStats hero, enemyStats enemy)
{
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {

            if (x == hero.heroX && y == hero.heroY) {
                std::cout << "x";
            }
            else if (x == enemy.enemyX && y == enemy.enemyY) {
                std::cout << "E";
            }
            else {
                std::cout << pMap->world[y][x];
            }

        }
        std::cout << "\n";
    }
}

void fillWorld(gameBoard* pMap, int* pRelictFields)
{
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            int spawnrate = rand() % 10;

            if (spawnrate >= 0 && spawnrate < 4) {
                pMap->world[y][x] = EMPTY_FIELD;
            }

            if (spawnrate >= 4 && spawnrate < 8) {
                pMap->world[y][x] = DANGER_FIELD;
            }

            if (spawnrate == 8) {
                pMap->world[y][x] = WELL_FIELD;
            }

            if (spawnrate == 9) {
                pMap->world[y][x] = RELICT_FIELD;
                (*pRelictFields)++;
            }
        }

        std::cout << "\n";
    }

    if (*pRelictFields == 0) {
        int randX = rand() % 5;
        int randY = rand() % 5;

        pMap->world[randY][randX] = RELICT_FIELD;
    }
}

void startScreen()
{
    char input;

    std::cout << "OASIS CRAWLER\n\n";
    std::cout << "Press any button to start!\n";
    std::cout << "Press [esc] to end game!\n\n";

    std::cin >> input;
}

void checkField(gameBoard* pMap, heroStats* pHero, gameStats* pStats)
{
    char tempInput;

    if (pMap->world[pHero->heroY][pHero->heroX] == DANGER_FIELD)
    {
        int damageOdds = rand() % 6;

        if (damageOdds == 0)
        {
            std::cout << "You fell down!\n You lost 1HP!\n";

            (pHero->healthPoints)--;
            (pStats->hpLost)++;

            std::cin >> tempInput;
        }
    }

    if (pMap->world[pHero->heroY][pHero->heroX] == WELL_FIELD)
    {
        std::cout << "You found a well and decided to rest!\n You recovered 1HP!\n";

        (pHero->healthPoints)++;
        (pStats->hpRecovered)++;

        std::cin >> tempInput;
    }

    if (pMap->world[pHero->heroY][pHero->heroX] == RELICT_FIELD)
    {
        std::cout << "You found a relict!\n";

        (pHero->relictPoints)++;

        std::cin >> tempInput;
    }
    
}

void enemyMovement(enemyStats* pEnemy)
{
    int enemyMovements = rand() % 4;

    switch (enemyMovements)
    {
    case 0: //enemy moves one field to the right
        if (pEnemy->enemyX < SIZE - 1) {
            (pEnemy->enemyX)++;
        }
        else { //except for when they are at x-coord 4, then they move 1 to the left
            (pEnemy->enemyX)--;
        }
        break;

    case 1: //enemy moves one field to the left
        if (pEnemy->enemyX > 0) {
            (pEnemy->enemyX)--;
        }
        else { //except for when they are at x-coord 0, then they move 1 to the right
            (pEnemy->enemyX)++;
        }
        break;

    case 2: //enemy moves one field down
        if (pEnemy->enemyY < SIZE - 1) {
            (pEnemy->enemyY)++;
        }
        else { //except for when they are at y-coord 4, then they move 1 up
            (pEnemy->enemyY)--;
        }
        break;

    case 3: //enemy moves one field up
        if (pEnemy->enemyY > 0) {
            (pEnemy->enemyY)--;
        }
        else { //except for when they are at y-coord 0, then they move 1 down
            (pEnemy->enemyY)++;
        }
        break;
    }
}
