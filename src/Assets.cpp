#include "Assets.hpp"


namespace Assets{

    using namespace Lang;

    Image actorPerson;
    Image actorDog;
    Image actorDragon;

    Image bgMountains;

    Image skillBg;
    Image skillLockedBg;
    Image skillConnectV;
    Image skillConnectLockedV;
    Image skillConnectFS;
    Image skillConnectLockedFS;
    Image skillConnectBS;
    Image skillConnectLockedBS;

    Image skillPerson;
    Image skillHeart;
    Image skillArrow;
    Image skillLightning;
    Image skillShield;
    Image skillFire;
    Image skillIce;
    Image skillBow;
    Image skillSword;

    void makeAssets(){

        actorPerson = Image(3, 3, 
            " o "
            "/|\\"
            "/ \\"
        );

        actorDog = Image(6, 2, 
            ".o,-,'"
            " /\\/\\ "
        );

        actorDragon = Image(20, 12, 
            "  _,-,,   --.       "
            ".'+ _ \\,   -.\\      "
            "'--' ) \\,  \\\\\\\\\\    "
            "     /  )   // \\\\\\  "
            "    /  /___//\\\\\\ \\\\ "
            "    \\       /\\\\\\\\\\\\ "
            "     \\,  ,  \\ \\\\ \\\\\\"
            "      | / \\  \\  \\\\\\\\"
            "      | |  \\ \\\\  \\ \\"
            "     / /   /-/\\\\,_  "
            "   =/_/  =/_/  \"\"\"\";"
            "            ___,-\"\" "
        );


        bgMountains = Image(80, 16,
            "                                                                                "
            "                                                                                "
            "                                                            ________            "
            "           _____                                           (________)           "
            "         _(     )___                      ___                                   "
            "        (___________)                  __(   )_                                 "
            "                                      (________)                   ______       "
            "               _____                                              (______)      "
            "      /\\      (_____)         /\\            /\\                                  "
            "     // \\              /\\    // \\    /\\    // \\            /\\    /\\             "
            "    //   \\    /\\  /\\  // \\  //   \\  // \\  //   \\    /\\    // \\  // \\            "
            "   //     \\  // \\// \\//   \\//     \\//   \\//     \\  // \\  //   \\//   \\      /\\   "
            "  //       \\//  //   \\    //      //     \\       \\//   \\//    //     \\  /\\// \\  "
            " //         \\  //     \\  //      //       \\      //     \\    //       \\////   \\ "
            "//           \\//       \\//      //         \\    //       \\  //         \\//     \\"
            "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
        );


        skillBg = Image(9, 5,
            "  _____  "
            " /     \\ "
            "/       \\"
            "\\       /"
            " \\_____/"
        );

        skillLockedBg = Image(9, 5,
            "   _ _   "
            " /     \\ "
            ".       ."
            "'       '"
            " \\ _ _ /"
        );

        skillConnectV = Image(9, 4,
            "    |    "
            "    |    "
            "    |    "
            "    |    "
        );

        skillConnectLockedV = Image(9, 4,
            "    .    "
            "    .    "
            "    .    "
            "    .    "
        );

        skillConnectFS = Image(9, 4,
            "         "
            "    _.-' "
            " .-'     "
            "         "
        );

        skillConnectLockedFS = Image(9, 4,
            "         "
            "     . ' "
            " . '     "
            "         "
        );

        skillConnectBS = Image(9, 4,
            "         "
            " '-._    "
            "     '-. "
            "         "
        );

        skillConnectLockedBS = Image(9, 4,
            "         "
            " ' .     "
            "     ' . "
            "         "
        );

        skillPerson = Image(7, 4,
            "   o   "
            "  /|\\  "
            "  / \\  "
            "       "
        );

        skillHeart = Image(7, 4,
            "  _ _  "
            " ( ' )  "
            "  \\_/  "
            "       "
        );

        skillArrow = Image(7, 4,
            "       "
            "  \\\\\\  "
            "  ///  "
            "       "
        );

        skillLightning = Image(7, 4,
            "   \\   "
            "  _.\\  "
            "  \\'   "
            "   \\   "
        );

        skillShield = Image(7, 4,
            "  ___  "
            " | + | "
            "  \\_/  "
            "       "
        );

        skillFire = Image(7, 4,
            "   .   "
            " .( '  "
            "(  ) ) "
            " )()(  "
        );

        skillIce = Image(7, 4,
            "  /\\   "
            "  \\/ ^ "
            " ^ /\\  "
            "   \\/  "
        );

        skillBow = Image(7, 4,
            "  |\\   "
            "  | |  "
            "  | |  "
            "  |/   "
        );

        skillSword = Image(7, 4,
            "    /  "
            "   /   "
            " \\/_   "
            " /     "
        );

    }

};