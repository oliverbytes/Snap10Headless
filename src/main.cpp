#include <bb/Application>

#include "service.hpp"

using namespace bb;

Q_DECL_EXPORT int main(int argc, char **argv)
{
	Application app(argc, argv);
	new Service(&app);
	return Application::exec();
}
