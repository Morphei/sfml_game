#ifndef RESOURCEHOLDER_HPP
#define RESOURCEHOLDER_HPP

#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>

const std::string path = "/home/morphei/resources/";//path to resource folder

namespace Textures {
        enum ID_InGame {
                            Landscape,
                            Amazon,
                            Paladin
                       };

        enum ID_InMenu {
                            Button,
                            ButtonPressed,
                            MenuBackground,
                            LoginForm,
                            LoginButton,
                            LoginButtonPressed,
                            RegisterForm,
                            RegisterButton,
                            RegisterButtonPressed,
                            ExitButton,
                            ExitButtonPressed,
                            CloseButton,
                            CloseButtonPressed,
                            TextBox,
                            ChooseForm
                       };
    }


namespace Fonts {
        enum ID_InGame {
                            MainFontGame
                       };

        enum ID_InMenu {
                            MainFontMenu
                       };
    }


namespace Sounds {
        enum ID_InGame {

                       };

        enum ID_InMenu {

                       };
    }
template <typename Resource, typename Identifier>
class ResourceHolder
{
    public:
        void						load(Identifier id, const std::string& filename);

        template <typename Parameter>
        void						load(Identifier id, const std::string& filename, const Parameter& secondParam);

        Resource&					get(Identifier id);
        const Resource&				get(Identifier id) const;


    private:
        void						insertResource(Identifier id, std::unique_ptr<Resource> resource);


    private:
        std::map<Identifier, std::unique_ptr<Resource>>	mResourceMap;
};

#include "resourceholder.inl"
#endif // BOOK_RESOURCEHOLDER_HPP
