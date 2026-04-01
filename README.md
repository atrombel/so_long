*This project has been created as part of the 42 curriculum by atrombel*

Description
-----------------------------
This project is a small 2D game.
Its purpose is to have you work with textures, sprites,
and other basic gameplay elements.
so_long is a project that challenges you to create a small 2D game where a player navigates through a map,
collects items (like coins or fuel), and reaches an exit point.
It’s a fantastic way to learn about graphics programming, event handling, and game logic

Instructions
-----------------------------
need cc and make

To play, first compile the project with make:
$ make
run ./so_long followed by the map:
$ ./so_long [MAP_PATH]/[MAP_FILE.ber]
expl :
$ ./so_long maps/level1.ber

You can parse any kind of map, as long as it respects the below rules:
The map must be a .ber file.
And can only contain these characters:
1	Wall
C	Coin
E	Exit
P	Player
0	Floor
The map must be rectangular and surrounded by walls '1'.
The map must contain at least one exit, one collectible, and one starting position.
Check some examples in the folder ./maps.
As in maps/level1.ber

Use WASD or arrow keys to move.
W 	Move up
A 	Move left
S  	Move down
D  	Move para right
Esc Close the game


After getting all the coin bags, the exit opens and you can escape trough the door.
You can close the game by Clicking on the red cross on the window’s frame, or pressing Esc.

Resources
-----------------------------
https://stackoverflow.com/questions/38418114/why-is-stack-chk-fail-happening-in-my-code
https://www.youtube.com/watch?v=spopCHE-kFc
https://www.geeksforgeeks.org/operating-systems/difference-between-shell-and-kernel/
https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
https://askubuntu.com/questions/226918/undefined-reference-to-xshmqueryversion
https://stackoverflow.com/questions/2975304/undefined-reference-to-xopendisplay-in-a-qt-project
https://www.youtube.com/watch?v=bYS93r6U0zg
https://fr.wikipedia.org/wiki/X_Window_System
https://www.x.org/archive/X11R7.5/doc/man/man3/XOpenDisplay.3.html
https://www.youtube.com/watch?v=s2mPA38JNcI
https://github.com/augustobecker/so_long_tester
https://en.wikipedia.org/wiki/Semicolon
ai was used as a teacher
discord 42 channel so_long
https://medium.com/@digitalpoolng/42-so-long-and-thanks-for-all-the-fish-building-your-first-2d-game-in-c-ccd24034bc8b
https://stackoverflow.com/questions/18326197/undefine-reference-for-libraries-so-how-could-i-find-the-right-path
https://github.com/augustobecker/so_long_tester
https://github.com/42paris/minilibx-linux/blob/master/man/man1/mlx_loop.1
https://tronche.com/gui/x/xlib/events/
https://stackoverflow.com/questions/73052301/whats-the-need-for-event-masks-in-x11
https://qst0.github.io/ft_libgfx/man_mlx_loop.html
https://gontjarow.github.io/MiniLibX/mlx-tutorial-create-image.html
https://stackoverflow.com/questions/10792361/how-do-i-gracefully-exit-an-x11-event-loop

amazing art by
-------------
https://shikashipx.itch.io/shikashis-fantasy-icons-pack
https://cainos.itch.io/pixel-art-top-down-basic0
https://xzany.itch.io/free-knight-2d-pixel-art
