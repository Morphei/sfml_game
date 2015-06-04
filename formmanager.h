#ifndef FORMMANAGER_H
#define FORMMANAGER_H

#include "gamestates.h"
#include "form.h"
#include "parser.h"

class FormManager
{
public:
    FormManager();

    Form createForm(Forms::ID id, sf::Vector2f position);

    void setParser(Parser* parser);

private:

    Parser* menuParser;
};

#endif // FORMMANAGER_H
