#ifndef GAMESTATES_H
#define GAMESTATES_H

namespace States{
    enum ID{
        Intro,
        Menu,
        Game,
        Close
    };
}

namespace Forms {

    enum ID{
        Register,
        Login
    };

    enum Components{
        TextBox,
        Label
    };

}

extern States::ID gameState;

namespace EntityState{

    enum stateOfObject{
        Normal,
        Run,
        Attack
    };

    enum direction{
            UpLeftDown,
            UpLeft,
            UpLeftUp,
            Up,
            UpRightUp,
            UpRight,
            UpRightDown,
            Right,
            DownRightUp,
            DownRight,
            DownRightDown,
            Down,
            DownLeftDown,
            DownLeft,
            DownLeftUp,
            Left
    };

    enum typeOfEntity{
        Amazon,
        Paladin,
        Sorcerer,
        EagleRat
    };

    struct statsOfEntity{
        int health;
        int manaPoints;
        int expirience;
        int attack;
        int defence;
    };

}
#endif // GAMESTATES_H
