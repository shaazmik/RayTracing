#ifndef RAYTRACING_SCENE
#define RAYTRACING_SCENE

#include "./Scene_objects/scene_objects.hpp"
#include "../Widget/widget.hpp"
#include "../Graphics/graphics.hpp"
#include "../log/log.hpp"

class RayTracingScene : public Widget
{ 
    private:

        sf::Texture texture_{};
        sf::Sprite  sprite_{};
        sf::Uint8*  pixels_{};

    public:

        RayTracingScene(){
        };

        RayTracingScene(unsigned x_size, unsigned y_size):Widget(x_size, y_size),
            texture_{},
            sprite_{}
            {
                pixels_ = new sf::Uint8[m_width * m_height * 4];

                texture_.create(m_width, m_height);
                texture_.update(pixels_, m_width, m_height, 0, 0);
                
                sprite_.setTexture(texture_);
            }

        ~RayTracingScene()
            {
                delete[] pixels_;
            }

        void _init()
        {
            pixels_ = new sf::Uint8[m_width * m_height * 4];

            texture_.create(m_width, m_height);
            texture_.update(pixels_, m_width, m_height, 0, 0);
                
            sprite_.setTexture(texture_);
        }

        bool set_pixel(const Vector& pxl_pos,          const PGL::PsColor& pxl_val, unsigned char alpha);
        bool set_pixel(unsigned x_pos, unsigned y_pos, const PGL::PsColor& pxl_val, unsigned char alpha);

        PGL::PsColor get_pixel(const Vector& pxl_pos,          unsigned char* alpha);
        PGL::PsColor get_pixel(unsigned x_pos, unsigned y_pos, unsigned char* alpha);
        
        void pixels_update()
        {
            texture_.update(pixels_, m_width, m_height, 0, 0);
        }

        void pixels_draw()
        {
            PGL::Graphics::getInstance()->m_window.draw(sprite_);
        }
};


#endif