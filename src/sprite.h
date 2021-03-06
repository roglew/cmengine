#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "collision.h"
#include "resourcemanager.h"
#include "square.h"
#include "ids.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Sprite: public sf::Sprite
{
  protected:
    ResourceManager *resource_manager;
    ResourceImage image;
    Square image_pos;
    bool is_part, image_defined, loaded;
  
  public:
    Collision collision;

    Sprite(ResourceManager *resource_manager);
    // set_collision(const &Collision);
    // MODIFIES: This
    // EFFECTS:  Sets the collision struct of the sprite

    ~Sprite();
    // Destructor

    bool collides(Sprite& other_sprite);
    // EFFECTS: Returns whether the two sprites collide
    
    void set_image(ResourceImage image);
    // MODIFIES: This
    // Sets the image to the entire texture
    
    void set_image(ResourceImage image, Square &position);
    void set_image(ResourceImage image, int x, int y, int w, int h);
    // MODIFIES: This
    // EFFECTS: Sets the image and section to load when load() is called

    void set_position(int x, int y);
    // MODIFIES: This, this's collision
    // EFFECTS:  Sets the position of the sf::Sprite and this sprite's collision

    int get_sprite_width();
    // EFFECTS: Returns the width of the image

    int get_sprite_height();
    // EFFECTS: Returns the height of the image
    
    void update_texture();
    // MODIFIES: This
    // EFFECTS:  Updates the sfml texture to match the image. Also loads the image if
    //           neccesary
    
    void load();
    // REQUIRES: Image must have been set
};


#endif

