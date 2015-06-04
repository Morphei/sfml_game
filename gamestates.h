#ifndef GAMESTATES_H
#define GAMESTATES_H
namespace NetworkCommands{
        enum ID {
                Login,
                ListOfUsers,
                Register
                };
    }

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
        RegisterForm,
        LoginForm,
        ChooseCharacters
    };

    enum Components{
        TextBox,
        Label
    };

    enum buttonID{
        Login,
        Register,
        Settings,
        Exit
    };

    enum textBoxID{
        LoginTextBox,
        PasswordTextBox
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
