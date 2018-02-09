#include "Statblock.h"

Vitals::Vitals (float h, float s, float m, float mH, float mS, float mM)
{
    health = h;
    maxHealth = mH;
    stamina = s;
    maxStamina = mS;
    magic = m;
    maxMagic = mM;
}

Vitals::Vitals (const Vitals &v)
{
    health = v.health;
    maxHealth = v.maxHealth;
    stamina = v.stamina;
    maxStamina = v.maxStamina;
    magic = v.magic;
    maxMagic = v.maxMagic;
}

Vitals::Vitals()
{

}

void Vitals::ApplyDamage (float x, unsigned char t)
{
    switch (t)
    {
    case 'h':
        health -= x;

        if (health > maxHealth)
            health = maxHealth;

        break;

    case 's':
        stamina -= x;

        if (stamina > maxStamina)
            stamina = maxStamina;

        break;

    case 'm':
        magic -= x;

        if (magic > maxMagic)
            magic = maxMagic;

        break;
    }
}

void Vitals::SetVitals (float x, unsigned char t, bool replenish)
{
    switch (t)
    {
    case 'h':
        maxHealth = x;

        if (replenish)
        {
            ApplyDamage (health - maxHealth, t);
        }

        break;

    case 's':
        maxStamina = x;

        if (replenish)
        {
            ApplyDamage (stamina - maxStamina, t);
        }

        break;

    case 'm':
        maxMagic = x;

        if (replenish)
        {
            ApplyDamage (magic - maxMagic, t);
        }

        break;
    }
}

void Vitals::Kill()
{
    ApplyDamage (health, 'h');  //Should just straight up kill it, but if in doubt, (I'll add something later...)
}


Stats::Stats() {

}

Stats::Stats(Stat sword, Stat axe, Stat hammer, Stat bow, Stat magic) {
    statSword = sword;
    statAxe = axe;
    statHammer = hammer;
    statBow = bow;
    statMagic = magic;
}

Stats::Stats (const Stats &s)
{
    statSword = s.statSword;
    statAxe = s.statAxe;
    statHammer = s.statHammer;
    statBow = s.statBow;
    statMagic = s.statMagic;
}

Stat* Stats::GetStats (unsigned char skill)
{
    switch (skill)
    {
    case 's':
        return &statSword;
        break;

    case 'h':
        return &statHammer;
        break;

    case 'a':
        return &statAxe;
        break;

    case 'b':
        return &statBow;
        break;

    case 'm':
        return &statMagic;
        break;
    }

    return nullptr;
}

void Stats::SetLevel (unsigned char skill, unsigned char level)
{
    GetStats (skill)->level = level;
}

unsigned char Stats::GetLevel (unsigned char skill)
{
    return GetStats (skill)->level;
}

unsigned char Stats::CalculateLevel (bool combatLevel)
{
    int *stats = new int[5] {statSword.level, statAxe.level, statHammer.level, statBow.level, statMagic.level};
    unsigned char greatest = Maths::Greatest (stats, 5);
    delete[] stats;
    return greatest;
}



Stat* PlayerStats::GetStats (unsigned char skill)
{
    switch (skill)
    {
    case 's':
        return &statSword;
        break;

    case 'h':
        return &statHammer;
        break;

    case 'a':
        return &statAxe;
        break;

    case 'b':
        return &statBow;
        break;

    case 'm':
        return &statMagic;
        break;

    case 'B':
        return &statBlacksmith;
        break;

    case 'T':
        return &statTailor;
        break;

    case 'S':
        return &statSpellcraft;
        break;

    case 'M':
        return &statMining;
        break;

    case 'L':
        return &statLumberjack;
        break;
    }

    return nullptr;
}

bool PlayerStats::ApplyExperience (unsigned char skill, float x, bool applyAsLevels)
{
    Stat *s = GetStats (skill);

    if (s != nullptr)
    {
        if (!applyAsLevels)
        {
            s->experience += x;

            if (s->experience / Maths::Pow (1.2f, s->level++) > 100)
            {
                s->level++;
                return true;
            }
        }
        else
        {
            s->experience = 100 * Maths::Pow (1.2f, (unsigned int) x);
            s->level = x;
            return true;
        }
    }

    return false;
}

void PlayerStats::SetLevel (unsigned char skill, unsigned char level)
{
    Stat *s = GetStats (skill);

    if (s != nullptr)
    {
        ApplyExperience (level - s->level, level, true);
    }
}

float PlayerStats::NextLevel (unsigned char skill)
{
    Stat *s = GetStats (skill);

    if (s != nullptr)
    {
        return NextLevel (s);
    }

    return -1;
}

float PlayerStats::NextLevel (Stat *s)
{
    return (100 * Maths::Pow (1.2f, s->level + 1) ) - GetExperience (s);
}

float PlayerStats::GetExperience (unsigned char skill)
{
    return GetStats (skill)->experience;
}

float PlayerStats::GetExperience (Stat *s)
{
    return s->experience;
}

unsigned char PlayerStats::GetLevel (unsigned char skill)
{
    return GetStats (skill)->level;
}

unsigned char PlayerStats::GetLevel (Stat *s)
{
    return s->level;
}

unsigned char PlayerStats::CalculateLevel (bool combatLevel)
{
    if (combatLevel)
    {
        return Stats::CalculateLevel();
    }
    else
    {
        int *values = new int[5] {statBlacksmith.level, statTailor.level, statMining.level, statLumberjack.level, statSpellcraft.level};
        unsigned char craftLevel = Maths::Mean (values, 5);
        delete[] values;
        return craftLevel;
    }
}
