#ifndef STATBLOCK_H
#define STATBLOCK_H

#include <Maths.h>

/**
        Vitals are a specific type of stats, encompassing everything that affects the character
        'physically'.  Health because without it they'd die, Magic because without it they can't
        do magic, and Stamina because without it they can barely last thirty seconds.  In a fight.
**/

class Vitals {

protected:
    float health, maxHealth;
    float stamina, maxStamina;
    float magic, maxMagic;

public:
    Vitals ( float h, float s, float m, float mH, float mS, float mM );
    Vitals ( const Vitals &v );
    Vitals ();

    void ApplyDamage ( float x, unsigned char t );
    void SetVitals ( float x, unsigned char t, bool r );
    void Kill();
    //void
};

struct Stat {
public:
    float experience = 0;
    unsigned char level = 1;

    Stat ( float x, unsigned char l )
    {
        experience = x;
        level = l;
    }
};

class Stats {
protected:
    Stat statSword {0, 1};
    Stat statHammer {0, 1};
    Stat statAxe {0, 1};
    Stat statBow {0, 1};
    Stat statMagic {0, 1};

    virtual Stat* GetStats ( unsigned char s );

public:
    virtual void SetLevel ( unsigned char s, unsigned char l );
    virtual unsigned char GetLevel ( unsigned char s );

    virtual unsigned char CalculateLevel ( bool combatLevel = true );

    Stats ( Stat *stats );
    Stats ( Stat sword, Stat axe, Stat hammer, Stat bow, Stat magic );
    Stats ( const Stats &s );
    Stats ();
    virtual ~Stats();
};

class PlayerStats : public Stats {
private:
    Stat statBlacksmith {0, 1};
    Stat statTailor {0, 1};
    Stat statSpellcraft {0, 1};
    Stat statMining {0, 1};
    Stat statLumberjack {0, 1};

    Stat* GetStats ( unsigned char s );

public:
    PlayerStats ( Stat *stats, Stat *playerStats );
    virtual ~PlayerStats ();

    bool ApplyExperience ( unsigned char s, float x, bool l );
    void SetLevel ( unsigned char s, unsigned char l );
    float NextLevel ( unsigned char s );
    float NextLevel ( Stat *s );
    float GetExperience ( unsigned char s );
    float GetExperience ( Stat *s );
    unsigned char GetLevel ( unsigned char s );
    unsigned char GetLevel ( Stat *s );

    unsigned char CalculateLevel ( bool combatLevel );
};

#endif // STATBLOCK_H
