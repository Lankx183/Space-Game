#include "splashkit.h"
#include "planet_play.h"
using namespace std;


bitmap planet_bitmap(planet_kind kind)
{
    switch(kind)
    {
        case MERCURY : return bitmap_named("mercury");
        case VENUS:return bitmap_named("venus");
        case EARTH:return bitmap_named("earth");
        case MARS:return bitmap_named("mars");
        case JUPITER:return bitmap_named("jupiter");
        case SATURN:return bitmap_named("saturn");
        case URANUS:return bitmap_named("uranus");
        case NEPTUNE:return bitmap_named("neptune");
        case PLUTO:return bitmap_named("pluto");
    }
}



planet_kind random_planet_kind()
{
    return static_cast<planet_kind>( rnd(9));
}

void draw_planet(const planet_data &planet)
{
    bitmap to_draw;
    to_draw = planet_bitmap(planet.kind);
    draw_bitmap(to_draw, planet.x, planet.y);
}

planet_data new_planet()
{
    planet_data result;
    result.x =  screen_width() + rnd(200);
    result.y = rnd(screen_height()) - 150;
    result.kind =  random_planet_kind();
    return result;
}

void update_planet(planet_data &the_planet)
{
    the_planet.x = the_planet.x - PLANET_SPEED;
    if(the_planet.x < 0 - bitmap_width(planet_bitmap(the_planet.kind)))
    {
        the_planet = new_planet();
    }
}