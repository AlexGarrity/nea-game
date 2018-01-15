#ifndef GAMESTATE_H
#define GAMESTATE_H


class GameState {
public:
    virtual void Input() =0;
    virtual void Update() =0;
    virtual void Draw() =0;

protected:

private:
};

#endif // GAMESTATE_H
