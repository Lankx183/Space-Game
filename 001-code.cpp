#include "splashkit.h"
#include "planet_play.h"
using namespace std;
//The link address for the video can be found at https://youtu.be/GKDDq_wPCho


space_game_data new_game()
{
    space_game_data result;
    result.player = new_player();
    add_random_coin(result);
    add_random_planet(result);
    result.score = 0; 
    return result;
}

void draw_game(const space_game_data &game)
{
    clear_screen(COLOR_BLACK);
    
    draw_player(game.player);
    for(int i = 0; i<game.coins.size();i++)
    {
        draw_coin(game.coins[i]);
    }
    for(int j = 0; j < game.planets.size(); j++)
    {
        draw_planet(game.planets[j]);
    }
    draw_text("Score: " + to_string(game.score), COLOR_WHITE, 0, 0);
    draw_text("Planets on screen " + to_string(game.planets.size()), COLOR_WHITE, 100, 0);
    refresh_screen(60);
}

void remove_coin(vector<coin_data> &coins , int idx)
{
    free_animation(coins[idx].coin_animation);
    coins[idx] = coins[coins.size()-1];
    coins.pop_back();
}

void add_random_coin(space_game_data &game)
{
    game.coins.push_back( new_coin() );
}
void add_random_planet(space_game_data &game)
{
    game.planets.push_back( new_planet() );
}


void update_coins(vector<coin_data> &coins,const player_data &player, space_game_data &game)
{
    
    if(rnd() < 0.33)
    {
    add_random_coin(game);
    }   
    vector<int> to_remove;
    for(int i = 0 ; i < coins.size() ; i++)
    {
        update_coin(coins[i]);

        if(player_hit_coin(player,coins[i]))
        {
            to_remove.push_back(i);
            game.score = game.score + 1;
        }

        for(int j  = 0 ; j < game.planets.size() ; j++)
        {
            if(planet_hit_coin( game.planets[j] , coins[i] ))
            {
                to_remove.push_back(i);
            }
        }

      
        
    }

    for(int i = to_remove.size()-1 ; i >=0; i--)
    {
        remove_coin(coins , to_remove[i]);
    }
}


void update_planets (vector <planet_data> &planets, space_game_data &game, const player_data &player)
{
    int to_remove;
    vector<int> coin_remove;
    while(game.planets.size() < 3)
    {
    add_random_planet(game);
    }

    for (int i = 0 ; i < planets.size() ; i++)
    {        
               
        planets[i].x = planets[i].x - PLANET_SPEED;
        
        
        if(player_hit_planet(player,planets[i]))
        {
            if(game.score > 0)
            {
            game.score = game.score - 1;
            load_sound_effect("player-hit", "crash.wav");
            play_sound_effect("player-hit");
            delay(100);
            }
        }

        if(planets[i].x < 0 - bitmap_width(planet_bitmap(planets[i].kind)))
        {
            to_remove++;            
        }        
        
        if(to_remove == 3)
        {
            planets.pop_back();
            planets.pop_back();
            planets.pop_back();
        }
       

    }



}

void update_game(space_game_data &game)
{
    update_planets(game.planets,game,game.player);
    update_coins(game.coins,game.player,game);
    
    //update_planet(game.the_planet);
    /*if(player_hit_coin(game.player,game.the_coin))
    {
        game.the_coin.x = rnd(screen_width() - bitmap_width(bitmap_named("gold_coin")));
        game.the_coin.y = rnd(screen_height() - bitmap_height(bitmap_named("gold_coin")));
        /* can the following code be considered a more viable approach since
        the coin is consumed by a ship and a new one is created for the game. Thanks
        game.the_coin = new coin();
        */
     //   game.score++;
    //}
}


