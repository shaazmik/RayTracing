#include "./raytracing_scene.hpp"

PGL::PsColor RayTracingScene::get_pixel(const Vector& pxl_pos, unsigned char* alpha)
{
    unsigned x_pos = (unsigned) pxl_pos.x();
    unsigned y_pos = (unsigned) pxl_pos.y();

    return get_pixel(x_pos, y_pos, alpha);
}

//---------------------------------------------------------

PGL::PsColor RayTracingScene::get_pixel(unsigned x_pos, unsigned y_pos, unsigned char* alpha)
{
    if (x_pos < m_width && y_pos < m_height)
    {
        unsigned cur_pos = (y_pos * m_width + x_pos) * 4;

        unsigned char r = (unsigned char) pixels_[cur_pos    ];
        unsigned char g = (unsigned char) pixels_[cur_pos + 1];
        unsigned char b = (unsigned char) pixels_[cur_pos + 2]; 
        
        if (alpha)
            *alpha = (unsigned char) pixels_[cur_pos + 3];

        return PGL::PsColor(r, g, b, 255);
    }
    else
    {
        return PGL::PsColor(0, 0, 0, 255);
    }
}

//---------------------------------------------------------

bool RayTracingScene::set_pixel(const Vector& pxl_pos, const PGL::PsColor& pxl_val, unsigned char alpha)
{
    unsigned x_pos = (unsigned) pxl_pos.x();
    unsigned y_pos = (unsigned) pxl_pos.y();

    return set_pixel(x_pos, y_pos, pxl_val, alpha);
}

//---------------------------------------------------------

bool RayTracingScene::set_pixel(unsigned x_pos, unsigned y_pos, const PGL::PsColor& pxl_val, unsigned char alpha)
{
    if (x_pos < m_width && y_pos < m_height)
    {
        unsigned cur_pos = (y_pos * m_width + x_pos) * 4;

        pixels_[cur_pos    ] = (unsigned char) pxl_val.get_r(); 
        pixels_[cur_pos + 1] = (unsigned char) pxl_val.get_g(); 
        pixels_[cur_pos + 2] = (unsigned char) pxl_val.get_b(); 
        pixels_[cur_pos + 3] = alpha;                      

        return true;
    }
    else
    {
        return false;
    }
}
