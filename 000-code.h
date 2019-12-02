#include "splashkit.h"
#include <vector>
using namespace std;
#define PLAYER_SPEED 7.0
#define PLANET_SPEED 5.0;


enum ship_kind
{
    AQUARII,
    GLIESE,
    PEGASI
};

enum planet_kind
{
    MERCURY,
    VENUS,
    EARTH,
    MARS,
    JUPITER,
    SATURN,
    URANUS,
    NEPTUNE,
    PLUTO
};

struct planet_data
{
    planet_kind kind;
    double x;
    double y;
};

struct player_data
{
    ship_kind kind;
    double x;
    double y;
};
struct coin_data
{
    animation coin_animation;
    double x;
    double y;
};

struct space_game_data
{
    player_data player;
    vector<coin_data> coins;
    vector<planet_data> planets;
    int score;

};



planet_data new_planet();
void draw_planet(const planet_data &planet);
void update_planet(planet_data &planet);
bitmap planet_bitmap(planet_kind kind);

player_data new_player();
void draw_player(const player_data &player_to_draw);
bool player_hit_coin(const player_data &player , const coin_data &coin);
void handle_input(player_data &player);
bool player_hit_planet(const player_data &player ,  const planet_data &planet);


coin_data new_coin(double x , double y);
coin_data new_coin();
void draw_coin(const coin_data &coin);
void update_coin(coin_data &coin);
bool planet_hit_coin(const planet_data &planet , const coin_data &coin);

space_game_data new_game();
void draw_game(const space_game_data &game);
void update_game(space_game_data &game);
void add_random_coin(space_game_data &game);
void add_random_planet(space_game_data &game);
