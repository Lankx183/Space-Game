#include "planet_play.h"
#include "splashkit.h"


coin_data new_coin(double x , double y)
{
    coin_data result;

    result.x = x;
    result.y = y;
    result.coin_animation = create_animation("coins","spins");
    
    return result;
}

coin_data new_coin()
{
    bitmap coin_bmp = bitmap_named("gold_coin");

    return new_coin(rnd(screen_width() - bitmap_width(coin_bmp)), rnd(screen_height()-bitmap_height(coin_bmp)));
}

void draw_coin(const coin_data &coin)
{
    draw_bitmap("gold_coin",coin.x, coin.y, option_with_animation(coin.coin_animation) );
}

void update_coin(coin_data &coin)
{
    update_animation(coin.coin_animation);
}

bool planet_hit_coin(const planet_data &planet , const coin_data &coin)
{
    bitmap coin_bmp = bitmap_named("gold_coin");
    int coin_cell = animation_current_cell(coin.coin_animation);
    
    bitmap planet_bmp = planet_bitmap(planet.kind);

    return bitmap_collision(
        coin_bmp, coin_cell , coin.x , coin.y,
        planet_bmp , 0 , planet.x , planet.y
    );


}