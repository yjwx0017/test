#ifndef {header-macro}
#define {header-macro}

#include <duilib2_global.h>
#include <Controls/{parent-class-name}.h>

namespace duilib2
{

class DUILIB2SHARED_EXPORT {class-name} : public {parent-class-name}
{
public:
	{class-name}(const String& name);
	virtual ~{class-name}();

	/// @copydoc Window::getType
	virtual String getType() const;

	/// @copydoc Window::getWidth
	virtual int getWidth() const;

	/// @copydoc Window::getHeight
	virtual int getHeight() const;

	/// @copydoc Window::getPosition
	virtual Point getPosition() const;

protected:
	virtual void render(RenderTarget* renderTarget);

private:
	static String sTypeName;
};

class DUILIB2SHARED_EXPORT {class-name}Factory : public WindowFactory
{
public:
	{class-name}Factory();
	virtual ~{class-name}Factory();

	/// @copydoc WindowFactory::getType
	virtual String getType() const;

	/// @copydoc WindowFactory::createInstance
	virtual Window* createInstance(const String& name);

	/// @copydoc WindowFactory::destroyInstance
	virtual void destroyInstance(Window* window);

private:
};

} // namespace duilib2

#endif  // {header-macro}
