#ifndef ABSTRACT_MANAGER
#define ABSTRACT_MANAGER

class AbstractManager
{
public:
    AbstractManager()  = default;
    ~AbstractManager() = default;

    virtual void addObj();
    virtual void deleteObj();
    
private:
};

#endif