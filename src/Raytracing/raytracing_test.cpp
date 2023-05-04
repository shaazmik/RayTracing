#include  <vector>
#include "./Scene_objects/scene_objects.hpp"
#include "./raytracing_config.hpp"
#include "./CoordSys/coordsys.hpp"
#include "../general.hpp"

static const int Coordsys_x_max = +5;
static const int Coordsys_x_min = -5;
static const int Coordsys_y_max = +5;
static const int Coordsys_y_min = -5;

static const unsigned Coordsys_x_pos = 0;
static const unsigned Coordsys_y_pos = 0;

static const unsigned Wndw_x_size = 720;
static const unsigned Wndw_y_size = 360;

//---------------------------------------------------------

// static const int Frame_num = 1;

//---------------------------------------------------------

static const double Camera_view_step = 0.5;

static const double Rot_angle_rad = (1 * M_PI / 180);
static const double Rot_angle_sin = sin(Rot_angle_rad);
static const double Rot_angle_cos = cos(Rot_angle_rad);

//---------------------------------------------------------

static const int Key_W = 0;
static const int Key_A = 1;
static const int Key_S = 2;
static const int Key_D = 3;

static const int Key_ArrUp    = 4;
static const int Key_ArrLeft  = 5;
static const int Key_ArrDown  = 6;
static const int Key_ArrRight = 7;

static const int Key_LShift = 8;
static const int Key_LCtrl  = 9;

static const int Control_keys_num = 10;

//=========================================================

static Vector get_direction(const View& view, const Vector& cur_point);

static void move_view_point(View* view, double forward, double up, double right);

static bool update_scene(View* view, const char keys_pressed[]);

static PGL::PsColor average_rgb(const PGL::PsColor& new_col, const PGL::PsColor& old_col, const int frames_still);

//=========================================================


//---------------------------------------------------------

int raytrace_test()
{
    Coordsys coordsys{Coordsys_x_max,
                      Coordsys_x_min,
                      Coordsys_y_max,
                      Coordsys_y_min,
                      Wndw_x_size,
                      Wndw_y_size};

    coordsys.x_pos = Coordsys_x_pos;
    coordsys.y_pos = Coordsys_y_pos;

    // Objects
    
    //---------------------------------

    std::vector<Object*> objects{};

    Non_trans_sphere  metal {Vector{ -5,    0,   0},   3, Material{PGL::PsColor(123,  57, 204, 255), 0.4, 1}};
    Non_trans_sphere  matte {Vector{  5, -1.5,   7}, 1.5, Material{PGL::PsColor(237, 149, 245, 255),   1, 1}};
    Non_trans_sphere  allum {Vector{  2, -1.5,   3}, 1.5, Material{PGL::PsColor(178, 237, 232, 255), 0.9, 1}};
    Non_trans_sphere  mirror{Vector{  3, -2.5,  18}, 0.5, Material{PGL::PsColor(0, 255, 255, 255),   0, 1}};
    Trans_sphere      trans {Vector{ -1,   -2,  15},   1, 1.5};
    Sphere_light      light {Vector{ -3 , -2.2,  15}, 0.8, PGL::PsColor(139, 247, 160, 255)};

    objects.push_back(&metal);
    objects.push_back(&matte);
    objects.push_back(&allum);
    objects.push_back(&trans);
    objects.push_back(&light);
    objects.push_back(&mirror);
    
    Non_trans_plane bottom{Vector{0, 1, 0}, Vector{  0, -3,   0}, Material{PGL::PsColor(255, 255, 255, 200),   1, 1}};
    Non_trans_plane left  {Vector{1, 0, 0}, Vector{-10,  0,   0}, Material{PGL::PsColor(255, 159,  53, 200),   1, 1}};
    Non_trans_plane right {Vector{1, 0, 0}, Vector{+10,  0,   0}, Material{PGL::PsColor( 87, 170, 252, 255),   1, 1}};
    Non_trans_plane back  {Vector{0, 0, 1}, Vector{  0,  0, -20}, Material{PGL::PsColor(202, 214, 222, 255), 0.5, 1}};
    Plane_light     top   {Vector{0, 1, 0}, Vector{  0, 10,   0}, PGL::PsColor(255, 255, 255, 255)};
    Non_trans_plane front {Vector{0, 0, 1}, Vector{  0,  0,  51}, Material{PGL::PsColor(255, 255, 255, 255),   1, 1}};

    objects.push_back(&bottom);
    objects.push_back(&top);
    objects.push_back(&left);
    objects.push_back(&right);
    objects.push_back(&back);
    objects.push_back(&front);

    View view{Vector{0, 0, 50}, Vector{0, 0, -25}, 0, 0};


    Factory::getInstance()->setWidgetCapacity(10);

    WidgetManager*     desktop    = Factory::getInstance()->makeWidgetManager();
    SphereColorButton* btn        = Factory::getInstance()->makeSphereColorButton();
    RayTracingScene*   rayScene   = Factory::getInstance()->makeRayTracingScene();

    PGL::PsColor btn1Color(0, 250,  10, 255);


    btn->setSize(40,25);
    btn->move(1850, 1040);
    btn->initObject(&metal, btn1Color);

    rayScene->setSize(Wndw_x_size, Wndw_y_size);
    rayScene->_init();

    desktop->setCapacity(20);
    desktop->addWidget(btn);

    PGL::Graphics* graphLib = PGL::Graphics::getInstance();
    PGL::PsEvent   event    = PGL::PsEvent();


    Scene scene{objects, view};
    Object_manager object_manager{&scene};



    while (graphLib->isOpen())
    {
        while (graphLib->pollEvent(event))
        {
            switch(event.getEventType())
            {
                case PGL::PsEvent::Closed:
                    graphLib->close();
                    break;

                case PGL::PsEvent::MouseButtonPressed:
                    desktop->controller(event);
                    break;

                default:
                    break;
            }
        }

        char keys_pressed[Control_keys_num] = { 0 };
        int  frames_still = 0;


        bool is_changed = update_scene(&(scene.view), keys_pressed);
        if (is_changed)
            frames_still = 0;

        srand(time(nullptr));
        for (unsigned cur_y_pos = 0; cur_y_pos < Wndw_y_size; cur_y_pos += 1)
        {
            for (unsigned cur_x_pos = 0; cur_x_pos < Wndw_x_size; cur_x_pos += 1)
            {
                Vector cur_point_r{(double)cur_x_pos, (double)cur_y_pos};
                Vector cur_point = coordsys.reverse_convert_coord(cur_point_r);
                cur_point.setZ(0);

                cur_point = scene.view.view_point + scene.view.image_plane_pos + cur_point;

                Vector direction = get_direction(scene.view, cur_point);

                Ray ray{scene.view.view_point, direction, 0};
                PGL::PsColor cur_point_rgb = 1.2 * object_manager.trace_ray(nullptr, ray);

                PGL::PsColor prev = rayScene->get_pixel(cur_point_r, nullptr);
                PGL::PsColor res  = average_rgb(cur_point_rgb, prev, frames_still);

                bool is_set = rayScene->set_pixel(cur_point_r, res, Alpha_default);
                {
                    if (is_set == false)
                    {
                        LOG_MSG("PIXEL_ISNT_SET");
                        return -1;
                    }
                }
            }
        }
    
        rayScene->pixels_update();
        rayScene->pixels_draw();
        desktop->draw();
        frames_still++;
        graphLib->display();
        graphLib->clear();
    }

    delete Factory::getInstance();
    delete graphLib;

    return 0;
}

//---------------------------------------------------------

static PGL::PsColor average_rgb(const PGL::PsColor& new_col, const PGL::PsColor& old_col, const int frames_still)
{

    PGL::PsColor aver = (old_col * frames_still + new_col) * (1.0 / (frames_still + 1.0));

    return aver;
}

//---------------------------------------------------------

static bool update_scene(View* view, const char keys_pressed[])
{
    assert(view);

    double forward = 0;
    double up      = 0;
    double right   = 0;

    bool is_changed = false;
    
    for (unsigned iter = 0; iter < Control_keys_num; iter++)
        if (keys_pressed[iter])
        {
            is_changed = true;
            break;
        }

    if (keys_pressed[Key_W]) 
        forward += Camera_view_step;

    if (keys_pressed[Key_A]) 
        right   -= Camera_view_step;

    if (keys_pressed[Key_S]) 
        forward -= Camera_view_step;

    if (keys_pressed[Key_D]) 
        right   += Camera_view_step;

    if (keys_pressed[Key_LShift]) 
        up      += Camera_view_step;

    if (keys_pressed[Key_LCtrl]) 
        up      -= Camera_view_step;

    if (keys_pressed[Key_ArrUp]) 
        view->ver_rot += Rot_angle_rad;

    if (keys_pressed[Key_ArrLeft]) 
        view->hor_rot += Rot_angle_rad;

    if (keys_pressed[Key_ArrDown]) 
        view->ver_rot -= Rot_angle_rad;

    if (keys_pressed[Key_ArrRight]) 
        view->hor_rot -= Rot_angle_rad;

    move_view_point(view, forward, up, right);

    return is_changed;
}

//---------------------------------------------------------

static void move_view_point(View* view, double forward, double up, double right)
{
    assert(view);

    Vector offs{right, up, -forward};

    offs.rotate_x(+view->ver_rot);
    offs.rotate_y(-view->hor_rot);

    view->view_point += offs;

    return;
}

//---------------------------------------------------------

static Vector get_direction(const View& view, const Vector& cur_point)
{
    Vector rotatable = cur_point - view.view_point;

    rotatable.rotate_x(+view.ver_rot);
    rotatable.rotate_y(-view.hor_rot);

    return rotatable;
}