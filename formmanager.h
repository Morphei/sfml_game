#ifndef FORMMANAGER_H
#define FORMMANAGER_H

#include "gamestates.h"
#include "form.h"

class FormManager
{
public:
    FormManager();
    Form createForm(Forms::ID id, sf::Vector2f position);

private:

};

#endif // FORMMANAGER_H
