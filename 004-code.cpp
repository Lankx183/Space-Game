#include "splashkit.h"
#include "planet_play.h"


bitmap ship_bitmap(ship_kind kind)
{
    switch(kind)
    {
        case AQUARII:
            return bitmap_named("aquarii");
        case GLIESE:
            return bitmap_named("gliese");
        default:
            return bitmap_named("pegasi");
    }
}

player_data new_player()
{
    player_data result;
    result.x = 50;
    result.y = 200;
    result.kind = PEGASI;
    return result;
}

void draw_player(const player_data &player_to_draw)
{
    bitmap to_draw;
    to_draw = ship_bitmap(player_to_draw.kind);
    draw_bitmap(to_draw , player_to_draw.x ,player_to_draw.y);
}

bool player_hit_coin(const player_data &player , const coin_data &coin)
{
    bitmap coin_bmp = bitmap_named("gold_coin");
    int coin_cell = animation_current_cell(coin.coin_animation);
    
    bitmap ship_bmp = ship_bitmap(player.kind);

    return bitmap_collision(
        coin_bmp, coin_cell , coin.x , coin.y,
        ship_bmp , 0 , player.x , player.y
    );


}
bool player_hit_planet(const player_data &player ,  const planet_data &planet)
{
    bitmap planet_bmp =  planet_bitmap(planet.kind);
    bitmap ship_bmp = ship_bitmap(player.kind);

    return bitmap_collision
    (
        planet_bmp  , 0 , planet.x , planet.y,
        ship_bmp , 0 , player.x , player.y
    );
}





void handle_input(player_data &player)
{
    if(key_typed(NUM_1_KEY)) player.kind = PEGASI;
    if(key_typed(NUM_2_KEY)) player.kind = GLIESE;
    if(key_typed(NUM_3_KEY)) player.kind = AQUARII;
    if(key_down(RIGHT_KEY)) player.x += PLAYER_SPEED;
    if(key_down(LEFT_KEY)) player.x -= PLAYER_SPEED;
    if(key_down(UP_KEY)) player.y -= PLAYER_SPEED;
    if(key_down(DOWN_KEY)) player.y += PLAYER_SPEED;
    
}

