#include <iostream>
#include <string>

void ShowStatus(int health)
{
    if (health <= 0)
    {
        std::cout << "Status: Dead\n";
    }
    else if (health <= 25)
    {
        std::cout << "Status: Critical\n";
    }
    else
    {
        std::cout << "Status: Alive\n";
    }
}

int ApplyDamage(int health, int damage)
{
    health = health - damage;
    
    if (health < 0)
    {
        health = 0;
    }

    return health;
}

bool CanCastSpell(int mana, int spellCost)
{
    return mana >= spellCost;
}

void ShowProfile(
    std::string name,
    int level,
    int health,
    int mana,
    int gold)
{
    std::cout << "\n=== Character Profile ===\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Level: " << level << "\n";
    std::cout << "Health: " << health << "\n";
    std::cout << "Mana: " << mana << "\n";
    std::cout << "Gold: " << gold << "\n";
}

int main()
{
    std::string playerName;
    int playerLevel;
    int playerHealth;
    int playerMana;
    int playerGold;
    int damage;
    int round = 1;

    std::cout << "Enter player name: ";
    std::cin >> playerName;

    std::cout << "Enter player level: ";
    std::cin >> playerLevel;

    std::cout << "Enter player health: ";
    std::cin >> playerHealth;

    std::cout << "Enter player mana: ";
    std::cin >> playerMana;

    std::cout << "Enter player gold: ";
    std::cin >> playerGold;

    int spellCost = 20;

    if (CanCastSpell(playerMana, spellCost))
    {
        std::cout << "\nMagic: Spell ready\n";
    }
    else
    {
        std::cout << "\nMagic: Not enough mana!\n";
    }

    std::cout << "\nBattle starts in:\n";

    for (int i = 3; i >= 1; i--)
    {
        std::cout << i << "\n";
    }

    std::cout << "Fight!\n";

    while (playerHealth > 0)
    {
        std::cout << "\n=== Round " << round << " ===\n";

        
        std::cout << "Enter damage: ";
        std::cin >> damage;
        while (damage <= 0)
        {
            std::cout << "Damage must be greater than 0. Enter again: ";
            std::cin >> damage;
        }

        playerHealth = ApplyDamage(playerHealth, damage);

        ShowStatus(playerHealth);
        
        std::cout << "Current health: " << playerHealth << "\n";

        round++;
    }

    ShowProfile(
        playerName,
        playerLevel,
        playerHealth,
        playerMana,
        playerGold
    );

    return 0;
}