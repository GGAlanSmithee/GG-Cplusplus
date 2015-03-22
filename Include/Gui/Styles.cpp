#include "Styles.h"

GG_GUI_Styles::GG_GUI_Styles() :
    GG_GUI_Styles(GG_GUI_Style::Relative, GG_GUI_Style::Relative, GG_GUI_Style::Relative)
{
    // Empty
}

GG_GUI_Styles::GG_GUI_Styles(GG_GUI_Style const positionStyle,
                             GG_GUI_Style const widthStyle,
                             GG_GUI_Style const heightStyle)
{
    styles[GG_GUI_Style_Position] = positionStyle;
    styles[GG_GUI_Style_Width] = widthStyle;
    styles[GG_GUI_Style_Height] = heightStyle;
}
