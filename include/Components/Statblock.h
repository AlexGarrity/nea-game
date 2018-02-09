#ifndef STATBLOCK_H
#define STATBLOCK_H

#include <Maths.h>

class Vitals
{

protected:
    float health, maxHealth;
    float stamina, maxStamina;
    float magic, maxMagic;

public:
    Vitals (float h, float s, float m, float mH, float mS, float mM);
    Vitals (const Vitals &v);
    Vitals ();

    void ApplyDamage (float x, unsigned char t);
    void SetVitals (float x, unsigned char t, bool r);
    void Kill();
    //void
};

struct Stat
{
public:
    float experience;
    unsigned char level;

    Stat (float x, unsigned char l)
    {
        experience = x;
        level = l;
    }
};

class Stats
{
protected:
    Stat statSword {0,1};
    Stat statHammer {0,1};
    Stat statAxe {0,1};
    Stat statBow {0,1};
    Stat statMagic {0,1};

    virtual Stat* GetStats (unsigned char s);

public:
    virtual void SetLevel (unsigned char s, unsigned char l);
    virtual unsigned char GetLevel (unsigned char s);

    virtual unsigned char CalculateLevel (bool combatLevel = true);

    Stats (Stat stats[5]);
    Stats (Stat sword, Stat axe, Stat hammer, Stat bow, Stat magic);
    Stats (const Stats &s);
    Stats ();
};

class PlayerStats : public Stats
{
private:
    Stat statBlacksmith {0, 1};
    Stat statTailor {0, 1};
    Stat statSpellcraft {0, 1};
    Stat statMining {0, 1};
    Stat statLumberjack {0, 1};

    Stat* GetStats (unsigned char s);

public:
    PlayerStats (Stat stats[5], Stat playerStats[5]);
    bool ApplyExperience (unsigned char s, float x, bool l);
    void SetLevel (unsigned char s, unsigned char l);
    float NextLevel (unsigned char s);
    float NextLevel (Stat *s);
    float GetExperience (unsigned char s);
    float GetExperience (Stat *s);
    unsigned char GetLevel (unsigned char s);
    unsigned char GetLevel (Stat *s);

    unsigned char CalculateLevel (bool combatLevel);
};

#endif // STATBLOCK_H
