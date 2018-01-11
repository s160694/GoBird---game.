#include <allegro5/allegro_font.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <stdlib.h>

int szer=700, wys=400, rozm=35;
int main()
{
    al_init();
    al_install_keyboard();
    al_init_font_addon();
    al_init_image_addon();

    ALLEGRO_KEYBOARD_STATE klawiatura;
    al_get_keyboard_state(&klawiatura);

    ALLEGRO_DISPLAY * okno = al_create_display(szer, wys);

    al_clear_to_color(al_map_rgb(0, 255, 255));
    al_set_window_title(okno, "GoBird");

    ALLEGRO_BITMAP * ptaszek = al_load_bitmap("ptaszek.png");
    ALLEGRO_BITMAP * kol = al_load_bitmap("kol1.png");
    ALLEGRO_BITMAP * kol2 = al_load_bitmap("kol2.png");
    ALLEGRO_BITMAP * kol3 = al_load_bitmap("kol3.png");
    ALLEGRO_BITMAP * kol4 = al_load_bitmap("kol4.png");
    ALLEGRO_BITMAP * menu = al_load_bitmap("menu.png");
    ALLEGRO_BITMAP * howToPlay = al_load_bitmap("howToPlay.png");


    ALLEGRO_FONT * font8 = al_create_builtin_font();

    int ptakx = 50;
    int ptaky = 50;

    double kolx = 900;
    double kolx2 = 700;
    double kolx3 = 500;
    double kolx4 = 300;

    double przyspieszenie = 0;
    double score = 0;

    double czas = al_get_time();

    bool kol1Change = false;
    bool kol2Change = false;
    bool kol3Change = false;
    bool kol4Change = false;
    ALLEGRO_BITMAP * render1;
    ALLEGRO_BITMAP * render2;
    ALLEGRO_BITMAP * render3;
    ALLEGRO_BITMAP * render4;

    int userInterface = 0;

    while (1)
    {
        al_get_keyboard_state(&klawiatura);
        switch ( userInterface)
        {
        case 0:

            al_draw_bitmap(menu, 0, 0, 0);
            al_flip_display();

            while ((!al_key_down(&klawiatura, ALLEGRO_KEY_1)) && (!al_key_down(&klawiatura, ALLEGRO_KEY_2)) && (!al_key_down(&klawiatura, ALLEGRO_KEY_3)))
            {
                al_get_keyboard_state(&klawiatura);
            }

            if (al_key_down(&klawiatura, ALLEGRO_KEY_1))
            {
                userInterface = 1;
            }

            if (al_key_down(&klawiatura, ALLEGRO_KEY_2))
            {
                userInterface = 2;
            }

            if (al_key_down(&klawiatura, ALLEGRO_KEY_3))
            {
                userInterface = 3;
            }
            break;
        case 1:

            while(!al_key_down(&klawiatura, ALLEGRO_KEY_ESCAPE))
            {
        al_get_keyboard_state(&klawiatura);


        if (al_get_time() > czas + 0.01)
        {
            if (ptaky < wys - rozm) ptaky = ptaky + 2;
            if (al_key_down(&klawiatura, ALLEGRO_KEY_SPACE) && ptaky > 0) ptaky = ptaky - 8;
            if (1)
            {
                kolx = kolx -1.5 - przyspieszenie;
                kolx2 = kolx2 -1.5 - przyspieszenie;
                kolx3 = kolx3 -1.5 - przyspieszenie;
                kolx4 = kolx4 -1.5 - przyspieszenie;
                przyspieszenie = przyspieszenie + 0.0005;

                if (((kolx4 >= 50 && kolx4 <= 100) || (kolx4 >= -20 && kolx4 <= 30)) && ptaky  <= 143)
                {
                    al_destroy_display(okno);
                }
                else if (((kolx4 >= 50 && kolx4 <= 100) || (kolx4 >= -20 && kolx4 <= 30)) && ptaky  >= 261)
                {
                    al_destroy_display(okno);
                }

                if (((kolx3 >= 50 && kolx3 <= 100) || (kolx3 >= -20 && kolx3 <= 30)) && ptaky  <= 84)
                {
                    al_destroy_display(okno);
                }
                else if (((kolx3 >= 50 && kolx3 <= 100) || (kolx3 >= -20 && kolx3 <= 30)) && ptaky  >= 223)
                {
                    al_destroy_display(okno);
                }

                if (((kolx2 >= 50 && kolx2 <= 100) || (kolx2 >= -20 && kolx2 <= 30)) && ptaky  <= 173)
                {
                    al_destroy_display(okno);
                }
                else if (((kolx2 >= 50 && kolx2 <= 100) || (kolx2 >= -20 && kolx2 <= 30)) && ptaky  >= 313)
                {
                    al_destroy_display(okno);
                }

                if (((kolx >= 50 && kolx <= 100) || (kolx >= -20 && kolx <= 30)) && ptaky  <= 115)
                {
                    al_destroy_display(okno);
                }
                else if (((kolx >= 50 && kolx <= 100) || (kolx >= -20 && kolx <= 30)) && ptaky  >= 252)
                {
                    al_destroy_display(okno);
                }
            }

            czas = al_get_time();
        }

        al_clear_to_color(al_map_rgb_f(0.0, 1.0, 1.0));
        al_draw_bitmap(ptaszek, ptakx, ptaky, 0);

        ALLEGRO_BITMAP * container;

        if (kol1Change == false)
        {
            al_draw_bitmap(kol, kolx, 0, 0);
        }
        if (kol2Change == false)
        {
            al_draw_bitmap(kol2, kolx2, 0, 0);
        }
        if (kol3Change == false)
        {
            al_draw_bitmap(kol3, kolx3, 0, 0);
        }
        if (kol4Change == false)
        {
            al_draw_bitmap(kol4, kolx4, 0, 0);
        }

        if (kol1Change == true)
        {
            al_draw_bitmap(render1, kolx, 0, 0);
        }
        if (kol2Change == true)
        {
            al_draw_bitmap(render2, kolx2, 0, 0);
        }
        if (kol3Change == true)
        {
            al_draw_bitmap(render3, kolx3, 0, 0);
        }
        if (kol4Change == true)
        {
            al_draw_bitmap(render4, kolx4, 0, 0);
        }

        score = al_get_time() * 3 + 0.1 * al_get_time();
        al_draw_textf(font8, al_map_rgb(0, 0, 0), 600, 10, 0, "Score = %0.0f", score);

        al_flip_display();
        al_rest(0.001);

        int randomNumber = rand() % 4;

        if (randomNumber == 0)
        {
            container = kol;
        }
        else if (randomNumber == 1)
        {
            container = kol2;
        }
        else if (randomNumber == 2)
        {
            container = kol3;
        }
        else if (randomNumber == 3)
        {
            container = kol4;
        }


        if (kolx <= -90 )
        {
            render1 = container;
            kolx = 800;
            kol1Change = true;
        }
        if (kolx2 <= -90 )
        {
            render2 = container;
            kolx2 = 800;
            kol2Change = true;
        }
        if (kolx3 <= -90 )
        {
            render3 = container;
            kolx3 = 800;
            kol3Change = true;
        }
        if (kolx4 <= -90 )
        {
            render4 = container;
            kolx4 = 800;
            kol4Change = true;
        }



    }
            break;

        case 2:
            al_draw_bitmap(howToPlay, 0, 0, 0);
            al_flip_display();

            while ((!al_key_down(&klawiatura, ALLEGRO_KEY_ESCAPE)))
            {
                al_get_keyboard_state(&klawiatura);
            }

            if (al_key_down(&klawiatura, ALLEGRO_KEY_ESCAPE))
            {
                userInterface = 0;
            }
            break;

        case 3:
            al_destroy_bitmap(menu);
            al_destroy_display(okno);
            return 0;
        }

   }

    al_destroy_bitmap(ptaszek);
    al_destroy_bitmap(kol3);
    al_destroy_bitmap(kol2);
    al_destroy_bitmap(kol);
    al_destroy_bitmap(kol4);
    al_destroy_display(okno);

    return 0;

}
