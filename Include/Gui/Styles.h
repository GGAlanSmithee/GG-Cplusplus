#ifndef GUI_STYLES_H_INCLUDED
#define GUI_STYLES_H_INCLUDED

#include <string>
#include <unordered_map>

enum class GG_GUI_Style
{
    None,
    Inherited,
    Relative,
    Absolute
};

const std::string GG_GUI_Style_Position = "position";
const std::string GG_GUI_Style_Width = "width";
const std::string GG_GUI_Style_Height = "height";

class GG_GUI_Styles
{
    public:
        GG_GUI_Styles();
        GG_GUI_Styles(GG_GUI_Style const, GG_GUI_Style const, GG_GUI_Style const);

    private:
        std::unordered_map<std::string, GG_GUI_Style> styles;
};

#endif // GUI_STYLES_H_INCLUDED
