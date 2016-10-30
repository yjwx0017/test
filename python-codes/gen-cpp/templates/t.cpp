#include <Controls/{class-name}.h>

namespace duilib2
{

static String g{class-name}Properties[][3] =
{
	// name              value         type
	{"", "", ""}
};


String {class-name}::sTypeName = "{class-name}";

{class-name}::{class-name}(const String& name)
	: {parent-class-name}(name)
{
	String* property = &g{class-name}Properties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

{class-name}::~{class-name}()
{

}

String {class-name}::getType() const
{
	return sTypeName;
}

int {class-name}::getWidth() const
{
	return 0;
}

int {class-name}::getHeight() const
{
	return 0;
}

Point {class-name}::getPosition() const
{
	return Point();
}

void {class-name}::render(RenderTarget* renderTarget)
{

}


{class-name}Factory::{class-name}Factory()
{

}

{class-name}Factory::~{class-name}Factory()
{

}

String {class-name}Factory::getType() const
{
	return String("{class-name}");
}

Window* {class-name}Factory::createInstance(const String& name)
{
	return new {class-name}(name);
}

void {class-name}Factory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
