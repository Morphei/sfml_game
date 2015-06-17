#ifndef GAMESTATES_H
#define GAMESTATES_H

namespace NetworkCommands{
        enum ID {
                Login,
                ListOfUsers,
                Register,
                NewChar,
                SendChoosenChar,
                DeleteChar,
                InGame,
                AddEnemy,
                MouseClick,
                ExitGame,
                Attack,
                SetStats
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
        ChooseCharacters,
        CreateNewChar
    };

    enum Components{
        TextBox,
        Label
    };

    enum buttonID{
        Login,
        Register,
        Settings,
        Exit,
        Play,
        New_Char,
        Delete_char,
        Cancel,
        CreateNew
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
        EagleRat,
        None
    };

    struct statsOfEntity{
            unsigned short hitPoints;
            unsigned short manaPoints;
            unsigned short attack;
            unsigned short attackSpeed;
            unsigned short defence;
    };

}
#endif // GAMESTATES_H
