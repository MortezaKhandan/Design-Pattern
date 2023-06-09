
#include <iostream>
#include <vector>
using namespace std;

// Component interface
struct GraphicObject
{
    virtual void draw() = 0;
};

// Leaf class
struct Circle : GraphicObject
{
    void draw() override 
    {
        cout << "Circle" << endl;
    }
};
// Leaf class
struct Square : GraphicObject
{
	void draw() override
	{
		cout << "Square" << endl;
	}
};

// Composite class
struct Group :GraphicObject
{
    std::string name;
    Group(const std::string& name)
        :name{name}
    {}

    void draw() override
    {
        cout << "Circle" << "Objects:" << endl;
        for (auto&& o : objects)
            o->draw();
    }

    std::vector<GraphicObject*> objects;
};


int main()
{
    Group root("root");
    Circle c1, c2;
    root.objects.emplace_back(&c1);

    Group sub("sub");
    sub.objects.push_back(&c2);

    root.objects.push_back(&sub);

    root.draw();

    return 0;
}