#ifndef OBJECT_HPP
#define OBJECT_HPP


#include "../../Vector/vector.hpp"
#include "../../Graphics/pscolor.hpp"



struct Ray
{
    Vector start_point{};
    Vector direction  {};
    int ref_num = 0;
};

class Object_manager;

class Object
{
    public:

        // moves object by offs vector
        virtual void move(const Vector& offs) = 0;

        // get current position of object
        virtual Vector get_pos() const = 0;

        // completely overwrites position 
        // returns previous position
        virtual Vector set_pos(const Vector& new_pos) = 0; 

        // rgb of object at specific point - use tracing
        virtual PGL::PsColor get_rgb(const Vector& point, 
                               const Ray& ray,
                               const Object_manager& obj_manager) const = 0;

        // normal vector to the surface of the object 
        // at a specific point
        // returned vector is normalized
        virtual Vector get_normal(const Vector& point) const = 0;

        // return boolean value that represents whether 
        // ray is crossing this object
        // 'point' - out parameter for crossing point 
        // 'point' is the first point on the way of the ray
        // if pointer is NULL, nothing returned 
        virtual bool ray_is_crossing(const Ray& ray, Vector* point) const = 0;

        // virtual dtor so it works fine with inheritance
        virtual ~Object() {}
};



class Material
{
    PGL::PsColor col_;
    double matte_coeff_ = 0;
    unsigned ray_num_   = 2; // TODO global
    // прибавлять светимость
    public:

        Material(const PGL::PsColor& col, double matte_coeff, unsigned ray_num):
            col_(col),
            matte_coeff_(matte_coeff),
            ray_num_(ray_num)
            {}

        Material():
            col_(PGL::PsColor(255, 255, 255, 255)),
            matte_coeff_(0),
            ray_num_(1)
            {}

        Material            (const Material& that) = default;
        Material& operator= (const Material& that) = default;
        ~Material()                                = default;

        void setColor(PGL::PsColor& col)
        {
            col_ = col;
        }

        PGL::PsColor get_rgb(const Vector& point, 
                       const Ray& ray,
                       const Object& self,
                       const Object_manager& obj_manager) const;
};


struct View
{
    // position of the view point
    Vector view_point{};

    // vector that defines position of
    // the 'monitor' image plane relatively to view point
    Vector image_plane_pos{};

    // Vetrical and horizontal rotation in rads
    double ver_rot = 0;
    double hor_rot = 0;
};


struct Scene
{
    // vector of all abjects in the scene
    std::vector<Object*> objects{};

    // view point and image plane
    View view{};
};

class Object_manager
{
    const Scene* scene_ptr_ = nullptr;

    public:

        Object_manager():
            scene_ptr_{nullptr}
            {}

        explicit Object_manager(const Scene* scene_ptr):
            scene_ptr_(scene_ptr)
            {}

        Object_manager            (const Object_manager& that) = default;
        Object_manager& operator= (const Object_manager& that) = default;
        ~Object_manager()                                      = default;

        const Scene* get_scene() const
            {
                return scene_ptr_;
            }

        void set_scene(const Scene* scene_ptr)
            {
                scene_ptr_ = scene_ptr;
            }

        PGL::PsColor trace_ray(const Object* self, const Ray& ray) const;

        Object* find_object_crossing(const Ray& ray, const Object* self, Vector* point) const;
};


Vector reflect_vector(const Vector& vector, const Vector& normal);

Vector refract_vector(const Vector& vector, const Vector& normal, double ref_ind);

Vector random_vector();


#endif