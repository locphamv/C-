#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ================= Base Class =================
class Character
{
  protected:
    string name;
    int hp;
    int attackPower;

  public:
    Character(string name, int hp, int attackPower) : name(name), hp(hp), attackPower(attackPower)
    {
    }

    virtual ~Character()
    {
    }

    string getName() const
    {
        return this->name;
    }

    int getHp() const
    {
        return this->hp;
    }

    bool isAlive() const
    {
        return this->hp > 0;
    }

    void takeDamage(int damage)
    {
        // TODO:
        // subtract damage from hp
        // hp should not go below 0
        this->hp -= damage;
        if (this->hp < 0)
        {
            this->hp = 0;
        }
    }

    void showStatus() const
    {
        // TODO:
        // print name and current hp
        // Example: Warrior John - HP: 80
        cout << this->name << " - " << "HP: " << this->hp << endl;
    }

    // Pure virtual function
    virtual void attack(Character *target) = 0;
};

// ================= Derived Class: Warrior =================
class Warrior : public Character
{
  public:
    Warrior(string name) : Character(name, 120, 20)
    {
    }

    void attack(Character *target) override
    {
        // TODO:
        // Print attack message
        // Deal normal attackPower damage to target
        if (!isAlive())
        {
            cout << name << " cannot attack because they are defeated.\n";
            return;
        }
        if (!target->isAlive())
        {
            cout << target->getName() << " is already defeated.\n";
            return;
        }
        cout << name << " attacks " << target->getName() << "!\n";
        int dmg = this->attackPower;
        target->takeDamage(dmg);
    }
};

// ================= Derived Class: Mage =================
class Mage : public Character
{
  public:
    Mage(string name) : Character(name, 80, 15)
    {
    }

    void attack(Character *target) override
    {
        // TODO:
        // Mage deals attackPower + 10 magic damage
        // Print attack message
        // Deal damage to target
        if (!isAlive())
        {
            cout << name << " cannot attack because they are defeated.\n";
            return;
        }
        if (!target->isAlive())
        {
            cout << target->getName() << " is already defeated.\n";
            return;
        }
        cout << name << " casts a spell on " << target->getName() << "!\n";
        int dmg = this->attackPower + 10;
        target->takeDamage(dmg);
    }
};

// ================= Derived Class: Archer =================
class Archer : public Character
{
  public:
    Archer(string name) : Character(name, 100, 18)
    {
    }

    void attack(Character *target) override
    {
        // TODO:
        // Archer has 30% chance to deal double damage
        // Use rand() % 100
        // If random number is less than 30, critical hit
        // Otherwise normal attack
        if (!isAlive())
        {
            cout << name << " cannot attack because they are defeated.\n";
            return;
        }
        if (!target->isAlive())
        {
            cout << target->getName() << " is already defeated.\n";
            return;
        }
        int x = rand() % 100;
        int dmg = this->attackPower;
        if (x < 30)
        {
            dmg *= 2;
            cout << name << " shoots a critical arrow at " << target->getName() << "!\n";
        }
        else
        {
            cout << name << " shoots an arrow at " << target->getName() << "!\n";
        }
        target->takeDamage(dmg);
    }
};

// ================= Main Function =================
int main()
{
    srand(time(0));

    vector<Character *> characters;

    characters.push_back(new Warrior("Arthur"));
    characters.push_back(new Mage("Merlin"));
    characters.push_back(new Archer("Robin"));

    cout << "===== Initial Status =====" << endl;
    for (Character *c : characters)
    {
        c->showStatus();
    }

    cout << "\n===== Battle Start =====" << endl;

    // Round 1
    characters[0]->attack(characters[1]); // Warrior attacks Mage
    characters[1]->attack(characters[2]); // Mage attacks Archer
    characters[2]->attack(characters[0]); // Archer attacks Warrior

    cout << "\n===== Status After Round 1 =====" << endl;
    for (Character *c : characters)
    {
        c->showStatus();
    }

    // TODO:
    // Add one more round of attacks by yourself

    // Round 2
    characters[0]->attack(characters[2]);
    characters[1]->attack(characters[0]);
    characters[2]->attack(characters[1]);

    cout << "\n===== Status After Round 2 =====" << endl;
    for (Character *c : characters)
    {
        c->showStatus();
    }

    cout << "\n===== Final Status =====" << endl;
    for (Character *c : characters)
    {
        c->showStatus();
    }

    // TODO:
    // Free memory using delete
    for (auto c : characters)
    {
        delete c;
    }
    return 0;
}